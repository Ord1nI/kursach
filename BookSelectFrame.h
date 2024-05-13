#pragma once
#include <wx/wx.h>
#include "VirtualList.h"

class BookSelectFrame: public wxDialog {
        VirtualList* list;
        wxString name;
        wxString auther;
        wxString date;
        wxString pages;
public:
    BookSelectFrame(const wxString& title,VirtualList* List);
    void Insert_Book(wxCommandEvent& event);
};
