# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;


void dispaly_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


bool IsSquenceOfBST(vector<int> &sequence, int start, int end)
{
    // cout << start << ' ' << end << endl;

    if (sequence.size() <= 0 || end - start <= 0)
        return true;

    int i, j;
    int root_val;

    root_val = sequence[end];
    for (i = start; i < end && sequence[i] < root_val; i++)
        ;
    for (j = end; j >= start && sequence[j] >= root_val; j--)
        ;

    if (i == j + 1)
        if (IsSquenceOfBST(sequence, start, i - 1))
            if (IsSquenceOfBST(sequence, j + 1, end - 1))
                return true;

    return false;
}


bool VerifySquenceOfBST(vector<int> &sequence)
{
    if (sequence.size() == 0)
        return false;

    if (sequence.size() == 1)
        return true;

    return IsSquenceOfBST(sequence, 0, sequence.size() - 1);
}


int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    vector<int> seq(arr, arr + 5);

    dispaly_vec(seq);

    if (VerifySquenceOfBST(seq))
        cout << "Sequence of BST." << endl;
    else
        cout << "Not sequence of BST." << endl;

    return 0;
}
