#pragma once
#include <wx/wx.h>
#include <wx/toolbar.h>
#include <string>
#include "VirtualList.h"
#include "BookSelectFrame.h"
enum ToolsId {
    ATool = wxID_LAST+1,
    RTool
};

class MyFrame : public wxFrame {
    public:
        VirtualList* IList;
        BookSelectFrame* BookSelect;
        MyFrame();
        void AddItem(const std::string &name, const std::string &auther, const std::string &date);
        void ShowBookSelectFrame(wxCommandEvent &event);
};
class MyApp : public wxApp {

    public:
        MyFrame* m_frame;
        bool OnInit();
};
class MyToolBar : public wxToolBar{
    public:
        MyToolBar(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
};
