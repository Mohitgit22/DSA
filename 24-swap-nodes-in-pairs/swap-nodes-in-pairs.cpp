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
    ListNode* swapPairs(ListNode* head) {
        
        int cnt = 0;
        ListNode* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
     
       if(cnt == 1)
       return head;
       
       ListNode* newhead = nullptr;
       ListNode* lastnode = nullptr;
       curr = head;
       cnt = cnt/2;
       while(cnt > 0 && curr){
        cnt--;
         ListNode *temp =curr->next;
         if(newhead == nullptr) newhead = temp;
         ListNode *nextturn = temp->next;
        
         curr->next = nextturn;
         temp->next = curr;     

          if(lastnode) lastnode->next = temp;
          lastnode = curr;

    

         curr = curr->next;
       }



       return newhead;
    }
};