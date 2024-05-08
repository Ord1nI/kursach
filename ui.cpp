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
    BookSelect = new BookSelectFrame("Добавление книги");

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

    auto NameLabel = new wxStaticText(this,wxID_ANY,wxT("Название Книги:"));
    auto NameTextCtrl = new wxTextCtrl(this,wxID_ANY);

    auto AutherLabel = new wxStaticText(this,wxID_ANY,wxT("Автор:"));
    auto AutherTextCtrl = new wxTextCtrl(this,wxID_ANY);

    auto DateLabel = new wxStaticText(this,wxID_ANY,wxT("Дата издания:"));
    auto DateTextCtrl = new wxTextCtrl(this,wxID_ANY);

    auto PageLabel = new wxStaticText(this,wxID_ANY,wxT("Кол-во страниц:"));
    auto PageTextCtrl = new wxTextCtrl(this,wxID_ANY);
    std::vector<wxWindow*> fromItems = {
        NameLabel,
        NameTextCtrl,
        AutherLabel,
        AutherTextCtrl,
        DateLabel,
        DateTextCtrl,
        PageLabel,
        PageTextCtrl};
    for (auto Item:fromItems) {
        SizerText->Add(Item,0,wxEXPAND|wxALL,FromDIP(3));
    }

    auto addButton = new wxButton(this,wxID_ANY,wxT("Добавить книгу"),wxDefaultPosition,wxDefaultSize);
    SizerButtons->Add(addButton,1,wxEXPAND|wxALL,FromDIP(3));
    auto rmButton = new wxButton(this,wxID_ANY,wxT("Закрыть"),wxDefaultPosition,wxDefaultSize);
    rmButton->Bind(wxEVT_BUTTON,[this](wxCommandEvent& event){
        this->Show(false);});
    SizerButtons->Add(rmButton,1,wxEXPAND|wxALL,FromDIP(3));

    SizerMain->Add(SizerText,1,wxALIGN_CENTER | wxRIGHT|wxTOP,FromDIP(10));
    SizerMain->Add(SizerButtons,0,wxALIGN_CENTER | wxLEFT|wxRIGHT);
    this->SetSizerAndFit(SizerMain);
}
void MyToolBar::Actions(wxCommandEvent& event){
    switch(event.GetId()) {
        case ATool:
            this->BookSelect->Show(true);

    }
}






IMPLEMENT_APP(MyApp)
