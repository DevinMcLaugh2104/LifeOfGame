#pragma once
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

class DrawingPanel :        //panel for storing cells
    public wxPanel
{
private:

    int gridSize = 15;      //grid size variable
    int gridWidth;          //width and height variables
    int gridHeight;

public:

    wxGraphicsContext* DPptr;       //object used for cell grid

    DrawingPanel(wxWindow* parent);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
};

