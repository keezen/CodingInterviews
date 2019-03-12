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


bool IsUngly(int num)
{
    if (num <= 0)
        return false;

    while (num % 2 == 0)
        num /= 2;
    while (num % 3 == 0)
        num /= 3;
    while (num % 5 == 0)
        num /= 5;

    return (num == 1);
}


int GetUglyNumber_Solution_Brute(int index)
{
    if (index <= 0)
        return 0;

    int count = 0, num = 0;

    while (count < index)
    {
        num++;
        if (IsUngly(num))
            count++;
    }

    return num;
}


int GetUglyNumber_Solution(int index)
{
    if (index <= 0)
        return 0;

    vector<int> ugly_nums;
    int t2, t3, t5;
    int next_ugly;

    ugly_nums.push_back(0);
    ugly_nums.push_back(1);
    t2 = t3 = t5 = 1;

    for (int i = 2; i <= index; i++)
    {
        next_ugly = min(min(ugly_nums[t2] * 2, ugly_nums[t3] * 3), ugly_nums[t5] * 5);
        ugly_nums.push_back(next_ugly);

        while ((t2 <= i) && (ugly_nums[t2] * 2 <= next_ugly))
            t2++;
        while ((t3 <= i) && (ugly_nums[t3] * 3 <= next_ugly))
            t3++;
        while ((t5 <= i) && (ugly_nums[t5] * 5 <= next_ugly))
            t5++;
    }

    return ugly_nums[index];
}


int main(int argc, char *argv[])
{
    int index = atoi(argv[1]);
    int result;

    cout << index << endl;

    result = GetUglyNumber_Solution(index);
    cout << result << endl;

    return 0;
}
