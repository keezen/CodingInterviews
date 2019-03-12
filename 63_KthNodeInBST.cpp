# include <iostream>
# include <vector>
# include <cstdlib>
# include <stack>
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


TreeNode* Traverse(TreeNode *pRoot, int k, int &num)
{
    if (pRoot == NULL || k <= 0)
        return NULL;

    TreeNode* left = Traverse(pRoot->left, k, num);
    if (left != NULL && num >= k)
        return left;

    if (++num == k)
        return pRoot;

    TreeNode* right = Traverse(pRoot->right, k, num);
    if (right != NULL && num >= k)
        return right;

    return NULL;
}


TreeNode* KthNode_Recur(TreeNode* pRoot, int k)
{
    if (pRoot == NULL || k <= 0)
        return NULL;

    int num = 0;  // node counter
    return Traverse(pRoot, k, num);
}


TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if (pRoot == NULL || k <= 0)
        return NULL;

    // in-order traverse
    stack<TreeNode *> s;
    TreeNode *p = pRoot;
    int num = 0;
    while (p != NULL || !s.empty())
    {
        if (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            if (++num == k)
                return p;
            p = p->right;
        }
    }

    return NULL;
}


int main()
{
    TreeNode *root = NULL, *p;
    TreeNode *res;
    int k = 3;

    // construct tree
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    p = root->left;
    p->left = new TreeNode(2);
    p->right = new TreeNode(4);

    p = root->right;
    p->left = new TreeNode(6);
    p->right = new TreeNode(8);

    dispaly_tree(root);
    cout << endl;
    cout << k << endl << endl;

    // result
    res = KthNode(root, k);
    if (res != NULL)
        cout << res->val << endl;
    else
        cout << "NULL" << endl;

    return 0;
}
