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


void scanDigits(char **str)
{
    if (str == NULL || *str == NULL)
        return;

    while (**str != '\0' && '0' <= **str && **str <= '9')
        (*str)++;
}


bool isExponential(char **str)
{
    if (str == NULL || *str == NULL)
        return false;

    if (**str != 'E' && **str != 'e')
        return false;

    (*str)++;

    if (**str == '+' || **str == '-')
        (*str)++;

    if (**str == '\0')
        return false;

    scanDigits(str);

    return **str == '\0';
}


bool isNumeric_Class(char* string)
{
    if (string == NULL || *string == '\0')
        return false;

    if (*string == '+' || *string == '-')
        string++;

    if (*string == '\0')
        return false;

    bool numeric = true;
    scanDigits(&string);

    if (*string != '\0')
    {
        if (*string == 'e' or *string == 'E')
            numeric = isExponential(&string);
        else if (*string == '.')
        {   
            string++;
            scanDigits(&string);
            if (*string == 'e' or *string == 'E')
                numeric = isExponential(&string);
        }
        else
            numeric = false;
    }

    return numeric && *string == '\0';
}


bool state_match(char cur, char cat)
{
    if ('0' <= cur && cur <= '9' && cat == 'n')
        return true;

    if (cur == 'E' && cat == 'e')
        return true;

    return cur == cat;
}


bool isNumeric(char* string)
{
    if (string == NULL || *string == '\0')
        return false;

    char arr[10] = "+-n.ne+-n";
    bool turn[10][10] = {
        //+  -  n  .  n  e  +  -  n  #end
        { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },  // #start
        { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },  // +
        { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },  // -
        { 0, 0, 1, 1, 0, 1, 0, 0, 0, 1 },  // n
        { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1 },  // .
        { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1 },  // n
        { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },  // e
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },  // +
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },  // -
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },  // n
    };
    int i, j, state;
    int len = strlen(string);

    state = 0;
    for (i = 0; i <= len; i++)
    {
        for (j = 0; j < 10; j++)
            if (state_match(string[i], arr[j]) && turn[state][j])
            {
                state = j + 1;
                break;
            }

        if (j == 10)  // can't transfer to current char state
            return false;
    }

    return state == 10;
}


int main(int argc, char *argv[])
{
    char *str = argv[1];
    bool res;

    cout << str << endl;

    int len = strlen(str);
    res = isNumeric(str);
    cout << res << endl;

    return 0;
}
