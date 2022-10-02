#pragma once
#include "chart/Chartcontrol.h"
#include "../presenter/Presenter.h"

#include <wx/wx.h>



class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	wxTextCtrl* txtPrint;
	wxStaticText* txtSlider;
	wxPanel* panel;
	ChartControl* chart1, * chart2;
	wxRadioBox* rbFirstSort, * rbSecondSort;
	wxSlider* slider;
	wxButton* btnPrint, * btnSort, * btnGraphs, * btnCreate;
	wxArrayString sorts;
	string sorts_std[3] = {"Shacker", "Quick", "Shell"};
	Presenter presenter1, presenter2;
	void OnCreateBtnClickedI(wxCommandEvent& evt);
	void OnPrintBtnClicked(wxCommandEvent& evt);
	void OnSortBtnClicked(wxCommandEvent& evt);
	void OnGraphBtnClicked(wxCommandEvent& evt);
};
