# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <set>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
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


vector<int> GetLeastNumbers_Solution_Partition(vector<int> input, int k)
{
    vector<int> result;

    if (input.size() <= 0)
        return result;

    if (k <= 0)
        return result;

    if (input.size() < k)
        return result;

    // find partition k
    int start = 0, end = input.size() - 1;
    int index = partion(input, start, end), target = k - 1;

    while (index != target)
    {
        if (index < target)
        {
            start = index + 1;
            index = partion(input, start, end);
        }
        else if (index > target)
        {
            end = index - 1;
            index = partion(input, start, end);
        }
    }

    // sort first k elements
    for (int i = 0; i <= target; i++)
        result.push_back(input[i]);
    sort(result.begin(), result.end());

    return result;
}


vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> result;

    if (input.size() <= 0)
        return result;

    if (k <= 0)
        return result;

    if (input.size() < k)
        return result;

    multiset<int, greater<int> > least_set;
    multiset<int, greater<int> >::iterator set_iter;

    for (int i = 0; i < input.size(); i++)
    {
        if (least_set.size() < k)
            least_set.insert(input[i]);
        else
        {
            set_iter = least_set.begin();  // max value
            if (*set_iter > input[i])
            {
                least_set.erase(set_iter);
                least_set.insert(input[i]);
            }

        }
    }

    // sort result
    for (set_iter = least_set.begin(); set_iter != least_set.end(); set_iter++)
        result.push_back(*set_iter);
    for (int i = 0; 2 * i < k; i++)
        swap(result[i], result[k - 1 - i]);

    return result;
}


int main()
{
    int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> vec(arr, arr + 8);
    vector<int> result;

    dispaly_vec(vec);

    result = GetLeastNumbers_Solution(vec, 4);
    dispaly_vec(result);

    return 0;
}
