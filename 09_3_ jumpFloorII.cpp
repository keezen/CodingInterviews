# include <iostream>
# include <vector>
# include <cmath>
# include <cstdlib>
using namespace std;

void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

int jumpFloorII(int number)
{
    if (number <= 1)
        return 1;

    return pow(2, number - 1);
}


int main()
{
    // int arr[] = {3, 4, 5, 1, 2};
    // vector<int> vec(arr, arr + 5);
    int n = 5;
    int result;

    result = jumpFloorII(n);
    cout << "Jump(" << n << ") = " << result << endl;

    return 0;
}
