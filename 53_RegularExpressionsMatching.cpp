# include <iostream>
# include <cstdlib>
# include <vector>
# include <cstring>
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


bool match_eat_repeat(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
        return false;

    int i = 0, j = 0;
    char repeat = '\0';

    while (str[i] != '\0' && pattern[j] != '\0')
    {
        cout << str[i] << " " << pattern[j] << endl;

        // repeat
        if (pattern[j + 1] == '*')
        {
            if(pattern[j] == '.' || str[i] == pattern[j])
            {
                repeat = str[i];
                i++;
            }
            else
                j += 2;

            continue;
        }

        // remove repeat
        if (pattern[j] == repeat)
        {
            j++; continue;
        }

        repeat = '\0';

        // arbitrary
        if (pattern[j] == '.' || str[i] == pattern[j])
        {
            i++; j++;
            continue;
        }

        return false;
    }

    // reduce star
    while (pattern[j] != '\0' && pattern[j + 1] == '*')
        j += 2;

    // reduce repeat
    while (pattern[j] != '\0' && pattern[j] == repeat)
        j++;

    // match
    if (str[i] == '\0' && pattern[j] == '\0')
        return true;

    return false;
}


bool match_recur(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
        return false;

    if (*str == '\0' && *pattern == '\0')
        return true;

    if (*str != '\0' && *pattern == '\0')
        return false;

    // second char is '*'
    if (*(pattern + 1) == '*')
    {
        // first char match
        if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            return match_recur(str + 1, pattern)  // stay at current
                || match_recur(str, pattern + 2);  // ignore pattern
        else  // first char doesn't match
            return match_recur(str, pattern + 2);  // ignore pattern
    }

    // second char is not '*'

    // first char match
    if (*str == *pattern || (*str != '\0' && *pattern == '.'))
        return match_recur(str + 1, pattern + 1);  // move to next

    // first char doesn't match
    return false;
}


bool match(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
        return false;

    int len1 = strlen(str), len2 = strlen(pattern);
    vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));

    // dynamic programming
    dp[len1][len2] = true;
    for (int i = len1; i >= 0; i--)
        for (int j = len2 - 1; j >= 0; j--)
            if (pattern[j + 1] == '*')
                if (pattern[j] == str[i] || (i < len1 && pattern[j] == '.'))
                    dp[i][j] = dp[i][j + 2] || dp[i + 1][j];
                else
                    dp[i][j] = dp[i][j + 2];
            else
                if (pattern[j] == str[i] || (i < len1 && pattern[j] == '.'))
                    dp[i][j] = dp[i + 1][j + 1];

    return dp[0][0];
}


int main(int argc, char *argv[])
{
    char *str = argv[1], *pattern = argv[2];
    bool res;

    cout << str << endl;
    cout << pattern << endl;

    res = match(str, pattern);
    cout << res << endl;

    return 0;
}
