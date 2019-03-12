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


void dispaly_matrix(vector<vector<int> > &mat)
{
    int n_rows = mat.size(), n_cols = mat[0].size();

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}


vector<int> printMatrix(vector<vector<int> > &matrix)
{
    int n_rows = matrix.size(), n_cols = matrix[0].size();
    int top, bottom, left, right, pos;
    vector<int> result(n_rows * n_cols, 0);

    if (n_rows <= 0 || n_cols <= 0)
        return result;

    top = 0, bottom = n_rows - 1, left = 0, right = n_cols - 1, pos = 0;
    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
            result[pos++] = matrix[top][j];

        if (top == bottom)
            break;

        for (int i = top + 1; i < bottom; i++)
            result[pos++] = matrix[i][right];

        for (int j = right; j >= left; j--)
            result[pos++] = matrix[bottom][j];

        if (left == right)
            break;

        for (int i = bottom - 1; i > top; i--)
            result[pos++] = matrix[i][left];

        top++, bottom--, left++, right--;
    }

    return result;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<int> vec(4, 0);
    vector<vector<int> > mat(4, vec);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat[i][j] = arr[4 * i + j];

    dispaly_matrix(mat);
    cout << endl;

    vec = printMatrix(mat);
    dispaly_vec(vec);

    return 0;
}
