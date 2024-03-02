#include "readFrame.h"
#include <wx/msgdlg.h>
#include <fstream>
#include <string.h>

using namespace std;


//(*InternalHeaders(readFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(readFrame)
const long readFrame::ID_BUTTON1 = wxNewId();
const long readFrame::ID_LISTVIEW1 = wxNewId();
const long readFrame::ID_PANEL1 = wxNewId();
const long readFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(readFrame,wxFrame)
	//(*EventTable(readFrame)
	//*)
END_EVENT_TABLE()

readFrame::readFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(readFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(350,266));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(200,264), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	verDatosButton = new wxButton(Panel1, ID_BUTTON1, _("ver datos"), wxPoint(8,208), wxSize(328,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	listContent = new wxListView(Panel1, ID_LISTVIEW1, wxPoint(8,16), wxSize(328,184), wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEW1"));
	MenuBar1 = new wxMenuBar();
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&readFrame::OnverDatosButtonClick);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&readFrame::OnlistContentBeginDrag);
	//*)
}

readFrame::~readFrame()
{
	//(*Destroy(readFrame)
	//*)
}

void readFrame::OnreadTextControlText(wxCommandEvent& event)
{

}

void readFrame::OnverDatosButtonClick(wxCommandEvent& event)
{
    wxListItem item;
    ifstream archivoLectura;
    string dato, datosLeidos, contenido;
    int index = 0;

    archivoLectura.open("datos.txt", ios::in);

    if(!archivoLectura.fail()) {
        listContent->DeleteAllItems();

        while(!archivoLectura.eof()) {
            getline(archivoLectura, datosLeidos);
            item.SetId(index);
            item.SetText(datosLeidos);
            listContent->InsertItem(item);

            index++;
        }

    } else {
        wxMessageBox(wxT("No se pudo abrir el archivo para leer."), wxT("Error"), wxOK | wxICON_ERROR);
    }

    archivoLectura.close();
}

void readFrame::OnlistContentBeginDrag(wxListEvent& event)
{
}
