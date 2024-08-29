#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(wxWindow* window) : wxDialog(window, wxID_ANY, "Settings")
{
	mainBox = new wxBoxSizer(wxVERTICAL);
	window->SetSizer(mainBox);

	child1 = new wxBoxSizer(wxHORIZONTAL);
	child2 = new wxBoxSizer(wxHORIZONTAL);

	control1 = new wxStaticText(this, wxID_ANY, "Text1");
	control2 = new wxStaticText(this, wxID_ANY, "Text2");

	spinCtrl = new wxSpinCtrl(this, SPIN);
	colorPicker = new wxColourPickerCtrl(this, COLOR_PICKER);
	
	okCancel = CreateButtonSizer(wxOK | wxCANCEL);

	child1->Add(control1);
	child2->Add(control2);

	child1->Add(spinCtrl);
	child2->Add(colorPicker);

	mainBox->Add(child1);
	mainBox->Add(child2);
	
}