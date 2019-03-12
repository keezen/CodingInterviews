# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
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


int StrToInt(string str)
{
    int error = 0;

    // empty string
    if (str.size() <= 0)
        return error;

    int flag = 1, i = 0, num = 0;

    // sign
    if (str[i] == '-')
    {
        flag = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    // only sign
    if (i >= str.size())
        return error;

    // every digit
    while (i < str.size())
    {
        // illegal digit
        if (str[i] < '0' || str[i] > '9')
            return error;
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num * flag;
}


int main(int argc, char *argv[])
{
    string str = argv[1];
    int res;

    cout << str << endl;

    res = StrToInt(str);
    cout << res << endl;

    return 0;
}
