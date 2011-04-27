#ifndef TETRISSHELL_H
#define TETRISSHELL_H

#include <wx/wx.h>

#include "board.h"


class TetrisShell : public wxFrame
{
    public:
        TetrisShell (const wxString& title);
        void OnPaint (wxPaintEvent& event);
        void OnTimer (wxCommandEvent& event);
        void OnKeyDown (wxKeyEvent& event);
        void DrawSquare (wxPaintDC& dc, int x, int y);
    protected:
    private:
        wxTimer *timer;
        int curX, curY;
        Board *tmpBoard;
        int WinHeight () { return GetClientSize().GetHeight();};
        int WinWidth () { return GetClientSize().GetWidth();};
};

#endif // TETRISSHELL_H
