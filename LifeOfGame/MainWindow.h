#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :      //Frame for holding application
    public wxFrame
{
private:
   
public:
    
    DrawingPanel* drawingPanel = nullptr;
    std::vector<std::vector<bool>> gameBoard;
    size_t gSize = 15;
    MainWindow();
    ~MainWindow();
    void WindowResize(wxSizeEvent& event);
    void InitializeGrid(std::vector<std::vector<bool>> param);
};

