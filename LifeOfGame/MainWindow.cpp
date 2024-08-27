#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::WindowResize)
EVT_MENU(TOOL_PLAY, MainWindow::OnPlay)
EVT_MENU(TOOL_PAUSE, MainWindow::OnPause)
EVT_MENU(TOOL_NEXT, MainWindow::OnNext)
EVT_MENU(TOOL_TRASH, MainWindow::OnTrash)
EVT_TIMER(FUNC_TIMER, MainWindow::Timer)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(200, 200))		
{
	drawingPanel = new DrawingPanel(this, gameBoard);
	InitializeGrid(gameBoard);
	drawingPanel->SetGridSize(gSize);
	InitializeStatusBar();
	InitializeToolBar();
	timer = new wxTimer(this, FUNC_TIMER);
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
}
void MainWindow::InitializeStatusBar()
{
	statusBar = CreateStatusBar();
	UpdateStatusBar();
}
void MainWindow::UpdateStatusBar()
{
	LivingCellCount();
	std::string barInfo = "Generation: " + std::to_string(generations) + "\tLiving Cells: " + std::to_string(livingCells);
	statusBar->SetStatusText(barInfo);
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
	timer->Start(timerVar);
}
void MainWindow::OnPause(wxCommandEvent& event)
{
	timer->Stop();
}
void MainWindow::OnNext(wxCommandEvent& event)
{
	NextGeneration();
}
void MainWindow::OnTrash(wxCommandEvent& event)
{	
	timer->Stop();
	gameBoard.clear();
	InitializeGrid(gameBoard);
	generations = 0;
	UpdateStatusBar();
	Refresh();
}
size_t MainWindow::Neighbors(size_t column, size_t row)
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
void MainWindow::NextGeneration()
{
	InitializeGrid(sandBox);

	for (int i = 0; i < sandBox.size(); i++)
	{
		for (int j = 0; j < sandBox[i].size(); j++)
		{
			int neighborCount = Neighbors(i, j);

			if (gameBoard[i][j] == true && neighborCount < 2)
			{
				sandBox[i][j] = false;
			}
			if (gameBoard[i][j] == true && neighborCount > 3)
			{
				sandBox[i][j] = false;
			}
			if (gameBoard[i][j] == true && (neighborCount == 2 || neighborCount == 3))
			{
				sandBox[i][j] = true;
			}
			if (gameBoard[i][j] == false && neighborCount == 3)
			{
				sandBox[i][j] = true;
			}
		}
	}

	gameBoard.swap(sandBox);
	sandBox.clear();
	generations++;
	LivingCellCount();
	UpdateStatusBar();
	Refresh();
}
void MainWindow::LivingCellCount()
{
	size_t cells{};

	for (int i = 0; i < gameBoard.size(); i++)
	{
		for (int j = 0; j < gameBoard[i].size(); j++)
		{
			if (gameBoard[i][j] == true)
			{
				cells++;
			}
		}
	}

	livingCells = cells;
}
void MainWindow::Timer(wxTimerEvent& event)
{
	NextGeneration();
}
