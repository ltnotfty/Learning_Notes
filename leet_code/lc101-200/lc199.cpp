#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), right(nullptr), left(nullptr) {}
    TreeNode( int x ) : val(x), left(nullptr), right(nullptr) {}
    TreeNode( int x, TreeNode *left, TreeNode *right) : val( x ), left( left), right( right ) {}

}


class Solution1 {
public:

    void rightView(TreeNode *root, int depth, vector<int> &res) {
        if (NULL == root)
            return;

        if ( depth > res.size()) {
            res.push_back(root->val);
        }
        
        rightView(root->right, depth + 1, res);
        rightView(root->left, depth + 1,res);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        
        rightView(root, 1, res);

        return res; 
    }
};
class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;

        queue<TreeNode *> node_q;
        node_q.push(root);
        TreeNode *cur_right_most = root;


        while ( !node_q.empty()) {
            TreeNode *cur = node_q.front();
            node_q.pop();


            if (cur && cur->left != NULL)
                node_q.push(cur->left);
            if (cur &&　cur->right != NULL)
                node_q.push(cur->right);

            if ( cur 　&& cur  == cur_right_most) {
                res.push_back(cur->val);
                if (cur->right)
                    cur_right_most = cur->right;
                else if ( cur->left)
                    cur_right_most = cur->left;
                else
                    cur_right_most = node_q.back();
            }
        }

        return res; 
    }
};
// binary tree + BFS or DFS
int main(int argc, char *argv[])
{





    return 0;
}
