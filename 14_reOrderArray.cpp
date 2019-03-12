# include <iostream>
# include <cstdlib>
# include <vector>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


void reOrderArrayUnstable(vector<int> &array)
{
    int i, j;

    if (array.size() <= 1)
        return;

    i = 0, j = array.size() - 1;
    while (i <= j)
    {
        if (array[i] & 1)  // odd number
            i++;
        else  // even number
        {
            swap(array[i], array[j]);
            j--;
        }
    }
}


void reOrderArray(vector<int> &array)
{
    int i, j;

    if (array.size() <= 1)
        return;

    vector<int> vec(array);
    int arr_len = array.size();

    i = 0, j = arr_len - 1;
    for (int k = 0; k < arr_len; k++)
        if (array[k] & 1)  // odd
            vec[i++] = array[k];
        else
            vec[j--] = array[k];

    for (int k = 0; k < arr_len; k++)
        if (k < i)
            array[k] = vec[k];
        else
            array[k] = vec[arr_len + i - 1 - k];
}


int main(int argc, char *argv[])
{
    int arr[] = {4, 2, 1, 5, 3};
    vector<int> vec(arr, arr + 5);

    dispaly_vec(vec);

    reOrderArray(vec);
    dispaly_vec(vec);

    return 0;
}
