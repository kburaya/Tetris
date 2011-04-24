#ifndef FIGURE_H
#define FIGURE_H

#include <algorithm>

using namespace std;

enum Names { Z, S, Line, T, Square, L, Ml, Bomb };

class Figure
{
    public:
        Figure ();
        virtual ~Figure ();
        void SetFigure (Names type);
        Names GetName () const;
        Names RandomType ();
        void RotateCW ();
        void RotateCCW ();
        int MinX () const;
        int MinY () const;
        int MaxX () const;
        int MaxY () const;
        int X (int i) const;
        int Y (int i) const;
        int Color() const;
    protected:
    private:
        Names name;
        int coords[4][2], color;
};

#endif // FIGURE_H
