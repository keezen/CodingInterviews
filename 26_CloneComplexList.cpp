# include <iostream>
# include <cstdlib>
# include <unordered_map>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


void dispaly_random_list(RandomListNode* head)
{
    if (head == NULL)
        return;
    for(RandomListNode* p = head; p != NULL; p = p->next)
        cout << p->label << ' ';
    cout << endl;

    for(RandomListNode* p = head; p != NULL; p = p->next)
        if (p->random != NULL)
            cout << "(" << p->label << ", " << p->random->label << ")" << endl;
}


RandomListNode* Clone_Map(RandomListNode* pHead)
{
    RandomListNode *head = NULL, *tail = NULL, *p = NULL, *node;
    unordered_map<RandomListNode*, RandomListNode*> node_map;

    if (pHead == NULL)
        return NULL;

    // copy list and random link, get node map
    for (p = pHead; p != NULL; p = p->next)
    {
        node = new RandomListNode(p->label);
        node->random = p->random;
        node_map[p] = node;
        if (head == NULL)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // map random link
    for (p = head; p != NULL; p = p->next)
        if (p->random != NULL)
            p->random = node_map[p->random];

    return head;
}


RandomListNode* Clone(RandomListNode* pHead)
{
    RandomListNode *head = NULL, *p = pHead, *clone = NULL;

    if (pHead == NULL)
        return NULL;

    // copy nodes, insert new node after original node
    while (p != NULL)
    {
        clone = new RandomListNode(p->label);
        clone->next = p->next;
        p->next = clone;
        p = clone->next;
    }

    // connect random link for new node
    p = pHead;
    while (p != NULL)
    {
        clone = p->next;
        if (p->random != NULL)
            clone->random = p->random->next;
        p = clone->next;
    }

    // split new list and original list
    RandomListNode *tmp;
    head = pHead->next;
    p = pHead;
    while (p->next != NULL)
    {
        tmp = p->next;
        p->next = tmp->next;
        p = tmp;
    }

    return head;
}


int main(int argc, char *argv[])
{
    int arr[5] = {1, 5, 3, 4, 2};
    RandomListNode *node = NULL, *head = NULL, *tail = NULL, *target = NULL;

    for (int i = 0; i < 5; i++)
    {
        node = new RandomListNode(arr[i]);

        if (head == NULL)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
            node = NULL;
        }
    }
    head->random = tail;
    dispaly_random_list(head);
    cout << endl;

    target = Clone(head);
    dispaly_random_list(target);

    return 0;
}
