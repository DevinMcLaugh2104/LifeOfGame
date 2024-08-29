#pragma once
#include "wx/wx.h"
#include "wx/spinctrl.h"
#include "wx/clrpicker.h"

enum IDs
{
    SPIN = 2000,
    COLOR_PICKER = 2010
};

class SettingsDialog :
    public wxDialog
{
private:

public:

    wxBoxSizer* mainBox;
    wxBoxSizer* child1;
    wxBoxSizer* child2;
    wxStaticText* control1;
    wxStaticText* control2;
    wxSpinCtrl* spinCtrl;
    wxColourPickerCtrl* colorPicker;
    wxSizer* okCancel;

    SettingsDialog(wxWindow* window);
};


