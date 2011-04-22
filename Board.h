#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "figure.h"

using namespace std;

enum Colors { White = 0, Black = 1, Red = 2, Green = 3, Yellow = 4, Blue = 5, Pink = 6, Grey = 7, Purple = 8 };

class Board
{
    public:
        Board();
        virtual ~Board();
        void SetSize(int height = 15, int width = 10);
        void IfFull();
        void DeleteFull(int NumberOfFull);
        void CreateNewFigure ();
        void AddNewFigure ();
        void MoveNewFigure ();
        bool NotFinished ();
        void AddAtBoard ();
    protected:
    private:
        int BoardWidth, BoardHeight;
        int CurX, curY;
        vector <vector <int> > board;
        int CurrentFigure[4][2];
};

#endif // BOARD_H
