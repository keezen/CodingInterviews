# include <iostream>
# include <cstdlib>
# include <vector>
# include <limits>
# include <deque>
using namespace std;


template <typename T> void display_vec(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}



vector<int> GetNeighbor(int offset, int rows, int cols)
{
    vector<int> neighbor;

    if (offset < 0 || rows <= 0 || cols <= 0 || offset >= rows * cols)
        return neighbor;

    int row = offset / cols, col = offset % cols;
    int top = row - 1, bottom = row + 1, left = col - 1, right = col + 1;

    if (0 <= top)
        neighbor.push_back(top * cols + col);
    if (0 <= left)
        neighbor.push_back(row * cols + left);
    if (right < cols)
        neighbor.push_back(row * cols + right);
    if (bottom < rows)
        neighbor.push_back(bottom * cols + col);

    return neighbor;
}


bool DFS(const string &mat, int rows, int cols, const string &s, vector<int> &path, vector<bool> &accessible)
{
    if (mat.size() <= 0 || s.size() <= 0 || mat.size() != rows * cols)
        return false;

    if (path.size() > s.size())
        return false;

    if (s[path.size() - 1] != mat[path.back()])
        return false;

    if (s.size() == path.size())
        return true;

    vector<int> neighbor = GetNeighbor(path.back(), rows, cols);
    vector<int>::iterator it;
    for (it = neighbor.begin(); it != neighbor.end(); it++)
    {
        if (accessible[*it])
        {
            path.push_back(*it);
            accessible[*it] = false;

            if (DFS(mat, rows, cols, s, path, accessible))
                return true;

            accessible[path.back()] = true;
            path.pop_back();
        }
    }

    return false;
}


bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if (matrix == NULL || str == NULL || rows <= 0 || cols <= 0)
        return false;

    string mat(matrix);
    string s(str);

    if (mat.size() <= 0 || s.size() <= 0 || mat.size() < s.size()
        || mat.size() != rows * cols)
        return false;

    vector<int> path;
    vector<bool> accessible(mat.size(), true);
    int i;

    for (i = 0; i < mat.size(); i++)
    {
        path.push_back(i);
        accessible[i] = false;

        if (DFS(mat, rows, cols, s, path, accessible))
            return true;

        accessible[path.back()] = true;
        path.pop_back();
    }

    return false;
}


int main(int argc, char *argv[])
{
    char matrix[] = "abcesfcsadee";
    int rows = 3, cols = 4;
    char str[] = "bcced";
    bool res;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i * cols + j] << ' ';
        cout << endl;
    }
    cout << str << endl << endl;

    res = hasPath(matrix, rows, cols, str);
    cout << res << endl;

    return 0;
}
