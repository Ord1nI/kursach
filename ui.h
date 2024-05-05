#pragma once
#include <wx/wx.h>
#include <string>
class MyFrame : public wxFrame {
    wxListCtrl* m_item_list;
    public:
        MyFrame();
        void AddItem(const std::string &name, const std::string &auther, const std::string &date);
};
class MyApp: public wxApp {
    wxFrame* m_frame;

    public:
        bool OnInit();
};
