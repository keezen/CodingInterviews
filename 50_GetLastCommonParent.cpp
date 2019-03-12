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


void dispaly_vec(vector<TreeNode *> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i]->val << ' ';
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


bool GetNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
{
    if (root == NULL || node == NULL)
        return false;

    path.push_back(root);

    if (root == node)
    {
        return true;
    }

    if (root->left != NULL && GetNodePath(root->left, node, path))
        return true;
    if (root->right != NULL && GetNodePath(root->right, node, path))
        return true;

    path.pop_back();
    return false;
}


TreeNode* GetLastCommonNode(vector<TreeNode *> &path1, vector<TreeNode *> &path2)
{
    if (path1.size() <= 0 || path2.size() <= 0)
        return NULL;

    // last common node in two lists
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;

    return i > 0 ? path1[i - 1] : NULL;
}


TreeNode* GetLastCommonParent(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
    if (root == NULL || node1 == NULL || node2 == NULL)
        return NULL;

    // get path
    vector<TreeNode *> path1, path2;
    if (GetNodePath(root, node1, path1) && GetNodePath(root, node2, path2))
        // common node
        return GetLastCommonNode(path1, path2);
    return NULL;
}


int main()
{
    TreeNode *root = NULL, *p, *node1, *node2;
    TreeNode *res;

    // construct tree
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    p = root->left;
    p->left = new TreeNode(4);
    p->right = new TreeNode(5);

    p = root->left->left;
    p->left = node1 = new TreeNode(6);
    p->right = new TreeNode(7);

    p = root->left->right;
    p->left = node2 = new TreeNode(8);
    p->right = new TreeNode(9);

    dispaly_tree(root);
    cout << endl;

    res = GetLastCommonParent(root, node1, node2);
    cout << res->val << endl;

    return 0;
}
