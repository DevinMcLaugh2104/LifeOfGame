#include "MainApp.h"
#include "wx/wx.h"

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
	mainWindow = new MainWindow;
	mainWindow->Show();
	return true;
}

MainApp::MainApp()
{

}
MainApp::~MainApp()
{

}

