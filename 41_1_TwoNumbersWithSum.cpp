# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
# include <unordered_set>
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


vector<int> FindNumbersWithSum_Set(vector<int> array, int sum)
{
    vector<int> res;

    if (array.size() <= 0)
        return res;

    unordered_set<int> uset;
    int product = 1000000;

    for (int i = 0; i < array.size(); i++)
        uset.insert(array[i]);

    for (int i = 0; i < array.size(); i++)
    {
        int t = array[i];
        if (uset.find(sum - t) != uset.end() && t <= sum - t && t * (sum - t) < product)
        {
            if (res.size() == 2)
            {
                res[0] = t;
                res[1] = sum - t;
            }
            else
            {
                res.push_back(t);
                res.push_back(sum - t);
            }
            product = t * (sum - t);
        }
    }

    return res;
}


vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    vector<int> res;

    if (array.size() <= 1)
        return res;

    int i = 0, j = array.size() - 1;

    while (i < j)
    {
        if (array[i] + array[j] == sum)
        {
            res.push_back(array[i]);
            res.push_back(array[j]);
            break;
        }
        else if (array[i] + array[j] > sum)
            j--;
        else if (array[i] + array[j] < sum)
            i++;
    }

    return res;
}


int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 4, 7, 11, 15};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int sum = 15;
    vector<int> res;

    dispaly_vec(data);
    cout << sum << endl << endl;

    res = FindNumbersWithSum(data, sum);
    dispaly_vec(res);

    return 0;
}
