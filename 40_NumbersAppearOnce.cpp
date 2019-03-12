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


void FindNumsAppearOnce(vector<int> data, int &num1, int &num2)
{
    if (data.size() <= 0)
    {
        num1 = num2 = -1;
        return;
    }

    // first xor
    int res_xor = 0, i;
    for (i = 0; i < data.size(); i++)
        res_xor ^= data[i];

    // find first position of 1 bit
    int mask = 1;
    while (!(res_xor & mask))
        mask <<= 1;

    // divide numbers into two sub-arrays, xor them respectively
    num1 = num2 = 0;
    for (i = 0; i < data.size(); i++)
        if (data[i] & mask)
            num1 ^= data[i];
        else
            num2 ^= data[i];
}


int main(int argc, char *argv[])
{
    int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int num1, num2;

    dispaly_vec(data);

    FindNumsAppearOnce(data, num1, num2);
    cout << num1 << ", " << num2 << endl;

    return 0;
}
