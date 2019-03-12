# include <iostream>
# include <cstdlib>
# include <vector>
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


void CountFreq(vector<int> &freq, int n, int sum)
{
    // all dices have been determined
    if (n <= 0)
    {
        freq[sum] += 1;
        return;
    }

    // throw one dice
    for (int i = 1; i <= 6; i++)
        CountFreq(freq, n - 1, sum + i);
}


void PrintProbability_Exp(int n)
{
    if (n <= 0)
        return;

    vector<int> freq(6 * n + 1, 0);

    // count frequency of all results
    for (int i = 1; i <= 6; i++)
        CountFreq(freq, n - 1, i);

    int total_freq = pow(6, n);
    for (int i = n; i <= 6 * n; i++)
        cout << i << ": " << freq[i] * 1.0 / total_freq << endl;
}


void PrintProbability(int N)
{
    if (N <= 0)
        return;

    vector<int> freq(6 * N + 1, 0);
    vector<int> tmp(freq);
    int n, s, i;
    int start, end;

    // n = 1
    for (i = 1; i <= 6; i++)
        freq[i] = 1;

    // from n = 2 to N
    for (n = 2; n <= N; n++)
    {
        for (s = n; s <= 6 * n; s++)
        {
            start = max(s - 6, n - 1);
            end = min(s - 1, 6 * n - 6);
            for (i = start, tmp[s] = 0; i <= end; i++)
                tmp[s] += freq[i];
        }

        for (s = n; s <= 6 * n; s++)
            freq[s] = tmp[s];
    }

    // print
    int total_freq = pow(6, N);
    for (int s = N; s <= 6 * N; s++)
        cout << s << ": " << freq[s] * 1.0 / total_freq << endl;    
}


int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    cout << n << endl << endl;

    PrintProbability(n);

    return 0;
}
