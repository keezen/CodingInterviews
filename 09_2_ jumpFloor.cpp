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

int jumpFloor(int number)
{
    // Number of methods of jumping.

    if (number <= 1)
        return 1;

    int fib1 = 1, fib2 = 1;
    for (int i = 2; i <= number; i++)
    {
        int t = fib1 + fib2;
        fib1 = fib2;
        fib2 = t;
    }

    return fib2; 
}


int main()
{
    // int arr[] = {3, 4, 5, 1, 2};
    // vector<int> vec(arr, arr + 5);
    int n = 5;
    int result;

    result = jumpFloor(n);
    cout << "Jump(" << n << ") = " << result << endl;

    return 0;
}
