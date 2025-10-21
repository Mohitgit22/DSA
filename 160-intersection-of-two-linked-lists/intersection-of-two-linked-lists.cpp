/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head){
        if(head == nullptr) return 0;
       
        int cnt = 0;
        ListNode* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = len(headA);
        int len2 = len(headB);
      
        ListNode* temp1 = len1 > len2 ? headA : headB;
        ListNode* temp2 = nullptr;

        if(temp1 == headA)
        temp2 = headB;
        else
        temp2 = headA;

        int diff = abs(len1 - len2);

        for(int i = 0; i < diff; i++){
            temp1 = temp1->next;
        }

        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 != temp2) return nullptr;
        
        return temp1;



    }
};