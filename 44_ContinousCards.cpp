# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
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


bool IsContinuous_Sort(vector<int> numbers)
{
    if (numbers.size() <= 0)
        return false;

    // sort
    sort(numbers.begin(), numbers.end());

    // find min and max value which is not 0
    int max_val = numbers[numbers.size() - 1], i, min_val;
    for(i = 0, min_val = 0; i < numbers.size(); i++)
        if (numbers[i] != 0)
        {
            min_val = numbers[i];
            break;    
        }

    // find repeat elements
    for (; i < numbers.size() - 1 && numbers[i] != numbers[i + 1]; i++) ;
    bool repeat = (i < numbers.size() - 1);

    if (min_val < 0)
        return false;

    return ((max_val - min_val + 1) <= numbers.size()) && (!repeat);
}


bool IsContinuous(vector<int> numbers)
{
    if (numbers.size() <= 0)
        return false;

    vector<int> count(14, 0);
    int max_val = -1, min_val = 14;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            continue;

        if (numbers[i] < 0 || numbers[i] > 13)
            return false;

        if (++count[numbers[i]] > 1)
            return false;

        max_val = max(max_val, numbers[i]);
        min_val = min(min_val, numbers[i]);
    }

    return ((max_val - min_val + 1) <= numbers.size());
}


int main(int argc, char *argv[])
{
    // int arr[] = {1, 3, 0, 0, 5};
    int arr[] = {0, 3, 2, 6, 4};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(arr[0]));
    bool res;

    display_vec(data);

    res = IsContinuous(data);
    cout << res << endl;

    return 0;
}
