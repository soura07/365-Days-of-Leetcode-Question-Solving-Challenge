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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> arr(k, nullptr);
        if (k == 1) {
            arr[0] = head;
            return arr;
        }

        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }

        if (count <= k) {
            current = head;
            for (int i = 0; i < count; i++) {
                arr[i] = head;
                ListNode* tail = head;
                head = head->next;
                tail->next = nullptr;
            }
            return arr;
        }

        int extraCount = count % k;
        int elementsCount = count / k;

        for (int i = 0; i < k; i++) {
            arr[i] = head;
            int currentPartSize = elementsCount + (extraCount > 0 ? 1 : 0);
            extraCount--;

            for (int j = 0; j < currentPartSize - 1; j++) {
                head = head->next;
            }

            if (head != nullptr) {
                ListNode* tail = head;
                head = head->next;
                tail->next = nullptr;
            }
        }

        return arr;
    }
};