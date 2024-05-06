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
    void deleteNode(ListNode* node) {
        if(node == nullptr or node->next == nullptr) return;
        ListNode* temp = node;
        temp->val = temp->next->val;
        ListNode* deleteNode = temp->next;
        ListNode* nextNode = nullptr;
        if(temp->next != nullptr){
            nextNode = temp->next->next;
        }
        temp -> next = nextNode;
        delete deleteNode;
    }
};