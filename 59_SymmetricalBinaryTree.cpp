# include <iostream>
# include <vector>
# include <cstdlib>
# include <queue>
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


bool isSymmetrical(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->val == root2->val)
        if (isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left))
            return true;

    return false;
}


bool isSymmetrical_Recur(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return true;

    return isSymmetrical(pRoot->left, pRoot->right);
}


bool isSymmetrical(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return true;

    queue<TreeNode *> q1, q2;
    TreeNode *p1 = NULL, *p2 = NULL;

    q1.push(pRoot);
    q2.push(pRoot);
    while (!q1.empty() && !q2.empty())
    {
        p1 = q1.front();
        p2 = q2.front();
        q1.pop();
        q2.pop();
        
        if (p1 == NULL && p2 == NULL)
            continue;

        if (p1 == NULL || p2 == NULL)
            return false;

        if (p1->val != p2->val)
            return false;

        q1.push(p1->left);
        q1.push(p1->right);
        q2.push(p2->right);
        q2.push(p2->left);
    }

    return true;
}


int main()
{
    TreeNode *root = NULL, *p;
    bool res;

    // construct tree
    root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);

    p = root->left;
    p->left = new TreeNode(5);
    p->right = new TreeNode(7);

    p = root->right;
    p->left = new TreeNode(7);
    p->right = new TreeNode(5);

    dispaly_tree(root);
    cout << endl;

    // result
    res = isSymmetrical(root);
    cout << res << endl;

    return 0;
}
