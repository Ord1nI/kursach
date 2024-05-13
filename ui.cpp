#include <wx/listctrl.h>
#include <wx/wx.h>
#include <wx/toolbar.h>
#include "ui.h"
#include "Linked_list.h"
#include "VirtualList.h"
#include <wx/srchctrl.h>
#include <wx/artprov.h>
#include <wx/textctrl.h>
MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT("Библиотека"), wxPoint(50,50), wxSize(800,600)) {
    wxPanel* mainPane = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    auto toolbar = CreateToolBar();
        toolbar->AddTool(ATool, "NEW", wxArtProvider::GetBitmap("wxART_PLUS"));
        toolbar->AddTool(RTool, "Rm", wxArtProvider::GetBitmap("wxART_MINUS"));
        toolbar->AddTool(UTool, "Undo",wxArtProvider::GetBitmap("wxART_UNDO"));
        toolbar->Realize();

    wxSearchCtrl* Search = new wxSearchCtrl(mainPane,wxID_ANY);

    Search->ShowSearchButton(false);
    Search->SetDescriptiveText(wxT("Поиск"));
    IList = new VirtualList(mainPane, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    IList->GetFromFile("books.xml");
    IList->GenFile("test.xml");

    BookSelect = new BookSelectFrame("Добавление книги",IList);

    Search->Bind(wxEVT_SEARCH,&VirtualList::find,IList);
    Search->Bind(wxEVT_SEARCH_CANCEL,&VirtualList::Clear_search,IList);

    toolbar->Bind(wxEVT_TOOL, &MyFrame::ShowBookSelectFrame,this,ATool);
    toolbar->Bind(wxEVT_TOOL, &MyFrame::Remove,this,RTool);
    toolbar->Bind(wxEVT_TOOL, &VirtualList::Undo,IList,UTool);
    sizer->Add(Search,0,wxEXPAND | wxLEFT | wxRIGHT, 10);
    sizer->Add(IList,1, wxEXPAND | wxALL, 10);
    mainPane->SetSizerAndFit(sizer);
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
