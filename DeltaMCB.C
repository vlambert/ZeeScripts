#ifndef __CINT__
#include "RooGlobalFunc.h"
#include<stdio.h>
#include<string>
#include<sstream>
#include<iostream>
#include<ifstream>
#include<fstream>
#endif

#include "TH1.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "TFile.h"
#include "RooWorkspace.h"
#include "RooAbsPdf.h"
#include "RooFormulaVar.h"
#include "RooArgSet.h"
#include "RooArgList.h"
#include "RooRealVar.h"
#include "TROOT.h"
#include "TStyle.h"


void FillHistogram(TH1F &histo, RooWorkspace &w, char* bin); 
string setType(string input);

//_____________________________________________________________________________
void 
DeltaMCB() 
{
  string input1;
  string input2;
  cout<<"Choose among the data types:"<<endl;
  cout<<"A = MC_reweighted" <<endl;
  cout<<"B = MC_notreweighted"<<endl;
  cout<<"C = Data_Regression_fixedalpha"<<endl;
  cout<<"D = Data_Regression_unfixedalpha"<<endl;
  cout<<"E = Data_noRegression"<< endl;
  cout<<"F = Data_Regression_fixedalpha_notreweighted"<<endl;
  cout<<"Choose first type" << endl;
  getline(cin,input1);
  string type1 = setType(input1);
  cout<<"Choose second type" << endl;
  getline(cin,input2);
  string type2 = setType(input2);

  // text files containing the names of the root files, output names, upper y axis limit and lower y axis limits respectively
  ifstream cutfiles("cutfiles.txt");
  ifstream outputs("scalehistolines.txt");
  ifstream Axes("MCaxesDeltaMupper.txt");
  ifstream lowerAxes("MCaxesDeltaM.txt");
  if (!cutfiles.is_open()){
    cout<<"ERROR: cut files could not be opened. File does not exist"<<endl;
    exit(1);
  };
  if (!outputs.is_open()){
    cout<<"ERROR: Outputs could not be opened. File does not exist"<<endl;
    exit(1);
  };
  if (!Axes.is_open()){
    cout<<"ERROR: Upper Axes could not be opened. File does not exist"<<endl;
    exit(1);
  };
  if (!lowerAxes.is_open()){
    cout<<"ERROR: Lower Axes could not be opened. File does not exist"<<endl;
    exit(1);
  };
  int nloweraxes = 0;
  int naxes = 0;
  int nlines = 0;
  int noutputs = 0;
  string cfiles[200];
  string outputlines[200];
  string axeslines[200];
  string loweraxes[200];
  string loweraxis;
  string rootfile;
  string outputline;
  string axesline;
  while (true){
    getline(Axes, axesline);
    if (Axes.eof()) {
      break;
    }
    axeslines[naxes] = axesline ;
    naxes++;
  };
  while (true){
    getline(lowerAxes, loweraxis);
    if (lowerAxes.eof()) {
      break;
    }
    loweraxes[nloweraxes] = loweraxis ;
    nloweraxes++;
  };
  while (true){
    getline(cutfiles, rootfile);
    if (cutfiles.eof()) {
      break;
    }
    cfiles[nlines] = rootfile ;
    nlines++;
  }
  while (true){
    getline(outputs, outputline);
    if (outputs.eof()) {
      break;
    }
    outputlines[noutputs] = outputline ;
    noutputs++;
  }
  assert (nlines == noutputs);
  assert (nlines == naxes);
  assert (naxes == nloweraxes);
  TFile *rootfiletight1;
  TFile *rootfilemva1;
  TFile *rootfilemvatight1;
  TFile *rootfiletight2;
  TFile *rootfilemva2;
  TFile *rootfilemvatight2;
  char* tightfile1;
  char* mvafile1;
  char* mvatightfile1;
  char* tightfile2;
  char* mvafile2;
  char* mvatightfile2;
  char* outputfile;
  string rfile1;
  string rfile2;
  string rfile3;

  string rfile4;
  string rfile5;
  string rfile6;

  string out;
  Double_t max;
  Double_t min;

  for (int i=0; i<nlines;i++) {
    rfile1 = type1 + "/tight" + cfiles[i];
    rfile2 = type1 + "/mva" + cfiles[i];
    rfile3 = type1 + "/mvat" + cfiles[i];
    tightfile1 = rfile1.c_str();
    mvafile1 = rfile2.c_str();
    mvatightfile1 = rfile3.c_str();

    rfile4 = type2 + "/tight" + cfiles[i];
    rfile5 = type2 + "/mva" + cfiles[i];
    rfile6 = type2 + "/mvat" + cfiles[i];
    tightfile2 = rfile4.c_str();
    mvafile2 = rfile5.c_str();
    mvatightfile2 = rfile6.c_str();

    out = type1 + "_" + type2 + outputlines[i];
    outputfile = out.c_str();

    rootfiletight1 = TFile::Open(tightfile1);
    rootfilemva1 = TFile::Open(mvafile1);
    rootfilemvatight1 = TFile::Open(mvatightfile1);

    rootfiletight2 = TFile::Open(tightfile2);
    rootfilemva2 = TFile::Open(mvafile2);
    rootfilemvatight2 = TFile::Open(mvatightfile2);
    // Type 1 RooWorkSpaces
    RooWorkspace *w1 = (RooWorkspace*) rootfiletight1->Get("zfit");
    RooWorkspace *w2 = (RooWorkspace*) rootfilemva1->Get("zfit");
    RooWorkspace *w3 = (RooWorkspace*) rootfilemvatight1->Get("zfit");
    // Type 2 RooWorkSpaces
    RooWorkspace *w4 = (RooWorkspace*) rootfiletight2->Get("zfit");
    RooWorkspace *w5 = (RooWorkspace*) rootfilemva2->Get("zfit");
    RooWorkspace *w6 = (RooWorkspace*) rootfilemvatight2->Get("zfit");
  
    //Create new canvas to plot the Sigma values with error bars by cut
    TCanvas *c = new TCanvas("c", "Normalized Overlay of Invariant Mass Fits", 0,0,800,600);
    TH1F *Overlays1 = new TH1F ("Electron Cuts", "", 3, 0, 4);
    FillHistogram(Overlays1, w1, 1.0);
    FillHistogram(Overlays1, w2, 2.0);
    FillHistogram(Overlays1, w3, 3.0);
    Overlays1->GetXaxis()->SetBinLabel(1,"Tight");
    Overlays1->GetXaxis()->SetBinLabel(2,"MVA");
    Overlays1->GetXaxis()->SetBinLabel(3,"MVA + Tight");
    Overlays1->GetXaxis()->SetLabelSize(0.05);
    Overlays1->GetYaxis()->SetLabelSize(0.04);
    //max = Overlays1->GetBinContent(Overlays1->GetMaximumBin());
    //min = Overlays1->GetBinContent(Overlays1->GetMinimumBin());
    max = atof(axeslines[i].c_str());
    min = atof(loweraxes[i].c_str());
    Overlays1->GetYaxis()->SetRangeUser(min, max); 
    Overlays1->SetBarWidth(0.2);
    
    TH1F *Overlays1 = new TH1F ("Electron Cuts", "", 3, 0, 4);
    FillHistogram(Overlays, w4, 1.0);
    FillHistogram(Overlays, w5, 2.0);
    FillHistogram(Overlays, w6, 3.0);
    Overlays2->GetXaxis()->SetBinLabel(1,"Tight");
    Overlays2->GetXaxis()->SetBinLabel(2,"MVA");
    Overlays2->GetXaxis()->SetBinLabel(3,"MVA + Tight");
    Overlays2->GetXaxis()->SetLabelSize(0.05);
    Overlays2->GetYaxis()->SetLabelSize(0.04);
    Overlays2->GetYaxis()->SetRangeUser(min, max); 
    Overlays2->SetBarWidth(0.2);
    
    
    Overlays1->GetXaxis()->SetTitle("Electron ID Cuts");
    Overlays1->GetXaxis()->SetTitleSize(0.05);
    Overlays1->GetYaxis()->SetTitle("\Delta M_{CB} (GeV)/c^{2}");
    Overlays1->GetYaxis()->SetTitleSize(0.05);

    Overlays2->GetXaxis()->SetTitle("Electron ID Cuts");
    Overlays2->GetXaxis()->SetTitleSize(0.05);
    Overlays2->GetYaxis()->SetTitle("\Delta M_{CB} (GeV)/c^{2}");
    Overlays2->GetYaxis()->SetTitleSize(0.05);
    
    Overlays1->SetLineColor(kBlack);
    Overlays1->SetLineColor(kBlue);
    
    Overlays1->Draw();
    Overlays1->Draw("same");
    
    TLegend *leg = new TLegend(0.6, 0.8, 0.9, 0.95);
    leg->SetTextSize(0.02);
    leg->AddEntry(Overlays1, "2012 Data ", "l");
    leg-> AddEntry(Overlays2,"2012 Monte Carlo", "l");
    leg->Draw();
    
    c->Update();
    c->Print(outputfile);
  } // overlay(..)
}

