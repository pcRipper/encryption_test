#include <wx/wx.h>
#include <GUI/General/Headers/MainWindow.h>

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainWindow* window = new MainWindow("Encryption Test");
    window->Show();

    return true;
}