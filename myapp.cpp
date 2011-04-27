#include "myapp.h"
#include "tetrisshell.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    TetrisShell *line = new TetrisShell(wxT("Tetris"));
    line->Show(true);

    return true;
}
