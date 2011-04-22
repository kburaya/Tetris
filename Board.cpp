#include "Board.h"

Board::Board()
{
    Board::SetSize();
}

void Board::SetSize (int height, int width)
{
    BoardHeight = height;
    BoardWidth = width;
    board.resize (BoardHeight);
    for (int i = 0; i < BoardHeight; ++i)
        board[i].resize (BoardWidth, 0);
}

void Board::DeleteFull (int NumberOfFull)
{
    for (int i = 0; i < BoardWidth; ++i)
        board[NumberOfFull][i] = 0;
    for (int i = NumberOfFull; i > 0; --i)
        for (int j = 0; j < BoardWidth; ++j)
            swap (board[i][j], board[i - 1][j]);
    board[0].assign (BoardWidth, 0);
}

void Board::IfFull ()
{
    int tmp;
    for (int i = 0; i < BoardHeight; ++i)
    {
        tmp = 0;
        for (int j = 0; j < BoardWidth; ++j)
            if(board[i][j])
                ++tmp;
        if (tmp == BoardWidth)
        {
            Board::DeleteFull(i);
            --i;
        }
    }
}
