#include "tetrisshell.h"
#include <ctime>
#include <cstdlib>

TetrisShell::TetrisShell(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(150*2, 250*2))
{
    tmpBoard = new Board();
    timer = new wxTimer(this, 1);
    //wxStatusBar *sb = CreateStatusBar();
    //sb->SetStatusText((wxT("0")));
    isPaused = false;
    this->Connect(wxEVT_TIMER, wxCommandEventHandler(TetrisShell::OnTimer));
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(TetrisShell::OnPaint));
    this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(TetrisShell::OnKeyDown));
    this->Centre();
    srand(time(NULL));
    timer->Start(300);
    tmpBoard->CreateNewFigure();
}

void TetrisShell::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    wxColor col1;
    col1.Set(wxT("#f0ffff"));
    const wxColour wxColors[8] = { wxColour(255, 255, 255), wxColour(204, 102, 102), wxColour(102, 204, 102), wxColour(102, 102, 204), wxColour(204, 102, 102), wxColour(129, 98, 1), wxColour(1, 1, 199)};
    wxBrush brush(wxColor(255, 255, 255), wxSOLID);
    dc.SetBrush(brush);
    dc.SetPen(wxPen(col1, 1, wxSOLID));
    int h = WinWidth()/tmpBoard->GetCurWidth();
    for(int i = 0; i < tmpBoard->GetCurHeight(); ++i)
    {
        for(int j = 0; j < tmpBoard->GetCurWidth() ; ++j)
        {
            brush.SetColour(wxColors[tmpBoard->GetCurBoard()[i][j]]);
            dc.SetBrush(brush);
            dc.DrawRectangle(0 + j*h, 0 + i*h, h, h);
        }
    }

    brush.SetColour(wxColors[tmpBoard->GetCurFigure().Color()]);
    dc.SetBrush(brush);
    for (int i = 0; i < 4; ++i)
        dc.DrawRectangle(tmpBoard->GetCurY()*h + tmpBoard->GetCurFigure().Y(i) * h, tmpBoard->GetCurX()*h + tmpBoard->GetCurFigure().X(i) * h, h, h);
}

void TetrisShell::OnTimer(wxCommandEvent& event)
{
    Refresh();
    if(tmpBoard->CheckMove(tmpBoard->GetCurFigure(), tmpBoard->GetCurX(), tmpBoard->GetCurY()))
    {
        tmpBoard->LineDown();
        tmpBoard->FindFull();
    }


    else
    {
        tmpBoard->CreateNewFigure();
        if(tmpBoard->Finished())
            timer->Stop();
    }
}

void TetrisShell::OnKeyDown(wxKeyEvent& event)
{
    int keycode = event.GetKeyCode();
    if(keycode == 'p' || keycode == 'P')
    {
        isPaused = !isPaused;
    }
    if(isPaused)
    {
        timer->Stop();
        //m_stsbar->SetStatusText(wxT("PAUSED"));
    }
    else
        timer -> Start(300);
    switch (keycode)
    {
    case WXK_LEFT:
        if(tmpBoard->CheckMove(tmpBoard->GetCurFigure(), tmpBoard->GetCurX() - 1, tmpBoard->GetCurY()))
           tmpBoard->MoveLeft();
        break;
    case WXK_RIGHT:
        if(tmpBoard->CheckMove(tmpBoard->GetCurFigure(), tmpBoard->GetCurX() + 1, tmpBoard->GetCurY()))
           tmpBoard->MoveRight();
        break;
    case WXK_UP:
        tmpBoard->RotateCW();
        break;
    case WXK_DOWN:
        while(tmpBoard->CheckMove(tmpBoard->GetCurFigure(), tmpBoard->GetCurX(), tmpBoard->GetCurY() + 1))
            tmpBoard->LineDown();
        break;
    }
}
