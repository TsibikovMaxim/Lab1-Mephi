#include "MainFrame.h"

#include <wx/wx.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	panel = new wxPanel(this);
	panel->SetBackgroundColour(*wxLIGHT_GREY);

	topicTxtStat = new wxStaticText(panel, wxID_ANY, "Undirected Graph", wxPoint(45, 20), wxDefaultSize);
	wxFont font = topicTxtStat->GetFont();
	font.SetPointSize(12);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	topicTxtStat->SetFont(font);

	topsCountTxtStat = new wxStaticText(panel, wxID_ANY, "Enter graph tops: ", wxPoint(30, 60), wxDefaultSize);
	topsCountTxtCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(130, 55), wxSize(80, -1));

	arcsCountTxtStat = new wxStaticText(panel, wxID_ANY, "Enter graph arcs: ", wxPoint(30, 90), wxDefaultSize);
	arcsCountTxtCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(130, 85), wxSize(80, -1));

	cteateGraphBtn = new wxButton(panel, wxID_ANY, "create Graph", wxPoint(30, 120), wxDefaultSize);
	cteateGraphBtn->SetBackgroundColour(wxColor(70, 205, 70));

	line1 = new wxStaticLine(panel, wxID_ANY, wxPoint(10, 150), wxSize(235, 5));

	//

	colorGraphTxtStat = new wxStaticText(panel, wxID_ANY, "Color Graph ", wxPoint(80, 170), wxDefaultSize);
	colorGraphTxtStat->SetFont(font);

	colorGraphBtn = new wxButton(panel, wxID_ANY, "color Graph", wxPoint(30, 210), wxDefaultSize);
	colorGraphBtn->SetBackgroundColour(wxColor(70, 205, 70));

	line2 = new wxStaticLine(panel, wxID_ANY, wxPoint(10, 240), wxSize(235, 5));

	//

	tspTxtStat = new wxStaticText(panel, wxID_ANY, "Travelling Salesman Problem", wxPoint(20, 260), wxDefaultSize);
	tspTxtStat->SetFont(font);

	startTopTxtStat = new wxStaticText(panel, wxID_ANY, "Enter top to start with: ", wxPoint(30, 300), wxDefaultSize);
	startTopTxtCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(155, 295), wxSize(30, -1));

	visitTopTxtStat = new wxStaticText(panel, wxID_ANY, "Enter tops to visit: ", wxPoint(30, 330), wxDefaultSize);
	visitTopTxtCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(130, 325), wxSize(80, -1));

	processTspBtn = new wxButton(panel, wxID_ANY, "process", wxPoint(30, 360), wxDefaultSize);
	processTspBtn->SetBackgroundColour(wxColor(70, 205, 70));

	line3 = new wxStaticLine(panel, wxID_ANY, wxPoint(10, 390), wxSize(235, 5));

	//

	findShorWayTxtStat = new wxStaticText(panel, wxID_ANY, "Find The Shortest Way", wxPoint(50, 410), wxDefaultSize);
	findShorWayTxtStat->SetFont(font);

	firstTopTxtStat = new wxStaticText(panel, wxID_ANY, "Enter top to start with: ", wxPoint(30, 450), wxDefaultSize);
	firstTopTxtCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(155, 445), wxSize(30, -1));

	secondTopTxtStat = new wxStaticText(panel, wxID_ANY, "Enter top to end with: ", wxPoint(30, 480), wxDefaultSize);
	secondTopTxtCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(155, 475), wxSize(30, -1));

	processShortestWayBtn = new wxButton(panel, wxID_ANY, "process", wxPoint(30, 510), wxDefaultSize);
	processShortestWayBtn->SetBackgroundColour(wxColor(70, 205, 70));

	line4 = new wxStaticLine(panel, wxID_ANY, wxPoint(10, 540), wxSize(235, 5));

	//
	backboneTxtStat = new wxStaticText(panel, wxID_ANY, "Find The Backbone ", wxPoint(60, 550), wxDefaultSize);
	backboneTxtStat->SetFont(font);

	backboneBtn = new wxButton(panel, wxID_ANY, "process", wxPoint(30, 575), wxDefaultSize);
	backboneBtn->SetBackgroundColour(wxColor(70, 205, 70));

	line5 = new wxStaticLine(panel, wxID_ANY, wxPoint(250, 10), wxSize(5, 580));

	// 

	txtPrint = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(270, 20), wxSize(520, 500), wxTE_MULTILINE);

	clearBtn = new wxButton(panel, wxID_ANY, "Clear", wxPoint(710, 525), wxSize(80, -1));

	testsBtn = new wxButton(panel, wxID_ANY, "show tests", wxPoint(270, 525), wxDefaultSize);
	showChartsBtn = new wxButton(panel, wxID_ANY, "show chart", wxPoint(360, 525), wxDefaultSize);
	hideChartsBtn = new wxButton(panel, wxID_ANY, "hide chart", wxPoint(360, 560), wxDefaultSize);

	//Bindings
	cteateGraphBtn->Bind(wxEVT_BUTTON, &MainFrame::OnCreateGraphBtnClicked, this);
	colorGraphBtn->Bind(wxEVT_BUTTON, &MainFrame::OnColorGraphBtnClicked, this);
	processTspBtn->Bind(wxEVT_BUTTON, &MainFrame::OnProcessTspBtnClicked, this);
	processShortestWayBtn->Bind(wxEVT_BUTTON, &MainFrame::OnProcessShortestWayBtnClicked, this);
	backboneBtn->Bind(wxEVT_BUTTON, &MainFrame::OnBackboneBtnBtnClicked, this);
	clearBtn->Bind(wxEVT_BUTTON, &MainFrame::OnClearGraphBtnClicked, this);
	testsBtn->Bind(wxEVT_BUTTON, &MainFrame::OnTestsGraphBtnClicked, this);
	showChartsBtn->Bind(wxEVT_BUTTON, &MainFrame::OnShowChartsBtnClicked, this);
	hideChartsBtn->Bind(wxEVT_BUTTON, &MainFrame::OnHideChartsBtnClicked, this);
}

