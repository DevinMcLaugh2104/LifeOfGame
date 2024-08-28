#pragma once
#include "wx/wx.h"

struct Settings
{
	int livingColorRed = 128;
	int livingColorBlue = 128;
	int livingColorGreen = 128;
	int livingColorAlpha = 255;
	int deadColorRed = 255;
	int deadColorBlue = 255;
	int deadColorGreen = 255;
	int deadColorAlpha = 255;

	int gridSize = 15;
	int timerVar = 50;

	wxColor GetLivingCellColor()
	{
		return wxColor(livingColorRed, livingColorBlue, livingColorGreen, livingColorAlpha);
	}
	wxColor GetDeadCellColor()
	{
		return wxColor(deadColorRed, deadColorBlue, deadColorGreen, deadColorAlpha);
	}
	void SetLivingCellColor(wxColor& color)
	{
		livingColorRed = color.GetRed();
		livingColorBlue = color.GetBlue();
		livingColorGreen = color.GetGreen();
		livingColorAlpha = color.GetAlpha();
	}
	void SetDeadCellColor(wxColor& color)
	{
		deadColorRed = color.GetRed();
		deadColorBlue = color.GetBlue();
		deadColorGreen = color.GetGreen();
		deadColorAlpha = color.GetAlpha();
	}
};
