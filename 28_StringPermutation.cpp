# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
# include <unordered_set>
# include <algorithm>
using namespace std;


void dispaly_vec(vector<string> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
}


void _Permutation(string str, int pos, vector<string> &res)
{
    if (pos >= str.size())
        return;

    if (pos == str.size() - 1)
    {
        res.push_back(str);
        return;        
    }

    unordered_set<char> myset;
    for (int i = pos; i < str.size(); i++)
    {
        if (myset.find(str[i]) == myset.end())
        {
            myset.insert(str[i]);

            swap(str[pos], str[i]);
            _Permutation(str, pos + 1, res);
            swap(str[pos], str[i]);
        }
    }
}


vector<string> Permutation(string str)
{
    vector<string> res;
    string path;

    if (str.size() == 0)
        return res;

    _Permutation(str, 0, res);

    sort(res.begin(), res.end());

    return res;
}


int main()
{
    string str = "baa";
    vector<string> result;

    result = Permutation(str);
    dispaly_vec(result);

    return 0;
}
