#ifndef __CINT__
#include "RooGlobalFunc.h"
#include<stdio.h>
#include<string>
#include<sstream>
#include<iostream>
#include<ifstream>
#include<fstream>
#endif

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


void plotFitOn(RooPlot&, RooWorkspace&, int color = kBlue, double scale = 1.0);
RooDataSet* scaleDataSet(RooDataSet&, double);
string setType(string input);

//_____________________________________________________________________________
void 
NormalizedOverlay() 
{
  string input1;
  cout<<"Choose among the data types:"<<endl;
  cout<<"A = MC_reweighted" <<endl;
  cout<<"B = MC_notreweighted"<<endl;
  cout<<"C = Data_Regression_fixedalpha"<<endl;
  cout<<"D = Data_Regression_unfixedalpha"<<endl;
  cout<<"E = Data_noRegression"<< endl;
  cout<<"F = Data_Regression_fixedalpha_notreweighted"<<endl;
  cout<<"Choose first type" << endl;
  getline(cin,input1);
  string input2;
  cout<<"Choose second type"<< endl;
  getline(cin,input2); 
  string file1 = setType(input1);
  string file2 = setType(input2);
  ifstream rfiles("rootfiles.txt");
  ifstream outputs("outputlines.txt");

  if (!rfiles.is_open()){
    cout<<"ERROR: root files could not be opened. File does not exist"<<endl;
    exit(1);
  };
  if (!outputs.is_open()){
    cout<<"ERROR: output files could not be opened. File does not exist"<<endl;
    exit(1);
  };

  int nlines = 0;
  int noutputs = 0;
  string rootfiles[200];
  string outputlines[200];
  string rootfile;
  string outputline;

  while (true){
    getline(rfiles, rootfile);
    if (rfiles.eof()) {
      break;
    }
    rootfiles[nlines] = rootfile ;
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
  TFile *rootfile1;
  TFile *rootfile2;
  char* firstroot;
  char* secondroot;
  char* outputfile;
  char* title1 = file1.c_str();
  char* title2 = file2.c_str();
  string rfile1;
  string rfile2;
  string out;
  Double_t sum1;
  Double_t sum2;
  Double_t scale1;
  Double_t scale2;

  for (int i=0; i<nlines;i++) {
    rfile1 = file1 + rootfiles[i];
    rfile2 = file2 + rootfiles[i];
    firstroot = rfile1.c_str();
    secondroot = rfile2.c_str();
    out = file1 + "_" + file2 + outputlines[i];
    outputfile = out.c_str();
    rootfile1 = TFile::Open(firstroot);
    rootfile2 = TFile::Open(secondroot);
    
    RooWorkspace *w1 = (RooWorkspace*) rootfile1->Get("zfit");
    RooWorkspace *w2 = (RooWorkspace*) rootfile2->Get("zfit");
  
  /// Normalize to 1
  Double_t sum1 = w1->data("dataset")->sumEntries();
  Double_t sum2 = w2->data("dataset")->sumEntries();
  assert(sum2 > 0);
  Double_t scale1 = 1.0;
  Double_t scale2 = sum1 / sum2;
  // Create new canvas and plot normalized data sets and models
  TCanvas *c = new TCanvas("c", "Normalized Overlay of Invariant Mass Fits", 0,0,800,600);
  RooPlot * frame = w1->var("mass")->frame();
  frame->SetTitle("");

  TLegend *leg = new TLegend(0.60,0.8,0.9,0.95,NULL,"NDC");
  leg->SetTextSize(0.02);
  plotFitOn(*frame, *w1, kBlue, scale1, leg, title1);
  plotFitOn(*frame, *w2, kRed , scale2, leg, title2);

  frame->Draw();
  leg->Draw();
  c->Update();
  c->Print(outputfile);
  } // overlay(..)
}

//_____________________________________________________________________________
void 
plotFitOn(RooPlot &plot, RooWorkspace &w, int color, double scale, TLegend *leg, char* title) 
{
  using namespace RooFit;
  // Access the data and model from the RooWorkSpace and plot it
  RooDataSet *data = scaleDataSet(*(RooDataSet*)w.data("dataset"), scale);
  TH1 *h = new TH1F(title, title, 1,0,1);
  h->SetLineColor(color);
  data->plotOn(&plot, LineColor(color), MarkerColor(color));
  w.pdf ("model")->plotOn(&plot, LineColor(color));
  entry = leg->AddEntry(h, title, "l");
  entry->SetTextSize(0.015);
} // plotFitOn(..)


//_____________________________________________________________________________
RooDataSet* 
scaleDataSet(RooDataSet& data, double scale)
{
  // Rescale the data set
  RooFormulaVar scaleFunc("scale", Form("%g", scale), RooArgList());
  data.addColumn(scaleFunc);
  data.Print();
  RooDataSet * scaledData = new RooDataSet(data.GetName(), data.GetTitle(),
                                           &data, *data.get(), "", "scale");
  return scaledData;
}

//----------------------------------------------------------------------------------------------
// Fast method of selecting data types
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
