#include "figure.h"

Figure::Figure ()
{
    SetFigure (RandomType ());
}

Figure::~Figure ()
{

}

Names Figure::RandomType ()
{
    int t = rand()%7;
    if (!(t == 7 && rand()%3 == 0))
        t = rand()%7;
    return Names (t);
}

void Figure::SetFigure (Names type)
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
    color = type+1;
    for (int i=0; i<4; ++i)
        for (int j=0; j<2; ++j)
            coords[i][j] = COORDS[type][i][j];
}

Names Figure::GetName () const
{
	return name;
}

void Figure::RotateCW ()
{
    if (name == Square || name == Bomb)
        return;
    int tmp;
    for (int i=0; i<4; ++i)
    {
        tmp = coords[i][0];
        coords[i][0] = -coords[i][1];
        coords[i][1] = tmp;
    }
}

void Figure::RotateCCW ()
{
    if (name == Square || name == Bomb)
        return;
    int tmp;
    for (int i=0; i<4; ++i)
    {
        tmp = coords[i][1];
        coords[i][1] = -coords[i][0];
        coords[i][0] = tmp;
    }
}

int Figure::MinX () const
{
	int res = coords[0][0];
	for (int i=1; i<4; ++i)
		res = min (res, coords[i][0]);
	return res;
}

int Figure::MaxX () const
{
	int res = coords[0][0];
	for (int i=1; i<4; ++i)
		res = max (res, coords[i][0]);
	return res;
}

int Figure::MinY () const
{
	int res = coords[0][1];
	for (int i=1; i<4; ++i)
		res = min (res, coords[i][1]);
	return res;
}

int Figure::MaxY () const
{
	int res = coords[0][1];
	for (int i=1; i<4; ++i)
		res = max (res, coords[i][1]);
	return res;
}

int Figure::X (int i) const
{
    return coords[i][0];
}

int Figure::Y (int i) const
{
    return coords[i][1];
}

int Figure::Color () const
{
    return color;
}
