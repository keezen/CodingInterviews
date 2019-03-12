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


int Add_Bit(int num1, int num2)
{
    int x, y, c = 0, s;
    int res = 0, mask = 1;

    while (mask)
    {
        x = mask & num1; y = mask & num2;

        s = x ^ y ^ c;  // sum
        c = (x & y) | (x & c) | (y & c);  // carry

        c <<= 1;
        res |= s;

        mask <<= 1;
    }

    return res;
}


int Add(int num1, int num2)
{
    int carry = num2, sum = num1;
    int t;

    while (carry)
    {
        t = sum ^ carry;
        carry = (sum & carry) << 1;
        sum = t;
    }

    return sum;
}


int main(int argc, char *argv[])
{
    int num1 = atoi(argv[1]), num2 = atoi(argv[2]);
    int res;

    cout << num1 << ", " << num2 << endl;

    res = Add(num1, num2);
    cout << res << endl;

    return 0;
}
