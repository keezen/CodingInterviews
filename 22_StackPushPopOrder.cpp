# include <iostream>
# include <cstdlib>
# include <vector>
# include <cassert>
# include <stack>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> st;
    int push_size = pushV.size(), pop_size = popV.size();
    int push_ix = 0, pop_ix = 0;

    if (push_size <= 0 || pop_size <= 0)
        return false;

    assert(push_size == pop_size);

    while (pop_ix < pop_size)
    {
        int pop_val = popV[pop_ix];

        while ((st.empty() || st.top() != pop_val) && push_ix < push_size)
            st.push(pushV[push_ix++]);

        if (st.top() == pop_val)
        {
            st.pop();
            pop_ix++;
        }else if (push_ix == push_size)
            break;
    }

    if (pop_ix == pop_size)
        return true;

    return false; 
}


int main(int argc, char *argv[])
{
    int arr_push[] = {1, 2, 3, 4, 5};
    int arr_pop[] = {4, 3, 5, 1, 2};
    vector<int> vec_push(arr_push, arr_push + 5);
    vector<int> vec_pop(arr_pop, arr_pop + 5);

    dispaly_vec(vec_push);
    dispaly_vec(vec_pop);

    if (IsPopOrder(vec_push, vec_pop))
        cout << "Is pop order." << endl;
    else
        cout << "Is not pop order." << endl;

    return 0;
}
