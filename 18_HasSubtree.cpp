# include <iostream>
# include <vector>
# include <cstdlib>
# include <string>
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


TreeNode* reConstructBinaryTree(vector<int> &pre, vector<int> &vin)
{
    TreeNode *root = NULL;
    int length = pre.size();

    if (pre.size() <= 0 || vin.size() <= 0)
        return NULL;

    // construct root node
    int root_val = pre[0];
    root = new TreeNode(root_val);

    // find root index in in-order array
    int root_idx = 0;
    for (root_idx = 0; root_idx < vin.size(); root_idx++)
        if (vin[root_idx] == root_val)
            break;

    // construct left children tree
    int len_left = root_idx;
    vector<int> pre_left(len_left), in_left(len_left);
    for (int i = 0; i < len_left; i++)
    {
        pre_left[i] = pre[i + 1];
        in_left[i] = vin[i];
    }
    root->left = reConstructBinaryTree(pre_left, in_left);

    // construct right children tree
    int len_right = length - root_idx - 1;
    vector<int> pre_right(len_right), in_right(len_right);
    for (int i = 0; i < len_right; i++)
    {
        pre_right[i] = pre[i + len_left + 1];
        in_right[i] = vin[i + len_left + 1];
    }
    root->right = reConstructBinaryTree(pre_right, in_right);

    return root;
}


bool IsSubtree_Simple(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot2 == NULL)
        return true;

    if (pRoot1 == NULL)
        return false;

    return (pRoot1->val == pRoot2->val) &&
        IsSubtree_Simple(pRoot1->left, pRoot2->left) &&
        IsSubtree_Simple(pRoot1->right, pRoot2->right);
}


bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    bool left = false, right = false;

    if (pRoot2 == NULL)
        return true;

    if (pRoot1 == NULL)
        return false;

    if (pRoot1->val == pRoot2->val)
    {
        if (pRoot2->left == NULL)
            left = true;
        else if (pRoot1->left != NULL && IsSubtree(pRoot1->left, pRoot2->left))
            left = true;

        if (!left)
            return false;

        if (pRoot2->right == NULL)
            right = true;
        else if (pRoot1->right != NULL && IsSubtree(pRoot1->right, pRoot2->right))
            right = true;

        if (!right)
            return false;

        return true;
    }

    return false;
}


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot2 == NULL || pRoot1 == NULL)
        return false;

    if (IsSubtree(pRoot1, pRoot2))
        return true;

    if (HasSubtree(pRoot1->left, pRoot2))
        return true;

    if (HasSubtree(pRoot1->right, pRoot2))
        return true;

    return false;
}


int main()
{
    TreeNode *root1 = NULL, *root2 = NULL, *p;
    int pre_arr1[7] = {8, 1, 9, 2, 4, 7, 7};  // pre-order array
    int in_arr1[7] = {9, 1, 4, 2, 7, 8, 7};  // in-order array
    vector<int> pre1(pre_arr1, pre_arr1 + 7);
    vector<int> vin1(in_arr1, in_arr1 + 7);
    int pre_arr2[7] = {1, 9, 2};  // pre-order array
    int in_arr2[7] = {9, 1, 2};  // in-order array
    vector<int> pre2(pre_arr2, pre_arr2 + 3);
    vector<int> vin2(in_arr2, in_arr2 + 3);

    // reconstruct tree
    // root1 = reConstructBinaryTree(pre1, vin1);
    root1 = new TreeNode(8);
    root1->left = p = new TreeNode(8);
    root1->right = new TreeNode(7);
    p->left = new TreeNode(9);
    p->right = new TreeNode(2);
    p = p->right;
    p->left = new TreeNode(4);
    p->right = new TreeNode(7);
    dispaly_tree(root1);
    cout << endl;

    // root2 = reConstructBinaryTree(pre2, vin2);
    root2 = new TreeNode(8);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(2);
    dispaly_tree(root2);
    cout << endl;

    if (HasSubtree(root1, root2))
        cout << "Tree 2 is sub-tree of tree 1." << endl;
    else
        cout << "Tree 2 i not sub-tree of tree 1." << endl;

    return 0;
}
