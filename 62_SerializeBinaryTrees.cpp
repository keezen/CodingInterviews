# include <iostream>
# include <vector>
# include <cstdlib>
# include <string>
# include <cstring>
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


void Serialize(TreeNode *root, string &res)
{
    if (root == NULL)
    {
        res += "$ ";
        return;
    }

    res += (to_string(root->val) + " ");
    Serialize(root->left, res);
    Serialize(root->right, res);
}


char* Serialize(TreeNode *root)
{
    string res_str;

    Serialize(root, res_str);
    res_str.pop_back();

    // convert to char
    char *res = new char[res_str.size() + 1];
    strcpy(res, res_str.c_str());

    return res;
}


TreeNode* Deserialize(vector<TreeNode *> &series, int &pos)
{
    if (series.size() <= 0 || pos < 0 || pos >= series.size())
        return NULL;

    if (series[pos] == NULL)
    {
        pos += 1;
        return NULL;
    }

    TreeNode *root = series[pos]; pos += 1;
    root->left = Deserialize(series, pos);
    root->right = Deserialize(series, pos);

    return root;
}


TreeNode* Deserialize(char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    // split string to node
    vector<TreeNode *> series;
    TreeNode *node;
    char *p = str, *q = str;
    int val;
    while (*p != '\0')
    {
        // find end
        for (q = p; *q != '\0' && *q != ' '; q++) ;

        // string to node
        string t(p, q - p);
        if (t[0] != '$')
        {
            val = atoi(t.c_str());
            node = new TreeNode(val);
        }
        else
            node = NULL;
        series.push_back(node);

        // find start
        for (p = q; *p != '\0' && *p == ' '; p++) ;
    }

    // de-serialize
    int pos = 0;
    return Deserialize(series, pos);
}


int main()
{
    TreeNode *root = NULL, *p, *root_de;
    char *res;

    // construct tree
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    p = root->left;
    p->left = new TreeNode(4);

    p = root->right;
    p->left = new TreeNode(5);
    p->right = new TreeNode(6);

    dispaly_tree(root);
    cout << endl << endl;

    // result
    res = Serialize(root);
    cout << res << endl;

    root_de = Deserialize(res);
    dispaly_tree(root_de);
    cout << endl;

    return 0;
}
