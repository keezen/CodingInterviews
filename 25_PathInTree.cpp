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


void dispaly_matrix(vector<vector<int> > &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}


void dispaly_tree(TreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << ' ';
    dispaly_tree(root->left);
    dispaly_tree(root->right);
}


void DFS(TreeNode* root, int expectNumber, vector<vector<int> > &res, vector<int> &path)
{
    if (root == NULL)
        return;

    path.push_back(root->val);

    // leaf node
    if (root->left == NULL && root->right == NULL && root->val == expectNumber)
        res.push_back(path);

    if (root->left != NULL)
        DFS(root->left, expectNumber - root->val, res, path);
    if (root->right != NULL)
        DFS(root->right, expectNumber - root->val, res, path);

    path.pop_back();
}


vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
{
    vector<vector<int> > res;
    vector<int> path;

    if (root == NULL)
        return res;

    DFS(root, expectNumber, res, path);

    return res;
}


int main()
{
    TreeNode *root = NULL, *p;
    vector<vector<int> > result;

    // construct tree
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);

    p = root->left;
    p->left = new TreeNode(4);
    p->right = new TreeNode(7);

    dispaly_tree(root);
    cout << endl << endl;

    result = FindPath(root, 22);
    dispaly_matrix(result);

    return 0;
}
