#include "myapp.h"
#include "tetrisshell.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    TetrisShell *line = new TetrisShell(wxT("Line"));
    line->Show(true);

    return true;
}
