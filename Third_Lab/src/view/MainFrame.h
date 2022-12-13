#pragma once

#include <wx/wx.h>
#include <wx/statline.h>
#include <string>
#include <iostream>

#include "../presenter/Presenter.h"

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	wxPanel * panel;
	wxTextCtrl * topsCountTxtCtrl, * arcsCountTxtCtrl, * startTopTxtCtrl, * visitTopTxtCtrl, \
		* firstTopTxtCtrl, * secondTopTxtCtrl, * txtPrint;
	wxStaticText * topicTxtStat, * topsCountTxtStat, * arcsCountTxtStat, * colorGraphTxtStat, \
		* tspTxtStat, * startTopTxtStat, * visitTopTxtStat, * findShorWayTxtStat, * firstTopTxtStat, \
		* secondTopTxtStat, * backboneTxtStat;
	wxButton * cteateGraphBtn, * colorGraphBtn, * processTspBtn, * processShortestWayBtn, * backboneBtn, \
		* clearBtn, * testsBtn, * showChartsBtn, * hideChartsBtn;
	wxStaticLine * line1, * line2, * line3, * line4, * line5;

	Presenter presenter;
	
	void OnCreateGraphBtnClicked(wxCommandEvent& evt);
	void OnColorGraphBtnClicked(wxCommandEvent& evt);
	void OnProcessTspBtnClicked(wxCommandEvent& evt);
	void OnProcessShortestWayBtnClicked(wxCommandEvent& evt);
	void OnBackboneBtnBtnClicked(wxCommandEvent& evt);
	void OnClearGraphBtnClicked(wxCommandEvent& evt);
	void OnTestsGraphBtnClicked(wxCommandEvent& evt);
	void OnShowChartsBtnClicked(wxCommandEvent& evt);
	void OnHideChartsBtnClicked(wxCommandEvent& evt);
};
