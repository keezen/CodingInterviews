# include <iostream>
# include <vector>
# include <cstdlib>
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

void _quick_sort(vector<int> &vec, int start, int end)
{
    if (start >= end)
        return;

    int pivot = partion(vec, start, end);  // partition

    _quick_sort(vec, start, pivot - 1);  // sort left part
    _quick_sort(vec, pivot + 1, end);  // sort right part
}

void quick_sort(vector<int> &vec) 
{
    _quick_sort(vec, 0, vec.size() - 1);
}


int main()
{
    int arr[] = {2, 1, 5, 3, 4};
    vector<int> vec(arr, arr + 5);

    cout << "before sort:\n";
    dispaly_vec(vec);
    cout << endl;

    quick_sort(vec);
    cout << "after sort:\n";
    dispaly_vec(vec);
    cout << endl;

    return 0;
}
