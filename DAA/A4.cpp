#include <iostream>
#include <vector>

using namespace std;

int N = 4;
vector<vector<int>> board(N, vector<int>(N, 0));
pair<int, int> placed = {2, 3}; 

void printBoard(const vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0)
                cout << ". ";
            else if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << "P "; 
        }
        cout << endl;
    }
}

bool is_safe(const vector<vector<int>> &board, int pos_x, int pos_y)
{
    for (int i = 0; i < N; i++)
    {
        if (board[i][pos_y] == 1)
            return false;
    }

    for (int i = 0; i < N; i++)
    {
        if (board[pos_x][i] == 1)
            return false;
    }

    int i = pos_x, j = pos_y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    i = pos_x, j = pos_y;
    while (i < N && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }

    i = pos_x, j = pos_y;
    while (i >= 0 && j < N)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }

    i = pos_x, j = pos_y;
    while (i < N && j < N)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j++;
    }

    return true;
}

bool NQueens(vector<vector<int>> &board, int col)
{
    if (col >= N)
        return true;

    if (col == placed.second)
        return NQueens(board, col + 1);

    for (int i = 0; i < N; i++)
    {
        if (i == placed.first)
            continue;

        if (is_safe(board, i, col))
        {
            board[i][col] = 1;

            if (NQueens(board, col + 1))
                return true;

            board[i][col] = 0; 
        }
    }

    return false;
}

int main()
{
    board[placed.first][placed.second] = 1;

    // cout << "Initial Board" << endl;
    // printBoard(board);
    // cout << "********" << endl;

    if (NQueens(board, 0))
    {
        cout << "Solution" << endl;
        printBoard(board);
        cout << "********" << endl;
    }
    else
    {
        cout << "No Solution" << endl;
    }

    return 0;
}
