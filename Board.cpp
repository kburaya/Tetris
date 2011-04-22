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



void CreateNewFigure ()
{

}

void AddNewFigure ()
{
   curX = BoardWidth / 2;
   curY = 0;
   bool fx = true, fy = true;
   while (fx && fy)
   {
       for (int i = 0; i < 4; ++i)
       {
           if (curX + CurrentFigure[i][0] < 0)
                fx = false;
            if (curY + CurrentFigure[i][1] < 0)
                fy = false;
       }
       if (!fx)
            ++curX;
       if(!fy)
            ++curY;
   }

   for (int i = 0; i < 4; ++i)
       board[curX + CurrentFigure[i][0]][curY + CurrentFigure[i][1]] = ; //номер цвета
}

void MoveNewFigureDown ()
{
    while (!NotFinished ())
        curX++;
}

bool NotFinished ()
{
    for (int i = 0; i < 4; ++i)
        if (curX == 0 || board[curX + CurrentFigure[i][0] + 1][curY + CurrentFigure[i][1]] != 0)
            return true;
    return false;
}
