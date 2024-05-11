#include <wx/listctrl.h>
#include <vector>
#include <wx/wx.h>
#include <wx/toolbar.h>
#include "ui.h"
#include "Linked_list.h"
#include "VirtualList.h"
#include <wx/artprov.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT("Библиотека"), wxPoint(50,50), wxSize(800,600)) {
    wxPanel* mainPane = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    auto toolbar = CreateToolBar();
        toolbar->AddTool(ATool, "NEW", wxArtProvider::GetBitmap("wxART_PLUS"));
        toolbar->AddTool(RTool, "Rm", wxArtProvider::GetBitmap("wxART_MINUS"));
        toolbar->Realize();

    IList = new VirtualList(mainPane, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    IList->Add("a","s","s","s");
    IList->Add("b","s","s","s");
    IList->Add("c","s","s","s");
    IList->Add("d","s","s","s");
    IList->Add("e","s","s","s");
    IList->Add("f","s","s","s");
    IList->Add("g","s","s","s");
    IList->Add("h","s","s","s");
    IList->RefrashAfterUpdate();
    BookSelect = new BookSelectFrame("Добавление книги",IList);


    toolbar->Bind(wxEVT_TOOL, &MyFrame::ShowBookSelectFrame,this,ATool);
    toolbar->Bind(wxEVT_TOOL, &MyFrame::Remove,this,RTool);
    sizer->Add(IList,1, wxEXPAND | wxALL, 10);
    mainPane->SetSizer(sizer);
}
void MyFrame::Remove(wxCommandEvent &event) {
    IList->Remove(IList->GetFirstSelectedIndex());
    IList->RefrashAfterUpdate();
}

void MyFrame::ShowBookSelectFrame(wxCommandEvent &event) {
    BookSelect->Show(true);
}

bool MyApp::OnInit() {
    m_frame = new MyFrame();
    m_frame->Show();
    return true;
}
MyToolBar::MyToolBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    :wxToolBar(parent,id,pos,size){

    this->AddTool(ATool, "NEW", wxArtProvider::GetBitmap("wxART_PLUS"));
    this->AddTool(RTool, "Rm", wxArtProvider::GetBitmap("wxART_MINUS"));
    this->Realize();
}
IMPLEMENT_APP(MyApp)
