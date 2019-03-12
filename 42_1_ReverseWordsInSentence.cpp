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


string ReverseSentence(string str)
{
    if (str.size() <= 1)
        return str;

    // reverse all string
    reverse(str, 0, str.size() - 1);

    // reverse every word
    int i = 0, j = 0;
    while (i < str.size() && j < str.size())
    {
        for (; i < str.size() && str[i] == ' '; i++) ;
        for (j = i; j < str.size() && str[j] != ' '; j++) ;

        if (i < j)
        {
            reverse(str, i, j - 1);
            i = j;
        }
    }

    return str;
}


int main(int argc, char *argv[])
{
    string input = "I am a student.";
    string res;

    cout << input << endl;

    res = ReverseSentence(input);
    cout << res << endl;

    return 0;
}
