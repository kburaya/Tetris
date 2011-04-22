#ifndef FIGURE_H
#define FIGURE_H

enum Names { Z, S, Line, T, Square, L, Ml, Bomb };

class Figure
{
    public:
        Figure();
        ~Figure();
        void SetFigure(Names type);
        Names GetName() const { return name; }
        void RotateCW();
        void RotateCCW();
    protected:
    private:
        Names name;
        int coords[4][2], color;
};

#endif // FIGURE_H
