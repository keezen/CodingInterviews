# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;

// definition of tree node
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL)
    {}
};

void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


void dispaly_tree(TreeLinkNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << ' ';
    dispaly_tree(root->left);
    dispaly_tree(root->right);
}


void connect_tree(TreeLinkNode* root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        root->left->next = root;
    if (root->right != NULL)
        root->right->next = root;

    connect_tree(root->left);
    connect_tree(root->right);
}


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if (pNode == NULL)
        return NULL;

    TreeLinkNode *p;

    if (pNode->right != NULL)  // right not empty
    {
        for (p = pNode->right; p->left != NULL; p = p->left)
            ;
        return p;
    }
    else  // right empty
    {
        for (p = pNode; p->next != NULL && p->next->right == p; p = p->next)
            ;
        return p->next;
    }
}


int main()
{
    TreeLinkNode *root = NULL, *p;
    TreeLinkNode *res;

    // reconstruct tree
    root = new TreeLinkNode(1);
    root->left = p = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);

    p->left = new TreeLinkNode(4);
    p->right = new TreeLinkNode(5);

    p = p->right;
    p->left = new TreeLinkNode(8);
    p->right = new TreeLinkNode(9);

    p = root->right;
    p->left = new TreeLinkNode(6);
    p->right = new TreeLinkNode(7);

    connect_tree(root);
    dispaly_tree(root);
    cout << endl;

    p = root->left;
    cout << p->val << endl;

    // result
    res = GetNext(p);
    if (res != NULL)
        cout << res->val << endl;
    else
        cout << "NULL" << endl;

    return 0;
}
