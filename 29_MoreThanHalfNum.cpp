# include <iostream>
# include <cstdlib>
# include <vector>
# include <map>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


int MoreThanHalfNum_Solution_Map(vector<int> numbers)
{
    map<int, int> mymap;

    if (numbers.size() <= 0)
        return 0;

    // count frequency
    for (int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i];
        if (mymap.find(num) != mymap.end())
            mymap[num] += 1;
        else
            mymap[num] = 1;
    }

    // number more than half
    int target = 0, freq = 0;
    for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        if (it->second > freq)
        {
            target = it->first;
            freq = it->second;
        }

    // max frequency less than half
    if (2 * freq <= numbers.size())
        target = 0;

    return target;
}


int partion(vector<int> &vec, int start, int end)
{
    if (start == end)
        return start;

    if (start > end)
        throw "Illegal span.";

    int i = start, j = end - 1;
    int pivot_val = vec[end];  // last value as pivot
    while (i <= j)
    {
        if (vec[i] < pivot_val)  // move smaller to left
            i++;
        else  // move larger to right
        {
            swap(vec[i], vec[j]);
            j--;
        }
    }

    int pivot = j + 1;
    swap(vec[pivot], vec[end]);

    return pivot;
}


int MoreThanHalfNum_Solution_Partition(vector<int> numbers)
{
    if (numbers.size() <= 0)
        return 0;

    int start = 0, end = numbers.size() - 1;
    int mid = (end + 1) / 2;
    int index;

    // find the middle item
    index = partion(numbers, start, end);
    while (index != mid)
    {
        if (index > mid)
        {
            end = index - 1;
            index = partion(numbers, start, end);
        }
        else if (index < mid)
        {
            start = index + 1;
            index = partion(numbers, start, end);
        }
    }

    // check whether more than half
    int target = numbers[index], times = 0;

    for (int i = 0; i < numbers.size(); i++)
        if (numbers[i] == target)
            times += 1;

    if (times <= mid)
        target = 0;

    return target;
}


int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if (numbers.size() <= 0)
        return 0;

    // accord result and frequency
    int result = 0, freq = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (freq == 0)
        {
            result = numbers[i];
            freq = 1;
        }
        else if (numbers[i] == result)
            freq++;
        else
            freq--;
    }


    // check whether more than half
    int times = 0;

    for (int i = 0; i < numbers.size(); i++)
        if (numbers[i] == result)
            times++;

    if (times * 2 <= numbers.size())
        result = 0;

    return result;
}


int main()
{
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    vector<int> vec(arr, arr + 9);
    int result;

    dispaly_vec(vec);

    result = MoreThanHalfNum_Solution(vec);
    cout << result << endl;

    return 0;
}
