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


vector<int> PrintFromTopToBottom(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode *> que;
    TreeNode *p;

    if (root == NULL)
        return result;

    que.push(root);
    while(!que.empty())
    {
        p = que.front();  // current node
        que.pop();
        result.push_back(p->val);
        if (p->left != NULL)  // left
            que.push(p->left);
        if (p->right != NULL)  // right
            que.push(p->right);
    }

    return result;
}


int main()
{
    TreeNode *root = NULL, *p;
    vector<int> result;

    // construct tree
    root = new TreeNode(8);
    root->left = p = new TreeNode(6);
    root->right = new TreeNode(10);

    p->left = new TreeNode(5);
    p->right = new TreeNode(7);

    p = root->right;
    p->left = new TreeNode(9);
    p->right = new TreeNode(11);

    dispaly_tree(root);
    cout << endl;

    result = PrintFromTopToBottom(root);

    cout << "Hierarchical Order:" << endl;
    dispaly_vec(result);


    return 0;
}
