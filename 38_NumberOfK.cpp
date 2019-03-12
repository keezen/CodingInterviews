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


int GetNumberOfK(vector<int> data ,int k)
{
    if (data.size() <= 0)
        return 0;

    int left, right, mid;
    int start = -1, end = -1;

    // find start index of range of k
    left = 0, right = data.size() - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (data[mid] == k && (mid == 0 || data[mid - 1] < data[mid]))
        {
            start = mid;
            break;
        }
        else if (data[mid] >= k)
            right = mid - 1;
        else
            left = mid + 1;
    }

    // find end index of range of k
    left = 0, right = data.size() - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (data[mid] == k && (mid == data.size() - 1 || data[mid + 1] > data[mid]))
        {
            end = mid;
            break;
        }
        else if (data[mid] <= k)
            left = mid + 1;
        else
            right = mid - 1;
            
    }

    // number of k
    if (start >= 0 && end >= 0 && start <= end)
        return (end - start + 1);
    else
        return 0;
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int k = 3, result;

    dispaly_vec(data);
    cout << k << endl << endl;

    result = GetNumberOfK(data, k);
    cout << result << endl;

    return 0;
}
