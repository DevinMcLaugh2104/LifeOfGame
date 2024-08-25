#pragma once
#include "wx/wx.h"
#include "MainWindow.h"

class MainApp :     //Main app class for starting application
    public wxApp
{
private:

public:

    MainWindow* mainWindow;  //main window object for frame

    MainApp();
    ~MainApp();
    virtual bool OnInit();
};

