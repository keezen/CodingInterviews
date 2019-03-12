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


vector<vector<int> > Print_Queue(TreeNode* pRoot)
{
    vector<vector<int> > res;

    if (pRoot == NULL)
        return res;

    queue<TreeNode *> qnode;
    queue<int> qrow;
    TreeNode *p;
    int r = 0;  // row label starting from 0

    qnode.push(pRoot);
    qrow.push(r);
    while(!qnode.empty() && !qrow.empty())
    {
        p = qnode.front();
        r = qrow.front();
        qnode.pop();
        qrow.pop();

        // print
        if (r >= res.size())
            res.push_back(vector<int>());
        res[r].push_back(p->val);

        if (p->left != NULL)
        {
            qnode.push(p->left);
            qrow.push(r + 1);
        }
        if (p->right != NULL)
        {
            qnode.push(p->right);
            qrow.push(r + 1);
        }
    }

    return res;
}


void PrintDepth(TreeNode *root, int depth, vector<vector<int> > &res)
{
    if (root == NULL)
        return;

    if (depth >= res.size())
        res.push_back(vector<int>());

    res[depth].push_back(root->val);
    PrintDepth(root->left, depth + 1, res);
    PrintDepth(root->right, depth + 1, res);
}


vector<vector<int> > Print(TreeNode* pRoot)
{
    vector<vector<int> > res;

    if (pRoot == NULL)
        return res;

    PrintDepth(pRoot, 0, res);

    return res;
}


int main()
{
    TreeNode *root = NULL, *p;
    vector<vector<int> > res;

    // construct tree
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
    cout << endl << endl;

    // result
    res = Print(root);
    for (int i = 0; i < res.size(); i++)
        dispaly_vec(res[i]);

    return 0;
}
