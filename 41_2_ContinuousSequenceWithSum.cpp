# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
# include <cmath>
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


void display_matrix(vector<vector<int> > &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}


vector<vector<int> > FindContinuousSequence_DoublePointer(int sum)
{
    vector<vector<int> > res;

    if (sum < 3)
        return res;

    int i = 1, j = 2, end = (sum + 1) / 2;
    int cur_sum, start;

    // two pointers
    while (j <= end && i < j)
    {
        cur_sum = (i + j) * (j - i + 1) / 2;

        if (cur_sum == sum)
        {
            vector<int> t(2, 0);
            t[0] = i, t[1] = j;
            res.push_back(t);
            j++;
        }
        else if (cur_sum < sum)
            j++;
        else
            i++;
    }

    // expand sequence
    for (i = 0; i < res.size(); i++)
    {
        start = res[i][0], end = res[i][1];

        vector<int> t;
        for (j = start; j <= end; j++)
            t.push_back(j);

        res[i] = t;
    }

    return res;
}


vector<vector<int> > FindContinuousSequence(int sum)
{
    // 1）由于我们要找的是和为S的连续正数序列，因此这个序列是个公差为1的等差数列，而这个序列的中间值代表了平均值的大小。假设序列长度为n，那么这个序列的中间值可以通过（S / n）得到，知道序列的中间值和长度，也就不难求出这段序列了。
    // 2）满足条件的n分两种情况：
    // n为奇数时，序列中间的数正好是序列的平均值，所以条件为：(n & 1) == 1 && sum % n == 0；
    // n为偶数时，序列中间两个数的平均值是序列的平均值，而这个平均值的小数部分为0.5，所以条件为：(sum % n) * 2 == n.
    // 3）由题可知n >= 2，那么n的最大值是多少呢？我们完全可以将n从2到S全部遍历一次，但是大部分遍历是不必要的。为了让n尽可能大，我们让序列从1开始，
    // 根据等差数列的求和公式：S = (1 + n) * n / 2，得到.

    // 最后举一个例子，假设输入sum = 100，我们只需遍历n = 13~2的情况（按题意应从大到小遍历），n = 8时，得到序列[9, 10, 11, 12, 13, 14, 15, 16]；n  = 5时，得到序列[18, 19, 20, 21, 22]。

    vector<vector<int> > res;

    if (sum < 3)
        return res;

    int n, i, j;

    for (n = (int) sqrt(sum * 2); n >= 2; n--)
    {
        if (((n & 1) == 1 && sum % n == 0) || (sum % n) * 2 == n)
        {
            vector<int> t;
            for (i = sum / n - (n - 1) / 2, j = 0; j < n; i++, j++)
                t.push_back(i);
            res.push_back(t);
        }
    }

    return res;
}


int main(int argc, char *argv[])
{
    int sum = 100;
    vector<vector<int> > res;

    cout << sum << endl << endl;

    res = FindContinuousSequence(sum);
    display_matrix(res);

    return 0;
}
