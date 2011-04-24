#include "board.h"

Board::Board ()
{
    Board::SetSize ();
}

Board::Board ()
{
	board.clear ();
}

void Board::SetSize (int height, int width)
{
    BoardHeight = height;
    BoardWidth = width;
    board.resize (BoardHeight);
    for (int i = 0; i < BoardHeight; ++i)
        board[i].resize (BoardWidth, 0);
}

void Board::DeleteFull (int number)
{
    for (int i = number; i > 0; --i)
        for (int j = 0; j < BoardWidth; ++j)
            swap (board[i][j], board[i - 1][j]);
    board[0].assign (BoardWidth, 0);
}

void Board::FindFull ()
{
    bool full;
    for (int i = 0; i < BoardHeight; ++i)
    {
        full = true;
        for (int j = 0; j < BoardWidth; ++j)
            if(board[i][j] == 0) {
                full = false;
                break;
            }
        if (full)
            DeleteFull (i);
    }
}

bool Board::CreateNewFigure ()
{
	current.SetFigure (current.RandomType ());
	curX = BoardHeight / 2 + 1;
	curY = -current.MinY ();
	if (!CheckMove (current, curX, curY)) {
		finished = true;
		return false;
	}
	else
		return true;
}

void Board::LineDown ()
{
    if (CheckMove (current, curX+1, curY))
    	curX++;
    else {
    	finished = true;
    	AddToBoard ();
    }
}

void Board::Drop ()
{
	while(!finished)
		LineDown ();
}

bool Board::Finished ()
{
    return finished;
}

bool Board::CheckMove (const Figure & figure, int newX, int newY)
{
	for (int i=0; i<4; ++i) {
		int x = newX + figure.X(i);
		int y = newY + figure.Y(i);
		if (x < 0 || x >= BoardHeight || y < 0 || y >= BoardWidth || board[x][y] != 0)
			return false;
	}
	return true;
}

void Board::AddToBoard ()
{
    for (int i = 0; i < 4; ++i)
        board[curX + current.X(i)][curY + current.Y(i)] = current.Color ();
}

void Board::RotateCCW ()
{
	current.RotateCCW ();
	if (!CheckMove(current, curX, curY))
		current.RotateCW ();
}

void Board::RotateCW ()
{
	current.RotateCW ();
	if (!CheckMove(current, curX, curY))
		current.RotateCCW ();
}

void Board::MoveLeft ()
{
	if (CheckMove(current, curX, curY-1))
		++curY;
}

void Board::MoveRight ()
{
	if (CheckMove(current, curX, curY+1))
		++curY;
}
