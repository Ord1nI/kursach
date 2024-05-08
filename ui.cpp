#include <wx/listctrl.h>
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
    this->SetToolBar(toolbar->ToolBar);




    VirtualList* Ilist = new VirtualList(mainPane, wxID_ANY, wxDefaultPosition, wxDefaultSize);



    Ilist->RefrashAfterUpdate();

    sizer->Add(Ilist,1, wxEXPAND | wxALL, 10);
    mainPane->SetSizer(sizer);
}

bool MyApp::OnInit() {
    m_frame = new MyFrame();
    m_frame->Show();
    return true;
}
MyToolBar::MyToolBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size){
    ToolBar = new wxToolBar(parent,id,pos,size);
    ToolBar->AddTool(ATool, "NEW", wxArtProvider::GetBitmap("wxART_PLUS"));
    ToolBar->AddTool(RTool, "NEW", wxArtProvider::GetBitmap("wxART_MINUS"));
    ToolBar->Bind(wxEVT_TOOL, &MyToolBar::Actions, this);
}


// MyToolBar::Insert_Book() {

// }
BookSelectFrame::BookSelectFrame(const wxString& title)
    :wxDialog(NULL, wxID_ANY,title,wxDefaultPosition,wxSize(250,230)){
    auto Frame = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    auto SizerMain = new wxBoxSizer(wxVERTICAL);
    auto SizerText = new wxBoxSizer(wxVERTICAL);
    auto SizerButtons = new wxBoxSizer(wxHORIZONTAL);

    auto NameLabel = new wxStaticText(this,wxID_ANY,wxT("Название Книги"));
    auto NameTextCtrl = new wxTextCtrl(this,wxID_ANY);
    SizerText->Add(NameLabel);
    SizerText->Add(NameTextCtrl);

    auto AutherLabel = new wxStaticText(this,wxID_ANY,wxT("Автор"));
    auto AutherTextCtrl = new wxTextCtrl(this,wxID_ANY);
    SizerText->Add(AutherLabel);
    SizerText->Add(AutherTextCtrl);

    auto DateLabel = new wxStaticText(this,wxID_ANY,wxT("Дата издания"));
    auto DateTextCtrl = new wxTextCtrl(this,wxID_ANY);
    SizerText->Add(DateLabel);
    SizerText->Add(DateTextCtrl);

    auto PageLabel = new wxStaticText(this,wxID_ANY,wxT("Кол-во страниц"));
    auto PageTextCtrl = new wxTextCtrl(this,wxID_ANY);
    SizerText->Add(PageLabel);
    SizerText->Add(PageTextCtrl);

    auto addButton = new wxButton(this,wxID_ANY,wxT("Добавить книгу"),wxDefaultPosition,wxDefaultSize);
    SizerButtons->Add(addButton);
    auto rmButton = new wxButton(this,wxID_ANY,wxT("Удалить книгу"),wxDefaultPosition,wxDefaultSize);
    SizerButtons->Add(rmButton);

    SizerMain->Add(SizerText);
    SizerMain->Add(SizerButtons);
    this->SetSizer(SizerMain);
}
void MyToolBar::Actions(wxCommandEvent& event){
    switch(event.GetId()) {
        case ATool:
            this->BookSelect->Show();

    }
}






IMPLEMENT_APP(MyApp)
