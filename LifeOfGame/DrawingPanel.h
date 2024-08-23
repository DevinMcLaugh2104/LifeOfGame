#pragma once
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

class DrawingPanel :        
    public wxPanel
{
private:

    int gridWidth{};         
    int gridHeight{};

public:

    size_t gridSize = 15;                       
    wxGraphicsContext* DPptr = nullptr;      
    std::vector<std::vector<bool>>& rGameBoard;
    DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& param);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
    void SetSize(wxSize& param);
    void SetGridSize(size_t param);
    void OnMouseEvent(wxMouseEvent& event);
};

