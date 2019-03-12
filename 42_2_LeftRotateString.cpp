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


void reverse(string &str, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
        swap(str[i], str[j]);
}


string LeftRotateString(string str, int n)
{
    if (str.size() <= 1 || n <= 0 || str.size() <= n)
        return str;

    // reverse whole string
    int len = str.size();
    reverse(str, 0, len - 1);

    // reverse separate part
    reverse(str, 0, len - n - 1);
    reverse(str, len - n, len - 1);

    return str;
}


int main(int argc, char *argv[])
{
    string str = "abcdefg";
    int n = 2;
    string res;

    cout << str << endl;

    res = LeftRotateString(str, n);
    cout << res << endl;

    return 0;
}
