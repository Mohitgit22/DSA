/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head, *prev = nullptr;

        while(temp){
            ListNode* front = temp->next;
            temp-> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        return reverse(head);
    }
};