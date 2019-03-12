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


int Fibonacci(int n)
{
    if (n <= 0)
        return 0;

    if (n <= 2)
        return 1;

    int fib1 = 1, fib2 = 1, t;
    for (int i = 3; i <= n; i++)
    {
        t = fib1 + fib2;
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
    int fib;

    fib = Fibonacci(n);
    cout << "Fib(" << n << ") = " << fib << endl;


    return 0;
}
