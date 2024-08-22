#pragma once
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

class DrawingPanel :
    public wxPanel
{
private:

public:

    wxGraphicsContext* DPptr;

    DrawingPanel(wxWindow* parent);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
};

