# include <iostream>
# include <cstdlib>
# include <vector>
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


vector<int> multiply(const vector<int>& A)
{
    if (A.size() <= 0)
        return vector<int>();

    vector<int> left(A), right(A), res(A);
    int end = A.size() - 1, i;

    for (i = 1, left[0] = 1; i <= end; i++)
        left[i] = left[i - 1] * A[i - 1];

    for (i = end - 1, right[end] = 1; i >= 0; i--)
        right[i] = right[i + 1] * A[i + 1];

    for (i = 0; i <= end; i++)
        res[i] = left[i] * right[i];

    return res;
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> res;

    display_vec(data);

    res = multiply(data);
    display_vec(res);

    return 0;
}
