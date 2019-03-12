# include <iostream>
# include <cstdlib>
# include <vector>
# include <limits>
# include <deque>
using namespace std;


void display_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


void display_vec(vector<string> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


vector<int> maxInWindows_Brute(const vector<int>& num, unsigned int size)
{
    if (num.size() <= 0 || size <= 0 || num.size() < size)
        return vector<int>();

    int i, length = num.size();
    vector<int> res(length - size + 1);
    deque<int> q;

    for (i = 0; i < size - 1; i++)
        q.push_back(num[i]);

    for (i = 0; i < res.size(); i++)
    {
        q.push_back(num[i + size - 1]);
        int max = numeric_limits<int>::min();
        for (deque<int>::iterator it = q.begin(); it != q.end(); it++)
            if (*it > max)
                max = *it;
        q.pop_front();
        res[i] = max;
    }

    return res;
}


vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    if (num.size() <= 0 || size <= 0 || num.size() < size)
        return vector<int>();

    int i, cur, length = num.size();
    vector<int> res(length - size + 1);
    deque<int> q;

    for (i = 0; i < num.size(); i++)
    {
        // pop smaller number from back
        while (!q.empty() && num[q.back()] < num[i])
            q.pop_back();
        // pop outside number from front
        while (!q.empty() && i - q.front() >= size)
            q.pop_front();
        
        q.push_back(i);

        // front number is max
        if (i >= size - 1)
            res[i - size + 1] = num[q.front()];
    }

    return res;
}


int main(int argc, char *argv[])
{
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int length = sizeof(arr) / sizeof(int);
    vector<int> data(arr, arr + length);
    int size = 3;
    vector<int> res;

    display_vec(data);

    res = maxInWindows(data, size);
    display_vec(res);

    return 0;
}
