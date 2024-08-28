#include "DrawingPanel.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
EVT_PAINT(DrawingPanel::OnPaint)
EVT_LEFT_UP(DrawingPanel::OnMouseEvent)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& param, Settings* pSettings) : wxPanel(parent, wxID_ANY, wxPoint(0, 0), wxSize(200, 200)), rGameBoard(param), settings(pSettings)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
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
	size_t width = panelSize.GetWidth() / settings->gridSize;
	size_t height = panelSize.GetHeight() / settings->gridSize;

	DPptr->SetPen(*wxBLACK);
	
	for (int i = 0; i < settings->gridSize; i++)
	{
		for (int j = 0; j < settings->gridSize; j++)
		{
			if (rGameBoard[i][j] == true)
			{
				DPptr->SetBrush(settings->GetLivingCellColor());
				DPptr->DrawRectangle(i * width, j * height, width, height);
			}
			else
			{
				DPptr->SetBrush(settings->GetDeadCellColor());
				DPptr->DrawRectangle(i * width, j * height, width, height);
			}
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
	settings->gridSize = param;
}
void DrawingPanel::OnMouseEvent(wxMouseEvent& event)
{
	size_t x = event.GetX();
	size_t y = event.GetY();
	wxSize panelSize = GetSize();
	size_t pointX = x * settings->gridSize / panelSize.GetWidth();
	size_t pointY = y * settings->gridSize / panelSize.GetHeight();

	if (rGameBoard[pointX][pointY] == false)
	{
		rGameBoard[pointX][pointY] = true;
	}
	else
	{
		rGameBoard[pointX][pointY] = false;
	}

	Refresh();
}