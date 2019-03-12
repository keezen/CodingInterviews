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

void dispaly_tree(TreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << ' ';
    dispaly_tree(root->left);
    dispaly_tree(root->right);
}

void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
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


int main()
{
    TreeNode *root = NULL;
    int pre_arr[8] = {1, 2, 4, 7, 3, 5, 6, 8};  // pre-order array
    int in_arr[8] = {4, 7, 2, 1, 5, 3, 8, 6};  // in-order array
    vector<int> pre(pre_arr, pre_arr + 8);
    vector<int> vin(in_arr, in_arr + 8);
    vector<int> vec;

    dispaly_vec(pre);
    dispaly_vec(vin);

    // reconstruct tree
    root = reConstructBinaryTree(pre, vin);
    dispaly_tree(root);
    cout << endl;

    return 0;
}
