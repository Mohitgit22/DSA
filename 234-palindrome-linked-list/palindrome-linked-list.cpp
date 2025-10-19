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
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;

        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow ->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverse(slow);

        while(head and head2){
            if(head->val != head2->val) return false;

            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};