#include <wx/wx.h>
#include "ui.h"
wxIMPLEMENT_APP(App);
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
}
bool App::OnInit() {
    MainFrame* mainframe = new MainFrame("test");
    mainframe->Show();
    return true;
}
