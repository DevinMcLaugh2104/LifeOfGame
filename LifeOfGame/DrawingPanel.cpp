#include "DrawingPanel.h"

DrawingPanel::DrawingPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(200, 200))		//drawing panel constructor
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

	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			DPptr->DrawRectangle(i*10, j*10, 10, 10);
		}
	}
	
}
