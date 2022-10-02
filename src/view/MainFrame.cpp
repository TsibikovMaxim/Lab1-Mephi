#include "MainFrame.h"

#include <wx/wx.h>
#include <wx/listbook.h>



MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	panel = new wxPanel(this);
	panel->SetBackgroundColour(*wxLIGHT_GREY);

	sorts.Add("Shacker");
	sorts.Add("Quick");
	sorts.Add("Shell");

	rbFirstSort = new wxRadioBox(panel, wxID_ANY, "Firts Sort", wxPoint(30, 20), wxDefaultSize, sorts);
	rbSecondSort = new wxRadioBox(panel, wxID_ANY, "Second Sort", wxPoint(30, 80), wxDefaultSize, sorts);
	rbSecondSort->SetSelection(1);

	txtSlider = new wxStaticText(panel, wxID_ANY, "Number of elements: ", wxPoint(30, 160), wxDefaultSize);
	slider = new wxSlider(panel, wxID_ANY, 10, 10, 10000, wxPoint(30, 180), wxSize(200, -1), wxSL_LABELS);

	btnCreate = new wxButton(panel, wxID_ANY, "Create arrays", wxPoint(250, 25), wxSize(120, -1));
	btnPrint = new wxButton(panel, wxID_ANY, "Print arrays", wxPoint(250, 55), wxSize(120, -1));
	btnSort = new wxButton(panel, wxID_ANY, "Sort arrays", wxPoint(250, 85), wxSize(120, -1));
	btnGraphs = new wxButton(panel, wxID_ANY, "Construct graphs", wxPoint(380, 25), wxSize(120, -1));

	txtPrint = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(250, 120), wxSize(550, 75), wxTE_MULTILINE);
	txtPrint->SetBackgroundColour(*wxWHITE);

	btnCreate->Bind(wxEVT_BUTTON, &MainFrame::OnCreateBtnClickedI, this);
	btnPrint->Bind(wxEVT_BUTTON, &MainFrame::OnPrintBtnClicked, this);
	btnSort->Bind(wxEVT_BUTTON, &MainFrame::OnSortBtnClicked, this);
	btnGraphs->Bind(wxEVT_BUTTON, &MainFrame::OnGraphBtnClicked, this);

	CreateStatusBar();

	chart1 = new ChartControl(panel, 121, wxPoint(30, 240), wxSize(350, 350));
	chart1->SetBackgroundColour(wxTheColourDatabase->Find("DARK GREY"));
	chart1->values = { 0.34, -0.17, 0.98, 0.33 };

	chart2 = new ChartControl(panel, wxID_ANY, wxPoint(420, 240), wxSize(350, 350));
	chart2->SetBackgroundColour(wxTheColourDatabase->Find("DARK GREY"));
	chart2->values = { 0.34, -0.17, 0.98, 0.33 };

}

void MainFrame::OnCreateBtnClickedI(wxCommandEvent& evt) {
	presenter1.createArr(slider->GetValue());
	presenter2.createArr(slider->GetValue());

	txtPrint->WriteText("Arrays were created!\n\n");
}

void MainFrame::OnPrintBtnClicked(wxCommandEvent& evt) {
	string arr1 = presenter1.getArr();
	string arr2 = presenter2.getArr();

	txtPrint->WriteText("First array: " + arr1 + "\n" + "Second array: " + arr2 + "\n\n");
}

void MainFrame::OnSortBtnClicked(wxCommandEvent& evt) {
	string time1 = presenter1.sortArr(sorts_std[rbFirstSort->GetSelection()]);
	string time2 = presenter2.sortArr(sorts_std[rbSecondSort->GetSelection()]);

	txtPrint->WriteText("Arrays were sorted!\n");
	txtPrint->WriteText("Sorting time first array: " + time1 + "\n");
	txtPrint->WriteText("Sorting time second array: " + time2 + "\n\n");
}

void MainFrame::OnGraphBtnClicked(wxCommandEvent& evt) {
	vector<double> valVec1 = presenter1.getPointForGraph(sorts_std[rbFirstSort->GetSelection()]);
	vector<double> valVec2 = presenter2.getPointForGraph(sorts_std[rbSecondSort->GetSelection()]);

	chart1 = new ChartControl(panel, 121, wxPoint(30, 240), wxSize(350, 350));
	chart1->title = sorts[rbFirstSort->GetSelection()] + " Sort";
	chart1->SetBackgroundColour(wxTheColourDatabase->Find("DARK GREY"));
	chart1->values = valVec1;
	
	chart2 = new ChartControl(panel, wxID_ANY, wxPoint(420, 240), wxSize(350, 350));
	chart2->title = sorts[rbSecondSort->GetSelection()] + " Sort";
	chart2->SetBackgroundColour(wxTheColourDatabase->Find("DARK GREY"));
	chart2->values = valVec2;
} 
