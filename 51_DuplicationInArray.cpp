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


bool duplicate_hash(int numbers[], int length, int* duplication)
{
    vector<bool> existed(length, false);

    for (int i = 0; i < length; i++)
        if (existed[numbers[i]])
        {
            *duplication = numbers[i];
            return true;
        }
        else
            existed[numbers[i]] = true;

    return false;
}


bool duplicate_place(int numbers[], int length, int* duplication)
{
    if (numbers == NULL && length < 0)
        return false;

    int i = 0, m;
    while (i < length)
    {
        m = numbers[i];

        if (m < 0 || m > length - 1)
            return false;

        if (i == m)  // placed well, next
            i++;
        else  // not placed well, swap
        {
            if (numbers[m] == m)  // duplicate
            {
                *duplication = m;
                return true;
            }
            else
                swap(numbers[i], numbers[m]);
        }
    }

    return false;
}


bool duplicate(int numbers[], int length, int* duplication)
{
    if (numbers == NULL && length < 0)
        return false;

    int i, m;

    // in-place hash
    for (i = 0; i < length; i++)
    {
        m = numbers[i] % length;

        if (numbers[m] >= length)
        {
            *duplication = m;
            return true;
        }

        numbers[m] += length;
    }

    return false;
}


int main(int argc, char *argv[])
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int length = sizeof(arr) / sizeof(int);
    int res = 0;

    for (int i = 0; i < length; i++)
        cout << arr[i] << ' ';
    cout << endl;

    if (duplicate(arr, length, &res))
        cout << res << endl;

    return 0;
}
