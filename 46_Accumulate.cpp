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


int Sum_Solution_Short(int n)
{
    int res = n;
    (n > 0) && (res += Sum_Solution_Short(n - 1));
    return res;
}


int multi(int a, int b)
{
    int res = 0;
    (a & 1) && (res += b);
    a >>= 1; b <<= 1;
    a && (res += multi(a, b));
    return res;
}


int Sum_Solution_Bit(int n)
{
    return multi(n, n + 1) >> 1;
}


int Sum_Solution(int n)
{
    int res = 0;
    (n > 0) && (res = n + Sum_Solution(n - 1));
    return res;
}


int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int res, x = 0, y = 8;

    cout << n << endl;

    res = Sum_Solution(n);
    cout << res << endl;

    return 0;
}
