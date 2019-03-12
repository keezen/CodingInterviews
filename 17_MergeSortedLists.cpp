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


ListNode* CreateList(int arr[], int len)
{
    ListNode *head = NULL, *tail = NULL, *node = NULL;

    for (int i = 0; i < len; i++)
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

    return head;     
}


void display_list(ListNode* head)
{
    if (head == NULL)
        return;
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
}


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode *p1 = pHead1, *p2 = pHead2, *head = NULL, *tail = NULL;
    ListNode **pp;
    ListNode *p;

    if (p1 == NULL)
        return p2;

    if (p2 == NULL)
        return p1;

    // get smaller node
    while (p1 != NULL && p2 != NULL)
    {
        pp = (p1->val < p2->val) ? &p1 : &p2;

        if (head == NULL)
        {
            head = tail = *pp;
            *pp = (*pp)->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = *pp;
            tail = *pp;
            (*pp) = (*pp)->next;
            tail->next = NULL;
        }
    }

    // append non-empty list to tail
    p = (p1 == NULL) ? p2 : p1;
    tail->next = p;

    return head;
}


int main(int argc, char *argv[])
{
    int arr1[5] = {1, 3, 5};
    int arr2[2] = {2, 4};
    ListNode *head1 = NULL, *head2 = NULL, *headm = NULL;

    head1 = CreateList(arr1, 3);
    head2 = CreateList(arr2, 2);

    display_list(head1);
    display_list(head2);

    headm = Merge(head1, head2);
    if (headm != NULL)
        display_list(headm);
    else
        cout << "Error." << endl;

    return 0;
}