//_____________________________________________________________________________
void FillHistogram(TH1F *histo, RooWorkspace *w, Double_t bin) 
{
  using namespace RooFit;
  // Access Delta M for Crystal Ball from WorkSpace and plot value with error bar
  // "#Deltam_{CB}" can be switched to "\Sigma_{CB}" to plot the Crystal Ball sigma values
  RooRealVar *mySavedDeltaM = w->var("#Deltam_{CB}");
  Double_t DeltaM = mySavedDeltaM->getVal();
  Double_t DeltaMerror = mySavedDeltaM->getError();
  histo->Fill(bin,DeltaM); 
  histo->SetBinError(bin,DeltaMerror);
} // plotFitOn(..)


//----------------------------------------------------------------------------------------------
// Faster access to data types
string setType(string input) {
  string output;
  if (input == "A") {
    output = "MC_reweighted";
  }
  else if (input == "B") {
    output = "MC_notreweighted";
  }
  else if (input == "C") {
    output = "Data_Regression_fixedalpha";
  }
  else if (input == "D") {
    output = "Data_Regression_unfixedalpha";
  }
  else if (input == "E") {
    output = "Data_noRegression";
  }
  else if (input == "F") {
    output = "Data_Regression_fixedalpha_notreweighted";
  }
  else 
    cout<<"ERROR: Not a recognized file"<<endl;
  return output;
}
