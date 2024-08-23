#pragma once
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

class DrawingPanel :        //panel for storing cells
    public wxPanel
{
private:

    int gridWidth{};          //width and height variables
    int gridHeight{};

public:

    size_t gridSize = 15;                        //grid size variable
    wxGraphicsContext* DPptr = nullptr;       //object used for cell grid
    DrawingPanel(wxWindow* parent);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
    void SetSize(wxSize& param);
    void SetGridSize(size_t param);
};

