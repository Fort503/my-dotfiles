/***************************************************************
 * Name:      CRUD_Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-11-15
 * Copyright:  ()
 * License:
 **************************************************************/

#include "CRUD_Main.h"
#include <wx/msgdlg.h>
#include <fstream>
#include <string.h>
#include "readFrame.h"

using namespace std;

//(*InternalHeaders(CRUD_Frame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CRUD_Frame)
const long CRUD_Frame::ID_STATICTEXT1 = wxNewId();
const long CRUD_Frame::ID_TEXTCTRL1 = wxNewId();
const long CRUD_Frame::ID_BUTTON1 = wxNewId();
const long CRUD_Frame::ID_BUTTON2 = wxNewId();
const long CRUD_Frame::ID_PANEL1 = wxNewId();
const long CRUD_Frame::idMenuQuit = wxNewId();
const long CRUD_Frame::idMenuAbout = wxNewId();
const long CRUD_Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CRUD_Frame,wxFrame)
    //(*EventTable(CRUD_Frame)
    //*)
END_EVENT_TABLE()

CRUD_Frame::CRUD_Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CRUD_Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(350,250));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(248,256), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("CRUD prueba"), wxPoint(112,16), wxSize(144,48), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(15,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Cascadia Code"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    createTextControl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(72,56), wxSize(224,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    sendButton = new wxButton(Panel1, ID_BUTTON1, _("Enviar"), wxPoint(72,96), wxSize(224,27), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    verDatosButton = new wxButton(Panel1, ID_BUTTON2, _("Ver datos"), wxPoint(72,136), wxSize(224,27), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CRUD_Frame::OncreateTextControlText);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CRUD_Frame::OnsendButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CRUD_Frame::OnverDatosButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CRUD_Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CRUD_Frame::OnAbout);
    //*)
}

CRUD_Frame::~CRUD_Frame()
{
    //(*Destroy(CRUD_Frame)
    //*)
}

void CRUD_Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CRUD_Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void CRUD_Frame::OncreateTextControlText(wxCommandEvent& event)
{
}

void CRUD_Frame::OnsendButtonClick(wxCommandEvent& event)
{
    ofstream archivoEscritura;
    ifstream archivoLectura;
    string dato, datosLeidos, contenido;

    archivoEscritura.open("datos.txt", ios::app);
    archivoLectura.open("datos.txt", ios::in);

    if(!archivoEscritura.fail()) {
        dato = createTextControl->GetValue();
        archivoEscritura << dato << endl;
        wxMessageBox(wxT("Datos escritos en el archivo correctamente."), wxT("Éxito"), wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox(wxT("No se pudo abrir el archivo para leer."), wxT("Error"), wxOK | wxICON_ERROR);
    }

    if(!archivoLectura.fail()) {
        while(!archivoLectura.eof()) {
            getline(archivoLectura, datosLeidos);
            contenido += datosLeidos;
        }
 //       readTextControl->SetValue(contenido);
    } else {
        wxMessageBox(wxT("No se pudo abrir el archivo para leer."), wxT("Error"), wxOK | wxICON_ERROR);
    }

    archivoEscritura.close();
    archivoLectura.close();
}

void CRUD_Frame::OnreadTextControlText(wxCommandEvent& event)
{
}

void CRUD_Frame::OnverDatosButtonClick(wxCommandEvent& event)
{
    readFrame * tmp = new readFrame(0);
    tmp->Show();
}
