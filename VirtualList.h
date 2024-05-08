#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Linked_list.h"

class VirtualList : public wxListCtrl{
    public:
    LinkedList* Data;
    VirtualList(wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size);
    virtual wxString OnGetItemText(long index, long column) const wxOVERRIDE{
        Node* item = Data->GetByPos(index);
        if(item == nullptr)
            return "";
        switch (column){
            case 0: return item->name;
            case 1: return item->auther;
            case 2: return item->date;
            default: return "";
        }
    }
    void RefrashAfterUpdate();
    void sort_by_col(int n);
};
