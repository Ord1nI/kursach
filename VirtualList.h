#pragma once
#include <vector>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Linked_list.h"
#include <wx/string.h>
#include "tinyxml2.h"

class VirtualList : public wxListCtrl{
    bool Revers = false;
    public:
    LinkedList* Data;
    LinkedList* UndoList;
    LinkedList* Search;
    bool Search_mode;
    VirtualList(wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size);
    virtual wxString OnGetItemText(long index, long column) const wxOVERRIDE{
        Node* item = Data->GetByPos(index,Revers);
        if(item == nullptr)
            return "";
        switch (column){
            case 0: return wxString().FromUTF8(item->name);
            case 1: return wxString().FromUTF8(item->auther);
            case 2: return item->year;
            case 3: return item->pages;
            default: return "";
        }
    }
    void RefrashAfterUpdate();
    void sort_by_col(int n);
    void Add(std::string name,std::string auther,std::string year,std::string pages);
    void Remove(long index);
    long GetFirstSelectedIndex();
    void GetFromFile(const char *string);
    void GenFile(const char *string);
    void Undo(wxCommandEvent &event);
    void find(wxCommandEvent &event);
    bool find(std::string search_by);
    void Clear_search(wxCommandEvent& event);
    // ~VirtualList();
};
