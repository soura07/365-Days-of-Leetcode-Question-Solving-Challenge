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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m, vector<int>(n, -1));

        int xStart = -1, xEnd = n;
        int yStart = -1, yEnd = m;

        int y = 0, x = 0;
        
        int dir = 0;

        while(head) {
            arr[y][x] = head->val;

            if(dir == 0) {
                if(x+1 == xEnd) {
                    dir++;
                    yStart = y;
                    y++;
                }
                else x++;
            } else if(dir == 1) {
                if(y+1 == yEnd) {
                    dir++;
                    xEnd = x;
                    x--;
                }
                else y++;
            } else if(dir == 2) {
                if(x-1 == xStart) {
                    dir++;
                    yEnd = y;
                    y--;
                }
                else x--;
            } else if(dir == 3) {
                if(y-1 == yStart) {
                    dir = 0;
                    xStart = x;
                    x++;
                }
                else y--;
            }
            head = head->next;
        }
        return arr;
    }
};