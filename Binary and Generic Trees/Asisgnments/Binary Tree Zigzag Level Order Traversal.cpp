//leetcode-103: Binary Tree Zigzag Level Order Traversal
//TC: O(n), SC: O(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool LtoR = true;

        while (!q.empty()) {
            int size = q.size(); // Capture the initial size of the queue
            vector<int> temp(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* front = q.front(); q.pop();
                int index = LtoR ? i : size - i - 1;
                temp[index] = front->val;

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            LtoR = !LtoR;
            ans.push_back(temp);
        }
        return ans;
    }
};