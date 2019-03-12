# include <iostream>
# include <vector>
# include <cstdlib>
# include <queue>
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


vector<vector<int> > Print(TreeNode* pRoot)
{
    vector<vector<int> > res;

    if (pRoot == NULL)
        return res;

    stack<TreeNode *> q1, q2;
    int first = 1;
    TreeNode *p;

    q1.push(pRoot);
    while(!q1.empty() || !q2.empty())
    {
        vector<int> t;

        if (first)  // left to right
        {
            while (!q1.empty())
            {
                p = q1.top();
                q1.pop();

                t.push_back(p->val);
                if (p->left != NULL)
                    q2.push(p->left);
                if (p->right != NULL)
                    q2.push(p->right);
            }
        }
        else  // right to lefte
        {
            while (!q2.empty())
            {
                p = q2.top();
                q2.pop();

                t.push_back(p->val);
                if (p->right != NULL)
                    q1.push(p->right);
                if (p->left != NULL)
                    q1.push(p->left);
            }
        }

        res.push_back(t);
        first = 1 - first;
    }

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
