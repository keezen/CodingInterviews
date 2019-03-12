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


int TreeDepth(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return 0;

    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);

    return max(left, right) + 1;
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
    res = TreeDepth(root);
    cout << res << endl;

    return 0;
}
