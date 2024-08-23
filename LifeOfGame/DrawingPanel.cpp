#include "DrawingPanel.h"

DrawingPanel::DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& param) : wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(200, 200)), rGameBoard(param)		//drawing panel constructor
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
	this->Bind(wxEVT_LEFT_UP, &DrawingPanel::OnMouseEvent, this);
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

	wxSize panelSize = GetSize();
	int width = panelSize.GetWidth() / gridSize;
	int height = panelSize.GetHeight() / gridSize;

	DPptr->SetPen(*wxBLACK);
	DPptr->SetBrush(*wxWHITE);

	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			DPptr->DrawRectangle(i * width, j * height, width, height);
		}
	}
}
void DrawingPanel::SetSize(wxSize& param)
{
	wxPanel::SetSize(param);
	Refresh();
}
void DrawingPanel::SetGridSize(size_t param)
{
	gridSize = param;
}
void DrawingPanel::OnMouseEvent(wxMouseEvent& event)
{
	size_t x = event.GetX();
	size_t y = event.GetY();
	wxSize panelSize = GetSize();
	size_t cellWidth = panelSize.GetWidth();
	size_t cellHeight = panelSize.GetHeight();

	size_t pointX = x / cellWidth;
	size_t pointY = y / cellHeight;

	if (rGameBoard[pointX][pointY] == false)
	{
		rGameBoard[pointX][pointY] == true;
	}
	else
	{
		rGameBoard[pointX][pointY] == false;
	}

	Refresh();

}