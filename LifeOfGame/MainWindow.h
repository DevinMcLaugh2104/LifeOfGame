#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"



class MainWindow :      //Frame for holding application
    public wxFrame
{
private:
    size_t generations{};
    size_t livingCells{};

public:
    wxStatusBar* statusBar;
    DrawingPanel* drawingPanel = nullptr;
    std::vector<std::vector<bool>> gameBoard;
    size_t gSize = 15;
    

    MainWindow();
    ~MainWindow();
    void WindowResize(wxSizeEvent& event);
    void InitializeGrid(std::vector<std::vector<bool>>& param);
    wxDECLARE_EVENT_TABLE();
};

