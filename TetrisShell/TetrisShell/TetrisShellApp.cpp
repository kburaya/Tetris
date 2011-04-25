/***************************************************************
 * Name:      TetrisShellApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ksuh vs ZumZoom ()
 * Created:   2011-04-23
 * Copyright: Ksuh vs ZumZoom ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "TetrisShellApp.h"

//(*AppHeaders
#include "TetrisShellMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TetrisShellApp);

bool TetrisShellApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TetrisShellFrame* Frame = new TetrisShellFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
