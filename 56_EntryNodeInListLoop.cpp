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


ListNode* EntryNodeOfLoop_Set(ListNode* pHead)
{
    unordered_set<ListNode *> node_set;

    for (ListNode *p = pHead; p != NULL; p = p->next)
        if (node_set.find(p) == node_set.end())
            node_set.insert(p);
        else
            return p;

    return NULL;
}


int GetNodesInLoop(ListNode *head)
{
    if (head == NULL)
        return 0;

    ListNode *slow = head, *fast = head->next;

    while (slow != NULL && fast != NULL && slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }

    // no loop
    if (slow == NULL || fast == NULL)
        return 0;

    // there is loop
    int num_loop = 1;
    for ( ;slow->next != fast; slow = slow->next)
        num_loop++;

    return num_loop;
}


ListNode* EntryNodeOfLoop_Nloop(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;

    int num_loop = GetNodesInLoop(pHead);

    // no loop
    if (num_loop <= 0)
        return NULL;

    // having loop
    ListNode *ahead = pHead, *behind = pHead;

    // walk num_loop steps ahead
    for (int i = 0; i < num_loop && ahead != NULL; i++)
        ahead = ahead->next;

    // walk simultaneously
    while (ahead != NULL && behind != NULL && ahead != behind)
    {
        ahead = ahead->next;
        behind = behind->next;
    }

    return ahead == NULL ? NULL : ahead;
}


ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if (pHead == NULL)
        return 0;

    // meet in the circle
    ListNode *slow = pHead, *fast = pHead;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        if (slow == fast)
            break;
    }

    // no loop
    if (slow == NULL || fast == NULL)
        return 0;

    // having loop, walk together
    slow = pHead;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    ListNode *node = NULL, *head = NULL, *tail = NULL, *res = NULL, *p = NULL;

    // list 1
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

        if (vec[i] == 3)
            p = tail;
    }
    display_list(head);

    tail->next = p;  // circle

    res = EntryNodeOfLoop(head);
    if (res != NULL)
        cout << res->val << endl;
    else
        cout << "Null." << endl;

    return 0;
}
