#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :      //Frame for holding application
    public wxFrame
{
private:
   
public:
    
    DrawingPanel* drawingPanel = nullptr;
    MainWindow();
    ~MainWindow();
    void WindowResize(wxSizeEvent& event);
};

