# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


int FindGreatestSumOfSubArray(vector<int> array)
{
    if (array.size() <= 0)
        return 0;

    int greatest, cur_sum;

    cur_sum = array[0], greatest = array[0];
    for (int i = 1; i < array.size(); i++)
    {
        if (cur_sum > 0)
            cur_sum += array[i];
        else
            cur_sum = array[i];

        if (cur_sum > greatest)
            greatest = cur_sum;
    }

    return greatest;
}


int main()
{
    int arr[] = {6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> vec(arr, arr + 8);
    int result;

    dispaly_vec(vec);

    result = FindGreatestSumOfSubArray(vec);
    cout << result << endl;

    return 0;
}
