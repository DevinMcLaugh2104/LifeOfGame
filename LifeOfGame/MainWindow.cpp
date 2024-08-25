#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::WindowResize)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(200, 200))		//frame constructor
{
	statusBar = CreateStatusBar(2);
	statusBar->SetStatusText("Generations: ", 0);
	statusBar->SetStatusText("Living Cell: ", 1);
	drawingPanel = new DrawingPanel(this, gameBoard);
	InitializeGrid(gameBoard);
	this->Layout();
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