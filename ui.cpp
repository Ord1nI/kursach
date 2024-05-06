#include <wx/listctrl.h>
#include <wx/wx.h>
#include "ui.h"
#include "Linked_list.h"
#include "VirtualList.h"
MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT("Hello wxWidgets"), wxPoint(50,50), wxSize(800,600))
{
    wxPanel* mainPane = new wxPanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    VirtualList* Ilist = new VirtualList(mainPane, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    Ilist->Data->insert("a","d","21.23.2003",21);
    Ilist->Data->insert("b","c","21.23.2003",21);
    Ilist->Data->insert("c","b","21.23.2003",21);
    Ilist->Data->insert("d","a","21.23.2003",21);
    Ilist->Data->insert("d","a","21.23.2003",21);
    Ilist->RefrashAfterUpdate();

    sizer->Add(Ilist,1, wxEXPAND | wxALL, 10);
    mainPane->SetSizer(sizer);
}

bool MyApp::OnInit() {
    m_frame = new MyFrame();
    m_frame->Show();
    return true;
}

VirtualList::VirtualList(wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size)
    :wxListCtrl(parent, id, pos, size, wxLC_REPORT | wxLC_VIRTUAL) {


    Data = new LinkedList();
    wxListItem col0;
    col0.SetId(0);
    col0.SetText( _("Названи*е") );
    col0.SetWidth(50);
    this->InsertColumn(0, col0);

    // Add second column
    wxListItem col1;
    col1.SetId(1);
    col1.SetText( _("Автор") );
    col1.SetWidth(100);
    this->InsertColumn(1, col1);

    // Add third column
    wxListItem col2;
    col2.SetId(2);
    col2.SetText( _("Дата") );
    col2.SetWidth(100);
    this->InsertColumn(2, col2);

    this->Bind(wxEVT_LIST_COL_CLICK, [this](wxListEvent &evt) {
        this->sort_by_col(evt.GetColumn());
        this->RefrashAfterUpdate();
    });

}
void VirtualList::sort_by_col(int n) {
    this->Data->sort(n);
}
void VirtualList::RefrashAfterUpdate() {
    this->SetItemCount(Data->size);
    this->Refresh();
}



IMPLEMENT_APP(MyApp)
