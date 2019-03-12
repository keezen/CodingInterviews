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


int LastRemaining_Solution_Circle(int n, int m)
{
    if (m <= 0 || n <= 0)
        return -1;

    if (n == 1)
        return 0;

    vector<int> circle(n, 0);  // circular list
    int i, cur, prev, next;
    
    // initialize list
    for (i = 0; i < circle.size(); i++)
        circle[i] = (i + 1) % n;

    // remove node until only one remained
    cur = (m - 1) % n, prev = (m - 2) % n;
    while (circle[cur] != cur)
    {
        next = circle[cur];
        circle[prev] = next;

        for (i = 0; i < m - 1; i++)
            prev = circle[prev];
        cur = circle[prev];
    }

    return cur;
}


int LastRemaining_Solution(int n, int m)
{
    if (m <= 0 || n <= 0)
        return -1;

    if (n == 1)
        return 0;

    int res = 0;
    for (int i = 2; i <= n; i++)
        res = (res + m) % i;

    return res;
}


int main(int argc, char *argv[])
{
    int n = atoi(argv[1]), m = atoi(argv[2]);
    int res;

    cout << n << ", " << m << endl;

    res = LastRemaining_Solution(n, m);
    cout << res << endl;

    return 0;
}
