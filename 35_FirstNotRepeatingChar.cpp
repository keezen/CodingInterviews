# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
# include <map>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


void dispaly_vec(vector<string> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


int FirstNotRepeatingChar_Map(string str)
{
    if (str.size() <= 0)
        return -1;

    map<char, int> freq;
    for (int i = 0; i < str.size(); i++)
        if (freq.find(str[i]) == freq.end())
            freq[str[i]] = 1;
        else
            freq[str[i]] += 1;

    for (int i = 0; i < str.size(); i++)
        if (freq[str[i]] == 1)
            return i;

    return -1;
}


int FirstNotRepeatingChar(string str)
{
    if (str.size() <= 0)
        return -1;

    vector<int> freq(256, 0);
    for (int i = 0; i < str.size(); i++)
        freq[str[i]] += 1;

    for (int i = 0; i < str.size(); i++)
        if (freq[str[i]] == 1)
            return i;

    return -1;
}


int main(int argc, char *argv[])
{
    string str = "abaccdeff";
    int result;

    cout << str << endl;

    result = FirstNotRepeatingChar(str);
    cout << result << endl;

    return 0;
}
