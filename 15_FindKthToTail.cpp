# include <iostream>
# include <cstdlib>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)  // struct的构造函数
        : val(x), next(NULL)
    {}
};

void dispaly_list(ListNode* head)
{
    if (head == NULL)
        return;
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
}

ListNode* FindKthToTail_TwoPass(ListNode* pListHead, unsigned int k)
{
    int len, ix;
    ListNode *p;

    if (k <= 0 || pListHead == NULL)
        return NULL;

    for (p = pListHead, len = 0; p != NULL; p = p->next, len++) ;
    cout << len << endl;

    if (len < k)
        return NULL;
    
    for(p = pListHead, ix = 1; p != NULL && ix < len - k + 1; p = p->next, ix++)
        ;

    return p;
}


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    int len, ix;
    ListNode *p1, *p2;

    if (k <= 0 || pListHead == NULL)
        return NULL;

    // first pointer to k-th node
    for (p1 = pListHead, ix = 1; p1->next != NULL && ix < k; p1 = p1->next, ix++) ;

    if (ix < k)  // length shored than k
        return NULL;

    // move 2 pointers simultaneously    
    for(p2 = pListHead; p1->next != NULL; p1 = p1->next, p2 = p2->next) ;

    return p2;
}


int main(int argc, char *argv[])
{
    int arr[5] = {1, 5, 3, 4, 2};
    ListNode *node = NULL, *head = NULL, *tail = NULL;
    int pos = atoi(argv[1]);

    for (int i = 0; i < 5; i++)
    {
        node = new ListNode(arr[i]);

        if (head == NULL)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
            node = NULL;
        }
    }
    dispaly_list(head);

    node = FindKthToTail(head, pos);
    if (node != NULL)
        cout << pos << "-th tail node: " << node->val << endl;
    else
        cout << "Error." << endl;

    return 0;
}
