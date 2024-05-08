#pragma once
#include <wx/wx.h>
#include <wx/toolbar.h>
#include <string>
enum ToolsId {
    ATool = wxID_LAST+1,
    RTool
};

class MyFrame : public wxFrame {
    wxListCtrl* m_item_list;
    public:
        MyFrame();
        void AddItem(const std::string &name, const std::string &auther, const std::string &date);
};
class MyApp : public wxApp {
    wxFrame* m_frame;

    public:
        bool OnInit();
};
class BookSelectFrame: public wxDialog {
public:
  BookSelectFrame(const wxString& title);
};
class MyToolBar {
    BookSelectFrame* BookSelect;
    public:
        wxToolBar* ToolBar;
        MyToolBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        void Actions(wxCommandEvent& event);
};
