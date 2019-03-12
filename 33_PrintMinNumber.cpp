# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
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


bool str_cmp(string sa, string sb)
{
    return (sa + sb) <= (sb + sa);
}


string PrintMinNumber(vector<int> numbers)
{
    if (numbers.size() <= 0)
        return "";

    vector<string> nums_str;

    // int to string
    for (int i = 0; i < numbers.size(); i++)
        nums_str.push_back(to_string(numbers[i]));

    // sort vector
    sort(nums_str.begin(), nums_str.end(), str_cmp);

    // min number
    string res;
    for (int i = 0; i < nums_str.size(); i++)
        res.append(nums_str[i]);

    return res;
}


int main()
{
    int arr[] = {3, 32, 321};
    vector<int> numbers(arr, arr + 3);
    string result;

    dispaly_vec(numbers);

    result = PrintMinNumber(numbers);
    cout << result << endl;

    return 0;
}
