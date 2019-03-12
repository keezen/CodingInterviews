# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
# include <map>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


void dispaly_vec(vector<string> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


int InversePairs_Brute(vector<int> data)
{
    if (data.size() <= 1)
        return 0;

    int count = 0;
    for (int i = 0; i < data.size(); i++)
        for (int j = i + 1; j < data.size(); j++)
            if (data[i] > data[j])
                count++;

    return count % 1000000007;
}


int MergeSort(vector<int> &data, vector<int> &copy, int start, int end)
{
    // merge sort and return number of inverse pairs

    if (start >= end)
        return 0;

    int mid = (start + end) / 2;

    int count_left = MergeSort(data, copy, start, mid);
    int count_right = MergeSort(data, copy, mid + 1, end);
    int count_between = 0;
    int i = mid, j = end, k = end;

    while (i >= start && j >= mid + 1)
    {
        if (data[i] > data[j])
        {
            copy[k--] = data[i--];
            count_between += (j - mid);
            count_between = count_between % 1000000007;
        }
        else
            copy[k--] = data[j--];
    }

    while (i >= start)
        copy[k--] = data[i--];
    while (j >= mid + 1)
        copy[k--] = data[j--];

    for (k = start; k <= end; k++)
        data[k] = copy[k];

    return (count_left + count_right + count_between) % 1000000007;
}


int InversePairs(vector<int> &data)
{
    if (data.size() <= 1)
        return 0;

    vector<int> copy(data);
    return MergeSort(data, copy, 0, data.size() - 1);
}


int main(int argc, char *argv[])
{
    int arr[] = {7, 5, 6, 4};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int result;

    dispaly_vec(data);

    result = InversePairs(data);
    dispaly_vec(data);
    cout << result << endl;

    return 0;
}
