#include "figure.h"
#include <algorithm>

Figure::Figure()
{
    int t = rand()%8;
    if(!(t == 7 && rand()%3 == 0))
        t = rand()%7;
    SetFigure(Names(t));
}

void Figure::SetFigure(Names type)
{
    const int COORDS[8][4][2] = {
        { {0, -1}, {0, 0}, {-1, 0}, {-1, 1} },
        { {0, -1}, {0, 0}, {1, 0}, {1, 1} },
        { {0, -1}, {0, 0}, {0, 1}, {0, 2} },
        { {-1, 0}, {0, 0}, {1, 0}, {0, 1} },
        { {0, 0}, {1, 0}, {0, 1}, {1, 1} },
        { {-1, -1}, {0, -1}, {0, 0}, {0, 1} },
        { {1, -1}, {0, -1}, {0, 0}, {0, 1} },
        { {0, 0}, {0, 0}, {0, 0}, {0, 0} },
    };
    name = type;
    for(int i=0; i<4; ++i)
        for(int j=0; j<2; ++j)
            coords[i][j] = COORDS[type][i][j];
}

void Figure::RotateCW()
{
    if(name == Square || name == Bomb)
        return;
    int tmp;
    for(int i=0; i<4; ++i)
    {
        tmp = coords[i][0];
        coords[i][0] = -coords[i][1];
        coords[i][1] = tmp;
    }
}

void Figure::RotateCCW()
{
    if(name == Square || name == Bomb)
        return;
    int tmp;
    for(int i=0; i<4; ++i)
    {
        tmp = coords[i][1];
        coords[i][1] = -coords[i][0];
        coords[i][0] = tmp;
    }
}
