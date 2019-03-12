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


class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s.push_back(ch);
        freq[ch]++;
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (int i = 0; i < s.size(); i++)
            if (freq[s[i]] == 1)
                return s[i];

        return '#';
    }

    string GetStr()
    {
        return s;
    }

private:
    char freq[256] = {0};
    string s;   
};


int main(int argc, char *argv[])
{
    string str = "google";
    Solution sol;
    char res;

    // cout << str << endl;
    for (int i = 0; i < str.size(); i++)
    {
        sol.Insert(str[i]);
        cout << sol.GetStr() << endl;

        res = sol.FirstAppearingOnce();
        cout << res << endl;
    }

    return 0;
}
