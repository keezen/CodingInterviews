# include <iostream>
# include <vector>
# include <cstdlib>
# include <cmath>
using namespace std;

void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

double PowerNonNegativeRecursive(double base, int exp)
{
    if (exp == 0)
        return 1.0;
    if (exp == 1)
        return base;

    double pow = PowerNonNegativeRecursive(base, exp >> 1);
    pow = pow * pow;
    if (exp & 1)
        pow *= base;

    return pow;
}

double PowerNonNegative(double base, int exp)
{
    // power by bitwise product
    if (exp == 0)
        return 1.0;
    if (exp == 1)
        return base;

    double pow = 1.0;
    while (exp)
    {
        if (exp & 1)
            pow *= base;
        base *= base;
        exp = exp >> 1;
    }

    return pow;
}

double Power(double base, int exponent)
{
    int exp_abs = abs(exponent);
    double eps = 1e-5;

    if (abs(base - 0.0) < eps && exponent < 0)
        throw "Base 0 can't have negative exponent.";
    if (abs(base - 0.0) < eps)
        return 0.0;
    if (exponent == 0)
        return 1.0;

    // double pow = 1.0;
    // while (exp_abs--)
    //     pow *= base;
    double pow = PowerNonNegative(base, exp_abs);

    if (exponent < 0)
        pow = 1.0 / pow;

    return pow;
}


int main()
{
    double base[] = {2.0, 2.0, 1.5, -3.0, -3.0, -3.0, 0.0, 0.0, 0.0};
    int exp[] = {3, -3, 0, 2, -2, 0, 1, 0, -1};
    double result;

    for (int i = 0; i < 9; i++)
    {
        try
        {
            result = Power(base[i], exp[i]);
            cout << "f(" << base[i] << ", " << exp[i] << ") = " << result << endl;
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }

    return 0;
}
