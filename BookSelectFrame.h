#pragma once
#include <wx/wx.h>
#include "VirtualList.h"

class BookSelectFrame: public wxDialog {
        VirtualList* list;
public:
        wxString name;
        wxString auther;
        wxString date;
        wxString pages;
    BookSelectFrame(const wxString& title,VirtualList* List);
    void Insert_Book(wxCommandEvent& event);
};
