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

void DeleteNode(ListNode **phead, ListNode *target)
{
    ListNode *next_node = NULL, *head = *phead;

    if (head == NULL || target == NULL)
        return;

    // target is the only node of list
    if (head->next == NULL && head == target)
    {
        delete target;
        *phead = NULL;
        target = NULL;
        return;
    }

    // target is end of list
    if (target->next == NULL)
    {
        ListNode *p;
        // search from head
        for (p = head; p->next != target; p = p->next) ;
        delete target;  // remove target node
        p->next = NULL;
        target = NULL;
        return;
    }

    // target is not end of list
    next_node = target->next;
    target->val = next_node->val;  // copy content from next node to target
    target->next = next_node->next;  // remove next node
    delete next_node;
    next_node = NULL;
}


int main(int argc, char *argv[])
{
    int arr[5] = {1, 5, 3, 4, 2};
    ListNode *node = NULL, *head = NULL, *tail = NULL, *target = NULL;
    int pos = atoi(argv[1]);

    for (int i = 0; i < 5; i++)
    {
        node = new ListNode(arr[i]);

        if (i == pos)
            target = node;

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

    DeleteNode(&head, target);
    dispaly_list(head);

    return 0;
}
