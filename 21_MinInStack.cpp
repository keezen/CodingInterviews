# include <iostream>
# include <stack>
# include <cstdlib>
# include <cassert>
using namespace std;

// void dispaly_vec(vector<int> &vec)
// {
//     for (int i = 0; i < vec.size(); i++)
//         cout << vec[i] << ' ';
//     cout << endl;
// }


class Solution { 
public:
    void push(int value)
    {
        int min;

        _data.push(value);

        if (_aux.empty())  // push min value
            min = value;
        else
        {
            min = _aux.top();
            min = value < min ? value : min;
        }
        _aux.push(min);
    }

    void pop()
    {
        assert(!_data.empty() && !_aux.empty());

        _data.pop();
        _aux.pop();
    }

    int top()
    {
        assert(!_data.empty());

        return _data.top();
    }

    int min()
    {
        assert(!_aux.empty());

        return _aux.top();
    }

private:
    stack<int> _data;
    stack<int> _aux;
};


int main()
{
    int arr[] = {8, 3, 1, 5, 6};
    Solution st;

    for (int i = 0; i < 5; i++)
        st.push(arr[i]);

    for (int i = 0; i < 5; i++)
    {
        int x = st.top();
        st.pop();
        cout << x << ' ';
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
        st.push(arr[i]);

    for (int i = 0; i < 5; i++)
    {
        int x = st.min();
        st.pop();
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
