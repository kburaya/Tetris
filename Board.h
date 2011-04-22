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
    protected:
    private:
        int BoardWidth, BoardHeight;
        int CurX, curY;
        vector <vector <int> > board;
};

#endif // BOARD_H
