#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "figure.h"

using namespace std;

enum Colors { White = 0, Red = 1, Green = 2, Yellow = 3, Blue = 4,
			  Pink = 5, Grey = 6, Purple = 7, Black = 8 };

class Board
{
    public:
        Board();
        virtual ~Board();
        void SetSize (int height = 15, int width = 10);
        void FindFull ();
        void DeleteFull (int number);
        bool CreateNewFigure ();
        void LineDown ();
        void Drop();
        bool Finished ();
        bool CheckMove (const Figure & figure, int newX, int newY);
        void AddToBoard ();
        void RotateCW ();
        void RotateCCW ();
        void MoveLeft ();
        void MoveRight ();
    protected:
    private:
        int BoardWidth, BoardHeight;
        int curX, curY;
        vector <vector <int> > board;
        Figure current;
        bool finished;
};

#endif // BOARD_H
