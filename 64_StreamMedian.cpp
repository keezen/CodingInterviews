# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <functional>
using namespace std;


void display_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


class Solution_SortedArray
{
public:
    void Insert(int num)
    {
        int i, end = data.size();
        data.push_back(num);
        for (i = end - 1; i >= 0; i--)
            if (data[i] > data[i + 1])
                swap(data[i], data[i + 1]);
            else
                break;
    }

    double GetMedian()
    {
        int num = data.size();
        double median;
        if (num % 2 == 1)
            median = data[(num - 1) / 2];
        else
            median = (data[num / 2 - 1] + data[num / 2]) / 2.0;

        return median;
    }

    vector<int> GetData()
    {
        return data;
    }

private:
    vector<int> data;
};


class Solution
{
public:
    void Insert(int num)
    {
        if ((min.size() + max.size()) & 1)  // odd number
        {
            // number greater than min, re-balance
            if (min.size() > 0 && min.front() < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min.front();
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }

            // add to max heap
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
        else  // event number
        {
            // number greater than min, re-balance
            if (max.size() > 0 && max.front() > num)
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max.front();
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }

            // add to min heap
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
    }

    double GetMedian()
    {
        int size = max.size() + min.size();
        if (size <= 0)
            return -1;

        if (size & 1)  // odd number
            return min.front();
        else  // even number
            return (max.front() + min.front()) / 2.0;
    }   

private:
    vector<int> max;
    vector<int> min;
};


int main(int argc, char *argv[])
{
    int arr[] = {5,2,3,4,1,6,7,0,8};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(int));
    Solution sol;
    double res;

    // cout << str << endl;
    for (int i = 0; i < data.size(); i++)
    {
        sol.Insert(data[i]);
        vector<int> tmp(data.begin(), data.begin() + i + 1);
        display_vec(tmp);

        res = sol.GetMedian();
        cout << res << endl;
    }

    return 0;
}
