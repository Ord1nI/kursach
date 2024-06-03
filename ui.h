#ifndef _UI_H
#define _UI_H
#include<wx/srchctrl.h>
#include <wx/wx.h>
#include <string>
#include "VirtualList.h"
#include "BookSelectFrame.h"
#include <wx/artprov.h>
enum ToolsId {
    ATool = wxID_LAST+1,
    RTool,
    UTool,
    ITool,
};

class MyFrame : public wxFrame {
    public:
        VirtualList* IList;
        BookSelectFrame* BookSelect;
        MyFrame();
        void AddItem(const std::string &name, const std::string &auther, const std::string &date);
        void ShowBookSelectFrame(wxCommandEvent &event);
        void Remove(wxCommandEvent &event);
        void ShowInfo();
        void ShowInfo(wxCommandEvent &event);
};
class MyApp : public wxApp {

    public:
        MyFrame * m_frame;
        bool OnInit();
        // int OnExit();
        void on_close(wxCloseEvent& event);
};
#endif
