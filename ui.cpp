#include <wx/listctrl.h>
#include <vector>
#include <wx/wx.h>
#include <wx/toolbar.h>
#include "ui.h"
#include "Linked_list.h"
#include "VirtualList.h"
#include <wx/artprov.h>
#include <wx/textctrl.h>
MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT("Hello wxWidgets"), wxPoint(50,50), wxSize(800,600)) {
    wxPanel* mainPane = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    MyToolBar* toolbar = new MyToolBar(this,wxID_ANY, wxDefaultPosition, wxDefaultSize);
    this->SetToolBar(toolbar);
    toolbar->Bind(wxEVT_TOOL, &MyFrame::ShowBookSelectFrame,this);

    IList = new VirtualList(mainPane, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    BookSelect = new BookSelectFrame("Добавление книги",IList);


    sizer->Add(IList,1, wxEXPAND | wxALL, 10);
    mainPane->SetSizer(sizer);
}

void MyFrame::ShowBookSelectFrame(wxCommandEvent &event) {
    this->BookSelect->Show(true);
}
bool MyApp::OnInit() {
    m_frame = new MyFrame();
    m_frame->Show();
    return true;
}
MyToolBar::MyToolBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    :wxToolBar(parent,id,pos,size){

    this->AddTool(ATool, "NEW", wxArtProvider::GetBitmap("wxART_PLUS"));
    this->AddTool(RTool, "NEW", wxArtProvider::GetBitmap("wxART_MINUS"));
}
IMPLEMENT_APP(MyApp)
