#pragma once
#include "wx/wx.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"
#include "settings.h"

class DrawingPanel :        
    public wxPanel
{
private:

    int gridWidth{};         
    int gridHeight{};

public:
                      
    wxGraphicsContext* DPptr = nullptr;      
    std::vector<std::vector<bool>>& rGameBoard;
    Settings* settings;

    DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& param, Settings* pSettings);
    ~DrawingPanel();
    void OnPaint(wxPaintEvent& event);
    void SetSize(wxSize& param);
    void SetGridSize(size_t param);
    void OnMouseEvent(wxMouseEvent& event);
    wxDECLARE_EVENT_TABLE();
};

