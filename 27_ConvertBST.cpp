# include <iostream>
# include <cstdlib>
# include <vector>
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


void dispaly_bilist(TreeNode *root)
{
    for (TreeNode *p = root; p != NULL; p = p->right)
        cout << p->val << ' ';
    cout << endl;
}


void dispaly_tree(TreeNode* root)
{
    if (root == NULL)
        return;
    dispaly_tree(root->left);
    cout << root->val << ' ';
    dispaly_tree(root->right);
}


TreeNode* _Convert(TreeNode* pRootOfTree, TreeNode **tail)
{
    if (pRootOfTree == NULL)
    {
        (*tail) = NULL;
        return NULL;
    }

    // leaf node
    if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
    {
        (*tail) = pRootOfTree;
        return pRootOfTree;
    }

    TreeNode *pleft = NULL, *pright = NULL;

    if (pRootOfTree->left != NULL)
    {
        pleft = _Convert(pRootOfTree->left, tail);
        (*tail)->right = pRootOfTree;
        pRootOfTree->left = (*tail);
        (*tail) = pRootOfTree;
    }

    if (pRootOfTree->right != NULL)
    {
        pright = _Convert(pRootOfTree->right, tail);
        pRootOfTree->right = pright;
        pright->left = pRootOfTree;
    }

    return pleft ? pleft : pRootOfTree;
}


TreeNode* Convert(TreeNode* pRootOfTree)
{
    if (pRootOfTree == NULL)
        return NULL;

    // leaf node
    if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
        return pRootOfTree;

    TreeNode *tail;
    return _Convert(pRootOfTree, &tail);
}


int main()
{
    TreeNode *root = NULL, *bilist = NULL, *p = NULL;

    // construct tree
    root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);

    p = root->left;
    p->left = new TreeNode(4);
    p->right = new TreeNode(8);

    p = root->right;
    p->left = new TreeNode(12);
    p->right = new TreeNode(16);

    dispaly_tree(root);
    cout << endl;

    bilist = Convert(root);
    dispaly_bilist(bilist);

    return 0;
}
