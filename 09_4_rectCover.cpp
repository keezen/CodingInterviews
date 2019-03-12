# include <iostream>
# include <vector>
# include <cmath>
# include <cstdlib>
using namespace std;

void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

int rectCover(int number)
{
    if (number <= 0)
        return 0;
    if (number == 1)
        return 1;

    int f1 = 1, f2 = 2;
    for (int i = 3; i <= number; i++)
    {
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    return f2;
}


int main()
{
    // int arr[] = {3, 4, 5, 1, 2};
    // vector<int> vec(arr, arr + 5);
    int n = 5;
    int result;

    for (int i = 1; i <= 5; i++)
    {
        result = rectCover(i);
        cout << "rectCover(" << i << ") = " << result << endl;
    }

    return 0;
}
