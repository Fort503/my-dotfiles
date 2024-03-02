#include "lisaDeLlamadasFrame.h"
#include "wx/msgdlg.h"
#include "estructuras.h"

//(*InternalHeaders(lisaDeLlamadasFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(lisaDeLlamadasFrame)
const long lisaDeLlamadasFrame::ID_STATICBITMAP1 = wxNewId();
const long lisaDeLlamadasFrame::ID_STATICTEXT1 = wxNewId();
const long lisaDeLlamadasFrame::ID_LISTCTRL1 = wxNewId();
const long lisaDeLlamadasFrame::ID_BUTTON1 = wxNewId();
const long lisaDeLlamadasFrame::ID_BUTTON2 = wxNewId();
const long lisaDeLlamadasFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(lisaDeLlamadasFrame,wxFrame)
	//(*EventTable(lisaDeLlamadasFrame)
	//*)
END_EVENT_TABLE()

lisaDeLlamadasFrame::lisaDeLlamadasFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(lisaDeLlamadasFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,350));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(304,168), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(254,247,255));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/fort/documentos/proyectos/aplicacionDeLLamadas/assets/lista-de-verificacion.png")).Rescale(wxSize(64,64).GetWidth(),wxSize(64,64).GetHeight())), wxPoint(40,16), wxSize(64,64), 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Lista de llamadas registradas"), wxPoint(112,32), wxSize(304,32), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(17,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	listaLLamadasControl = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(32,96), wxSize(432,184), wxHSCROLL, wxDefaultValidator, _T("ID_LISTCTRL1"));
	cargarBoton = new wxButton(Panel1, ID_BUTTON1, _("Cargar lista"), wxPoint(32,296), wxSize(210,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont cargarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	cargarBoton->SetFont(cargarBotonFont);
	regresarBoton = new wxButton(Panel1, ID_BUTTON2, _("Regresar"), wxPoint(256,296), wxSize(210,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	regresarBoton->SetBackgroundColour(wxColour(247,242,250));
	wxFont regresarBotonFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Roboto"),wxFONTENCODING_DEFAULT);
	regresarBoton->SetFont(regresarBotonFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lisaDeLlamadasFrame::OncargarBotonClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lisaDeLlamadasFrame::OnregresarBotonClick);
	//*)
}

lisaDeLlamadasFrame::~lisaDeLlamadasFrame()
{
	//(*Destroy(lisaDeLlamadasFrame)
	//*)
}


void lisaDeLlamadasFrame::OnregresarBotonClick(wxCommandEvent& event)
{
    Close();
}

void lisaDeLlamadasFrame::OncargarBotonClick(wxCommandEvent& event)
{
    FILE* arch = fopen("llamadas.dat", "rb");

    if (arch == NULL) {
        wxMessageBox("Error al abrir el archivo", "Error", wxOK | wxICON_ERROR);
    }

    llamadas llamada;

    int index = 0;

    while (fread(&llamada, sizeof(llamada), 1, arch) == 1) {
        wxString codigoCliente = llamada.codigoCliente;
        wxString codigoServicio = llamada.codigoServicio;
        wxString fecha = llamada.fecha;
        wxString hora = llamada.hora;

        wxString item = "Cliente: " + codigoCliente + " | Servicio: " + codigoServicio +  " | fecha: " + fecha +  " | hora: " + hora;

        listaLLamadasControl->InsertItem(index, item);
        index++;
    }

    fclose(arch);
}

