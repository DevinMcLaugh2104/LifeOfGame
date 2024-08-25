#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::WindowResize)
EVT_MENU(TOOL_PLAY, MainWindow::OnPlay)
EVT_MENU(TOOL_PAUSE, MainWindow::OnPause)
EVT_MENU(TOOL_NEXT, MainWindow::OnNext)
EVT_MENU(TOOL_TRASH, MainWindow::OnTrash)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(200, 200))		
{
	drawingPanel = new DrawingPanel(this, gameBoard);
	InitializeGrid(gameBoard);
	InitializeStatusBar();
	InitializeToolBar();
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
void MainWindow::InitializeStatusBar()
{
	statusBar = CreateStatusBar(2);
	statusBar->SetStatusText("Generations: ", 0);
	statusBar->SetStatusText("Living Cell: ", 1);
}
void MainWindow::InitializeToolBar()
{
	toolBar = CreateToolBar(4);

	wxBitmap playIcon(play_xpm);
	toolBar->AddTool(TOOL_PLAY, "Play", playIcon);

	wxBitmap pauseIcon(pause_xpm);
	toolBar->AddTool(TOOL_PAUSE, "Pause", pauseIcon);

	wxBitmap nextIcon(next_xpm);
	toolBar->AddTool(TOOL_NEXT, "Next", nextIcon);

	wxBitmap trashIcon(trash_xpm);
	toolBar->AddTool(TOOL_TRASH, "Trash", trashIcon);

	toolBar->Realize();
}
void MainWindow::OnPlay(wxCommandEvent& event)
{

}
void MainWindow::OnPause(wxCommandEvent& event)
{

}
void MainWindow::OnNext(wxCommandEvent& event)
{

}
void MainWindow::OnTrash(wxCommandEvent& event)
{

}
size_t MainWindow::NeighborCount(size_t row, size_t column)
{
	size_t count = 0;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			size_t cellCol = column + i;
			size_t cellRow = row + j;

			if (i == 0 && j == 0)
			{
				continue;
			}

			if (cellCol == -1 || cellRow == -1)
			{
				continue;
			}

			if (cellCol >= gSize || cellRow >= gSize)
			{
				continue;
			}

			if (gameBoard[cellCol][cellRow] == true)
			{
				count++;
			}
		}
	}
	return count;
}