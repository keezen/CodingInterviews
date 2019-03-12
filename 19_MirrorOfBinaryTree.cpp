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


void Mirror(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return;

    // mirror left and right, then swap left and right
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    swap(pRoot->left, pRoot->right);
}


int main()
{
    TreeNode *root = NULL, *root_mirror = NULL, *p;

    // construct tree
    // root1 = reConstructBinaryTree(pre1, vin1);
    root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);

    p = root->left;
    p->left = new TreeNode(5);
    p->right = new TreeNode(7);

    p = root->right;
    p->left = new TreeNode(9);
    p->right = new TreeNode(11);

    dispaly_tree(root);
    cout << endl;

    Mirror(root);

    dispaly_tree(root);
    cout << endl;

    return 0;
}
