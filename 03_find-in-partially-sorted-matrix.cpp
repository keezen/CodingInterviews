# include <iostream>
# include <vector>
using namespace std;

void display(vector<vector<int> > &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << ' ';
        cout << '\n';
    }
}

bool Find(int target, vector<vector<int> > &array)
{
    // find whether target in 2-d array

    int row = array.size(), col = array[0].size();
    int top = 0, right = col - 1;
    int elem_top_right;

    while (top < row && right >= 0)
    {
        // check top-right element
        elem_top_right = array[top][right];
        if (elem_top_right == target)  // found
            return true;
        if (elem_top_right < target)  // smaller, discard row
            top++;
        else  // larger than target, discard col
            right--;
    }
    return false;
}


int main()
{
    const int row = 4, col = 4;
    int array[row * col] = {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15
    };
    vector<vector<int> > vec(row, vector<int>(col, 1));

    // initialize vector
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            vec[i][j] = array[i * col + j];
    display(vec);

    // find in 2-d array
    int target = 7;
    cout << "Found " << target << " in array: "
         << Find(target, vec) << endl;
    target = 5;
    cout << "Found " << target << " in array: "
         << Find(target, vec) << endl;

    return 0;
}
