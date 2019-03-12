# include <iostream>
# include <stack>
# include <cstdlib>
using namespace std;

// definition of queue
class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int node = -1;

        // stack 2 empty
        if (stack2.empty())
            // push nodes in stack 1 to stack 2
            while (!stack1.empty())
            {
                node = stack1.top();
                stack2.push(node);
                stack1.pop();
            }

        if (!stack2.empty())
        {
            node = stack2.top();
            stack2.pop();
        }

        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main()
{
    Solution queue;
    int arr[] = {1, 2, 3, 4, 5};
    int node = 0;

    cout << "Array pushed:\n";
    for (int i = 0; i < 5; i++)
    {
        queue.push(arr[i]);
        cout << arr[i] << ' ';
    }
    cout << endl;

    cout << "Array poped:\n";
    for (int i = 0; i < 5; i++)
    {
        node = queue.pop();
        cout << node << ' ';
    }
    cout << endl;

    return 0;
}
