# include <iostream>
# include <cstdlib>
# include <vector>
# include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)  // struct的构造函数
        : val(x), next(NULL)
    {}
};

void display_list(ListNode* head)
{
    if (head == NULL)
        return;
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
}


ListNode* FindFirstCommonNode_Set(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL || pHead2 == NULL)
        return NULL;

    unordered_set<ListNode *> first;
    ListNode *p;

    // set of first list nodes
    for (p = pHead1; p != NULL; p = p->next)
        first.insert(p);

    // check every node in second list
    for (p = pHead2; p != NULL; p = p->next)
        if (first.find(p) != first.end())
            return p;

    return NULL;
}


ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL || pHead2 == NULL)
        return NULL;

    int len_long = 0, len_short = 0, i = 0;
    ListNode *p, *q, *head_long = pHead1, *head_short = pHead2;

    // count length
    for (p = pHead1; p != NULL; p = p->next)
        len_long += 1;
    for (p = pHead2; p != NULL; p = p->next)
        len_short += 1;
    if (len_short > len_long)
    {
        swap(head_long, head_short);
        swap(len_long, len_short);
    }

    // walk long list
    for (i = 0, p = head_long; i < len_long - len_short; i++)
        p = p->next;

    // walk simultaneously until first common
    for (q = head_short; p != NULL && q != NULL; p = p->next, q = q->next)
        if (p == q)
            return p;

    return NULL;
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 6, 7};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    ListNode *node = NULL, *head1 = NULL, *tail = NULL, *res = NULL, *head2;

    // list 1
    for (int i = 0; i < vec.size(); i++)
    {
        node = new ListNode(vec[i]);

        if (head1 == NULL)
            head1 = tail = node;
        else
        {
            tail->next = node;
            tail = node;
            node = NULL;
        }
    }

    display_list(head1);

    // list 2
    head2 = node = new ListNode(4);
    node = new ListNode(5);
    head2->next = node;
    node->next = head1->next->next->next;

    display_list(head2);

    res = FindFirstCommonNode(head1, head2);
    if (res != NULL)
        cout << res->val << endl;
    else
        cout << "Error." << endl;

    return 0;
}