void MainFrame::OnCreateGraphBtnClicked(wxCommandEvent& evt) {
	int tops = stoi(topsCountTxtCtrl->GetValue().ToStdString());
	int arcs = stoi(arcsCountTxtCtrl->GetValue().ToStdString());
	presenter.createGraph(tops, arcs);

	txtPrint->WriteText("Graph: \n" + presenter.getGraph() + "\n\n");
}

void MainFrame::OnColorGraphBtnClicked(wxCommandEvent& evt) {
	pair<string, string> pair = presenter.colorGraph();

	txtPrint->WriteText("Colored graph: \n" + pair.first + "\n");
	txtPrint->WriteText("Time to color: " + pair.second + "\n\n");
}

void MainFrame::OnProcessTspBtnClicked(wxCommandEvent& evt) {
	int begin = stoi(startTopTxtCtrl->GetValue().ToStdString()) - 1;
	string vesitTops = visitTopTxtCtrl->GetValue().ToStdString();
	
	pair<string, string> pair = presenter.tspGraph(vesitTops, begin);

	txtPrint->WriteText("TSP solution: \n" + pair.first + "\n");
	txtPrint->WriteText("Time of processing: " + pair.second + "\n\n");
}

void MainFrame::OnProcessShortestWayBtnClicked(wxCommandEvent& evt) {
	int begin = stoi(firstTopTxtCtrl->GetValue().ToStdString()) - 1;
	int end = stoi(secondTopTxtCtrl->GetValue().ToStdString()) - 1;

	pair<string, string> pair = presenter.shortestWay(begin, end);

	txtPrint->WriteText("The shortest way is: \n" + pair.first + "\n");
	txtPrint->WriteText("Time of processing: " + pair.second + "\n\n");
}

void MainFrame::OnBackboneBtnBtnClicked(wxCommandEvent& evt) {
	pair<string, string> pair = presenter.backBone();
	txtPrint->WriteText("Backbobe: \n" + pair.first + "\n");
	txtPrint->WriteText("Time of processing: " + pair.second + "\n\n");
}

void MainFrame::OnClearGraphBtnClicked(wxCommandEvent& evt) {
	txtPrint->Clear();
}

void MainFrame::OnTestsGraphBtnClicked(wxCommandEvent& evt) {
	string tests = presenter.getTests();
	txtPrint->WriteText("Tests: \n" + tests + "\n");
}

void MainFrame::OnShowChartsBtnClicked(wxCommandEvent& evt) {

}

void MainFrame::OnHideChartsBtnClicked(wxCommandEvent& evt) {

}