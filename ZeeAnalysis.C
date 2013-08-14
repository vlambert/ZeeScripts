//=======================================================================//
//  For CMS ECAL Detector at the LHC, 2012                               //
//  Macro for Comparing MVA IDs and Electron Cuts                        //
//  within bins of r9 and eta                                            //
//                                                                       //
//  Valere Lambert                                                       // 
//=======================================================================//

#include<stdio.h>
#include<TH1.h>
#include<TFile.h>
#include<set>
#include "HggReduce.C"

void ZeeAnalysis()
{
  gROOT->SetStyle("Plain");
  gStyle -> SetTitleStyle(0000);
  
  //==================== Set Up Files and Data Chain ======================
  // Create and open text files to output and save Z masses
  FILE* Znc;
  FILE* Zt;
  FILE* Zmva;
  FILE* Zmvat;
  Znc   = fopen("text-files/Znc.txt", "w+");   // Uncut Z Peak
  Zt    = fopen("text-files/Zt.txt", "w+");    // Z Peak with Tight Cuts
  Zmva  = fopen("text-files/Zmva.txt", "w+");  // Z Peak with MVA ID Cuts
  Zmvat = fopen("text-files/Zmvat.txt", "w+"); // Z Peak with Both Tight and MVA ID Cuts

  // ==================================================================== //
  //                         * Electron ID Cuts *                         //
  //                                                                      //
  // Loose Cuts : WP 90, Theoretical 90% Cut Efficiency for Electrons     //
  // Tight Cuts : WP 70, Theoretical 70% Cut Efficiency for Electrons     //
  // MVA ID Cut : Multivariant Analysis Marker for Electron Validity      //
  //                                                                      //
  //              *  Detector Regions and R9 Categories  *                //
  //                                                                      //
  //               CB == Center Barrel            eta < 1.0               //
  //               OB == Outer Barrel       1.0 < eta < 1.44              //
  //               IC == Inner End Cap      1.5 < eta < 2.0               //
  //               OC == Outer End Cap      2.0 < eta < 2.5               //
  //                                                                      //
  //               L  == Low  R9               R9 < 0.94                  // 
  //               H  == High R9               R9 > 0.94                  //
  // ==================================================================== //

  // Tight Cut Z Files
  FILE* tightCBCBLL;
  FILE* tightCBCBLH;
  FILE* tightCBCBHH;
  FILE* tightOBOBLL;
  FILE* tightOBOBLH;
  FILE* tightOBOBHH;
  FILE* tightICICLL;
  FILE* tightICICLH;
  FILE* tightICICHH;
  FILE* tightOCOCLL;
  FILE* tightOCOCLH;
  FILE* tightOCOCHH;

  FILE* tightCBOBLL;
  FILE* tightCBOBLH;
  FILE* tightCBOBHH;
  FILE* tightCBICLL;
  FILE* tightCBICLH;
  FILE* tightCBICHH;
  FILE* tightCBOCLL;
  FILE* tightCBOCLH;
  FILE* tightCBOCHH;

  FILE* tightOBICLL;
  FILE* tightOBICLH;
  FILE* tightOBICHH;
  FILE* tightOBOCLL;
  FILE* tightOBOCLH;
  FILE* tightOBOCHH;

  FILE* tightICOCLL;
  FILE* tightICOCLH;
  FILE* tightICOCHH;

  tightCBCBLL = fopen("text-files/tightCBCBLL.txt","w+");
  tightCBCBLH = fopen("text-files/tightCBCBLH.txt","w+");
  tightCBCBHH = fopen("text-files/tightCBCBHH.txt","w+");
  tightOBOBLL = fopen("text-files/tightOBOBLL.txt","w+");
  tightOBOBLH = fopen("text-files/tightOBOBLH.txt","w+");
  tightOBOBHH = fopen("text-files/tightOBOBHH.txt","w+");
  tightICICLL = fopen("text-files/tightICICLL.txt","w+");
  tightICICLH = fopen("text-files/tightICICLH.txt","w+");
  tightICICHH = fopen("text-files/tightICICHH.txt","w+");
  tightOCOCLL = fopen("text-files/tightOCOCLL.txt","w+");
  tightOCOCLH = fopen("text-files/tightOCOCLH.txt","w+");
  tightOCOCHH = fopen("text-files/tightOCOCHH.txt","w+");
  
  tightCBOBLL = fopen("text-files/tightCBOBLL.txt","w+");
  tightCBOBLH = fopen("text-files/tightCBOBLH.txt","w+");
  tightCBOBHH = fopen("text-files/tightCBOBHH.txt","w+");
  tightCBICLL = fopen("text-files/tightCBICLL.txt","w+");
  tightCBICLH = fopen("text-files/tightCBICLH.txt","w+");
  tightCBICHH = fopen("text-files/tightCBICHH.txt","w+");
  tightCBOCLL = fopen("text-files/tightCBOCLL.txt","w+");
  tightCBOCLH = fopen("text-files/tightCBOCLH.txt","w+");
  tightCBOCHH = fopen("text-files/tightCBOCHH.txt","w+");

  tightOBICLL = fopen("text-files/tightOBICLL.txt","w+");
  tightOBICLH = fopen("text-files/tightOBICLH.txt","w+");
  tightOBICHH = fopen("text-files/tightOBICHH.txt","w+");
  tightOBOCLL = fopen("text-files/tightOBOCLL.txt","w+");
  tightOBOCLH = fopen("text-files/tightOBOCLH.txt","w+");
  tightOBOCHH = fopen("text-files/tightOBOCHH.txt","w+");
  
  tightICOCLL = fopen("text-files/tightICOCLL.txt","w+");
  tightICOCLH = fopen("text-files/tightICOCLH.txt","w+");
  tightICOCHH = fopen("text-files/tightICOCHH.txt","w+");
  
  // MVA ID Cut Z Files
  FILE* mvaCBCBLL;
  FILE* mvaCBCBLH;
  FILE* mvaCBCBHH;
  FILE* mvaOBOBLL;
  FILE* mvaOBOBLH;
  FILE* mvaOBOBHH;
  FILE* mvaICICLL;
  FILE* mvaICICLH;
  FILE* mvaICICHH;
  FILE* mvaOCOCLL;
  FILE* mvaOCOCLH;
  FILE* mvaOCOCHH;

  FILE* mvaCBOBLL;
  FILE* mvaCBOBLH;
  FILE* mvaCBOBHH;
  FILE* mvaCBICLL;
  FILE* mvaCBICLH;
  FILE* mvaCBICHH;
  FILE* mvaCBOCLL;
  FILE* mvaCBOCLH;
  FILE* mvaCBOCHH;

  FILE* mvaOBICLL;
  FILE* mvaOBICLH;
  FILE* mvaOBICHH;
  FILE* mvaOBOCLL;
  FILE* mvaOBOCLH;
  FILE* mvaOBOCHH;

  FILE* mvaICOCLL;
  FILE* mvaICOCLH;
  FILE* mvaICOCHH;

  mvaCBCBLL = fopen("text-files/mvaCBCBLL.txt","w+");
  mvaCBCBLH = fopen("text-files/mvaCBCBLH.txt","w+");
  mvaCBCBHH = fopen("text-files/mvaCBCBHH.txt","w+");
  mvaOBOBLL = fopen("text-files/mvaOBOBLL.txt","w+");
  mvaOBOBLH = fopen("text-files/mvaOBOBLH.txt","w+");
  mvaOBOBHH = fopen("text-files/mvaOBOBHH.txt","w+");
  mvaICICLL = fopen("text-files/mvaICICLL.txt","w+");
  mvaICICLH = fopen("text-files/mvaICICLH.txt","w+");
  mvaICICHH = fopen("text-files/mvaICICHH.txt","w+");
  mvaOCOCLL = fopen("text-files/mvaOCOCLL.txt","w+");
  mvaOCOCLH = fopen("text-files/mvaOCOCLH.txt","w+");
  mvaOCOCHH = fopen("text-files/mvaOCOCHH.txt","w+");
  
  mvaCBOBLL = fopen("text-files/mvaCBOBLL.txt","w+");
  mvaCBOBLH = fopen("text-files/mvaCBOBLH.txt","w+");
  mvaCBOBHH = fopen("text-files/mvaCBOBHH.txt","w+");
  mvaCBICLL = fopen("text-files/mvaCBICLL.txt","w+");
  mvaCBICLH = fopen("text-files/mvaCBICLH.txt","w+");
  mvaCBICHH = fopen("text-files/mvaCBICHH.txt","w+");
  mvaCBOCLL = fopen("text-files/mvaCBOCLL.txt","w+");
  mvaCBOCLH = fopen("text-files/mvaCBOCLH.txt","w+");
  mvaCBOCHH = fopen("text-files/mvaCBOCHH.txt","w+");

  mvaOBICLL = fopen("text-files/mvaOBICLL.txt","w+");
  mvaOBICLH = fopen("text-files/mvaOBICLH.txt","w+");
  mvaOBICHH = fopen("text-files/mvaOBICHH.txt","w+");
  mvaOBOCLL = fopen("text-files/mvaOBOCLL.txt","w+");
  mvaOBOCLH = fopen("text-files/mvaOBOCLH.txt","w+");
  mvaOBOCHH = fopen("text-files/mvaOBOCHH.txt","w+");
  
  mvaICOCLL = fopen("text-files/mvaICOCLL.txt","w+");
  mvaICOCLH = fopen("text-files/mvaICOCLH.txt","w+");
  mvaICOCHH = fopen("text-files/mvaICOCHH.txt","w+");

  // MVA and Tight Cut Z Files
  FILE* mvatCBCBLL;
  FILE* mvatCBCBLH;
  FILE* mvatCBCBHH;
  FILE* mvatOBOBLL;
  FILE* mvatOBOBLH;
  FILE* mvatOBOBHH;
  FILE* mvatICICLL;
  FILE* mvatICICLH;
  FILE* mvatICICHH;
  FILE* mvatOCOCLL;
  FILE* mvatOCOCLH;
  FILE* mvatOCOCHH;

  FILE* mvatCBOBLL;
  FILE* mvatCBOBLH;
  FILE* mvatCBOBHH;
  FILE* mvatCBICLL;
  FILE* mvatCBICLH;
  FILE* mvatCBICHH;
  FILE* mvatCBOCLL;
  FILE* mvatCBOCLH;
  FILE* mvatCBOCHH;

  FILE* mvatOBICLL;
  FILE* mvatOBICLH;
  FILE* mvatOBICHH;
  FILE* mvatOBOCLL;
  FILE* mvatOBOCLH;
  FILE* mvatOBOCHH;

  FILE* mvatICOCLL;
  FILE* mvatICOCLH;
  FILE* mvatICOCHH;

  mvatCBCBLL = fopen("text-files/mvatCBCBLL.txt","w+");
  mvatCBCBLH = fopen("text-files/mvatCBCBLH.txt","w+");
  mvatCBCBHH = fopen("text-files/mvatCBCBHH.txt","w+");
  mvatOBOBLL = fopen("text-files/mvatOBOBLL.txt","w+");
  mvatOBOBLH = fopen("text-files/mvatOBOBLH.txt","w+");
  mvatOBOBHH = fopen("text-files/mvatOBOBHH.txt","w+");
  mvatICICLL = fopen("text-files/mvatICICLL.txt","w+");
  mvatICICLH = fopen("text-files/mvatICICLH.txt","w+");
  mvatICICHH = fopen("text-files/mvatICICHH.txt","w+");
  mvatOCOCLL = fopen("text-files/mvatOCOCLL.txt","w+");
  mvatOCOCLH = fopen("text-files/mvatOCOCLH.txt","w+");
  mvatOCOCHH = fopen("text-files/mvatOCOCHH.txt","w+");
  
  mvatCBOBLL = fopen("text-files/mvatCBOBLL.txt","w+");
  mvatCBOBLH = fopen("text-files/mvatCBOBLH.txt","w+");
  mvatCBOBHH = fopen("text-files/mvatCBOBHH.txt","w+");
  mvatCBICLL = fopen("text-files/mvatCBICLL.txt","w+");
  mvatCBICLH = fopen("text-files/mvatCBICLH.txt","w+");
  mvatCBICHH = fopen("text-files/mvatCBICHH.txt","w+");
  mvatCBOCLL = fopen("text-files/mvatCBOCLL.txt","w+");
  mvatCBOCLH = fopen("text-files/mvatCBOCLH.txt","w+");
  mvatCBOCHH = fopen("text-files/mvatCBOCHH.txt","w+");

  mvatOBICLL = fopen("text-files/mvatOBICLL.txt","w+");
  mvatOBICLH = fopen("text-files/mvatOBICLH.txt","w+");
  mvatOBICHH = fopen("text-files/mvatOBICHH.txt","w+");
  mvatOBOCLL = fopen("text-files/mvatOBOCLL.txt","w+");
  mvatOBOCLH = fopen("text-files/mvatOBOCLH.txt","w+");
  mvatOBOCHH = fopen("text-files/mvatOBOCHH.txt","w+");
  
  mvatICOCLL = fopen("text-files/mvatICOCLL.txt","w+");
  mvatICOCLH = fopen("text-files/mvatICOCLH.txt","w+");
  mvatICOCHH = fopen("text-files/mvatICOCHH.txt","w+");

  //========================== Access Root Tree ===============================//
  // Create a chain of root files for ntuple
  TChain *chain = loadList("2012data.list", "ZeeOutput");
  
  cout << "chain made" << endl;
     
  //==========================  Create histograms  ============================//

  // MVA ID marker on non-triggering Electrons.
  TH1F *mvanontrignocut = new TH1F ("MVA no Cuts", "Non-triggering Electron MVA ID with no Cuts", 300,-1.1,1.1);
  TH1F *mvanontrigcut = new TH1F ("MVA w Tight Cuts", "Non-triggering Electron MVA ID with Tight Cuts", 300, -1.1, 1.1);
  TH1F *Znocut = new TH1F ("Z wout cuts", "Z masses With no Cuts", 300, 50, 120);
  TH1F *Zcut = new TH1F ("Z w cuts no MVA", "Z masses Tight Cuts", 300, 50, 120);
  TH1F *Zmvanontrignocut = new TH1F ("Z w MVA", "Z masses, Non-Triggering MVA With no Cuts", 300, 50, 120);
  TH1F *Zmvanontrigcut = new TH1F ("Z w MVA + Tight Cuts", "Z masses, Non-Triggering Electron MVA ID+ Tight Cuts", 300, 50, 120);


  // Zs with Tight cuts by R9 and Location within ECAL Detector
  TH1F *TightCBCBLL = new TH1F ("Tight CBCBLL", "R9: Low / Low, Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *TightCBCBLH = new TH1F ("Tight CBCBLH", "R9: High / Low , Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *TightCBCBHH = new TH1F ("Tight CBCBHH", " R9: High / High , Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *TightOBOBLL = new TH1F ("Tight OBOBLL", "R9: Low / Low, Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *TightOBOBLH = new TH1F ("Tight OBOBLH", "R9: High / Low , Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *TightOBOBHH = new TH1F ("Tight OBOBHH", " R9: High / High , Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *TightICICLL = new TH1F ("Tight ICICLL", "R9: Low / Low, Inner Cap / Inner Cap", 300,50,120);
  TH1F *TightICICLH = new TH1F ("Tight ICICLH", "R9: High / Low , Inner Cap / Inner Cap", 300,50,120);
  TH1F *TightICICHH = new TH1F ("Tight ICICHH", " R9: High / High , Inner Cap / Inner Cap", 300,50,120);
  TH1F *TightOCOCLL = new TH1F ("Tight OCOCLL", "R9: Low / Low, Outer Cap / Outer Cap", 300,50,120);
  TH1F *TightOCOCLH = new TH1F ("Tight OCOCLH", "R9: High / Low , Outer Cap / Outer Cap", 300,50,120);
  TH1F *TightOCOCHH = new TH1F ("Tight OCOCHH", " R9: High / High , Outer Cap / Outer Cap", 300,50,120);

  TH1F *TightCBOBLL = new TH1F ("Tight CBOBLL", "R9: Low / Low, Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *TightCBOBLH = new TH1F ("Tight CBOBLH", "R9: High / Low , Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *TightCBOBHH = new TH1F ("Tight CBOBHH", " R9: High / High , Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *TightCBICLL = new TH1F ("Tight CBICLL", "R9: Low / Low, Inner Barrel / Inner Cap", 300,50,120);
  TH1F *TightCBICLH = new TH1F ("Tight CBICLH", "R9: High / Low , Inner Barrel / Inner Cap", 300,50,120);
  TH1F *TightCBICHH = new TH1F ("Tight CBICHH", " R9: High / High , Inner Barrel / Inner Cap", 300,50,120);
  TH1F *TightCBOCLL = new TH1F ("Tight CBOCLL", "R9: Low / Low, Inner Barrel / Outer Cap", 300,50,120);
  TH1F *TightCBOCLH = new TH1F ("Tight CBOCLH", "R9: High / Low , Inner Barrel / Outer Cap", 300,50,120);
  TH1F *TightCBOCHH = new TH1F ("Tight CBOCHH", " R9: High / High , Inner Barrel / Outer Cap", 300,50,120);

  TH1F *TightOBICLL = new TH1F ("Tight OBICLL", "R9: Low / Low, Outer Barrel / Inner Cap", 300,50,120);
  TH1F *TightOBICLH = new TH1F ("Tight OBICLH", "R9: High / Low , Outer Barrel / Inner Cap", 300,50,120);
  TH1F *TightOBICHH = new TH1F ("Tight OBICHH", " R9: High / High , Outer Barrel / Inner Cap", 300,50,120);
  TH1F *TightOBOCLL = new TH1F ("Tight OBOCLL", "R9: Low / Low, Outer Barrel / Outer Cap", 300,50,120);
  TH1F *TightOBOCLH = new TH1F ("Tight OBOCLH", "R9: High / Low , Outer Barrel / Outer Cap", 300,50,120);
  TH1F *TightOBOCHH = new TH1F ("Tight OBOCHH", " R9: High / High , Outer Barrel / Outer Cap", 300,50,120);

  TH1F *TightICOCLL = new TH1F ("Tight ICOCLL", "R9: Low / Low, Inner Cap / Outer Cap", 300,50,120);
  TH1F *TightICOCLH = new TH1F ("Tight ICOCLH", "R9: High / Low , Inner Cap / Outer Cap", 300,50,120);
  TH1F *TightICOCHH = new TH1F ("Tight ICOCHH", " R9: High / High , Inner Cap / Outer Cap", 300,50,120);

  // Zs with MVA ID cuts by R9 and Location within ECAL Detector
  TH1F *MVACBCBLL = new TH1F ("MVA CBCBLL", "R9: Low / Low, Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *MVACBCBLH = new TH1F ("MVA CBCBLH", "R9: High / Low , Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *MVACBCBHH = new TH1F ("MVA CBCBHH", " R9: High / High , Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *MVAOBOBLL = new TH1F ("MVA OBOBLL", "R9: Low / Low, Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *MVAOBOBLH = new TH1F ("MVA OBOBLH", "R9: High / Low , Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *MVAOBOBHH = new TH1F ("MVA OBOBHH", " R9: High / High , Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *MVAICICLL = new TH1F ("MVA ICICLL", "R9: Low / Low, Inner Cap / Inner Cap", 300,50,120);
  TH1F *MVAICICLH = new TH1F ("MVA ICICLH", "R9: High / Low , Inner Cap / Inner Cap", 300,50,120);
  TH1F *MVAICICHH = new TH1F ("MVA ICICHH", " R9: High / High , Inner Cap / Inner Cap", 300,50,120);
  TH1F *MVAOCOCLL = new TH1F ("MVA OCOCLL", "R9: Low / Low, Outer Cap / Outer Cap", 300,50,120);
  TH1F *MVAOCOCLH = new TH1F ("MVA OCOCLH", "R9: High / Low , Outer Cap / Outer Cap", 300,50,120);
  TH1F *MVAOCOCHH = new TH1F ("MVA OCOCHH", " R9: High / High , Outer Cap / Outer Cap", 300,50,120);

  TH1F *MVACBOBLL = new TH1F ("MVA CBOBLL", "R9: Low / Low, Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *MVACBOBLH = new TH1F ("MVA CBOBLH", "R9: High / Low , Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *MVACBOBHH = new TH1F ("MVA CBOBHH", " R9: High / High , Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *MVACBICLL = new TH1F ("MVA CBICLL", "R9: Low / Low, Inner Barrel / Inner Cap", 300,50,120);
  TH1F *MVACBICLH = new TH1F ("MVA CBICLH", "R9: High / Low , Inner Barrel / Inner Cap", 300,50,120);
  TH1F *MVACBICHH = new TH1F ("MVA CBICHH", " R9: High / High , Inner Barrel / Inner Cap", 300,50,120);
  TH1F *MVACBOCLL = new TH1F ("MVA CBOCLL", "R9: Low / Low, Inner Barrel / Outer Cap", 300,50,120);
  TH1F *MVACBOCLH = new TH1F ("MVA CBOCLH", "R9: High / Low , Inner Barrel / Outer Cap", 300,50,120);
  TH1F *MVACBOCHH = new TH1F ("MVA CBOCHH", " R9: High / High , Inner Barrel / Outer Cap", 300,50,120);

  TH1F *MVAOBICLL = new TH1F ("MVA OBICLL", "R9: Low / Low, Outer Barrel / Inner Cap", 300,50,120);
  TH1F *MVAOBICLH = new TH1F ("MVA OBICLH", "R9: High / Low , Outer Barrel / Inner Cap", 300,50,120);
  TH1F *MVAOBICHH = new TH1F ("MVA OBICHH", " R9: High / High , Outer Barrel / Inner Cap", 300,50,120);
  TH1F *MVAOBOCLL = new TH1F ("MVA OBOCLL", "R9: Low / Low, Outer Barrel / Outer Cap", 300,50,120);
  TH1F *MVAOBOCLH = new TH1F ("MVA OBOCLH", "R9: High / Low , Outer Barrel / Outer Cap", 300,50,120);
  TH1F *MVAOBOCHH = new TH1F ("MVA OBOCHH", " R9: High / High , Outer Barrel / Outer Cap", 300,50,120);

  TH1F *MVAICOCLL = new TH1F ("MVA ICOCLL", "R9: Low / Low, Inner Cap / Outer Cap", 300,50,120);
  TH1F *MVAICOCLH = new TH1F ("MVA ICOCLH", "R9: High / Low , Inner Cap / Outer Cap", 300,50,120);
  TH1F *MVAICOCHH = new TH1F ("MVA ICOCHH", " R9: High / High , Inner Cap / Outer Cap", 300,50,120);

// Zs with MVA ID and Tight cuts by R9 and Location within ECAL Detector
  TH1F *MVATCBCBLL = new TH1F ("MVAT CBCBLL", "R9: Low / Low, Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *MVATCBCBLH = new TH1F ("MVAT CBCBLH", "R9: High / Low , Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *MVATCBCBHH = new TH1F ("MVAT CBCBHH", " R9: High / High , Inner Barrel / Inner Barrel", 300,50,120);
  TH1F *MVATOBOBLL = new TH1F ("MVAT OBOBLL", "R9: Low / Low, Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *MVATOBOBLH = new TH1F ("MVAT OBOBLH", "R9: High / Low , Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *MVATOBOBHH = new TH1F ("MVAT OBOBHH", " R9: High / High , Outer Barrel / Outer Barrel", 300,50,120);
  TH1F *MVATICICLL = new TH1F ("MVAT ICICLL", "R9: Low / Low, Inner Cap / Inner Cap", 300,50,120);
  TH1F *MVATICICLH = new TH1F ("MVAT ICICLH", "R9: High / Low , Inner Cap / Inner Cap", 300,50,120);
  TH1F *MVATICICHH = new TH1F ("MVAT ICICHH", " R9: High / High , Inner Cap / Inner Cap", 300,50,120);
  TH1F *MVATOCOCLL = new TH1F ("MVAT OCOCLL", "R9: Low / Low, Outer Cap / Outer Cap", 300,50,120);
  TH1F *MVATOCOCLH = new TH1F ("MVAT OCOCLH", "R9: High / Low , Outer Cap / Outer Cap", 300,50,120);
  TH1F *MVATOCOCHH = new TH1F ("MVAT OCOCHH", " R9: High / High , Outer Cap / Outer Cap", 300,50,120);

  TH1F *MVATCBOBLL = new TH1F ("MVAT CBOBLL", "R9: Low / Low, Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *MVATCBOBLH = new TH1F ("MVAT CBOBLH", "R9: High / Low , Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *MVATCBOBHH = new TH1F ("MVAT CBOBHH", " R9: High / High , Inner Barrel / Outer Barrel", 300,50,120);
  TH1F *MVATCBICLL = new TH1F ("MVAT CBICLL", "R9: Low / Low, Inner Barrel / Inner Cap", 300,50,120);
  TH1F *MVATCBICLH = new TH1F ("MVAT CBICLH", "R9: High / Low , Inner Barrel / Inner Cap", 300,50,120);
  TH1F *MVATCBICHH = new TH1F ("MVAT CBICHH", " R9: High / High , Inner Barrel / Inner Cap", 300,50,120);
  TH1F *MVATCBOCLL = new TH1F ("MVAT CBOCLL", "R9: Low / Low, Inner Barrel / Outer Cap", 300,50,120);
  TH1F *MVATCBOCLH = new TH1F ("MVAT CBOCLH", "R9: High / Low , Inner Barrel / Outer Cap", 300,50,120);
  TH1F *MVATCBOCHH = new TH1F ("MVAT CBOCHH", " R9: High / High , Inner Barrel / Outer Cap", 300,50,120);

  TH1F *MVATOBICLL = new TH1F ("MVAT OBICLL", "R9: Low / Low, Outer Barrel / Inner Cap", 300,50,120);
  TH1F *MVATOBICLH = new TH1F ("MVAT OBICLH", "R9: High / Low , Outer Barrel / Inner Cap", 300,50,120);
  TH1F *MVATOBICHH = new TH1F ("MVAT OBICHH", " R9: High / High , Outer Barrel / Inner Cap", 300,50,120);
  TH1F *MVATOBOCLL = new TH1F ("MVAT OBOCLL", "R9: Low / Low, Outer Barrel / Outer Cap", 300,50,120);
  TH1F *MVATOBOCLH = new TH1F ("MVAT OBOCLH", "R9: High / Low , Outer Barrel / Outer Cap", 300,50,120);
  TH1F *MVATOBOCHH = new TH1F ("MVAT OBOCHH", " R9: High / High , Outer Barrel / Outer Cap", 300,50,120);

  TH1F *MVATICOCLL = new TH1F ("MVAT ICOCLL", "R9: Low / Low, Inner Cap / Outer Cap", 300,50,120);
  TH1F *MVATICOCLH = new TH1F ("MVAT ICOCLH", "R9: High / Low , Inner Cap / Outer Cap", 300,50,120);
  TH1F *MVATICOCHH = new TH1F ("MVAT ICOCHH", " R9: High / High , Inner Cap / Outer Cap", 300,50,120);


  TightCBCBLL->SetLineColor(1);
  TightCBCBLH->SetLineColor(1);
  TightCBCBHH->SetLineColor(1);
  TightOBOBLL->SetLineColor(1);
  TightOBOBLH->SetLineColor(1);
  TightOBOBHH->SetLineColor(1);
  TightICICLL->SetLineColor(1);
  TightICICLH->SetLineColor(1);
  TightICICHH->SetLineColor(1);
  TightOCOCLL->SetLineColor(1);
  TightOCOCLH->SetLineColor(1);
  TightOCOCHH->SetLineColor(1);
  TightCBOBLL->SetLineColor(1);
  TightCBOBLH->SetLineColor(1);
  TightCBOBHH->SetLineColor(1);
  TightCBICLL->SetLineColor(1);
  TightCBICLH->SetLineColor(1);
  TightCBICHH->SetLineColor(1);
  TightCBOCLL->SetLineColor(1);
  TightCBOCLH->SetLineColor(1);
  TightCBOCHH->SetLineColor(1);
  TightOBICLL->SetLineColor(1);
  TightOBICLH->SetLineColor(1);
  TightOBICHH->SetLineColor(1);
  TightOBOCLL->SetLineColor(1);
  TightOBOCLH->SetLineColor(1);
  TightOBOCHH->SetLineColor(1);
  TightICOCLL->SetLineColor(1);
  TightICOCLH->SetLineColor(1);
  TightICOCHH->SetLineColor(1);

  MVACBCBLL->SetLineColor(4);
  MVACBCBLH->SetLineColor(4);
  MVACBCBHH->SetLineColor(4);
  MVAOBOBLL->SetLineColor(4);
  MVAOBOBLH->SetLineColor(4);
  MVAOBOBHH->SetLineColor(4);
  MVAICICLL->SetLineColor(4);
  MVAICICLH->SetLineColor(4);
  MVAICICHH->SetLineColor(4);
  MVAOCOCLL->SetLineColor(4);
  MVAOCOCLH->SetLineColor(4);
  MVAOCOCHH->SetLineColor(4);
  MVACBOBLL->SetLineColor(4);
  MVACBOBLH->SetLineColor(4);
  MVACBOBHH->SetLineColor(4);
  MVACBICLL->SetLineColor(4);
  MVACBICLH->SetLineColor(4);
  MVACBICHH->SetLineColor(4);
  MVACBOCLL->SetLineColor(4);
  MVACBOCLH->SetLineColor(4);
  MVACBOCHH->SetLineColor(4);
  MVAOBICLL->SetLineColor(4);
  MVAOBICLH->SetLineColor(4);
  MVAOBICHH->SetLineColor(4);
  MVAOBOCLL->SetLineColor(4);
  MVAOBOCLH->SetLineColor(4);
  MVAOBOCHH->SetLineColor(4);
  MVAICOCLL->SetLineColor(4);
  MVAICOCLH->SetLineColor(4);
  MVAICOCHH->SetLineColor(4);

  MVATCBCBLL->SetLineColor(2);
  MVATCBCBLH->SetLineColor(2);
  MVATCBCBHH->SetLineColor(2);
  MVATOBOBLL->SetLineColor(2);
  MVATOBOBLH->SetLineColor(2);
  MVATOBOBHH->SetLineColor(2);
  MVATICICLL->SetLineColor(2);
  MVATICICLH->SetLineColor(2);
  MVATICICHH->SetLineColor(2);
  MVATOCOCLL->SetLineColor(2);
  MVATOCOCLH->SetLineColor(2);
  MVATOCOCHH->SetLineColor(2);
  MVATCBOBLL->SetLineColor(2);
  MVATCBOBLH->SetLineColor(2);
  MVATCBOBHH->SetLineColor(2);
  MVATCBICLL->SetLineColor(2);
  MVATCBICLH->SetLineColor(2);
  MVATCBICHH->SetLineColor(2);
  MVATCBOCLL->SetLineColor(2);
  MVATCBOCLH->SetLineColor(2);
  MVATCBOCHH->SetLineColor(2);
  MVATOBICLL->SetLineColor(2);
  MVATOBICLH->SetLineColor(2);
  MVATOBICHH->SetLineColor(2);
  MVATOBOCLL->SetLineColor(2);
  MVATOBOCLH->SetLineColor(2);
  MVATOBOCHH->SetLineColor(2);
  MVATICOCLL->SetLineColor(2);
  MVATICOCLH->SetLineColor(2);
  MVATICOCHH->SetLineColor(2);
  
  // ======================================================================= //
  //                             Main Event Loop                             //
  // ======================================================================= //

  // Determine number of Events in Tree
  Int_t nevent = ZeeOutput->GetEntries();

  // Define Variables for Electron Processing
  Int_t   nbytes = 0;

  // Counts for Zs of each cut status
  Float_t nZs    = 0;
  Float_t nZmva  = 0;
  Float_t nZmvat = 0;
  Float_t nZt    = 0;

  // Cut Masses
  Float_t dataZmasst;
  Float_t dataZmassmva;
  Float_t dataZmassmvat;
  
  // Loop through each event in tree and choose the electrons with 
  // best Z mass from each event

  for (Int_t i=0; i<nevent;i++) {
    nbytes += ZeeOutput->GetEvent(i);   
    //cout<<"new event"<<endl;
     if (i%500==0) {
      cout <<">> Processing Entry "<< i << "/" << nevent << endl;
    };
    /*          Obtain Arrays of Variables for the Event          */
    // Invariant Mass of Reconstructed Z Boson
    Float_t mass;
    chain->SetBranchAddress("mass", &mass);

    // Eta for first Electron
    Float_t eta1;
    chain->SetBranchAddress("Ele1eta", &eta1);
    
    // Eta for second Electron
    Float_t eta2;
    chain->SetBranchAddress("Ele2eta", &eta2);

    // r9 for first Electron
    Float_t Ele1r9;
    chain->SetBranchAddress("Ele1r9", &Ele1r9);
    
    // r9 for second Electron
    Float_t Ele2r9;
    chain->SetBranchAddress("Ele2r9", &Ele2r9);

    // MVA ID for first Electron
    Float_t Ele1mva;
    chain->SetBranchAddress("Ele1mva", &Ele1mva);
    
    // MVA ID for second Electron
    Float_t Ele2mva;
    chain->SetBranchAddress("Ele2mva", &Ele2mva);

    // Pass status for WP 70 cuts
    Float_t passtight;
    chain->SetBranchAddress("passtight", &passtight);

    // Pass status for MVA ID cuts
    Float_t passmva;
    chain->SetBranchAddress("passmva", &passmva);
    
    // Pass status for WP 90 cuts
    Float_t passloose;
    chain->SetBranchAddress("passloose", &passloose);

    // Number of Electrons in original ntuple event
    Int_t nEle;
    chain->SetBranchAddress("nEle", &nEle);

    // Fill Histograms for MVA IDs without Cuts
    mvanontrignocut->Fill(Ele1mva);
    mvanontrignocut->Fill(Ele2mva);

    // Fill Histograms for MVA IDs with Tight Cuts
    // Apply cuts
    if (passtight == 1.0) {
      mvanontrigcut->Fill(Ele1mva);
      mvanontrigcut->Fill(Ele2mva);
    };
	    
    // Designate Passing Status for Masses
    if (passtight == 1.0) {
      dataZmasst = mass;              
    };
	    
    if (passmva == 1.0) {
      dataZmassmva = mass;      
    };
    
    if (passmva == 1.0 && passtight == 1.0) {
      dataZmassmvat = mass;           
    };	    
	  
    // Fill the Histograms with the Z masses  
    // =============================================================================================== //
    /*                                          All Zmasses                                            */
    // =============================================================================================== //
    Znocut->Fill(mass);
    fprintf (Znc, "%f \n", mass);
    if (mass>80 && mass<100) {
      nZs += 1; // add to count of Z
    };
    
    // =============================================================================================== //
    /*                          Z Masses with MVA ID Cuts but no Tight Cuts                            */
    // =============================================================================================== //
    if (dataZmassmva != 0) {
      Zmvanontrignocut->Fill(dataZmassmva);
      fprintf (Zmva, "%f \n", dataZmassmva);
      if (dataZmassmva>80 && dataZmassmva<100) {
	nZmva += 1; // add to count of Z with MVA cuts
      };
      
      /*          Divide by R9 and Eta           */
      
      // Both Inner Barrel
      if (fabs(eta1)<1.0 && fabs(eta2)<1.0) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVACBCBLL->Fill(dataZmassmva);
	  fprintf (mvaCBCBLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVACBCBLH->Fill(dataZmassmva);
	  fprintf (mvaCBCBLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVACBCBHH->Fill(dataZmassmva);
	  fprintf (mvaCBCBHH, "%f \n", dataZmassmva);
	};
      };

      // Both Outer Barrel
      if (fabs(eta1)>1.0 && fabs(eta1)>1.0 && fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVAOBOBLL->Fill(dataZmassmva);
	  fprintf (mvaOBOBLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVAOBOBLH->Fill(dataZmassmva);
	  fprintf (mvaOBOBLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVAOBOBHH->Fill(dataZmassmva);
	  fprintf (mvaOBOBHH, "%f \n", dataZmassmva);
	};
      };
      
      // Both Inner End Caps
      if (fabs(eta1)>1.5 && fabs(eta2)>1.5 && fabs(eta1)<2.0 && fabs(eta2)<2.0) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVAICICLL->Fill(dataZmassmva);
	  fprintf (mvaICICLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVAICICLH->Fill(dataZmassmva);
	  fprintf (mvaICICLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVAICICHH->Fill(dataZmassmva);
	  fprintf (mvaICICHH, "%f \n", dataZmassmva);
	};
      };
   
      // Both Outer End Caps
      if (fabs(eta1)>2.0 && fabs(eta2)>2.0 && fabs(eta1)<2.5 && fabs(eta2)<2.5) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVAOCOCLL->Fill(dataZmassmva);
	  fprintf (mvaOCOCLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVAOCOCLH->Fill(dataZmassmva);
	  fprintf (mvaOCOCLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVAOCOCHH->Fill(dataZmassmva);
	  fprintf (mvaOCOCHH, "%f \n", dataZmassmva);
	};
      };
      
      // Inner Barrel /  Outer Barrel
      if ((fabs(eta1)<1.0 && fabs(eta2)>1.0 && fabs(eta2)<1.44)||(fabs(eta2)<1.0 && fabs(eta1)>1.0 && fabs(eta1)<1.44)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVACBOBLL->Fill(dataZmassmva);
	  fprintf (mvaCBOBLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVACBOBLH->Fill(dataZmassmva);
	  fprintf (mvaCBOBLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVACBOBHH->Fill(dataZmassmva);
	  fprintf (mvaCBOBHH, "%f \n", dataZmassmva);
	};
      };
      
      // Inner Barrel /  Inner End Caps
      if ((fabs(eta1)<1.0 && fabs(eta2)>1.5 && fabs(eta2)<2.0)||(fabs(eta2)<1.0 && fabs(eta1)>1.5 && fabs(eta1)<2.0)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVACBICLL->Fill(dataZmassmva);
	  fprintf (mvaCBICLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVACBICLH->Fill(dataZmassmva);
	  fprintf (mvaCBICLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVACBICHH->Fill(dataZmassmva);
	  fprintf (mvaCBICHH, "%f \n", dataZmassmva);
	};
      };
      
      // Inner Barrel /  Outer End Caps
      if ((fabs(eta1)<1.0 && fabs(eta2)>2.0 && fabs(eta2)<2.5)||(fabs(eta2)<1.0 && fabs(eta1)>2.0 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVACBOCLL->Fill(dataZmassmva);
	  fprintf (mvaCBOCLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVACBOCLH->Fill(dataZmassmva);
	  fprintf (mvaCBOCLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVACBOCHH->Fill(dataZmassmva);
	  fprintf (mvaCBOCHH, "%f \n", dataZmassmva);
	};
      };
      
      
      // Outer Barrel /  Inner End Caps
      if ((fabs(eta1)>1.0 && fabs(eta2)>1.5 && fabs(eta1)<1.50 && fabs(eta2)<2.0)||(fabs(eta2)>1.0 && fabs(eta1)>1.5 && fabs(eta1)<2.0 && fabs(eta2)<1.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVAOBICLL->Fill(dataZmassmva);
	  fprintf (mvaOBICLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVAOBICLH->Fill(dataZmassmva);
	  fprintf (mvaOBICLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVAOBICHH->Fill(dataZmassmva);
	  fprintf (mvaOBICHH, "%f \n", dataZmassmva);
	};
      };
      
      // Outer Barrel /  Outer End Caps
      if ((fabs(eta1)>1.0 && fabs(eta2)>2.0 && fabs(eta1)<1.50 && fabs(eta2)<2.5)||(fabs(eta2)>1.0 && fabs(eta1)>2.0 && fabs(eta2)<1.50 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVAOBOCLL->Fill(dataZmassmva);
	  fprintf (mvaOBOCLL, "%f \n", dataZmassmva);
	};
	  // Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVAOBOCLH->Fill(dataZmassmva);
	  fprintf (mvaOBOCLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVAOBOCHH->Fill(dataZmassmva);
	  fprintf (mvaOBOCHH, "%f \n", dataZmassmva);
	};
      };
      
      // Inner End Caps /  Outer End Caps
      if ((fabs(eta1)>1.5 && fabs(eta2)>2.0 && fabs(eta1)<2.0 && fabs(eta2)<2.5)||(fabs(eta2)>1.5 && fabs(eta1)>2.0 && fabs(eta2)<2.0 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVAICOCLL->Fill(dataZmassmva);
	  fprintf (mvaICOCLL, "%f \n", dataZmassmva);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVAICOCLH->Fill(dataZmassmva);
	  fprintf (mvaICOCLH, "%f \n", dataZmassmva);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVAICOCHH->Fill(dataZmassmva);
	  fprintf (mvaICOCHH, "%f \n", dataZmassmva);
	};
      };
    };
    // ============================================================================================= //		
    /*                           Z Masses  with Tight Cuts but No MVA Cuts                           */
    // ============================================================================================= //
    if (dataZmasst != 0) {
      Zcut->Fill(dataZmasst);
      
      fprintf (Zt, "%f \n", dataZmasst);
      if (dataZmasst>80 && dataZmasst<100) {
	nZt += 1; // add to count of Z with tight cuts
      };

      /*          Divide by R9 and Eta           */

      // Both Inner Barrel
      if (fabs(eta1)<1.0 && fabs(eta2)<1.0) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightCBCBLL->Fill(dataZmasst);
	  fprintf (tightCBCBLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightCBCBLH->Fill(dataZmasst);
	  fprintf (tightCBCBLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightCBCBHH->Fill(dataZmasst);
	  fprintf (tightCBCBHH, "%f \n", dataZmasst);
	};
      };
      
      // Both Outer Barrel
      if (fabs(eta1)>1.0 && fabs(eta1)>1.0 && fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightOBOBLL->Fill(dataZmasst);
	  fprintf (tightOBOBLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightOBOBLH->Fill(dataZmasst);
	  fprintf (tightOBOBLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightOBOBHH->Fill(dataZmasst);
	  fprintf (tightOBOBHH, "%f \n", dataZmasst);
	};
      };
      
      // Both Inner End Caps
      if (fabs(eta1)>1.5 && fabs(eta2)>1.5 && fabs(eta1)<2.0 && fabs(eta2)<2.0) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightICICLL->Fill(dataZmasst);
	  fprintf (tightICICLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightICICLH->Fill(dataZmasst);
	  fprintf (tightICICLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightICICHH->Fill(dataZmasst);
	  fprintf (tightICICHH, "%f \n", dataZmasst);
	};
      };
      
      // Both Outer End Caps
      if (fabs(eta1)>2.0 && fabs(eta2)>2.0 && fabs(eta1)<2.5 && fabs(eta2)<2.5) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightOCOCLL->Fill(dataZmasst);
	  fprintf (tightOCOCLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightOCOCLH->Fill(dataZmasst);
	  fprintf (tightOCOCLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightOCOCHH->Fill(dataZmasst);
	  fprintf (tightOCOCHH, "%f \n", dataZmasst);
	};
      };
      
      // Inner Barrel /  Outer Barrel
      if ((fabs(eta1)<1.0 && fabs(eta2)>1.0 && fabs(eta2)<1.44)||(fabs(eta2)<1.0 && fabs(eta1)>1.0 && fabs(eta1)<1.44)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightCBOBLL->Fill(dataZmasst);
	  fprintf (tightCBOBLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightCBOBLH->Fill(dataZmasst);
	  fprintf (tightCBOBLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightCBOBHH->Fill(dataZmasst);
	  fprintf (tightCBOBHH, "%f \n", dataZmasst);
	};
      };
      
      // Inner Barrel /  Inner End Caps
      if ((fabs(eta1)<1.0 && fabs(eta2)>1.5 && fabs(eta2)<2.0)||(fabs(eta2)<1.0 && fabs(eta1)>1.5 && fabs(eta1)<2.0)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightCBICLL->Fill(dataZmasst);
	  fprintf (tightCBICLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightCBICLH->Fill(dataZmasst);
	  fprintf (tightCBICLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightCBICHH->Fill(dataZmasst);
	  fprintf (tightCBICHH, "%f \n", dataZmasst);
	};
      };
      
      // Inner Barrel /  Outer End Caps
      if ((fabs(eta1)<1.0 && fabs(eta2)>2.0 && fabs(eta2)<2.5)||(fabs(eta2)<1.0 && fabs(eta1)>2.0 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightCBOCLL->Fill(dataZmasst);
	  fprintf (tightCBOCLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightCBOCLH->Fill(dataZmasst);
	  fprintf (tightCBOCLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightCBOCHH->Fill(dataZmasst);
	  fprintf (tightCBOCHH, "%f \n", dataZmasst);
	};
      };
      
      
      // Outer Barrel /  Inner End Caps
      if ((fabs(eta1)>1.0 && fabs(eta2)>1.5 && fabs(eta1)<1.50 && fabs(eta2)<2.0)||(fabs(eta2)>1.0 && fabs(eta1)>1.5 && fabs(eta1)<2.0 && fabs(eta2)<1.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightOBICLL->Fill(dataZmasst);
	  fprintf (tightOBICLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightOBICLH->Fill(dataZmasst);
	  fprintf (tightOBICLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightOBICHH->Fill(dataZmasst);
	  fprintf (tightOBICHH, "%f \n", dataZmasst);
	};
      };
      
      // Outer Barrel /  Outer End Caps
      if ((fabs(eta1)>1.0 && fabs(eta2)>2.0 && fabs(eta1)<1.50 && fabs(eta2)<2.5)||(fabs(eta2)>1.0 && fabs(eta1)>2.0 && fabs(eta2)<1.50 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightOBOCLL->Fill(dataZmasst);
	  fprintf (tightOBOCLL, "%f \n", dataZmasst);
	};
	  // Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightOBOCLH->Fill(dataZmasst);
	  fprintf (tightOBOCLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightOBOCHH->Fill(dataZmasst);
	  fprintf (tightOBOCHH, "%f \n", dataZmasst);
	};
      };
      
      // Inner End Caps /  Outer End Caps
      if ((fabs(eta1)>1.5 && fabs(eta2)>2.0 && fabs(eta1)<2.0 && fabs(eta2)<2.5)||(fabs(eta2)>1.5 && fabs(eta1)>2.0 && fabs(eta2)<2.0 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  TightICOCLL->Fill(dataZmasst);
	  fprintf (tightICOCLL, "%f \n", dataZmasst);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  TightICOCLH->Fill(dataZmasst);
	  fprintf (tightICOCLH, "%f \n", dataZmasst);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  TightICOCHH->Fill(dataZmasst);
	  fprintf (tightICOCHH, "%f \n", dataZmasst);
	};
      };
    };
    //================================================================================================= //
    /*                            Z Masses with MVA ID and Tight Cuts                                   */
    //================================================================================================= //
    if (dataZmassmvat != 0) {
      Zmvanontrigcut->Fill(dataZmassmvat);
      fprintf (Zmvat, "%f \n", dataZmassmvat);
      if (dataZmassmvat>80 && dataZmassmvat<100) {
	nZmvat += 1; // add to count of Z with MVA and tight cuts
      };

      /*          Divide by R9 and Eta           */
      
      // Both Inner Barrel
      if (fabs(eta1)<1.0 && fabs(eta2)<1.0) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATCBCBLL->Fill(dataZmassmvat);
	  fprintf (mvatCBCBLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATCBCBLH->Fill(dataZmassmvat);
	  fprintf (mvatCBCBLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATCBCBHH->Fill(dataZmassmvat);
	  fprintf (mvatCBCBHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Both Outer Barrel
      if (fabs(eta1)>1.0 && fabs(eta1)>1.0 && fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATOBOBLL->Fill(dataZmassmvat);
	  fprintf (mvatOBOBLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATOBOBLH->Fill(dataZmassmvat);
	  fprintf (mvatOBOBLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATOBOBHH->Fill(dataZmassmvat);
	  fprintf (mvatOBOBHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Both Inner End Caps
      if (fabs(eta1)>1.5 && fabs(eta2)>1.5 && fabs(eta1)<2.0 && fabs(eta2)<2.0) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATICICLL->Fill(dataZmassmvat);
	  fprintf (mvatICICLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATICICLH->Fill(dataZmassmvat);
	  fprintf (mvatICICLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATICICHH->Fill(dataZmassmvat);
	  fprintf (mvatICICHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Both Outer End Caps
      if (fabs(eta1)>2.0 && fabs(eta2)>2.0 && fabs(eta1)<2.5 && fabs(eta2)<2.5) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATOCOCLL->Fill(dataZmassmvat);
	  fprintf (mvatOCOCLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATOCOCLH->Fill(dataZmassmvat);
	  fprintf (mvatOCOCLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATOCOCHH->Fill(dataZmassmvat);
	  fprintf (mvatOCOCHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Inner Barrel /  Outer Barrel
      if ((fabs(eta1)<1.0 && fabs(eta2)>1.0 && fabs(eta2)<1.44)||(fabs(eta2)<1.0 && fabs(eta1)>1.0 && fabs(eta1)<1.44)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATCBOBLL->Fill(dataZmassmvat);
	  fprintf (mvatCBOBLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATCBOBLH->Fill(dataZmassmvat);
	  fprintf (mvatCBOBLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATCBOBHH->Fill(dataZmassmvat);
	  fprintf (mvatCBOBHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Inner Barrel /  Inner End Caps
      if ((fabs(eta1)<1.0 && fabs(eta2)>1.5 && fabs(eta2)<2.0)||(fabs(eta2)<1.0 && fabs(eta1)>1.5 && fabs(eta1)<2.0)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATCBICLL->Fill(dataZmassmvat);
	  fprintf (mvatCBICLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATCBICLH->Fill(dataZmassmvat);
	  fprintf (mvatCBICLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATCBICHH->Fill(dataZmassmvat);
	  fprintf (mvatCBICHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Inner Barrel /  Outer End Caps
      if ((fabs(eta1)<1.0 && fabs(eta2)>2.0 && fabs(eta2)<2.5)||(fabs(eta2)<1.0 && fabs(eta1)>2.0 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATCBOCLL->Fill(dataZmassmvat);
	  fprintf (mvatCBOCLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATCBOCLH->Fill(dataZmassmvat);
	  fprintf (mvatCBOCLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATCBOCHH->Fill(dataZmassmvat);
	  fprintf (mvatCBOCHH, "%f \n", dataZmassmvat);
	};
      };
      
      
      // Outer Barrel /  Inner End Caps
      if ((fabs(eta1)>1.0 && fabs(eta2)>1.5 && fabs(eta1)<1.50 && fabs(eta2)<2.0)||(fabs(eta2)>1.0 && fabs(eta1)>1.5 && fabs(eta1)<2.0 && fabs(eta2)<1.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATOBICLL->Fill(dataZmassmvat);
	  fprintf (mvatOBICLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATOBICLH->Fill(dataZmassmvat);
	  fprintf (mvatOBICLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATOBICHH->Fill(dataZmassmvat);
	  fprintf (mvatOBICHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Outer Barrel /  Outer End Caps
      if ((fabs(eta1)>1.0 && fabs(eta2)>2.0 && fabs(eta1)<1.50 && fabs(eta2)<2.5)||(fabs(eta2)>1.0 && fabs(eta1)>2.0 && fabs(eta2)<1.50 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATOBOCLL->Fill(dataZmassmvat);
	  fprintf (mvatOBOCLL, "%f \n", dataZmassmvat);
	};
	  // Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATOBOCLH->Fill(dataZmassmvat);
	  fprintf (mvatOBOCLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATOBOCHH->Fill(dataZmassmvat);
	  fprintf (mvatOBOCHH, "%f \n", dataZmassmvat);
	};
      };
      
      // Inner End Caps /  Outer End Caps
      if ((fabs(eta1)>1.5 && fabs(eta2)>2.0 && fabs(eta1)<2.0 && fabs(eta2)<2.5)||(fabs(eta2)>1.5 && fabs(eta1)>2.0 && fabs(eta2)<2.0 && fabs(eta1)<2.5)) {
	// Low R9 / Low R9
	if (Ele1r9<0.94 && Ele2r9<0.94) {
	  MVATICOCLL->Fill(dataZmassmvat);
	  fprintf (mvatICOCLL, "%f \n", dataZmassmvat);
	};
	// Low R9 / High R9
	if ((Ele2r9>0.94 && Ele1r9<0.94)|| (Ele1r9>0.94 && Ele2r9<0.94)) {
	  MVATICOCLH->Fill(dataZmassmvat);
	  fprintf (mvatICOCLH, "%f \n", dataZmassmvat);
	};
	// High R9 / High R9 
	if (Ele1r9>0.94 && Ele2r9>0.94) {
	  MVATICOCHH->Fill(dataZmassmvat);
	  fprintf (mvatICOCHH, "%f \n", dataZmassmvat);
	};
      };
    };
  };


  // ================== Calculate Efficiencies for each Cut =================== //
  //                    Efficiencies are calculated using:                      //   
  //               # of Z masses between 80 to 100 GeV with cut                 //
  //               --------------------------------------------                 //
  //                 # of Z masses between 80 to 100 GeV uncut                  //
  // ========================================================================== //

  Float_t effMVA = 100*(nZmva/nZs);
  Float_t effcut = 100*(nZt/nZs);
  Float_t effMVAcut = 100*(nZmvat/nZs);
  
  //====================  Create Canvases to Plot Histograms ===================//
  cout<<"finished making masses"<<endl;
  // MVA Histograms
  TCanvas *c1 = new TCanvas("c1", "c1", 10,30,1000,700);
  c1->Divide(2,1);
  c1->cd(1);
  mvanontrignocut->Draw();
  c1->cd(2);
  mvanontrigcut->Draw();
  c1->Print("MVAplots.ps");
  // Z Histograms
  TCanvas *c2 = new TCanvas("c2", "c2", 10,30,1000,700);
  c2->Divide(2,2);
  c2->cd(1);
  Znocut->Draw();
  c2->cd(2);
  Zmvanontrignocut->Draw();
  //Print the Efficieny for the MVA Cuts
  TPaveText *p1 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p1->AddText(Form("Z Efficiency = %.2f", effMVA));
  p1->Draw();
  c2->Update();
  c2->cd(3);
  Zcut->Draw();
  //Print the Efficiency for the MVA + Tight Cuts
  TPaveText *p2 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p2->AddText(Form("Z Efficiency = %.2f", effcut));
  p2->Draw();
  c2->Update();
  c2->cd(4);
  Zmvanontrigcut->Draw();
  //Print the Efficiency for the MVA + Tight Cuts
  TPaveText *p3 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p3->AddText(Form("Z Efficiency = %.2f", effMVAcut));
  p3->Draw();
  c2->Update();
  c2->Print("Zhists.ps");

  // High R9 / High R9  and Same Locations
  TCanvas *c3 = new TCanvas("c3", "c3", 10,30,1000,700);
  c3->Divide(2,2);
  c3->cd(1);
  MVACBCBHH->Draw();
  TightCBCBHH->Draw("same");
  MVATCBCBHH->Draw("same");
  TLegend *l1 = new TLegend(0.7,0.7, 0.9,0.80,NULL,"NDC");
  l1->AddEntry(TightCBCBHH,"Tight Cuts", "l");
  l1->AddEntry(MVACBCBHH,"MVA ID Cuts", "l");
  l1->AddEntry(MVATCBCBHH,"MVA ID and Tight Cuts", "l");
  l1->Draw();
  c3->cd(2);
  MVAOBOBHH->Draw();
  TightOBOBHH->Draw("same");
  MVATOBOBHH->Draw("same");
  c3->cd(3);
  MVAICICHH->Draw();
  TightICICHH->Draw("same");
  MVATICICHH->Draw("same");
  c3->cd(4);
  MVAOCOCHH->Draw();
  TightOCOCHH->Draw("same");
  MVATOCOCHH->Draw("same");
  c3->Print("HHsame.ps");
  
  // Low R9 / Low R9 and Same Locations
  TCanvas *c4 = new TCanvas("c4", "c4", 10,30,1000,700);
  c4->Divide(2,2);
  c4->cd(1);
  MVACBCBLL->Draw();
  TightCBCBLL->Draw("same");
  MVATCBCBLL->Draw("same");
  TLegend *l2 = new TLegend(0.7,0.7, 0.9,0.80,NULL,"NDC");
  l2->AddEntry(TightCBCBHH,"Tight Cuts", "l");
  l2->AddEntry(MVACBCBHH,"MVA ID Cuts", "l");
  l2->AddEntry(MVATCBCBHH,"MVA ID and Tight Cuts", "l");
  l2->Draw();
  c4->cd(2);
  MVACBCBLL->Draw();
  TightCBCBLL->Draw("same");
  MVATCBCBLL->Draw("same");
  c4->cd(3);
  MVAICICLL->Draw();
  TightICICLL->Draw("same");
  MVATICICLL->Draw("same");
  c4->cd(4);
  MVAOCOCLL->Draw();
  TightOCOCLL->Draw("same");
  MVATOCOCLL->Draw("same");
  c4->Print("LLsame.ps");

  // Low R9 / High R9 and Same Locations
  TCanvas *c5 = new TCanvas("c5", "c5", 10,30,1000,700);
  c5->Divide(2,2);
  c5->cd(1);
  MVACBCBLH->Draw();
  TightCBCBLH->Draw("same");
  MVATCBCBLH->Draw("same");
  TLegend *l3 = new TLegend(0.7,0.7, 0.9,0.80,NULL,"NDC");
  l3->AddEntry(TightCBCBHH,"Tight Cuts", "l");
  l3->AddEntry(MVACBCBHH,"MVA ID Cuts", "l");
  l3->AddEntry(MVATCBCBHH,"MVA ID and Tight Cuts", "l");
  l3->Draw();
  c5->cd(2);
  MVAOBOBLH->Draw();
  TightOBOBLH->Draw("same");
  MVATOBOBLH->Draw("same");
  c5->cd(3);
  MVAICICLH->Draw();
  TightICICLH->Draw("same");
  MVATICICLH->Draw("same");
  c5->cd(4);
  MVAOCOCLH->Draw();
  TightOCOCLH->Draw("same");
  MVATOCOCLH->Draw("same");
  c5->Print("LHsame.ps");

  // Low R9 / Low R9 and Mixed Locations
  TCanvas *c6 = new TCanvas("c6", "c6", 10,30,1000,700);
  c6->Divide(3,2);
  c6->cd(1);
  MVACBOBLL->Draw();
  TightCBOBLL->Draw("same");
  MVATCBOBLL->Draw("same");
  TLegend *l4 = new TLegend(0.7,0.7, 0.9,0.80,NULL,"NDC");
  l4->AddEntry(TightCBCBHH,"Tight Cuts", "l");
  l4->AddEntry(MVACBCBHH,"MVA ID Cuts", "l");
  l4->AddEntry(MVATCBCBHH,"MVA ID and Tight Cuts", "l");
  l4->Draw();
  c6->cd(2);
  MVACBICLL->Draw();
  TightCBICLL->Draw("same");
  MVATCBICLL->Draw("same");
  c6->cd(3);
  MVACBOCLL->Draw();
  TightCBOCLL->Draw("same");
  MVATCBOCLL->Draw("same");
  c6->cd(4);
  MVAOBICLL->Draw();
  TightOBICLL->Draw("same");
  MVATOBICLL->Draw("same");
  c6->cd(5);
  MVAOBOCLL->Draw();
  TightOBOCLL->Draw("same");
  MVATOBOCLL->Draw("same");
  c6->cd(6);
  MVAICOCLL->Draw();
  TightICOCLL->Draw("same");
  MVATICOCLL->Draw("same");
  c6->Print("LLmix.ps");

// High R9 / High R9 and Mixed Locations
  TCanvas *c7 = new TCanvas("c7", "c7", 10,30,1000,700);
  c7->Divide(3,2);
  c7->cd(1);
  MVACBOBHH->Draw();
  TightCBOBHH->Draw("same");
  MVATCBOBHH->Draw("same");
  TLegend *l5 = new TLegend(0.7,0.7, 0.9,0.80,NULL,"NDC");
  l5->AddEntry(TightCBCBHH,"Tight Cuts", "l");
  l5->AddEntry(MVACBCBHH,"MVA ID Cuts", "l");
  l5->AddEntry(MVATCBCBHH,"MVA ID and Tight Cuts", "l");
  l5->Draw();
  c7->cd(2);
  MVACBICHH->Draw();
  TightCBICHH->Draw("same");
  MVATCBICHH->Draw("same");
  c7->cd(3);
  MVACBOCHH->Draw();
  TightCBOCHH->Draw("same");
  MVATCBOCHH->Draw("same");
  c7->cd(4);
  MVAOBICHH->Draw();
  TightOBICHH->Draw("same");
  MVATOBICHH->Draw("same");
  c7->cd(5);
  MVAOBOCHH->Draw();
  TightOBOCHH->Draw("same");
  MVATOBOCHH->Draw("same");
  c7->cd(6);
  MVAICOCHH->Draw();
  TightICOCHH->Draw("same");
  MVATICOCHH->Draw("same");
  c7->Print("HHmix.ps");

// Low R9 / High R9 and Mixed Locations
  TCanvas *c8 = new TCanvas("c8", "c8", 10,30,1000,700);
  c8->Divide(3,2);
  c8->cd(1);
  MVACBOBLH->Draw();
  TightCBOBLH->Draw("same");
  MVATCBOBLH->Draw("same");
  TLegend *l6 = new TLegend(0.7,0.7, 0.9,0.80,NULL,"NDC");
  l6->AddEntry(TightCBCBHH,"Tight Cuts", "l");
  l6->AddEntry(MVACBCBHH,"MVA ID Cuts", "l");
  l6->AddEntry(MVATCBCBHH,"MVA ID and Tight Cuts", "l");
  l6->Draw();
  c8->cd(2);
  MVACBICLH->Draw();
  TightCBICLH->Draw("same");
  MVATCBICLH->Draw("same");
  c8->cd(3);
  MVACBOCLH->Draw();
  TightCBOCLH->Draw("same");
  MVATCBOCLH->Draw("same");
  c8->cd(4);
  MVAOBICLH->Draw();
  TightOBICLH->Draw("same");
  MVATOBICLH->Draw("same");
  c8->cd(5);
  MVAOBOCLH->Draw();
  TightOBOCLH->Draw("same");
  MVATOBOCLH->Draw("same");
  c8->cd(6);
  MVAICOCLH->Draw();
  TightICOCLH->Draw("same");
  MVATICOCLH->Draw("same");
  c8->Print("LHmix.ps");

  
  // ================== Save Histograms ==================== //
  cout<<"saving"<<endl;
  // Create file to save histograms and write them all
  TFile *h = new TFile("mvahistos.root", "RECREATE");
  mvanontrignocut->Write();
  mvanontrigcut->Write();
  Zmvanontrignocut->Write();
  Zmvanontrigcut->Write();
  Znocut->Write();
  Zcut->Write();

  TightCBCBLL->Write();
  TightCBCBLH->Write();
  TightCBCBHH->Write();
  TightOBOBLL->Write();
  TightOBOBLH->Write();
  TightOBOBHH->Write();
  TightICICLL->Write();
  TightICICLH->Write();
  TightICICHH->Write();
  TightOCOCLL->Write();
  TightOCOCLH->Write();
  TightOCOCHH->Write();
  TightCBOBLL->Write();
  TightCBOBLH->Write();
  TightCBOBHH->Write();
  TightCBICLL->Write();
  TightCBICLH->Write();
  TightCBICHH->Write();
  TightCBOCLL->Write();
  TightCBOCLH->Write();
  TightCBOCHH->Write();
  TightOBICLL->Write();
  TightOBICLH->Write();
  TightOBICHH->Write();
  TightOBOCLL->Write();
  TightOBOCLH->Write();
  TightOBOCHH->Write();
  TightICOCLL->Write();
  TightICOCLH->Write();
  TightICOCHH->Write();

  MVACBCBLL->Write();
  MVACBCBLH->Write();
  MVACBCBHH->Write();
  MVAOBOBLL->Write();
  MVAOBOBLH->Write();
  MVAOBOBHH->Write();
  MVAICICLL->Write();
  MVAICICLH->Write();
  MVAICICHH->Write();
  MVAOCOCLL->Write();
  MVAOCOCLH->Write();
  MVAOCOCHH->Write();
  MVACBOBLL->Write();
  MVACBOBLH->Write();
  MVACBOBHH->Write();
  MVACBICLL->Write();
  MVACBICLH->Write();
  MVACBICHH->Write();
  MVACBOCLL->Write();
  MVACBOCLH->Write();
  MVACBOCHH->Write();
  MVAOBICLL->Write();
  MVAOBICLH->Write();
  MVAOBICHH->Write();
  MVAOBOCLL->Write();
  MVAOBOCLH->Write();
  MVAOBOCHH->Write();
  MVAICOCLL->Write();
  MVAICOCLH->Write();
  MVAICOCHH->Write();

  MVATCBCBLL->Write();
  MVATCBCBLH->Write();
  MVATCBCBHH->Write();
  MVATOBOBLL->Write();
  MVATOBOBLH->Write();
  MVATOBOBHH->Write();
  MVATICICLL->Write();
  MVATICICLH->Write();
  MVATICICHH->Write();
  MVATOCOCLL->Write();
  MVATOCOCLH->Write();
  MVATOCOCHH->Write();
  MVATCBOBLL->Write();
  MVATCBOBLH->Write();
  MVATCBOBHH->Write();
  MVATCBICLL->Write();
  MVATCBICLH->Write();
  MVATCBICHH->Write();
  MVATCBOCLL->Write();
  MVATCBOCLH->Write();
  MVATCBOCHH->Write();
  MVATOBICLL->Write();
  MVATOBICLH->Write();
  MVATOBICHH->Write();
  MVATOBOCLL->Write();
  MVATOBOCLH->Write();
  MVATOBOCHH->Write();
  MVATICOCLL->Write();
  MVATICOCLH->Write();
  MVATICOCHH->Write();
  h->Close();

  // Close text files
  fclose(Znc);
  fclose(Zmva);
  fclose(Zmvat);
  fclose(Zt);

  fclose(mvaCBCBLL);
  fclose(mvaCBCBLH);
  fclose(mvaCBCBHH);
  fclose(mvaOBOBLL);
  fclose(mvaOBOBLH);
  fclose(mvaOBOBHH);
  fclose(mvaICICLL);
  fclose(mvaICICLH);
  fclose(mvaICICHH);
  fclose(mvaOCOCLL);
  fclose(mvaOCOCLH);
  fclose(mvaOCOCHH);
  fclose(mvaCBOBLL);
  fclose(mvaCBOBLH);
  fclose(mvaCBOBHH);
  fclose(mvaCBICLL);
  fclose(mvaCBICLH);
  fclose(mvaCBICHH);
  fclose(mvaCBOCLL);
  fclose(mvaCBOCLH);
  fclose(mvaCBOCHH);
  fclose(mvaOBICLL);
  fclose(mvaOBICLH);
  fclose(mvaOBICHH);
  fclose(mvaOBOCLL);
  fclose(mvaOBOCLH);
  fclose(mvaOBOCHH);
  fclose(mvaICOCLL);
  fclose(mvaICOCLH);
  fclose(mvaICOCHH);

  fclose(mvatCBCBLL);
  fclose(mvatCBCBLH);
  fclose(mvatCBCBHH);
  fclose(mvatOBOBLL);
  fclose(mvatOBOBLH);
  fclose(mvatOBOBHH);
  fclose(mvatICICLL);
  fclose(mvatICICLH);
  fclose(mvatICICHH);
  fclose(mvatOCOCLL);
  fclose(mvatOCOCLH);
  fclose(mvatOCOCHH);
  fclose(mvatCBOBLL);
  fclose(mvatCBOBLH);
  fclose(mvatCBOBHH);
  fclose(mvatCBICLL);
  fclose(mvatCBICLH);
  fclose(mvatCBICHH);
  fclose(mvatCBOCLL);
  fclose(mvatCBOCLH);
  fclose(mvatCBOCHH);
  fclose(mvatOBICLL);
  fclose(mvatOBICLH);
  fclose(mvatOBICHH);
  fclose(mvatOBOCLL);
  fclose(mvatOBOCLH);
  fclose(mvatOBOCHH);
  fclose(mvatICOCLL);
  fclose(mvatICOCLH);
  fclose(mvatICOCHH);

  fclose(tightCBCBLL);
  fclose(tightCBCBLH);
  fclose(tightCBCBHH);
  fclose(tightOBOBLL);
  fclose(tightOBOBLH);
  fclose(tightOBOBHH);
  fclose(tightICICLL);
  fclose(tightICICLH);
  fclose(tightICICHH);
  fclose(tightOCOCLL);
  fclose(tightOCOCLH);
  fclose(tightOCOCHH);
  fclose(tightCBOBLL);
  fclose(tightCBOBLH);
  fclose(tightCBOBHH);
  fclose(tightCBICLL);
  fclose(tightCBICLH);
  fclose(tightCBICHH);
  fclose(tightCBOCLL);
  fclose(tightCBOCLH);
  fclose(tightCBOCHH);
  fclose(tightOBICLL);
  fclose(tightOBICLH);
  fclose(tightOBICHH);
  fclose(tightOBOCLL);
  fclose(tightOBOCLH);
  fclose(tightOBOCHH);
  fclose(tightICOCLL);
  fclose(tightICOCLH);
  fclose(tightICOCHH);
}
