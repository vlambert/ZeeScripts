//=========================================================================//
//  For CMS ECAL Detector at the LHC, 2012                                 //
//  Macro for Sorting Z Masses by Detector Location                        //
//                                                                         //
//  Valère Lambert                                                         //
//  California Institute of Technology                                     // 
//=========================================================================//

#include<stdio.h>
#include<TH1.h>
#include<TFile.h>
#include<set>
#include "HggReduce.C"

void Z12reduced()
{
  gROOT->SetStyle("Plain");
  gStyle -> SetTitleStyle(0000);
  
  //=========================== Set Up Files =============================//
  // Create and open text files to output and save Z masses
  

  // ==================================================================== //
  //                         * Electron ID Cuts *                         //
  //                                                                      //
  //  Loose Cuts : WP 90, Theoretical 90% Cut Efficiency for Electrons    //
  //  Tight Cuts : WP 70, Theoretical 70% Cut Efficiency for Electrons    //
  //  MVA ID Cut : Multivariant Analysis Marker for Electron Validity     //
  //                                                                      //
  //              *  Detector Geometry for Event Location *               //
  //   EB   = both particles detected in ECAL Barrel,     |eta|<1.44      //
  //   EE   = both particles detected in ECAL End Cap,    |eta|>1.52      //
  //   EBEE = one particle detected in Barrel and other in End Cap        //
  //   trueZmass refers to all Z masses of that cut type                  //
  //                                                                      //
  // ==================================================================== //

  // Z masses with any Electron ID cuts
  FILE* Zmass;
  FILE* ZmassEB;
  FILE* ZmassEE;
  FILE* ZmassEBEE;
  FILE* n2Ele;
  FILE* n3Ele;
  FILE* n4Ele;
  FILE* n5pEle;
  Zmass     = fopen("Ztextfiles/trueZmass.txt", "w+");
  ZmassEB   = fopen("Ztextfiles/dataZmassEB.txt", "w+");
  ZmassEE   = fopen("Ztextfiles/dataZmassEE.txt", "w+");
  ZmassEBEE = fopen("Ztextfiles/dataZmassEBEE.txt", "w+");
  n2Ele     = fopen("Ztextfiles/n2Ele.txt", "w+");
  n3Ele     = fopen("Ztextfiles/n3Ele.txt", "w+");
  n4Ele     = fopen("Ztextfiles/n4Ele.txt", "w+");
  n5pEle    = fopen("Ztextfiles/n5pEle.txt", "w+");
  
  // Z masses with Tight WP70 Cuts
  FILE* Zmasst;
  FILE* ZmassEBt;
  FILE* ZmassEEt;
  FILE* ZmassEBEEt;
  FILE* n2t;
  FILE* n3t;
  FILE* n4t;
  FILE* n5pt;
  Zmasst     = fopen("Ztextfiles/trueZmasst.txt", "w+");
  ZmassEBt   = fopen("Ztextfiles/dataZmassEBt.txt", "w+");
  ZmassEEt   = fopen("Ztextfiles/dataZmassEEt.txt", "w+");
  ZmassEBEEt = fopen("Ztextfiles/dataZmassEBEEt.txt", "w+");
  n2t        = fopen("Ztextfiles/n2t.txt", "w+");
  n3t        = fopen("Ztextfiles/n3t.txt", "w+");
  n4t        = fopen("Ztextfiles/n4t.txt", "w+");
  n5pt       = fopen("Ztextfiles/n5pt.txt", "w+");
  
  // Z masses with Loose WP90 Cuts
  FILE* Zmassl;
  FILE* ZmassEBl;
  FILE* ZmassEEl;
  FILE* ZmassEBEEl;
  FILE* n2l;
  FILE* n3l;
  FILE* n4l;
  FILE* n5pl;
  Zmassl     = fopen("Ztextfiles/trueZmassl.txt", "w+");
  ZmassEBl   = fopen("Ztextfiles/dataZmassEBl.txt", "w+");
  ZmassEEl   = fopen("Ztextfiles/dataZmassEEl.txt", "w+");
  ZmassEBEEl = fopen("Ztextfiles/dataZmassEBEEl.txt", "w+");
  n2l        = fopen("Ztextfiles/n2l.txt", "w+");
  n3l        = fopen("Ztextfiles/n3l.txt", "w+");
  n4l        = fopen("Ztextfiles/n4l.txt", "w+");
  n5pl       = fopen("Ztextfiles/n5pl.txt", "w+");
  
  // Z masses with MVA ID Cuts
  FILE* Zmassmva;
  FILE* ZmassEBmva;
  FILE* ZmassEEmva;
  FILE* ZmassEBEEmva;
  FILE* n2mva;
  FILE* n3mva;
  FILE* n4mva;
  FILE* n5pmva;
  Zmassmva     = fopen("Ztextfiles/trueZmassmva.txt", "w+");
  ZmassEBmva   = fopen("Ztextfiles/dataZmassEBmva.txt", "w+");
  ZmassEEmva   = fopen("Ztextfiles/dataZmassEEmva.txt", "w+");
  ZmassEBEEmva = fopen("Ztextfiles/dataZmassEBEEmva.txt", "w+");
  n2mva        = fopen("Ztextfiles/n2mva.txt", "w+");
  n3mva        = fopen("Ztextfiles/n3mva.txt", "w+");
  n4mva        = fopen("Ztextfiles/n4mva.txt", "w+");
  n5pmva       = fopen("Ztextfiles/n5pmva.txt", "w+");

  // Z masses with MVA ID and WP 70 Cuts
  FILE* Zmassmvat;
  FILE* ZmassEBmvat;
  FILE* ZmassEEmvat;
  FILE* ZmassEBEEmvat;
  FILE* n2mvat;
  FILE* n3mvat;
  FILE* n4mvat;
  FILE* n5pmvat;
  Zmassmvat     = fopen("Ztextfiles/trueZmassmvat.txt", "w+");
  ZmassEBmvat   = fopen("Ztextfiles/dataZmassEBmvat.txt", "w+");
  ZmassEEmvat   = fopen("Ztextfiles/dataZmassEEmvat.txt", "w+");
  ZmassEBEEmvat = fopen("Ztextfiles/dataZmassEBEEmvat.txt", "w+");
  n2mvat        = fopen("Ztextfiles/n2mvat.txt", "w+");
  n3mvat        = fopen("Ztextfiles/n3mvat.txt", "w+");
  n4mvat        = fopen("Ztextfiles/n4mvat.txt", "w+");
  n5pmvat       = fopen("Ztextfiles/n5pmvat.txt", "w+");
  
  //========================= Access Root Tree ============================//
  // Create a chain from the list of reduced data files with name "ZeeOutput"
  TChain *chain = loadList("2012data.list", "ZeeOutput");
  cout << "chain made" << endl;
  
  //===============  Create histograms to assign Z masses  ================//

  // Histograms for Z Masses with any Electron ID
  TH1F *trueZmass     = new TH1F ("All Z Masses", "All Z Masses", 300,50,120);
  TH1F *dataZmassEB   = new TH1F ("EB EB", "Barrel / Barrel", 300, 50, 120);
  TH1F *dataZmassEE   = new TH1F ("EE EE", "End Cap / End Cap", 300, 50, 120);
  TH1F *dataZmassEBEE = new TH1F ("EB EE", "Barrel / End Cap", 300, 50, 120);

  // Histograms for Uncut Z Masses split by Event Number of Electrons
  TH1F *hn2Ele  = new TH1F ("2 Electrons", "2 Electrons", 300, 50, 120);
  TH1F *hn3Ele  = new TH1F ("3 Electrons", "3 Electrons", 300, 50, 120);
  TH1F *hn4Ele  = new TH1F ("4 Electrons", "4 Electrons", 300, 50, 120);
  TH1F *hn5pEle = new TH1F ("Over 4 Electrons", "Over 4 Electrons", 300, 50, 120); 

 // Histograms for Z Masses with Tight Cuts
  TH1F *trueZmasst     = new TH1F ("Z w Tight Cuts", "Z Peak with Tight Cuts", 300,50,120);
  TH1F *dataZmassEBt   = new TH1F ("EB EB tight", "Barrel / Barrel", 300, 50, 120);
  TH1F *dataZmassEEt   = new TH1F ("EE EE tight", "End Cap / End Cap", 300, 50, 120);
  TH1F *dataZmassEBEEt = new TH1F ("EB EE tight", "Barrel / End Cap", 300, 50, 120);

  // Histograms for Z Masses with Tight Cuts split by Event Number of Electrons
  TH1F *hn2t  = new TH1F ("nEle = 2 Tight", "2 Electrons - Tight Cut", 300, 50, 120);
  TH1F *hn3t  = new TH1F ("nEle = 3 Tight", "3 Electrons - Tight Cut", 300, 50, 120);
  TH1F *hn4t  = new TH1F ("nEle = 4 Tight", "4 Electrons - Tight Cut", 300, 50, 120);
  TH1F *hn5pt = new TH1F ("nEle > 4 Tight", "Over 4 Electrons - Tight Cut", 300, 50, 120);

 // Histograms for Z Masses with Loose Cuts
  TH1F *trueZmassl     = new TH1F ("Z w Loose Cuts", "Z Peak with Loose Cuts", 300,50,120);
  TH1F *dataZmassEBl   = new TH1F ("EB EB loose", "Barrel / Barrel", 300, 50, 120);
  TH1F *dataZmassEEl   = new TH1F ("EE EE loose", "End Cap / End Cap", 300, 50, 120);
  TH1F *dataZmassEBEEl = new TH1F ("EB EE loose", "Barrel / End Cap", 300, 50, 120);

  // Histograms for Z Masses with Loose Cuts split by Event Number of Electrons
  TH1F *hn2l  = new TH1F ("nEle = 2 Loose", "2 Electrons - Loose Cut", 300, 50, 120);
  TH1F *hn3l  = new TH1F ("nEle = 3 Loose", "3 Electrons - Loose Cut", 300, 50, 120);
  TH1F *hn4l  = new TH1F ("nEle = 4 Loose", "4 Electrons - Loose Cut", 300, 50, 120);
  TH1F *hn5pl = new TH1F ("nEle > 4 Loose", "Over 4 Electrons - Loose Cut", 300, 50, 120);

 // Histograms for Z Masses with MVA ID Cuts
  TH1F *trueZmassmva     = new TH1F ("Z w MVA Cuts", "Z peak with MVA Non-Triggering Electron ID Cuts", 300,50,120);
  TH1F *dataZmassEBmva   = new TH1F ("EB EB MVA", "Barrel / Barrel", 300, 50, 120);
  TH1F *dataZmassEEmva   = new TH1F ("EE EE MVA", "End Cap / End Cap", 300, 50, 120);
  TH1F *dataZmassEBEEmva = new TH1F ("EB EE MVA", "Barrel / End Cap", 300, 50, 120);

  // Histograms for Z Masses with MVA ID Cuts split by Event Number of Electrons
  TH1F *hn2mva  = new TH1F ("nEle = 2 MVA", "2 Electrons - MVA Cut", 300, 50, 120);
  TH1F *hn3mva  = new TH1F ("nEle = 3 MVA", "3 Electrons - MVA Cut", 300, 50, 120);
  TH1F *hn4mva  = new TH1F ("nELe = 4 MVA", "4 Electrons - MVA Cut", 300, 50, 120);
  TH1F *hn5pmva = new TH1F ("nEle > 4 MVA", "Over 4 Electrons - MVA Cut", 300, 50, 120);

 // Histograms for Z Masses with MVA ID and Tight Cuts
  TH1F *trueZmassmvat     = new TH1F ("Z w MVA and Tight Cuts", "Z peak with Tight and MVA Non-Triggering Electron ID Cuts", 300,50,120);
  TH1F *dataZmassEBmvat   = new TH1F ("EB EB MVA Tight", "Barrel / Barrel", 300, 50, 120);
  TH1F *dataZmassEEmvat   = new TH1F ("EE EE MVA Tight", "End Cap / End Cap", 300, 50, 120);
  TH1F *dataZmassEBEEmvat = new TH1F ("EB EE MVA Tight", "Barrel / End Cap", 300, 50, 120);

  // Histograms for Z Masses with MVA ID and Tight Cuts split by Event Number of Electrons
  TH1F *hn2mvat  = new TH1F ("nEle = 2 MVA Tight", "2 Electrons - MVA Tight Cut", 300, 50, 120);
  TH1F *hn3mvat  = new TH1F ("nEle = 3 MVA Tight", "3 Electrons - MVA Tight Cut", 300, 50, 120);
  TH1F *hn4mvat  = new TH1F ("nELe = 4 MVA Tight", "4 Electrons - MVA Tight Cut", 300, 50, 120);
  TH1F *hn5pmvat = new TH1F ("nEle > 4 MVA Tight", "Over 4 Electrons - MVA Tight Cut", 300, 50, 120);
  
  // ========================  Main Event Loop  =========================//

  // Determine number of Events in Tree
  Int_t nevent = ZeeOutput->GetEntries();

  // Define Variables for Electron Processing
  Int_t   nbytes = 0;

  // Number of Z's for each cut status
  Float_t nZs     = 0;
  Float_t nZtight = 0;
  Float_t nZloose = 0;
  Float_t nZmva   = 0;
  Float_t nZmvat  = 0;

  // ====================================================================== //
  //     Loop through each event in tree and obtain values for physical     //
  //           properties of each potential electrons in the even           //
  // ====================================================================== //
  for (Int_t i=0; i<nevent;i++) {
    nbytes += ZeeOutput->GetEvent(i);   
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
    
    // =============  Fill the Histograms and Text Files with the Chosen Z masses  ============= //
    
    // Passing any of MVA, WP 90 or WP 70 cuts
    fprintf (Zmass,"%f \n",mass);           // Print to File
    trueZmass->Fill(mass);                  // Add to Histogram
    // Add count to number of uncut Zs    
    if (mass>80 && mass<100) {
      nZs += 1;                                  
    };
    
    // Separate uncut Zs by Event Location in ECAL
    // EB / EB
    if (fabs(eta1)<1.44 && fabs(eta2)<1.44) {
      fprintf (ZmassEB,"%f \n",mass);
      dataZmassEB->Fill(mass);
    };
    // EE / EE
    if (fabs(eta1)>1.52 && fabs(eta2)>1.52) {
      fprintf (ZmassEE,"%f \n", mass);
      dataZmassEE->Fill(mass);
    };
    // EB / EE
    if (fabs(eta1)<1.44 && fabs(eta2)>1.52) {
      fprintf (ZmassEBEE,"%f \n", mass);
      dataZmassEBEE->Fill(mass);
    };
    if (fabs(eta1)>1.52 && fabs(eta2)<1.44) {
      fprintf (ZmassEBEE,"%f \n", mass);
      dataZmassEBEE->Fill(mass);
    };
    
    // Separate uncut Zs by number of electrons in the event
    if (nEle == 2) {
      hn2Ele -> Fill(mass);
      fprintf (n2Ele,"%f \n" ,mass);
    };
    if (nEle == 3) {
      hn3Ele -> Fill(mass);
      fprintf (n3Ele,"%f \n" ,mass);
    };
    if (nEle == 4) {
      hn4Ele -> Fill(mass);
      fprintf (n4Ele,"%f \n" ,mass);
    };
    if (nEle >= 5) {
      hn5pEle -> Fill(mass);
      fprintf (n5pEle,"%f \n" ,mass);
    };
    
    // Tightly Cut Z masses
    if (passtight == 1.0) {
      fprintf (Zmasst,"%f \n",mass);      
      trueZmasst->Fill(mass);       
      
      // Add count to number of Zs with tight cuts      
      if (mass>80 && mass<100) {
	nZtight += 1;                          
      };
      
      // Separate tighly cut Zs by Event Location in ECAL
      // EB / EB
      if (fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	fprintf (ZmassEBt,"%f \n",mass);
	dataZmassEBt->Fill(mass);
      };
      // EE / EE
      if (fabs(eta1)>1.52 && fabs(eta2)>1.52) {
	fprintf (ZmassEEt,"%f \n", mass);
	dataZmassEEt->Fill(mass);
      };
      // EB / EE
      if (fabs(eta1)<1.44 && fabs(eta2)>1.52) {
	fprintf (ZmassEBEEt,"%f \n", mass);
	dataZmassEBEEt->Fill(mass);
      };
      if (fabs(eta1)>1.52 && fabs(eta2)<1.44) {
	fprintf (ZmassEBEEt,"%f \n", mass);
	dataZmassEBEEt->Fill(mass);
      };
      // Separate tighly cut Zs by the number of electrons in the event
      if (nEle == 2) {
	hn2t -> Fill(mass);
	fprintf (n2t,"%f \n" ,mass);
      };
      if (nEle == 3) {
	hn3t -> Fill(mass);
	fprintf (n3t,"%f \n" ,mass);
      };
      if (nEle == 4) {
	hn4t -> Fill(mass);
	fprintf (n4t,"%f \n" ,mass);
      };
      if (nEle >= 5) {
	hn5pt -> Fill(mass);
	fprintf (n5pt,"%f \n" ,mass);
      };
    };
    
    // Z masses with loose cuts
    if (passloose == 1.0) {
      fprintf (Zmassl,"%f \n",mass);   
      trueZmassl->Fill(mass);         
      
      // Add count to the number of Zs with loose cuts
      if ( mass>80 && mass<100) {
	nZloose += 1;                        
      };
      
      // Separate loosely cut Zs by Event Location in ECAL
      // EB / EB
      if (fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	fprintf (ZmassEBl,"%f \n",mass);
	dataZmassEBl->Fill(mass);
      };
      // EE / EE
      if (fabs(eta1)>1.52 && fabs(eta2)>1.52) {
	fprintf (ZmassEEl,"%f \n", mass);
	dataZmassEEl->Fill(mass);
      };
      // EB / EE
      if (fabs(eta1)<1.44 && fabs(eta2)>1.52) {
	fprintf (ZmassEBEEl,"%f \n", mass);
	dataZmassEBEEl->Fill(mass);
      };
      if (fabs(eta1)>1.52 && fabs(eta2)<1.44) {
	fprintf (ZmassEBEEl,"%f \n", mass);
	dataZmassEBEEl->Fill(mass);
      };
      // Separate loosely cut Zs by the number of electrons in the event
      if (nEle == 2) {
	hn2l -> Fill(mass);
	fprintf (n2l,"%f \n" ,mass);
      };
      if (nEle == 3) {
	hn3l -> Fill(mass);
	fprintf (n3l,"%f \n" ,mass);
      };
      if (nEle == 4) {
	hn4l -> Fill(mass);
	fprintf (n4l,"%f \n" ,mass);
      };
      if (nEle >= 5) {
	hn5pl -> Fill(mass);
	fprintf (n5pl,"%f \n" ,mass);
      };
    };
    
    // Zmass with MVA ID Cuts
    if (passmva == 1.0) {
      fprintf (Zmassmva,"%f \n",mass);   
      trueZmassmva->Fill(mass);  
      
      // Add count to the number of Zs with MVA ID cuts  
      if (mass>80 && mass<100) {
	nZmva += 1;                          
      };
      
      // Separate Zs with MVA ID cuts by Event Location in ECAL
      // EB / EB
      if (fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	fprintf (ZmassEBmva,"%f \n",mass);
	dataZmassEBmva->Fill(mass);
      };
      // EE / EE
      if (fabs(eta1)>1.52 && fabs(eta2)>1.52) {
	fprintf (ZmassEEmva,"%f \n", mass);
	dataZmassEEmva->Fill(mass);
      };
      // EB / EE
      if (fabs(eta1)<1.44 && fabs(eta2)>1.52) {
	fprintf (ZmassEBEEmva,"%f \n", mass);
	dataZmassEBEEmva->Fill(mass);
      };
      if (fabs(eta1)>1.52 && fabs(eta2)<1.44) {
	fprintf (ZmassEBEEmva,"%f \n", mass);
	dataZmassEBEEmva->Fill(mass);
      };
      // Separate Zs with MVA ID cuts by number of electrons in the event
      if (nEle == 2) {
	hn2mva -> Fill(mass);
	fprintf (n2mva,"%f \n" ,mass);
      };
      if (nEle == 3) {
	hn3mva -> Fill(mass);
	fprintf (n3mva,"%f \n" ,mass);
      };
      if (nEle == 4) {
	hn4mva -> Fill(mass);
	fprintf (n4mva,"%f \n" ,mass);
      };
      if (nEle >= 5) {
	hn5pmva -> Fill(mass);
	fprintf (n5pmva,"%f \n" ,mass);
      };
    };
    
    // Zmass with MVA ID and Tight Cuts
    if (passtight == 1.0 && passmva == 1.0) {
      fprintf (Zmassmvat,"%f \n",mass);   
      trueZmassmvat->Fill(mass);  
      
      // Add count to the number of Zs with MVA ID and Tight cuts  
      if (mass>80 && mass<100) {
	nZmvat += 1;                          
      };
      
      // Separate Zs with MVA ID and Tight cuts by Event Location in ECAL
      // EB / EB
      if (fabs(eta1)<1.44 && fabs(eta2)<1.44) {
	fprintf (ZmassEBmvat,"%f \n",mass);
	dataZmassEBmvat->Fill(mass);
      };
      // EE / EE
      if (fabs(eta1)>1.52 && fabs(eta2)>1.52) {
	fprintf (ZmassEEmvat,"%f \n", mass);
	dataZmassEEmvat->Fill(mass);
      };
      // EB / EE
      if (fabs(eta1)<1.44 && fabs(eta2)>1.52) {
	fprintf (ZmassEBEEmvat,"%f \n", mass);
	dataZmassEBEEmvat->Fill(mass);
      };
      if (fabs(eta1)>1.52 && fabs(eta2)<1.44) {
	fprintf (ZmassEBEEmvat,"%f \n", mass);
	dataZmassEBEEmvat->Fill(mass);
      };
      // Separate Zs with MVA ID cuts by number of electrons in the event
      if (nEle == 2) {
	hn2mvat -> Fill(mass);
	fprintf (n2mvat,"%f \n" ,mass);
      };
      if (nEle == 3) {
	hn3mvat -> Fill(mass);
	fprintf (n3mvat,"%f \n" ,mass);
      };
      if (nEle == 4) {
	hn4mvat -> Fill(mass);
	fprintf (n4mvat,"%f \n" ,mass);
      };
      if (nEle >= 5) {
	hn5pmvat -> Fill(mass);
	fprintf (n5pmvat,"%f \n" ,mass);
      };
    };
  };
  // ================== Calculate Efficiencies for each Cut =================== //
  //                    Efficiencies are calculated using:                      //   
  //               # of Z masses between 80 to 100 GeV with cut                 //
  //               --------------------------------------------                 //
  //                 # of Z masses between 80 to 100 GeV uncut                  //
  // ========================================================================== //
  
  Float_t effMVA   = 100*(nZmva/nZs);
  Float_t effMVAt  = 100*(nZmvat/nZs);
  Float_t effloose = 100*(nZloose/nZs);
  Float_t efftight = 100*(nZtight/nZs);
  
  //====================  Create Canvases to Plot Histograms ================== //
  
  // All Z Masses
  // Separated By Location
  TCanvas *c1 = new TCanvas("c1", "c1", 10,30,1000,700);
  c1->Divide(2,2);
  c1->cd(1);
  trueZmass->Draw();
  c1->cd(2);
  dataZmassEB->Draw();
  c1->cd(3);
  dataZmassEE->Draw();
  c1->cd(4);
  dataZmassEBEE->Draw();
  c1->Print("Ztextfiles/uncut.ps");
  
  // Separated by Number of Electrons in Event
  TCanvas *c2 = new TCanvas("c2", "c2", 10,30,1000,700);
  c2->Divide(2,2);
  c2->cd(1);
  hn2Ele->Draw();
  c2->cd(2);
  hn3Ele->Draw();
  c2->cd(3);
  hn4Ele->Draw();
  c2->cd(4);
  hn5pEle->Draw();
  c2->Print("Ztextfiles/uncutnEle.ps");

  // Z Masses passing WP 70 cuts
  TCanvas *c3 = new TCanvas("c3", "c3", 10,30,1000,700);
  c3->Divide(2,2);
  c3->cd(1);
  trueZmasst->Draw();
  // Print the Efficiency for the Tight Cuts
  TPaveText *p1 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p1->AddText(Form("Z Efficiency = %.2f", efftight));
  p1->Draw();
  c3->Update();
  c3->cd(2);
  dataZmassEBt->Draw();
  c3->cd(3);
  dataZmassEEt->Draw();
  c3->cd(4);
  dataZmassEBEEt->Draw();
  c3->Print("Ztextfiles/Tight.ps");

  // Separated by Number of Electrons in Event
  TCanvas *c4 = new TCanvas("c4", "c4", 10,30,1000,700);
  c4->Divide(2,2);
  c4->cd(1);
  hn2t->Draw();
  c4->cd(2);
  hn3t->Draw();
  c4->cd(3);
  hn4t->Draw();
  c4->cd(4);
  hn5pt->Draw();
  c4->Print("Ztextfiles/TightnEle.ps");

  // Z Masses passing WP 90 cuts
  TCanvas *c5 = new TCanvas("c5", "c5", 10,30,1000,700);
  c5->Divide(2,2);
  c5->cd(1);
  trueZmassl->Draw();
  // Print the Efficiency for the Loose Cuts
  TPaveText *p2 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p2->AddText(Form("Z Efficiency = %.2f", effloose));
  p2->Draw();
  c5->Update();
  c5->cd(2);
  dataZmassEBl->Draw();
  c5->cd(3);
  dataZmassEEl->Draw();
  c5->cd(4);
  dataZmassEBEEl->Draw();
  c5->Print("Ztextfiles/Loose.ps");

 // Separated by Number of Electrons in Event
  TCanvas *c6 = new TCanvas("c6", "c6", 10,30,1000,700);
  c6->Divide(2,2);
  c6->cd(1);
  hn2l->Draw();
  c6->cd(2);
  hn3l->Draw();
  c6->cd(3);
  hn4l->Draw();
  c6->cd(4);
  hn5pl->Draw();
  c6->Print("Ztextfiles/LoosenEle.ps");

  // Z Masses passng MVA ID cuts
  TCanvas *c7 = new TCanvas("c7", "c7", 10,30,1000,700);
  c7->Divide(2,2);
  c7->cd(1);
  trueZmassmva->Draw();
  // Print the Efficiency for the MVA ID Cuts
  TPaveText *p3 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p3->AddText(Form("Z Efficiency = %.2f", effMVA));
  p3->Draw();
  c7->Update();
  c7->cd(2);
  dataZmassEBmva->Draw();
  c7->cd(3);
  dataZmassEEmva->Draw();
  c7->cd(4);
  dataZmassEBEEmva->Draw();
  c7->Print("Ztextfiles/MVA.ps");

 // Separated by Number of Electrons in Event
  TCanvas *c8 = new TCanvas("c8", "c8", 10,30,1000,700);
  c8->Divide(2,2);
  c8->cd(1);
  hn2mva->Draw();
  c8->cd(2);
  hn3mva->Draw();
  c8->cd(3);
  hn4mva->Draw();
  c8->cd(4);
  hn5pmva->Draw();
  c8->Print("Ztextfiles/MVAnEle.ps");

 // Z Masses passing both MVA ID and WP 70 cuts
  TCanvas *c9 = new TCanvas("c9", "c", 10,30,1000,700);
  c9->Divide(2,2);
  c9->cd(1);
  trueZmassmvat->Draw();
  // Print the Efficiency for the MVA ID and Tight Cuts
  TPaveText *p4 = new TPaveText(0.645,0.7,0.9,0.8, "NDC");
  p4->AddText(Form("Z Efficiency = %.2f", effMVAt));
  p4->Draw();
  c9->Update();
  c9->cd(2);
  dataZmassEBmvat->Draw();
  c9->cd(3);
  dataZmassEEmvat->Draw();
  c9->cd(4);
  dataZmassEBEEmvat->Draw();
  c9->Print("Ztextfiles/MVAt.ps");

 // Separated by Number of Electrons in Event
  TCanvas *c10 = new TCanvas("c10", "c10", 10,30,1000,700);
  c10->Divide(2,2);
  c10->cd(1);
  hn2mvat->Draw();
  c10->cd(2);
  hn3mvat->Draw();
  c10->cd(3);
  hn4mvat->Draw();
  c10->cd(4);
  hn5pmvat->Draw();
  c10->Print("Ztextfiles/MVAtnEle.ps");

  // ================= Save Histograms and Close Files =================== //
  cout<<"saving files"<<endl;
  // Create file to save histograms to and write them all
  TFile *h = new TFile("histos_t.root", "RECREATE");
  trueZmass->Write();
  dataZmassEB->Write();
  dataZmassEE->Write();
  dataZmassEBEE->Write();
  hn2Ele->Write();
  hn3Ele->Write();
  hn4Ele->Write();
  hn5pEle->Write();
  trueZmasst->Write();
  dataZmassEBt->Write();
  dataZmassEEt->Write();
  dataZmassEBEEt->Write();
  hn2t->Write();
  hn3t->Write();
  hn4t->Write();
  hn5pt->Write();
  trueZmassl->Write();
  dataZmassEBl->Write();
  dataZmassEEl->Write();
  dataZmassEBEEl->Write();
  hn2l->Write();
  hn3l->Write();
  hn4l->Write();
  hn5pl->Write();
  trueZmassmva->Write();
  dataZmassEBmva->Write();
  dataZmassEEmva->Write();
  dataZmassEBEEmva->Write();
  hn2mva->Write();
  hn3mva->Write();
  hn4mva->Write();
  hn5pmva->Write();
  trueZmassmvat->Write();
  dataZmassEBmvat->Write();
  dataZmassEEmvat->Write();
  dataZmassEBEEmvat->Write();
  hn2mvat->Write();
  hn3mvat->Write();
  hn4mvat->Write();
  hn5pmvat->Write();
  h->Close();

  // Close all of the text files
  fclose(Zmass);
  fclose(ZmassEE);
  fclose(ZmassEB);
  fclose(ZmassEBEE);
  fclose(n2Ele);
  fclose(n3Ele);
  fclose(n4Ele);
  fclose(n5pEle);
  fclose(Zmasst);
  fclose(ZmassEEt);
  fclose(ZmassEBt);
  fclose(ZmassEBEEt);
  fclose(n2t);
  fclose(n3t);
  fclose(n4t);
  fclose(n5pt);
  fclose(Zmassl);
  fclose(ZmassEEl);
  fclose(ZmassEBl);
  fclose(ZmassEBEEl);
  fclose(n2l);
  fclose(n3l);
  fclose(n4l);
  fclose(n5pl);
  fclose(Zmassmva);
  fclose(ZmassEEmva);
  fclose(ZmassEBmva);
  fclose(ZmassEBEEmva);
  fclose(n2mva);
  fclose(n3mva);
  fclose(n4mva);
  fclose(n5pmva);
  fclose(Zmassmvat);
  fclose(ZmassEEmvat);
  fclose(ZmassEBmvat);
  fclose(ZmassEBEEmvat);
  fclose(n2mvat);
  fclose(n3mvat);
  fclose(n4mvat);
  fclose(n5pmvat);
}

