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
        void SetSize (int height = 25, int width = 15);
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
        int GetCurWidth () { return BoardWidth;};
        int GetCurHeight() { return BoardHeight;};
        int GetCurX () { return curX;};
        int GetCurY () { return curY;};
        vector <vector <int> > GetCurBoard () { return board;};
        Figure GetCurFigure () { return current;};
        bool GetFinished () {return finished;};
    protected:
    private:
        int BoardWidth, BoardHeight;
        int curX, curY;
        vector <vector <int> > board;
        Figure current;
        bool finished;
};

#endif // BOARD_H
