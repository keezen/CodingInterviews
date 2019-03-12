# include <iostream>
# include <vector>
# include <cstdlib>
# include <cmath>
using namespace std;

void dispaly_digit(const vector<char> &vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i];
    // cout << endl;
}

char char_adder(char ci, int n, int &carry)
{
    char co;

    // increment character by 1
    if (ci + n + carry > '9')
    {
        co = ci + n + carry - 1 - '9' + '0';
        carry = 1;
    }
    else
    {
        co = ci + n + carry;
        carry = 0;
    }

    return co;
}

vector<char>& digit_incrementor(vector<char> &digits)
{
    // increment digits by 1
    int carry = 1;
    char ci, co;

    for (int i = 0; i < digits.size(); i++)
    {
        ci = digits[i];
        co = char_adder(ci, 0, carry);
        digits[i] = co;
    }

    if (carry > 0)
    {
        co = carry + '0';
        digits.push_back(co);
    }

    return digits;
}

void printNDigit(int n)
{
    if (n <= 0)
        return;

    vector<char> digits(1);

    digits[0] = '1';

    while (digits.size() <= n)
    {
        dispaly_digit(digits);
        cout << ' ';
        digits = digit_incrementor(digits);
    }
    cout << endl;
}


int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    printNDigit(n);

    return 0;
}
