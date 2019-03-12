# include <iostream>
# include <cstdlib>
# include <vector>
# include <queue>
using namespace std;


template <typename T> void display_vec(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}


bool IsLegal(int row, int col, int rows, int cols, int threshold)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return false;

    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return false;

    int digit_sum = 0;
    for (; row > 0; row /= 10)
    {
        digit_sum += (row % 10);
    }
    for (; col > 0; col /= 10)
    {
        digit_sum += (col % 10);
    }

    return digit_sum <= threshold;
}


int movingCount_BFS(int threshold, int rows, int cols)
{
    // breadth first search (BFS)

    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;

    queue<int> qr, qc;
    int i, count = 0;
    int row, col, r, c;
    int neighbor[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<bool> > accessible(rows, vector<bool>(cols, true));

    qr.push(0); qc.push(0);
    accessible[0][0] = false;
    count++;
    while (!qr.empty() && !qc.empty())
    {
        row = qr.front(); qr.pop();
        col = qc.front(); qc.pop();

        for (i = 0; i < 4; i++)
        {
            r = row + neighbor[i][0];
            c = col + neighbor[i][1];

            if (IsLegal(r, c, rows, cols, threshold) && accessible[r][c])
            {
                qr.push(r); qc.push(c);
                accessible[r][c] = false;
                count++;
            }
        }
    }

    return count;
}


int DFS(int row, int col, int rows, int cols, int threshold, vector<bool> &accessible)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;

    if (!IsLegal(row, col, rows, cols, threshold) || !accessible[row * cols + col])
        return 0;

    accessible[row * cols + col] = false;  // visit

    return 1 + DFS(row - 1, col, rows, cols, threshold, accessible) +
        DFS(row, col - 1, rows, cols, threshold, accessible) +
        DFS(row, col + 1, rows, cols, threshold, accessible) +
        DFS(row + 1, col, rows, cols, threshold, accessible);
}


int movingCount(int threshold, int rows, int cols)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;

    vector<bool> accessible(rows * cols, true);

    return DFS(0, 0, rows, cols, threshold, accessible);
}


int main(int argc, char *argv[])
{
    int rows = 3, cols = 4, threshold = 3;
    int res;

    res = movingCount(threshold, rows, cols);
    cout << res << endl;

    return 0;
}
