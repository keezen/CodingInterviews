# include <iostream>
# include <cstdlib>
# include <vector>
# include <limits>
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


ListNode* deleteDuplication_iter(ListNode* pHead)
{
    // delete duplicate nodes in sorted list

    if (pHead == NULL)
        return NULL;

    ListNode *empty = new ListNode(numeric_limits<int>::max());
    ListNode *prev, *cur;
    int dup;

    empty->next = pHead;  // add empty node before head
    prev = empty; cur = pHead;
    while (cur != NULL && cur->next != NULL)
    {
        // duplicate
        if (cur->val == cur->next->val)
        {
            dup = cur->val;
            while (cur != NULL && cur->val == dup)
            {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    pHead = empty->next;
    delete empty;

    return pHead;
}


ListNode* deleteDuplication(ListNode* pHead)
{
    // delete duplicate nodes in sorted list

    if (pHead == NULL)
        return NULL;

    if (pHead != NULL && pHead->next == NULL)
        return pHead;

    ListNode *cur, *next = NULL;
    if (pHead->val == pHead->next->val)  // duplicate
    {
        int val = pHead->val;
        cur = pHead;
        while (cur != NULL && cur->val == val)
        {
            next = cur->next;
            delete cur;
            cur = next;
        }

        return deleteDuplication(cur);
    }
    else  // not duplicate
    {
        pHead->next = deleteDuplication(pHead->next);
        return pHead;
    }
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    ListNode *node = NULL, *head = NULL, *tail = NULL, *res = NULL, *p = NULL;

    // list
    for (int i = 0; i < vec.size(); i++)
    {
        node = new ListNode(vec[i]);

        if (head == NULL)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
            node = NULL;
        }
    }
    display_list(head);

    // result
    res = deleteDuplication(head);
    if (res != NULL)
        display_list(res);
    else
        cout << "Null." << endl;

    return 0;
}
