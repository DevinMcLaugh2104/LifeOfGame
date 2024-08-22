#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0, 0), wxSize(200, 200))		//frame constructor
{
	drawingPanel = new DrawingPanel(this);
}
MainWindow::~MainWindow()
{

}
