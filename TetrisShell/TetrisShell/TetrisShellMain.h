/***************************************************************
 * Name:      TetrisShellMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ksuh vs ZumZoom ()
 * Created:   2011-04-23
 * Copyright: Ksuh vs ZumZoom ()
 * License:
 **************************************************************/

#ifndef TETRISSHELLMAIN_H
#define TETRISSHELLMAIN_H

//(*Headers(TetrisShellFrame)
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class TetrisShellFrame: public wxFrame
{
    public:

        TetrisShellFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TetrisShellFrame();

    private:

        //(*Handlers(TetrisShellFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(TetrisShellFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(TetrisShellFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TETRISSHELLMAIN_H
