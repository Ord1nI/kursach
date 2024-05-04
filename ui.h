#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame{
    public:
        MainFrame(const wxString& title);


};
class App : public wxApp {
    public:
        bool OnInit();
};
