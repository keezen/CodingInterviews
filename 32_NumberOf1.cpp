# include <iostream>
# include <cstdlib>
# include <vector>
# include <cmath>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


int NumberOf1Between1AndN_Solution_Brute(int n)
{
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 1)
                res += 1;
            tmp /= 10;
        }
    }

    return res;
}


int NumberOf1Between1AndN_Solution_Recursive(int n)
{
    vector<int> digits;

    if (n <= 0)
        return 0;

    // digits
    for (int i = n; i > 0; i /= 10)
        digits.push_back(i % 10);

    int len = digits.size(), first = digits[len - 1];
    int num_first = 0, num_other = 0, num_recur = 0;

    if (len == 1)
        return 1;

    // 1 in first digit
    if (first > 1)
        num_first = pow(10, len - 1);
    else if (first == 1)
        num_first = (n - pow(10, len - 1)) + 1;

    // 1 in other digits
    num_other = first * (len - 1) * pow(10, len - 2);

    // recursive in low digits
    num_recur = NumberOf1Between1AndN_Solution_Recursive(n - first * pow(10, len - 1));

    return num_first + num_other + num_recur;
}


int NumberOf1Between1AndN_Solution(int n)
{
    int num_ones = 0, i, a, b;

    if (n <= 0)
        return 0;

    // check 1 in every position
    for (i = 1; i <= n; i *= 10)
    {
        a = n / i;
        b = n % i;
        num_ones += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
    }

    return num_ones;
}


int main()
{
    int n = 13, result;

    result = NumberOf1Between1AndN_Solution(n);
    cout << result << endl;

    return 0;
}
