#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :
    public wxFrame
{
private:
   
public:
    
    DrawingPanel* drawingPanel;
    MainWindow();
    ~MainWindow();
};

