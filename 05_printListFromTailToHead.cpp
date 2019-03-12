# include <iostream>
# include <stack>
# include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)  // struct的构造函数
        : val(x), next(NULL)
    {}
};

void dispaly(ListNode* head)
{
    if (head == NULL)
        return;
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
}

vector<int> printListFromTailToHead(ListNode* head)
{
    stack<ListNode *> st;
    ListNode *p = NULL;

    // push into stack
    for (p = head; p != NULL; p = p->next)
        st.push(p);

    // pop from stack
    vector<int> vec(st.size());
    for (int i = 0; !st.empty(); i++)
    {
        p = st.top();
        vec[i] = p->val;
        st.pop();
    } 

    return vec;
}


int main()
{
    ListNode *head = NULL, *tail = NULL, *x = NULL;
    int array[] = {1, 2, 3, 4, 5};
    vector<int> vec;

    // initialize list
    for (int i = 0; i < 5; i++)
    {
        x = new ListNode(array[i]);
        if (tail == NULL)
            head = tail = x;
        else
        {
            tail->next = x;
            tail = x;
        }
    }
    dispaly(head);

    // print reversely
    vec = printListFromTailToHead(head);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;

    return 0;
}
