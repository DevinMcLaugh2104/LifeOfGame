#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"

enum IDs
{
    TOOL_PLAY = 1000,
    TOOL_PAUSE = 1100,
    TOOL_NEXT = 1200, 
    TOOL_TRASH = 1300,
};

class MainWindow :      //Frame for holding application
    public wxFrame
{
private:
    size_t generations{};
    size_t livingCells{};

public:

    DrawingPanel* drawingPanel = nullptr;
    std::vector<std::vector<bool>> gameBoard;
    size_t gSize = 15;
    wxStatusBar* statusBar;
    wxToolBar* toolBar;
    

    MainWindow();
    ~MainWindow();
    void WindowResize(wxSizeEvent& event);
    void InitializeGrid(std::vector<std::vector<bool>>& param);
    void InitializeStatusBar();
    void InitializeToolBar();
    void OnPlay(wxCommandEvent& event);
    void OnPause(wxCommandEvent& event);
    void OnNext(wxCommandEvent& event);
    void OnTrash(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

 