#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void PrintMatrix(int size, int *matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << *(matrix + i * size + j) << " ";
        }
        std::cout << std::endl;
    }
}

bool CheckSudoku(std::vector<std::vector<int>> &board)
{
    bool row[4][4] = {false};
    bool col[4][4] = {false};
    bool box[4][4] = {false}; // box index = (r / 2) * 2 + c / 2
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            int num = board[r][c];
            if (num == 0) // 0 表示空格
                continue;
            int d = num - 1;
            int b = (r / 2) * 2 + c / 2;

            if (row[r][d] || col[c][d] || box[b][d])
            {
                return false;
            }
            row[r][d] = col[c][d] = box[b][d] = true;
        }
    }
    return true;
}

void MatrixExample()
{
    int size = 4;
    std::vector<std::vector<int>> board(size, std::vector<int>(size));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> board[i][j];
        }
    }

    bool isValid = CheckSudoku(board);
    std::cout << (isValid ? "Valid Sudoku" : "Invalid Sudoku") << std::endl;
}

int main()
{
    MatrixExample();
    return 0;
}