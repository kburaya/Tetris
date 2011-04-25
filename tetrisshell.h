#ifndef TETRISSHELL_H
#define TETRISSHELL_H

#include <wx/wx.h>

#include "board.h"

class TetrisShell : public wxFrame
{
    public:
        TetrisShell(const wxString& title);
        void OnPaint(wxPaintEvent& event);
    protected:
    private:
};

#endif // TETRISSHELL_H
