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
#include "TLatex.h"
#include "TCanvas.h"
#include "TROOT.h"

double getSigma(RooWorkspace &w); 
double getSigmaError(RooWorkspace &w);
string setType(string input);

//_____________________________________________________________________________
void 
Smear() 
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
  string file1 = setType(input1);
  cout<<"Choose second type" << endl;
  getline(cin,input2);
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
  };
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

  double sigmaData;
  double sigmaerrorData;
  double sigmaMC;
  double sigmaerrorMC;
  double smear;
  double smearerror;
  string outputtable = file1 + "_"+ file2 + "/smearingtable.txt"; 
  char* table = outputtable.c_str();
  char* Outfile;
  ofstream tablefile (table);

 for (int i=0; i<nlines;i++) {
   cout<< "Processing item"<< i << "/" << nlines << endl;
   rfile1 = file1 + rootfiles[i];
   rfile2 = file2 + rootfiles[i];
   firstroot = rfile1.c_str();
   secondroot = rfile2.c_str();
   cout << firstroot << endl;
   cout <<secondroot <<endl;
   Outfile = rootfiles[i].c_str();
   rootfile1 = TFile::Open(firstroot);
   rootfile2 = TFile::Open(secondroot);
   
   RooWorkspace *w1 = (RooWorkspace*) rootfile1->Get("zfit");
   RooWorkspace *w2 = (RooWorkspace*) rootfile2->Get("zfit");
   
   sigmaData = getSigma(w1);
   sigmaerrorData = getSigmaError(w1);
   sigmaMC = getSigma(w2);
   sigmaerrorMC = getSigmaError(w2);
   smear = pow (2 * (pow(sigmaData,2.0) - pow(sigmaMC,2.0)),0.5) ;
    smearerror = pow ( pow( (pow(2,.5) * sigmaData) / (pow(sigmaData,2)+pow(sigmaMC,2)) * sigmaerrorData, 2) + pow( (pow(2,.5) * sigmaMC) / (pow(sigmaData,2)+pow(sigmaMC,2)) * sigmaerrorMC, 2), 0.5);

  tablefile  << Form("%s   & $ %.3f \\pm  %.3f $ & $ %.3f \\pm %.3f $ & $ %.3f \\pm %.3f $ \\\\ \\hline \n", Outfile, sigmaData, sigmaerrorData, sigmaMC, sigmaerrorMC, smear, smearerror);
 } // overlay(..)
 tablefile.close();
}


//_____________________________________________________________________________
double getSigma(RooWorkspace *w) 
{
  using namespace RooFit;
  // Access saved Sigma CB values and error from WorkSpace
  RooRealVar *mySavedSigma = w->var("sigma_{CB}");
  RooRealVar *mySavedDeltaM = w->var("#Deltam_{CB}");
  Double_t sigma = mySavedSigma->getVal();
  Double_t sigmaerror = mySavedSigma->getError();
  Double_t DeltaM = mySavedDeltaM->getVal();
  Double_t DeltaMerror = mySavedDeltaM->getError();
  Double_t Sigpercent = 100 * sigma / (91.187 + DeltaM);
  Double_t Sigpercenterror = 100 * pow(pow(sigmaerror / (91.198 + DeltaM), 2) + pow((sigma * DeltaMerror) / pow(DeltaM + 91.198, 2), 2), .5);
  return Sigpercent;
} // plotFitOn(..)

double getSigmaError(RooWorkspace *w) 
{
  using namespace RooFit;
  // Access saved Sigma CB values and error from WorkSpace
  RooRealVar *mySavedSigma = w->var("sigma_{CB}");
  RooRealVar *mySavedDeltaM = w->var("#Deltam_{CB}");
  Double_t sigma = mySavedSigma->getVal();
  Double_t sigmaerror = mySavedSigma->getError();
  Double_t DeltaM = mySavedDeltaM->getVal();
  Double_t DeltaMerror = mySavedDeltaM->getError();
  Double_t Sigpercent = 100 * sigma / (91.187 + DeltaM);
  Double_t Sigpercenterror = 100 * pow(pow(sigmaerror / (91.198 + DeltaM), 2) + pow((sigma * DeltaMerror) / pow(DeltaM + 91.198, 2), 2), .5);
  return Sigpercenterror;
} // plotFitOn(..)


//----------------------------------------------------------------------------------------------
// Fast access to the different data types
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
