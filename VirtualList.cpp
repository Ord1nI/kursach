#include "VirtualList.h"
VirtualList::VirtualList(wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size)
    :wxListCtrl(parent, id, pos, size, wxLC_REPORT | wxLC_VIRTUAL) {


    Data = new LinkedList();
    wxListItem col0;
    col0.SetId(0);
    col0.SetText( wxT("Название") );
    col0.SetWidth(100);
    this->InsertColumn(0, col0);

    // Add second column
    wxListItem col1;
    col1.SetId(1);
    col1.SetText( wxT("Автор") );
    col1.SetWidth(100);
    this->InsertColumn(1, col1);

    // Add third column
    wxListItem col2;
    col2.SetId(2);
    col2.SetText( wxT("Дата") );
    col2.SetWidth(100);
    this->InsertColumn(2, col2);

    wxListItem col3;
    col3.SetId(3);
    col3.SetText( wxT("Кол-во страниц") );
    col3.SetWidth(120);
    this->InsertColumn(3, col3);

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
