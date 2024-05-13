#include "BookSelectFrame.h"
#include <iostream>
#include <wx/wx.h>
BookSelectFrame::BookSelectFrame(const wxString& title,VirtualList* List)
    :wxDialog(NULL, wxID_ANY,title,wxDefaultPosition,wxSize(250,230)){
    auto Frame = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    this-> list = List;
    auto SizerMain = new wxBoxSizer(wxVERTICAL);
    auto SizerText = new wxBoxSizer(wxVERTICAL);
    auto SizerButtons = new wxBoxSizer(wxHORIZONTAL);

    auto NameLabel = new wxStaticText(this,wxID_ANY,wxT("Название Книги:"));
    auto NameTextCtrl = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(FromDIP(300),wxDefaultSize.GetHeight()));
    NameTextCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &name));


    auto AutherLabel = new wxStaticText(this,wxID_ANY,wxT("Автор:"));
    auto AutherTextCtrl = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(FromDIP(300),wxDefaultSize.GetHeight()));
    AutherTextCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &auther));

    auto DateLabel = new wxStaticText(this,wxID_ANY,wxT("Дата издания:"));
    auto DateTextCtrl = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(FromDIP(300),wxDefaultSize.GetHeight()));
    DateTextCtrl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &date));

    auto PageLabel = new wxStaticText(this,wxID_ANY,wxT("Кол-во страниц:"));
    auto PageTextCtrl = new wxTextCtrl(this,wxID_ANY,wxEmptyString,wxDefaultPosition,wxSize(FromDIP(300),wxDefaultSize.GetHeight()));
    PageTextCtrl->SetValidator(wxTextValidator(wxFILTER_DIGITS, &pages));
    PageTextCtrl->SetDefaultStyle(wxTextAttr(wxNullColour, *wxLIGHT_GREY));
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
        SizerText->Add(Item,0,wxALL,FromDIP(3));
    }

    auto addButton = new wxButton(this,wxID_ANY,wxT("Добавить книгу"),wxDefaultPosition,wxDefaultSize);
    addButton->Bind(wxEVT_BUTTON, &BookSelectFrame::Insert_Book,this);
    SizerButtons->Add(addButton,1,wxEXPAND|wxALL,FromDIP(3));
    auto rmButton = new wxButton(this,wxID_ANY,wxT("Закрыть"),wxDefaultPosition,wxDefaultSize);
    rmButton->Bind(wxEVT_BUTTON,[this](wxCommandEvent& event){
        this->Show(false);});
    SizerButtons->Add(rmButton,1,wxEXPAND|wxALL,FromDIP(3));


    SizerMain->Add(SizerText,1,wxALIGN_CENTER|wxALL ,FromDIP(10));
    SizerMain->Add(SizerButtons,0,wxALIGN_CENTER | wxLEFT|wxRIGHT);
    this->SetSizerAndFit(SizerMain);
}
 void BookSelectFrame::Insert_Book(wxCommandEvent &event) {
     TransferDataFromWindow();
     if(name.IsNull() || auther.IsNull() || date.IsNull() || pages.IsNull())
         return;
     list->Add(name.utf8_string(),auther.utf8_string(),date.utf8_string(),pages.utf8_string());
     name.Clear();
     auther.Clear();
     date.Clear();
     pages.Clear();
     list->RefrashAfterUpdate();
     this->Show(false);
}
