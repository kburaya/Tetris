#include "tetrisshell.h"
#include <ctime>
#include <cstdlib>

TetrisShell::TetrisShell(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(150*3, 250*3))
{
    tmpBoard = new Board();
    timer = new wxTimer(this, 1);
    this->Connect(wxEVT_TIMER, wxCommandEventHandler(TetrisShell::OnTimer));
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(TetrisShell::OnPaint));
    //this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(TetrisShell::OnKeyDown));
    this->Centre();
    srand(time(NULL));
    timer->Start(300);
    tmpBoard->CreateNewFigure();
}

void TetrisShell::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    wxColor col1;
    col1.Set(wxT("#0c0c0c"));
    const wxColour wxColors[8] = { wxColour(0, 0, 0), wxColour(204, 102, 102), wxColour(102, 204, 102), wxColour(102, 102, 204), wxColour(204, 102, 102), wxColour(129, 98, 1), wxColour(1, 1, 199)};
    wxBrush brush(wxColor(255, 255, 255), wxSOLID);
    dc.SetBrush(brush);
    dc.SetPen(wxPen(col1, 1, wxSOLID));
    int h = WinWidth()/tmpBoard->GetCurWidth();
    for(int i = 0; i < tmpBoard->GetCurHeight(); ++i)
    {
        for(int j = 0; j < tmpBoard->GetCurWidth() ; ++j)
        {
            brush.SetColour(wxColors[tmpBoard->GetCurBoard()[i][j]]);
            dc.DrawRectangle(0 + i*h, 0 + j*h, h, h);
        }
    }

    brush.SetColour(wxColors[tmpBoard->GetCurFigure().Color()]);
    for (int i = 0; i < 4; ++i)
        dc.DrawRectangle(tmpBoard->GetCurX() * h + tmpBoard->GetCurFigure().X(i) * h, tmpBoard->GetCurY() * h + tmpBoard->GetCurFigure().Y(i) * h, h, h);
}

void TetrisShell::OnTimer(wxCommandEvent& event)
{
    Refresh();
    tmpBoard->LineDown();
}

