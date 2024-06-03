#include "ui.h"
MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY,  wxT("Библиотека"), wxPoint(50,50), wxSize(800,600)) {

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* search_sizer = new wxBoxSizer(wxHORIZONTAL);

    auto toolbar = CreateToolBar();
        toolbar->AddTool(ITool, "Info",wxArtProvider::GetBitmap("wxART_TIP"));
        toolbar->AddTool(ATool, "NEW", wxArtProvider::GetBitmap("wxART_PLUS"));
        toolbar->AddTool(RTool, "Rm", wxArtProvider::GetBitmap("wxART_MINUS"));
        toolbar->AddTool(UTool, "Undo",wxArtProvider::GetBitmap("wxART_UNDO"));
        toolbar->Realize();

    wxSearchCtrl* Search = new wxSearchCtrl(this,wxID_ANY);
    wxButton* SearchBtn = new wxButton(this,wxID_ANY,wxT("Искать"));

    Search->ShowSearchButton(true);
    Search->ShowCancelButton(true);

    Search->SetDescriptiveText(wxT("Поиск"));
    IList = new VirtualList(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    IList->GetFromFile("books.xml");

    BookSelect = new BookSelectFrame(this,"Добавление книги",IList);
    Search->Bind(wxEVT_SEARCH,&VirtualList::find,IList);
    Search->Bind(wxEVT_SEARCH_CANCEL,&VirtualList::Clear_search,IList);
    Search->Bind(wxEVT_TEXT,[this](wxCommandEvent& event) {
        if (event.GetString() == "" && IList->Search_mode == true)
            IList->Clear_search(event);
    });
    SearchBtn->Bind(wxEVT_BUTTON,&VirtualList::find,IList);

    toolbar->Bind(wxEVT_TOOL, &MyFrame::ShowInfo, this, ITool);
    toolbar->Bind(wxEVT_TOOL, &MyFrame::ShowBookSelectFrame, this, ATool);
    toolbar->Bind(wxEVT_TOOL, &MyFrame::Remove, this, RTool);
    toolbar->Bind(wxEVT_TOOL, &VirtualList::Undo, IList, UTool);


    search_sizer->Add(Search,1,wxEXPAND);
    search_sizer->Add(SearchBtn,0,wxLEFT,10);
    sizer->Add(search_sizer,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);
    sizer->Add(IList,1, wxEXPAND | wxALL, 10);
    this->SetSizerAndFit(sizer);
}
void MyFrame::Remove(wxCommandEvent &event) {
    IList->Remove(IList->GetFirstSelectedIndex());
    IList->RefrashAfterUpdate();
}

void MyFrame::ShowBookSelectFrame(wxCommandEvent &event) {
    BookSelect->Show(true);
}
void MyFrame::ShowInfo(wxCommandEvent &event) {
    wxMessageBox("Программа библиотека.\n\n"
                 "Нажмите + чтобы добавить книгу.\n"
                 "Нажмите - чтобы удалить книгу.\n"
                 "Поиск: для поиска введите искомую книги, автора или год выпуска в поле сверху", "Инфорация", wxICON_QUESTION);
}
void MyFrame::ShowInfo() {
    wxMessageBox("Программа библиотека.\n\n"
                 "Нажмите + чтобы добавить книгу.\n"
                 "Нажмите - чтобы удалить книгу.\n"
                 "Поиск: для поиска введите искомую книги, автора или год выпуска в поле сверху", "Информация", wxICON_QUESTION);
}

bool MyApp::OnInit() {
    m_frame = new MyFrame();
    m_frame->Bind(wxEVT_CLOSE_WINDOW,&MyApp::on_close,this);
    m_frame->Show();
    m_frame->ShowInfo();
    return true;
}
void MyApp::on_close(wxCloseEvent& event){
    m_frame->IList->GenFile("books.xml");
    delete m_frame->IList->Data;
    delete m_frame->IList->Search;
    delete m_frame->IList->UndoList;
    m_frame->Destroy();
}

// int MyApp::OnExit() {
//     // m_frame->IList->GenFile("Books.xml");
//     // delete m_frame;
//     // m_frame->Close();
//     return 0;
// }
IMPLEMENT_APP(MyApp)
