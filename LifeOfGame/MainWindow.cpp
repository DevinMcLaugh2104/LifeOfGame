#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(200, 200))		//frame constructor
{
	drawingPanel = new DrawingPanel(this);
	this->Bind(wxEVT_SIZE, &MainWindow::WindowResize, this);
	InitializeGrid(gameBoard);
}
MainWindow::~MainWindow()
{

}
void MainWindow::WindowResize(wxSizeEvent& event)
{
	wxSize windowSize = GetSize();
	drawingPanel->SetSize(windowSize);
	event.Skip();
}
void MainWindow::InitializeGrid(std::vector<std::vector<bool>>& param)
{
	param.resize(gSize);

	for (int i = 0; i < param.size(); i++)
	{
		param[i].resize(gSize);
	}

	drawingPanel->SetGridSize(gSize);
}