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


int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() <= 0)
        throw "Illegal array.";

    int start = 0, end = rotateArray.size() - 1, mid;

    // [start, end] is span containing minimum
    while (start < end)
    {
        mid = (start + end) / 2;

        if (rotateArray[mid] < rotateArray[end])  // mid in second part
            end = mid;
        else if (rotateArray[mid] > rotateArray[end])  // mid in first part
            start = mid + 1;
        else  // mid and end are equal
            end--;
    }

    return rotateArray[end];
}


int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    // int arr[] = {1, 0, 1, 1, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec(arr, arr + 5);
    int min_num;

    dispaly_vec(vec);

    // min number
    min_num = minNumberInRotateArray(vec);
    cout << min_num << endl;

    return 0;
}
