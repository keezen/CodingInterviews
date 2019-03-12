# include <iostream>
# include <cstdlib>
using namespace std;

void replaceSpace(char *str,int length)
{
    // Replace space in string.
    // @param str: string
    // @param length: volume of char array

    if (str == NULL || length <= 0)
        return;

    int n_blanks = 0, str_len = 0;

    // number of total blanks
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            n_blanks++;
        str_len++;
    }

    // string too long
    if (str_len + n_blanks * 2 > length - 1)
        return;
    
    // replace space reversely
    int blank_cnt = n_blanks;
    for (int i = str_len; i >= 0; i--)
    {
        if (str[i] != ' ')
            str[i + blank_cnt * 2] = str[i];
        else
        {
            blank_cnt--;
            str[i + blank_cnt * 2] = '%';
            str[i + blank_cnt * 2 + 1] = '2';
            str[i + blank_cnt * 2 + 2] = '0';
        }
    }
}


int main()
{
    const int length = 100;
    char str[length] = "We Are Happy.";

    cout << "before:\n" << str << endl;
    replaceSpace(str, length);
    cout << "after:\n" << str << endl;

    return 0;
}
