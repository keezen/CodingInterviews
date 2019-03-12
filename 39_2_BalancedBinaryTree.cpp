# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;

// definition of tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


void dispaly_tree(TreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << ' ';
    dispaly_tree(root->left);
    dispaly_tree(root->right);
}


bool IsBalanced(TreeNode* root, int &depth)
{
    if (root == NULL)
    {
        depth = 0;
        return true;
    }
    
    int left_depth, right_depth;
    if (IsBalanced(root->left, left_depth) && IsBalanced(root->right, right_depth))
        if (abs(left_depth - right_depth) <= 1)
        {
            depth = left_depth > right_depth ? left_depth + 1 : right_depth + 1;
            return true;
        }

    return false;
}


bool IsBalanced_Solution(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return true;

    int depth;
    return IsBalanced(pRoot, depth);
}


int main()
{
    TreeNode *root = NULL, *p;
    int res;

    // construct tree
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    p = root->left;
    p->left = new TreeNode(4);
    p->right = new TreeNode(5);

    p = root->right;
    p->right = new TreeNode(6);

    p = root->left->right;
    p->left = new TreeNode(7);

    dispaly_tree(root);
    cout << endl;

    // test
    res = IsBalanced_Solution(root);
    cout << res << endl;

    return 0;
}
