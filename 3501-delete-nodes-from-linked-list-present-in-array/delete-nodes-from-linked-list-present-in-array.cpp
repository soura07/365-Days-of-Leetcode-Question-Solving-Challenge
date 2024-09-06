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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numValue(nums.begin(), nums.end());

        ListNode example;
        example.next = head;
        ListNode* curr = &example;

        while(curr->next != NULL){
            if(numValue.find(curr->next->val) != numValue.end()){
                curr->next = curr->next->next;
            }
            else{
            curr = curr->next;
            }
        }
        return example.next;
        
    }
    
};