#pragma once
#include "wx/wx.h"
#include "MainWindow.h"

class MainApp :     
    public wxApp
{
private:

public:

    MainWindow* mainWindow;  

    MainApp();
    ~MainApp();
    virtual bool OnInit();
};

