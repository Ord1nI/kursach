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
    Ilist->Data->insert("a","e","b",34);
    Ilist->Data->insert("b","d","b",34);
    Ilist->Data->insert("c","c","b",34);
    Ilist->Data->insert("d","b","b",34);
    Ilist->Data->insert("e","a","b",34);
    Ilist->Data->sort(1);

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

    Data = new LinkedList();
}
void VirtualList::RefrashAfterUpdate() {
    this->SetItemCount(Data->size);
    this->Refresh();
}



IMPLEMENT_APP(MyApp)
