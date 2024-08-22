#include "DrawingPanel.h"

DrawingPanel::DrawingPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(200, 200))
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
}
DrawingPanel::~DrawingPanel()
{

}
void DrawingPanel::OnPaint(wxPaintEvent& event)
{
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	DPptr = wxGraphicsContext::Create(dc);
	if (!DPptr) { return; }

	DPptr->SetPen(*wxBLACK);
	DPptr->SetBrush(*wxWHITE);
	DPptr->DrawRectangle(0, 0, 10, 10);
}
