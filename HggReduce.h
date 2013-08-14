//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug  6 04:52:08 2012 by ROOT version 5.32/00
// from TTree HggReduce/HggReduce
// found on file: /mnt/hadoop/store/user/amott/Hgg2012/data/Prompt/Run2012B/DoubleElectron/Reduced/DoubleElectron_Run2012B_Prompt_50.root
//////////////////////////////////////////////////////////

#ifndef HggReduce_h
#define HggReduce_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <TObject.h>
#include <TVector3.h>
#include <utility>
#include <TLorentzVector.h>
#include <vector>
#include <utility>
#include <utility>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxPhotons = 6;
const Int_t kMaxggVerticesPhotonIndices = 15;
const Int_t kMaxggVerticesVertexIndex = 15;
const Int_t kMaxggVerticesVertexIndex2nd = 15;
const Int_t kMaxggVerticesVertexIndex3rd = 15;
const Int_t kMaxMuons = 21;
const Int_t kMaxElectrons = 8;
const Int_t kMaxJets = 29;

class HggReduce {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           lumiBlock;
   Int_t           runNumber;
   Int_t           evtNumber;
   Int_t           bunchX;
   Int_t           orbitNumber;
   Int_t           evtTime;
   Int_t           isRealData;
   Int_t           nVtx;
   Float_t         vtxX[25];   //[nVtx]
   Float_t         vtxY[25];   //[nVtx]
   Float_t         vtxZ[25];   //[nVtx]
   Float_t         vtxChi2[25];   //[nVtx]
   Float_t         vtxNdof[25];   //[nVtx]
   Float_t         vtxNormalizedChi2[25];   //[nVtx]
   Int_t           vtxTrackSize[25];   //[nVtx]
   Int_t           vtxIsFake[25];   //[nVtx]
   Int_t           vtxIsValid[25];   //[nVtx]
   Int_t           phyDeclared;
   Float_t         rho;
   Float_t         rhoEtaMax44;
   vector<short>   *pileupBunchX;
   vector<short>   *pileupNInteraction;
   Float_t         pileupTrueNumInterations;
   Int_t           nPho;
   Int_t           nPair;
   Int_t           Photons_;
   Int_t           Photons_index[kMaxPhotons];   //[Photons_]
   Float_t         Photons_energy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_eta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_phi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_correctedEnergy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_correctedEnergyError[kMaxPhotons];   //[Photons_]
   Float_t         Photons_scaledEnergy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_scaledEnergyError[kMaxPhotons];   //[Photons_]
   Float_t         Photons_finalEnergy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_finalEnergyError[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dEoE[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dEoEErr[kMaxPhotons];   //[Photons_]
   Int_t           Photons_SC_BCSeed_index[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_energy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_eta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_phi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e3x3[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e5x5[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_eTop[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_eLeft[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_eRight[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_eBottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_eMax[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e2nd[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e2x5Max[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e2x5Left[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e2x5Right[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e2x5Top[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_e2x5Bottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_etaCrystal[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_phiCrystal[kMaxPhotons];   //[Photons_]
   Int_t           Photons_SC_BCSeed_iEta[kMaxPhotons];   //[Photons_]
   Int_t           Photons_SC_BCSeed_iPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_thetaTilt[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_phiTilt[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_sigmaIEtaIEta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_sigmaIEtaIPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_BCSeed_sigmaIPhiIPhi[kMaxPhotons];   //[Photons_]
   Int_t           Photons_SC_nBCs[kMaxPhotons];   //[Photons_]
 //vector<VecbosBC> Photons_SC_basicClusters[kMaxPhotons];
   Int_t           Photons_SC_index[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_energy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_esEnergy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_eta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_phi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e3x3[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e5x5[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e3x1[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e1x3[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e4x4[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_eMax[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2x2[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2nd[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e1x5[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2x5Max[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2x5Left[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2x5Right[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2x5Top[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_e2x5Bottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_eLeft[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_eRight[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_eTop[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_eBottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_sigmaIEtaIEta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_sigmaIEtaIPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_sigmaIPhiIPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_esEffSigRR[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_SC_CaloPos_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_SC_CaloPos_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_SC_CaloPos_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_SC_CaloPos_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_SC_CaloPos_fZ[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_rawE[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_phiWidth[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_etaWidth[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_HoverE[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_r9[kMaxPhotons];   //[Photons_]
   Float_t         Photons_SC_s4ratio[kMaxPhotons];   //[Photons_]
   Int_t           Photons_PFSC_BCSeed_index[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_energy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_eta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_phi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e3x3[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e5x5[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_eTop[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_eLeft[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_eRight[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_eBottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_eMax[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e2nd[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e2x5Max[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e2x5Left[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e2x5Right[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e2x5Top[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_e2x5Bottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_etaCrystal[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_phiCrystal[kMaxPhotons];   //[Photons_]
   Int_t           Photons_PFSC_BCSeed_iEta[kMaxPhotons];   //[Photons_]
   Int_t           Photons_PFSC_BCSeed_iPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_thetaTilt[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_phiTilt[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_sigmaIEtaIEta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_sigmaIEtaIPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_BCSeed_sigmaIPhiIPhi[kMaxPhotons];   //[Photons_]
   Int_t           Photons_PFSC_nBCs[kMaxPhotons];   //[Photons_]
 //vector<VecbosBC> Photons_PFSC_basicClusters[kMaxPhotons];
   Int_t           Photons_PFSC_index[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_energy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_esEnergy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_eta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_phi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e3x3[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e5x5[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e3x1[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e1x3[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e4x4[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_eMax[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2x2[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2nd[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e1x5[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2x5Max[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2x5Left[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2x5Right[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2x5Top[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_e2x5Bottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_eLeft[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_eRight[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_eTop[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_eBottom[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_sigmaIEtaIEta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_sigmaIEtaIPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_sigmaIPhiIPhi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_esEffSigRR[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_PFSC_CaloPos_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_PFSC_CaloPos_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_PFSC_CaloPos_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_PFSC_CaloPos_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_PFSC_CaloPos_fZ[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_rawE[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_phiWidth[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_etaWidth[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_HoverE[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_r9[kMaxPhotons];   //[Photons_]
   Float_t         Photons_PFSC_s4ratio[kMaxPhotons];   //[Photons_]
 //vector<VecbosPFBC> Photons_PFSC_pfClusters[kMaxPhotons];
   Float_t         Photons_HoverE[kMaxPhotons];   //[Photons_]
   Float_t         Photons_HTowOverE[kMaxPhotons];   //[Photons_]
   Int_t           Photons_hasPixel[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_CaloPos_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_CaloPos_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_CaloPos_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_CaloPos_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_CaloPos_fZ[kMaxPhotons];   //[Photons_]
   vector<float>   Photons_photonTrkIsoFromVtx[kMaxPhotons];
   Float_t         Photons_photonWorstIsoDR03_first[kMaxPhotons];   //[Photons_]
   Int_t           Photons_photonWorstIsoDR03_second[kMaxPhotons];   //[Photons_]
   Float_t         Photons_photonWorstIsoDR04_first[kMaxPhotons];   //[Photons_]
   Int_t           Photons_photonWorstIsoDR04_second[kMaxPhotons];   //[Photons_]
   Int_t           Photons_conversion_index[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_pPair_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_pPair_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_pPair_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_pPair_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_pPair_fZ[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_pRefittedPair_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_pRefittedPair_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_pRefittedPair_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_pRefittedPair_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_pRefittedPair_fZ[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_p4RefittedPair_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_p4RefittedPair_fBits[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_p4RefittedPair_fP_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_p4RefittedPair_fP_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_p4RefittedPair_fP_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_p4RefittedPair_fP_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_p4RefittedPair_fP_fZ[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_p4RefittedPair_fE[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_CaloPos_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_CaloPos_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_CaloPos_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_CaloPos_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_CaloPos_fZ[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_eOverP[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_vtx_fUniqueID[kMaxPhotons];   //[Photons_]
   UInt_t          Photons_conversion_vtx_fBits[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_vtx_fX[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_vtx_fY[kMaxPhotons];   //[Photons_]
   Double_t        Photons_conversion_vtx_fZ[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_vtxChi2[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_vtxChi2Prob[kMaxPhotons];   //[Photons_]
   Bool_t          Photons_conversion_vtxIsValid[kMaxPhotons];   //[Photons_]
   Int_t           Photons_conversion_vtxNTracks[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_vtxMVA[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1Dz[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1DzError[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1Charge[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1Algo[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1D0[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1Pout[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk1Pin[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2Dz[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2DzError[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2Charge[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2Algo[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2D0[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2Pout[kMaxPhotons];   //[Photons_]
   Float_t         Photons_conversion_trk2Pin[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr03EcalRecHitSumEtCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr03HcalTowerSumEtCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr03TrkSumPtCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr03TrkSumPtHollowCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr04EcalRecHitSumEtCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr04HcalTowerSumEtCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr04TrkSumPtCone[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr04TrkSumPtHollowCone[kMaxPhotons];   //[Photons_]
   Int_t           Photons_nPV[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr01ChargedHadronPFIso[kMaxPhotons][100];   //[Photons_]
   Float_t         Photons_dr02ChargedHadronPFIso[kMaxPhotons][100];   //[Photons_]
   Float_t         Photons_dr03ChargedHadronPFIso[kMaxPhotons][100];   //[Photons_]
   Float_t         Photons_dr04ChargedHadronPFIso[kMaxPhotons][100];   //[Photons_]
   Float_t         Photons_dr05ChargedHadronPFIso[kMaxPhotons][100];   //[Photons_]
   Float_t         Photons_dr06ChargedHadronPFIso[kMaxPhotons][100];   //[Photons_]
   Float_t         Photons_dr01NeutralHadronPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr02NeutralHadronPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr03NeutralHadronPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr04NeutralHadronPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr05NeutralHadronPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr06NeutralHadronPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr01PhotonPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr02PhotonPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr03PhotonPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr04PhotonPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr05PhotonPFIso[kMaxPhotons];   //[Photons_]
   Float_t         Photons_dr06PhotonPFIso[kMaxPhotons];   //[Photons_]
   Int_t           Photons_genMatch_index[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_energy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_pt[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_eta[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_phi[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_mass[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_Vx[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_Vy[kMaxPhotons];   //[Photons_]
   Float_t         Photons_genMatch_Vz[kMaxPhotons];   //[Photons_]
   Int_t           Photons_genMatch_status[kMaxPhotons];   //[Photons_]
   Int_t           Photons_genMatch_id[kMaxPhotons];   //[Photons_]
   Int_t           Photons_genMatch_statusMother[kMaxPhotons];   //[Photons_]
   Int_t           Photons_genMatch_idMother[kMaxPhotons];   //[Photons_]
   Int_t           Photons_genMatch_indexMother[kMaxPhotons];   //[Photons_]
   Int_t           ggVerticesPhotonIndices_;
   Int_t           ggVerticesPhotonIndices_first[kMaxggVerticesPhotonIndices];   //[ggVerticesPhotonIndices_]
   Int_t           ggVerticesPhotonIndices_second[kMaxggVerticesPhotonIndices];   //[ggVerticesPhotonIndices_]
   Int_t           ggVerticesVertexIndex_;
   Int_t           ggVerticesVertexIndex_first[kMaxggVerticesVertexIndex];   //[ggVerticesVertexIndex_]
   Float_t         ggVerticesVertexIndex_second[kMaxggVerticesVertexIndex];   //[ggVerticesVertexIndex_]
   Int_t           ggVerticesVertexIndex2nd_;
   Int_t           ggVerticesVertexIndex2nd_first[kMaxggVerticesVertexIndex2nd];   //[ggVerticesVertexIndex2nd_]
   Float_t         ggVerticesVertexIndex2nd_second[kMaxggVerticesVertexIndex2nd];   //[ggVerticesVertexIndex2nd_]
   Int_t           ggVerticesVertexIndex3rd_;
   Int_t           ggVerticesVertexIndex3rd_first[kMaxggVerticesVertexIndex3rd];   //[ggVerticesVertexIndex3rd_]
   Float_t         ggVerticesVertexIndex3rd_second[kMaxggVerticesVertexIndex3rd];   //[ggVerticesVertexIndex3rd_]
   vector<float>   *ggVerticesPerEvtMVA;
   Bool_t          photonMatchedElectron[6];   //[nPho]
   Int_t           nMu;
   Int_t           Muons_;
   Int_t           Muons_index[kMaxMuons];   //[Muons_]
   Float_t         Muons_energy[kMaxMuons];   //[Muons_]
   Float_t         Muons_pt[kMaxMuons];   //[Muons_]
   Float_t         Muons_eta[kMaxMuons];   //[Muons_]
   Float_t         Muons_phi[kMaxMuons];   //[Muons_]
   Int_t           Muons_charge[kMaxMuons];   //[Muons_]
   Float_t         Muons_combinedIso[kMaxMuons];   //[Muons_]
   Float_t         Muons_emIso[kMaxMuons];   //[Muons_]
   Float_t         Muons_hadIso[kMaxMuons];   //[Muons_]
   Float_t         Muons_trkIso[kMaxMuons];   //[Muons_]
   Bool_t          Muons_isGlobalMuon[kMaxMuons];   //[Muons_]
   Bool_t          Muons_isTrackerMuon[kMaxMuons];   //[Muons_]
   Bool_t          Muons_isPromptMuon[kMaxMuons];   //[Muons_]
   Int_t           Muons_nTrackHits[kMaxMuons];   //[Muons_]
   Int_t           Muons_nPixelHits[kMaxMuons];   //[Muons_]
   Float_t         Muons_trackImpactPar[kMaxMuons];   //[Muons_]
   Bool_t          Muons_isLooseMuon[kMaxMuons];   //[Muons_]
   Bool_t          Muons_isTightMuon[kMaxMuons];   //[Muons_]
   Int_t           Muons_genMatch_index[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_energy[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_pt[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_eta[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_phi[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_mass[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_Vx[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_Vy[kMaxMuons];   //[Muons_]
   Float_t         Muons_genMatch_Vz[kMaxMuons];   //[Muons_]
   Int_t           Muons_genMatch_status[kMaxMuons];   //[Muons_]
   Int_t           Muons_genMatch_id[kMaxMuons];   //[Muons_]
   Int_t           Muons_genMatch_statusMother[kMaxMuons];   //[Muons_]
   Int_t           Muons_genMatch_idMother[kMaxMuons];   //[Muons_]
   Int_t           Muons_genMatch_indexMother[kMaxMuons];   //[Muons_]
   Int_t           nEle;
   Int_t           Electrons_;
   Int_t           Electrons_index[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_pt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_energy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_eta[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_phi[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_charge[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_correctedEnergy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_correctedEnergyError[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_SC_BCSeed_index[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_energy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_eta[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_phi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e3x3[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e5x5[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_eTop[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_eLeft[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_eRight[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_eBottom[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_eMax[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e2nd[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e2x5Max[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e2x5Left[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e2x5Right[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e2x5Top[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_e2x5Bottom[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_etaCrystal[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_phiCrystal[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_SC_BCSeed_iEta[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_SC_BCSeed_iPhi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_thetaTilt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_phiTilt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_sigmaIEtaIEta[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_sigmaIEtaIPhi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_BCSeed_sigmaIPhiIPhi[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_SC_nBCs[kMaxElectrons];   //[Electrons_]
 //vector<VecbosBC> Electrons_SC_basicClusters[kMaxElectrons];
   Int_t           Electrons_SC_index[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_energy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_esEnergy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_eta[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_phi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e3x3[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e5x5[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e3x1[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e1x3[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e4x4[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_eMax[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2x2[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2nd[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e1x5[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2x5Max[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2x5Left[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2x5Right[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2x5Top[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_e2x5Bottom[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_eLeft[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_eRight[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_eTop[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_eBottom[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_sigmaIEtaIEta[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_sigmaIEtaIPhi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_sigmaIPhiIPhi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_esEffSigRR[kMaxElectrons];   //[Electrons_]
   UInt_t          Electrons_SC_CaloPos_fUniqueID[kMaxElectrons];   //[Electrons_]
   UInt_t          Electrons_SC_CaloPos_fBits[kMaxElectrons];   //[Electrons_]
   Double_t        Electrons_SC_CaloPos_fX[kMaxElectrons];   //[Electrons_]
   Double_t        Electrons_SC_CaloPos_fY[kMaxElectrons];   //[Electrons_]
   Double_t        Electrons_SC_CaloPos_fZ[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_rawE[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_phiWidth[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_etaWidth[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_HoverE[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_r9[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_SC_s4ratio[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_esEnergy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_HoverE[kMaxElectrons];   //[Electrons_]
   Bool_t          Electrons_isEcalDriven[kMaxElectrons];   //[Electrons_]
   Bool_t          Electrons_isTrackerDriven[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_vtxX[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_vtxY[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_vtxZ[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_EOverP[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_d0Track[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dzTrack[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dEtaSCTrackAtVtx[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dPhiSCTrackAtVtx[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dEtaSCTrackAtCalo[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dPhiSCTrackAtCalo[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr03ChargedHadronPFIso[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr03NeutralHadronPFIso[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr03PhotonPFIso[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr04ChargedHadronPFIso[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr04NeutralHadronPFIso[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr04PhotonPFIso[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr03TkSumPt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr03EcalRecHitSumEt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr03HcalTowerSumEt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr04TkSumPt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr04EcalRecHitSumEt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_dr04HcalTowerSumEt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_idMVA[kMaxElectrons];   //[Electrons_]
   Bool_t          Electrons_hasMatchedConversion[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_expInnerLayersHits[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_genMatch_index[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_energy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_pt[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_eta[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_phi[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_mass[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_Vx[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_Vy[kMaxElectrons];   //[Electrons_]
   Float_t         Electrons_genMatch_Vz[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_genMatch_status[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_genMatch_id[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_genMatch_statusMother[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_genMatch_idMother[kMaxElectrons];   //[Electrons_]
   Int_t           Electrons_genMatch_indexMother[kMaxElectrons];   //[Electrons_]
   Int_t           nJet;
   Int_t           Jets_;
   Int_t           Jets_index[kMaxJets];   //[Jets_]
   Float_t         Jets_energy[kMaxJets];   //[Jets_]
   Float_t         Jets_uncorrEnergy[kMaxJets];   //[Jets_]
   Float_t         Jets_pt[kMaxJets];   //[Jets_]
   Float_t         Jets_eta[kMaxJets];   //[Jets_]
   Float_t         Jets_phi[kMaxJets];   //[Jets_]
   Int_t           Jets_charge[kMaxJets];   //[Jets_]
   Int_t           Jets_type[kMaxJets];   //[Jets_]
   Float_t         Jets_vtxX[kMaxJets];   //[Jets_]
   Float_t         Jets_vtxY[kMaxJets];   //[Jets_]
   Float_t         Jets_vtxZ[kMaxJets];   //[Jets_]
   Float_t         Jets_area[kMaxJets];   //[Jets_]
   Float_t         Jets_chargedHadronFraction[kMaxJets];   //[Jets_]
   Float_t         Jets_neutralHadronFraction[kMaxJets];   //[Jets_]
   Float_t         Jets_jetIdMva[kMaxJets];   //[Jets_]
   Float_t         Jets_betaStar[kMaxJets];   //[Jets_]
   Float_t         Jets_betaStarIdMVA[kMaxJets];   //[Jets_]
   Float_t         Jets_betaStarClassicIdMVA[kMaxJets];   //[Jets_]
   Float_t         Jets_rmsCands[kMaxJets];   //[Jets_]
   Float_t         Jets_rmsCandsHand[kMaxJets];   //[Jets_]
   Float_t         Jets_combinedSecondaryVertex[kMaxJets];   //[Jets_]
   Float_t         Jets_simpleSecondaryVertexHighPur[kMaxJets];   //[Jets_]
   Float_t         Jets_simpleSecondaryVertexHighEff[kMaxJets];   //[Jets_]
   Float_t         CaloMET;
   Float_t         CaloMETPhi;
   Float_t         PFMET;
   Float_t         PFMETPhi;
   Float_t         TCMET;
   Float_t         TCMETPhi;
   Float_t         ptbal;
   Float_t         ptasym;
   Float_t         logsumpt2;
   Float_t         limPullToConv;
   Float_t         nConv;

   // List of branches
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_evtNumber;   //!
   TBranch        *b_bunchX;   //!
   TBranch        *b_orbitNumber;   //!
   TBranch        *b_evtTime;   //!
   TBranch        *b_isRealData;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_vtxX;   //!
   TBranch        *b_vtxY;   //!
   TBranch        *b_vtxZ;   //!
   TBranch        *b_vtxChi2;   //!
   TBranch        *b_vtxNdof;   //!
   TBranch        *b_vtxNormalizedChi2;   //!
   TBranch        *b_vtxTrackSize;   //!
   TBranch        *b_vtxIsFake;   //!
   TBranch        *b_vtxIsValid;   //!
   TBranch        *b_phyDeclared;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoEtaMax44;   //!
   TBranch        *b_pileupBunchX;   //!
   TBranch        *b_pileupNInteraction;   //!
   TBranch        *b_pileupTrueNumInterations;   //!
   TBranch        *b_nPho;   //!
   TBranch        *b_nPair;   //!
   TBranch        *b_Photons_;   //!
   TBranch        *b_Photons_index;   //!
   TBranch        *b_Photons_energy;   //!
   TBranch        *b_Photons_eta;   //!
   TBranch        *b_Photons_phi;   //!
   TBranch        *b_Photons_correctedEnergy;   //!
   TBranch        *b_Photons_correctedEnergyError;   //!
   TBranch        *b_Photons_scaledEnergy;   //!
   TBranch        *b_Photons_scaledEnergyError;   //!
   TBranch        *b_Photons_finalEnergy;   //!
   TBranch        *b_Photons_finalEnergyError;   //!
   TBranch        *b_Photons_dEoE;   //!
   TBranch        *b_Photons_dEoEErr;   //!
   TBranch        *b_Photons_SC_BCSeed_index;   //!
   TBranch        *b_Photons_SC_BCSeed_energy;   //!
   TBranch        *b_Photons_SC_BCSeed_eta;   //!
   TBranch        *b_Photons_SC_BCSeed_phi;   //!
   TBranch        *b_Photons_SC_BCSeed_e3x3;   //!
   TBranch        *b_Photons_SC_BCSeed_e5x5;   //!
   TBranch        *b_Photons_SC_BCSeed_eTop;   //!
   TBranch        *b_Photons_SC_BCSeed_eLeft;   //!
   TBranch        *b_Photons_SC_BCSeed_eRight;   //!
   TBranch        *b_Photons_SC_BCSeed_eBottom;   //!
   TBranch        *b_Photons_SC_BCSeed_eMax;   //!
   TBranch        *b_Photons_SC_BCSeed_e2nd;   //!
   TBranch        *b_Photons_SC_BCSeed_e2x5Max;   //!
   TBranch        *b_Photons_SC_BCSeed_e2x5Left;   //!
   TBranch        *b_Photons_SC_BCSeed_e2x5Right;   //!
   TBranch        *b_Photons_SC_BCSeed_e2x5Top;   //!
   TBranch        *b_Photons_SC_BCSeed_e2x5Bottom;   //!
   TBranch        *b_Photons_SC_BCSeed_etaCrystal;   //!
   TBranch        *b_Photons_SC_BCSeed_phiCrystal;   //!
   TBranch        *b_Photons_SC_BCSeed_iEta;   //!
   TBranch        *b_Photons_SC_BCSeed_iPhi;   //!
   TBranch        *b_Photons_SC_BCSeed_thetaTilt;   //!
   TBranch        *b_Photons_SC_BCSeed_phiTilt;   //!
   TBranch        *b_Photons_SC_BCSeed_sigmaIEtaIEta;   //!
   TBranch        *b_Photons_SC_BCSeed_sigmaIEtaIPhi;   //!
   TBranch        *b_Photons_SC_BCSeed_sigmaIPhiIPhi;   //!
   TBranch        *b_Photons_SC_nBCs;   //!
   TBranch        *b_Photons_SC_index;   //!
   TBranch        *b_Photons_SC_energy;   //!
   TBranch        *b_Photons_SC_esEnergy;   //!
   TBranch        *b_Photons_SC_eta;   //!
   TBranch        *b_Photons_SC_phi;   //!
   TBranch        *b_Photons_SC_e3x3;   //!
   TBranch        *b_Photons_SC_e5x5;   //!
   TBranch        *b_Photons_SC_e3x1;   //!
   TBranch        *b_Photons_SC_e1x3;   //!
   TBranch        *b_Photons_SC_e4x4;   //!
   TBranch        *b_Photons_SC_eMax;   //!
   TBranch        *b_Photons_SC_e2x2;   //!
   TBranch        *b_Photons_SC_e2nd;   //!
   TBranch        *b_Photons_SC_e1x5;   //!
   TBranch        *b_Photons_SC_e2x5Max;   //!
   TBranch        *b_Photons_SC_e2x5Left;   //!
   TBranch        *b_Photons_SC_e2x5Right;   //!
   TBranch        *b_Photons_SC_e2x5Top;   //!
   TBranch        *b_Photons_SC_e2x5Bottom;   //!
   TBranch        *b_Photons_SC_eLeft;   //!
   TBranch        *b_Photons_SC_eRight;   //!
   TBranch        *b_Photons_SC_eTop;   //!
   TBranch        *b_Photons_SC_eBottom;   //!
   TBranch        *b_Photons_SC_sigmaIEtaIEta;   //!
   TBranch        *b_Photons_SC_sigmaIEtaIPhi;   //!
   TBranch        *b_Photons_SC_sigmaIPhiIPhi;   //!
   TBranch        *b_Photons_SC_esEffSigRR;   //!
   TBranch        *b_Photons_SC_CaloPos_fUniqueID;   //!
   TBranch        *b_Photons_SC_CaloPos_fBits;   //!
   TBranch        *b_Photons_SC_CaloPos_fX;   //!
   TBranch        *b_Photons_SC_CaloPos_fY;   //!
   TBranch        *b_Photons_SC_CaloPos_fZ;   //!
   TBranch        *b_Photons_SC_rawE;   //!
   TBranch        *b_Photons_SC_phiWidth;   //!
   TBranch        *b_Photons_SC_etaWidth;   //!
   TBranch        *b_Photons_SC_HoverE;   //!
   TBranch        *b_Photons_SC_r9;   //!
   TBranch        *b_Photons_SC_s4ratio;   //!
   TBranch        *b_Photons_PFSC_BCSeed_index;   //!
   TBranch        *b_Photons_PFSC_BCSeed_energy;   //!
   TBranch        *b_Photons_PFSC_BCSeed_eta;   //!
   TBranch        *b_Photons_PFSC_BCSeed_phi;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e3x3;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e5x5;   //!
   TBranch        *b_Photons_PFSC_BCSeed_eTop;   //!
   TBranch        *b_Photons_PFSC_BCSeed_eLeft;   //!
   TBranch        *b_Photons_PFSC_BCSeed_eRight;   //!
   TBranch        *b_Photons_PFSC_BCSeed_eBottom;   //!
   TBranch        *b_Photons_PFSC_BCSeed_eMax;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e2nd;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e2x5Max;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e2x5Left;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e2x5Right;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e2x5Top;   //!
   TBranch        *b_Photons_PFSC_BCSeed_e2x5Bottom;   //!
   TBranch        *b_Photons_PFSC_BCSeed_etaCrystal;   //!
   TBranch        *b_Photons_PFSC_BCSeed_phiCrystal;   //!
   TBranch        *b_Photons_PFSC_BCSeed_iEta;   //!
   TBranch        *b_Photons_PFSC_BCSeed_iPhi;   //!
   TBranch        *b_Photons_PFSC_BCSeed_thetaTilt;   //!
   TBranch        *b_Photons_PFSC_BCSeed_phiTilt;   //!
   TBranch        *b_Photons_PFSC_BCSeed_sigmaIEtaIEta;   //!
   TBranch        *b_Photons_PFSC_BCSeed_sigmaIEtaIPhi;   //!
   TBranch        *b_Photons_PFSC_BCSeed_sigmaIPhiIPhi;   //!
   TBranch        *b_Photons_PFSC_nBCs;   //!
   TBranch        *b_Photons_PFSC_index;   //!
   TBranch        *b_Photons_PFSC_energy;   //!
   TBranch        *b_Photons_PFSC_esEnergy;   //!
   TBranch        *b_Photons_PFSC_eta;   //!
   TBranch        *b_Photons_PFSC_phi;   //!
   TBranch        *b_Photons_PFSC_e3x3;   //!
   TBranch        *b_Photons_PFSC_e5x5;   //!
   TBranch        *b_Photons_PFSC_e3x1;   //!
   TBranch        *b_Photons_PFSC_e1x3;   //!
   TBranch        *b_Photons_PFSC_e4x4;   //!
   TBranch        *b_Photons_PFSC_eMax;   //!
   TBranch        *b_Photons_PFSC_e2x2;   //!
   TBranch        *b_Photons_PFSC_e2nd;   //!
   TBranch        *b_Photons_PFSC_e1x5;   //!
   TBranch        *b_Photons_PFSC_e2x5Max;   //!
   TBranch        *b_Photons_PFSC_e2x5Left;   //!
   TBranch        *b_Photons_PFSC_e2x5Right;   //!
   TBranch        *b_Photons_PFSC_e2x5Top;   //!
   TBranch        *b_Photons_PFSC_e2x5Bottom;   //!
   TBranch        *b_Photons_PFSC_eLeft;   //!
   TBranch        *b_Photons_PFSC_eRight;   //!
   TBranch        *b_Photons_PFSC_eTop;   //!
   TBranch        *b_Photons_PFSC_eBottom;   //!
   TBranch        *b_Photons_PFSC_sigmaIEtaIEta;   //!
   TBranch        *b_Photons_PFSC_sigmaIEtaIPhi;   //!
   TBranch        *b_Photons_PFSC_sigmaIPhiIPhi;   //!
   TBranch        *b_Photons_PFSC_esEffSigRR;   //!
   TBranch        *b_Photons_PFSC_CaloPos_fUniqueID;   //!
   TBranch        *b_Photons_PFSC_CaloPos_fBits;   //!
   TBranch        *b_Photons_PFSC_CaloPos_fX;   //!
   TBranch        *b_Photons_PFSC_CaloPos_fY;   //!
   TBranch        *b_Photons_PFSC_CaloPos_fZ;   //!
   TBranch        *b_Photons_PFSC_rawE;   //!
   TBranch        *b_Photons_PFSC_phiWidth;   //!
   TBranch        *b_Photons_PFSC_etaWidth;   //!
   TBranch        *b_Photons_PFSC_HoverE;   //!
   TBranch        *b_Photons_PFSC_r9;   //!
   TBranch        *b_Photons_PFSC_s4ratio;   //!
   TBranch        *b_Photons_HoverE;   //!
   TBranch        *b_Photons_HTowOverE;   //!
   TBranch        *b_Photons_hasPixel;   //!
   TBranch        *b_Photons_CaloPos_fUniqueID;   //!
   TBranch        *b_Photons_CaloPos_fBits;   //!
   TBranch        *b_Photons_CaloPos_fX;   //!
   TBranch        *b_Photons_CaloPos_fY;   //!
   TBranch        *b_Photons_CaloPos_fZ;   //!
   TBranch        *b_Photons_photonTrkIsoFromVtx;   //!
   TBranch        *b_Photons_photonWorstIsoDR03_first;   //!
   TBranch        *b_Photons_photonWorstIsoDR03_second;   //!
   TBranch        *b_Photons_photonWorstIsoDR04_first;   //!
   TBranch        *b_Photons_photonWorstIsoDR04_second;   //!
   TBranch        *b_Photons_conversion_index;   //!
   TBranch        *b_Photons_conversion_pPair_fUniqueID;   //!
   TBranch        *b_Photons_conversion_pPair_fBits;   //!
   TBranch        *b_Photons_conversion_pPair_fX;   //!
   TBranch        *b_Photons_conversion_pPair_fY;   //!
   TBranch        *b_Photons_conversion_pPair_fZ;   //!
   TBranch        *b_Photons_conversion_pRefittedPair_fUniqueID;   //!
   TBranch        *b_Photons_conversion_pRefittedPair_fBits;   //!
   TBranch        *b_Photons_conversion_pRefittedPair_fX;   //!
   TBranch        *b_Photons_conversion_pRefittedPair_fY;   //!
   TBranch        *b_Photons_conversion_pRefittedPair_fZ;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fUniqueID;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fBits;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fP_fUniqueID;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fP_fBits;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fP_fX;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fP_fY;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fP_fZ;   //!
   TBranch        *b_Photons_conversion_p4RefittedPair_fE;   //!
   TBranch        *b_Photons_conversion_CaloPos_fUniqueID;   //!
   TBranch        *b_Photons_conversion_CaloPos_fBits;   //!
   TBranch        *b_Photons_conversion_CaloPos_fX;   //!
   TBranch        *b_Photons_conversion_CaloPos_fY;   //!
   TBranch        *b_Photons_conversion_CaloPos_fZ;   //!
   TBranch        *b_Photons_conversion_eOverP;   //!
   TBranch        *b_Photons_conversion_vtx_fUniqueID;   //!
   TBranch        *b_Photons_conversion_vtx_fBits;   //!
   TBranch        *b_Photons_conversion_vtx_fX;   //!
   TBranch        *b_Photons_conversion_vtx_fY;   //!
   TBranch        *b_Photons_conversion_vtx_fZ;   //!
   TBranch        *b_Photons_conversion_vtxChi2;   //!
   TBranch        *b_Photons_conversion_vtxChi2Prob;   //!
   TBranch        *b_Photons_conversion_vtxIsValid;   //!
   TBranch        *b_Photons_conversion_vtxNTracks;   //!
   TBranch        *b_Photons_conversion_vtxMVA;   //!
   TBranch        *b_Photons_conversion_trk1Dz;   //!
   TBranch        *b_Photons_conversion_trk1DzError;   //!
   TBranch        *b_Photons_conversion_trk1Charge;   //!
   TBranch        *b_Photons_conversion_trk1Algo;   //!
   TBranch        *b_Photons_conversion_trk1D0;   //!
   TBranch        *b_Photons_conversion_trk1Pout;   //!
   TBranch        *b_Photons_conversion_trk1Pin;   //!
   TBranch        *b_Photons_conversion_trk2Dz;   //!
   TBranch        *b_Photons_conversion_trk2DzError;   //!
   TBranch        *b_Photons_conversion_trk2Charge;   //!
   TBranch        *b_Photons_conversion_trk2Algo;   //!
   TBranch        *b_Photons_conversion_trk2D0;   //!
   TBranch        *b_Photons_conversion_trk2Pout;   //!
   TBranch        *b_Photons_conversion_trk2Pin;   //!
   TBranch        *b_Photons_dr03EcalRecHitSumEtCone;   //!
   TBranch        *b_Photons_dr03HcalTowerSumEtCone;   //!
   TBranch        *b_Photons_dr03TrkSumPtCone;   //!
   TBranch        *b_Photons_dr03TrkSumPtHollowCone;   //!
   TBranch        *b_Photons_dr04EcalRecHitSumEtCone;   //!
   TBranch        *b_Photons_dr04HcalTowerSumEtCone;   //!
   TBranch        *b_Photons_dr04TrkSumPtCone;   //!
   TBranch        *b_Photons_dr04TrkSumPtHollowCone;   //!
   TBranch        *b_Photons_nPV;   //!
   TBranch        *b_Photons_dr01ChargedHadronPFIso;   //!
   TBranch        *b_Photons_dr02ChargedHadronPFIso;   //!
   TBranch        *b_Photons_dr03ChargedHadronPFIso;   //!
   TBranch        *b_Photons_dr04ChargedHadronPFIso;   //!
   TBranch        *b_Photons_dr05ChargedHadronPFIso;   //!
   TBranch        *b_Photons_dr06ChargedHadronPFIso;   //!
   TBranch        *b_Photons_dr01NeutralHadronPFIso;   //!
   TBranch        *b_Photons_dr02NeutralHadronPFIso;   //!
   TBranch        *b_Photons_dr03NeutralHadronPFIso;   //!
   TBranch        *b_Photons_dr04NeutralHadronPFIso;   //!
   TBranch        *b_Photons_dr05NeutralHadronPFIso;   //!
   TBranch        *b_Photons_dr06NeutralHadronPFIso;   //!
   TBranch        *b_Photons_dr01PhotonPFIso;   //!
   TBranch        *b_Photons_dr02PhotonPFIso;   //!
   TBranch        *b_Photons_dr03PhotonPFIso;   //!
   TBranch        *b_Photons_dr04PhotonPFIso;   //!
   TBranch        *b_Photons_dr05PhotonPFIso;   //!
   TBranch        *b_Photons_dr06PhotonPFIso;   //!
   TBranch        *b_Photons_genMatch_index;   //!
   TBranch        *b_Photons_genMatch_energy;   //!
   TBranch        *b_Photons_genMatch_pt;   //!
   TBranch        *b_Photons_genMatch_eta;   //!
   TBranch        *b_Photons_genMatch_phi;   //!
   TBranch        *b_Photons_genMatch_mass;   //!
   TBranch        *b_Photons_genMatch_Vx;   //!
   TBranch        *b_Photons_genMatch_Vy;   //!
   TBranch        *b_Photons_genMatch_Vz;   //!
   TBranch        *b_Photons_genMatch_status;   //!
   TBranch        *b_Photons_genMatch_id;   //!
   TBranch        *b_Photons_genMatch_statusMother;   //!
   TBranch        *b_Photons_genMatch_idMother;   //!
   TBranch        *b_Photons_genMatch_indexMother;   //!
   TBranch        *b_ggVerticesPhotonIndices_;   //!
   TBranch        *b_ggVerticesPhotonIndices_first;   //!
   TBranch        *b_ggVerticesPhotonIndices_second;   //!
   TBranch        *b_ggVerticesVertexIndex_;   //!
   TBranch        *b_ggVerticesVertexIndex_first;   //!
   TBranch        *b_ggVerticesVertexIndex_second;   //!
   TBranch        *b_ggVerticesVertexIndex2nd_;   //!
   TBranch        *b_ggVerticesVertexIndex2nd_first;   //!
   TBranch        *b_ggVerticesVertexIndex2nd_second;   //!
   TBranch        *b_ggVerticesVertexIndex3rd_;   //!
   TBranch        *b_ggVerticesVertexIndex3rd_first;   //!
   TBranch        *b_ggVerticesVertexIndex3rd_second;   //!
   TBranch        *b_ggVerticesPerEvtMVA;   //!
   TBranch        *b_photonMatchedElectron;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_Muons_;   //!
   TBranch        *b_Muons_index;   //!
   TBranch        *b_Muons_energy;   //!
   TBranch        *b_Muons_pt;   //!
   TBranch        *b_Muons_eta;   //!
   TBranch        *b_Muons_phi;   //!
   TBranch        *b_Muons_charge;   //!
   TBranch        *b_Muons_combinedIso;   //!
   TBranch        *b_Muons_emIso;   //!
   TBranch        *b_Muons_hadIso;   //!
   TBranch        *b_Muons_trkIso;   //!
   TBranch        *b_Muons_isGlobalMuon;   //!
   TBranch        *b_Muons_isTrackerMuon;   //!
   TBranch        *b_Muons_isPromptMuon;   //!
   TBranch        *b_Muons_nTrackHits;   //!
   TBranch        *b_Muons_nPixelHits;   //!
   TBranch        *b_Muons_trackImpactPar;   //!
   TBranch        *b_Muons_isLooseMuon;   //!
   TBranch        *b_Muons_isTightMuon;   //!
   TBranch        *b_Muons_genMatch_index;   //!
   TBranch        *b_Muons_genMatch_energy;   //!
   TBranch        *b_Muons_genMatch_pt;   //!
   TBranch        *b_Muons_genMatch_eta;   //!
   TBranch        *b_Muons_genMatch_phi;   //!
   TBranch        *b_Muons_genMatch_mass;   //!
   TBranch        *b_Muons_genMatch_Vx;   //!
   TBranch        *b_Muons_genMatch_Vy;   //!
   TBranch        *b_Muons_genMatch_Vz;   //!
   TBranch        *b_Muons_genMatch_status;   //!
   TBranch        *b_Muons_genMatch_id;   //!
   TBranch        *b_Muons_genMatch_statusMother;   //!
   TBranch        *b_Muons_genMatch_idMother;   //!
   TBranch        *b_Muons_genMatch_indexMother;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_Electrons_;   //!
   TBranch        *b_Electrons_index;   //!
   TBranch        *b_Electrons_pt;   //!
   TBranch        *b_Electrons_energy;   //!
   TBranch        *b_Electrons_eta;   //!
   TBranch        *b_Electrons_phi;   //!
   TBranch        *b_Electrons_charge;   //!
   TBranch        *b_Electrons_correctedEnergy;   //!
   TBranch        *b_Electrons_correctedEnergyError;   //!
   TBranch        *b_Electrons_SC_BCSeed_index;   //!
   TBranch        *b_Electrons_SC_BCSeed_energy;   //!
   TBranch        *b_Electrons_SC_BCSeed_eta;   //!
   TBranch        *b_Electrons_SC_BCSeed_phi;   //!
   TBranch        *b_Electrons_SC_BCSeed_e3x3;   //!
   TBranch        *b_Electrons_SC_BCSeed_e5x5;   //!
   TBranch        *b_Electrons_SC_BCSeed_eTop;   //!
   TBranch        *b_Electrons_SC_BCSeed_eLeft;   //!
   TBranch        *b_Electrons_SC_BCSeed_eRight;   //!
   TBranch        *b_Electrons_SC_BCSeed_eBottom;   //!
   TBranch        *b_Electrons_SC_BCSeed_eMax;   //!
   TBranch        *b_Electrons_SC_BCSeed_e2nd;   //!
   TBranch        *b_Electrons_SC_BCSeed_e2x5Max;   //!
   TBranch        *b_Electrons_SC_BCSeed_e2x5Left;   //!
   TBranch        *b_Electrons_SC_BCSeed_e2x5Right;   //!
   TBranch        *b_Electrons_SC_BCSeed_e2x5Top;   //!
   TBranch        *b_Electrons_SC_BCSeed_e2x5Bottom;   //!
   TBranch        *b_Electrons_SC_BCSeed_etaCrystal;   //!
   TBranch        *b_Electrons_SC_BCSeed_phiCrystal;   //!
   TBranch        *b_Electrons_SC_BCSeed_iEta;   //!
   TBranch        *b_Electrons_SC_BCSeed_iPhi;   //!
   TBranch        *b_Electrons_SC_BCSeed_thetaTilt;   //!
   TBranch        *b_Electrons_SC_BCSeed_phiTilt;   //!
   TBranch        *b_Electrons_SC_BCSeed_sigmaIEtaIEta;   //!
   TBranch        *b_Electrons_SC_BCSeed_sigmaIEtaIPhi;   //!
   TBranch        *b_Electrons_SC_BCSeed_sigmaIPhiIPhi;   //!
   TBranch        *b_Electrons_SC_nBCs;   //!
   TBranch        *b_Electrons_SC_index;   //!
   TBranch        *b_Electrons_SC_energy;   //!
   TBranch        *b_Electrons_SC_esEnergy;   //!
   TBranch        *b_Electrons_SC_eta;   //!
   TBranch        *b_Electrons_SC_phi;   //!
   TBranch        *b_Electrons_SC_e3x3;   //!
   TBranch        *b_Electrons_SC_e5x5;   //!
   TBranch        *b_Electrons_SC_e3x1;   //!
   TBranch        *b_Electrons_SC_e1x3;   //!
   TBranch        *b_Electrons_SC_e4x4;   //!
   TBranch        *b_Electrons_SC_eMax;   //!
   TBranch        *b_Electrons_SC_e2x2;   //!
   TBranch        *b_Electrons_SC_e2nd;   //!
   TBranch        *b_Electrons_SC_e1x5;   //!
   TBranch        *b_Electrons_SC_e2x5Max;   //!
   TBranch        *b_Electrons_SC_e2x5Left;   //!
   TBranch        *b_Electrons_SC_e2x5Right;   //!
   TBranch        *b_Electrons_SC_e2x5Top;   //!
   TBranch        *b_Electrons_SC_e2x5Bottom;   //!
   TBranch        *b_Electrons_SC_eLeft;   //!
   TBranch        *b_Electrons_SC_eRight;   //!
   TBranch        *b_Electrons_SC_eTop;   //!
   TBranch        *b_Electrons_SC_eBottom;   //!
   TBranch        *b_Electrons_SC_sigmaIEtaIEta;   //!
   TBranch        *b_Electrons_SC_sigmaIEtaIPhi;   //!
   TBranch        *b_Electrons_SC_sigmaIPhiIPhi;   //!
   TBranch        *b_Electrons_SC_esEffSigRR;   //!
   TBranch        *b_Electrons_SC_CaloPos_fUniqueID;   //!
   TBranch        *b_Electrons_SC_CaloPos_fBits;   //!
   TBranch        *b_Electrons_SC_CaloPos_fX;   //!
   TBranch        *b_Electrons_SC_CaloPos_fY;   //!
   TBranch        *b_Electrons_SC_CaloPos_fZ;   //!
   TBranch        *b_Electrons_SC_rawE;   //!
   TBranch        *b_Electrons_SC_phiWidth;   //!
   TBranch        *b_Electrons_SC_etaWidth;   //!
   TBranch        *b_Electrons_SC_HoverE;   //!
   TBranch        *b_Electrons_SC_r9;   //!
   TBranch        *b_Electrons_SC_s4ratio;   //!
   TBranch        *b_Electrons_esEnergy;   //!
   TBranch        *b_Electrons_HoverE;   //!
   TBranch        *b_Electrons_isEcalDriven;   //!
   TBranch        *b_Electrons_isTrackerDriven;   //!
   TBranch        *b_Electrons_vtxX;   //!
   TBranch        *b_Electrons_vtxY;   //!
   TBranch        *b_Electrons_vtxZ;   //!
   TBranch        *b_Electrons_EOverP;   //!
   TBranch        *b_Electrons_d0Track;   //!
   TBranch        *b_Electrons_dzTrack;   //!
   TBranch        *b_Electrons_dEtaSCTrackAtVtx;   //!
   TBranch        *b_Electrons_dPhiSCTrackAtVtx;   //!
   TBranch        *b_Electrons_dEtaSCTrackAtCalo;   //!
   TBranch        *b_Electrons_dPhiSCTrackAtCalo;   //!
   TBranch        *b_Electrons_dr03ChargedHadronPFIso;   //!
   TBranch        *b_Electrons_dr03NeutralHadronPFIso;   //!
   TBranch        *b_Electrons_dr03PhotonPFIso;   //!
   TBranch        *b_Electrons_dr04ChargedHadronPFIso;   //!
   TBranch        *b_Electrons_dr04NeutralHadronPFIso;   //!
   TBranch        *b_Electrons_dr04PhotonPFIso;   //!
   TBranch        *b_Electrons_dr03TkSumPt;   //!
   TBranch        *b_Electrons_dr03EcalRecHitSumEt;   //!
   TBranch        *b_Electrons_dr03HcalTowerSumEt;   //!
   TBranch        *b_Electrons_dr04TkSumPt;   //!
   TBranch        *b_Electrons_dr04EcalRecHitSumEt;   //!
   TBranch        *b_Electrons_dr04HcalTowerSumEt;   //!
   TBranch        *b_Electrons_idMVA;   //!
   TBranch        *b_Electrons_hasMatchedConversion;   //!
   TBranch        *b_Electrons_expInnerLayersHits;   //!
   TBranch        *b_Electrons_genMatch_index;   //!
   TBranch        *b_Electrons_genMatch_energy;   //!
   TBranch        *b_Electrons_genMatch_pt;   //!
   TBranch        *b_Electrons_genMatch_eta;   //!
   TBranch        *b_Electrons_genMatch_phi;   //!
   TBranch        *b_Electrons_genMatch_mass;   //!
   TBranch        *b_Electrons_genMatch_Vx;   //!
   TBranch        *b_Electrons_genMatch_Vy;   //!
   TBranch        *b_Electrons_genMatch_Vz;   //!
   TBranch        *b_Electrons_genMatch_status;   //!
   TBranch        *b_Electrons_genMatch_id;   //!
   TBranch        *b_Electrons_genMatch_statusMother;   //!
   TBranch        *b_Electrons_genMatch_idMother;   //!
   TBranch        *b_Electrons_genMatch_indexMother;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jets_;   //!
   TBranch        *b_Jets_index;   //!
   TBranch        *b_Jets_energy;   //!
   TBranch        *b_Jets_uncorrEnergy;   //!
   TBranch        *b_Jets_pt;   //!
   TBranch        *b_Jets_eta;   //!
   TBranch        *b_Jets_phi;   //!
   TBranch        *b_Jets_charge;   //!
   TBranch        *b_Jets_type;   //!
   TBranch        *b_Jets_vtxX;   //!
   TBranch        *b_Jets_vtxY;   //!
   TBranch        *b_Jets_vtxZ;   //!
   TBranch        *b_Jets_area;   //!
   TBranch        *b_Jets_chargedHadronFraction;   //!
   TBranch        *b_Jets_neutralHadronFraction;   //!
   TBranch        *b_Jets_jetIdMva;   //!
   TBranch        *b_Jets_betaStar;   //!
   TBranch        *b_Jets_betaStarIdMVA;   //!
   TBranch        *b_Jets_betaStarClassicIdMVA;   //!
   TBranch        *b_Jets_rmsCands;   //!
   TBranch        *b_Jets_rmsCandsHand;   //!
   TBranch        *b_Jets_combinedSecondaryVertex;   //!
   TBranch        *b_Jets_simpleSecondaryVertexHighPur;   //!
   TBranch        *b_Jets_simpleSecondaryVertexHighEff;   //!
   TBranch        *b_CaloMET;   //!
   TBranch        *b_CaloMETPhi;   //!
   TBranch        *b_PFMET;   //!
   TBranch        *b_PFMETPhi;   //!
   TBranch        *b_TCMET;   //!
   TBranch        *b_TCMETPhi;   //!
   TBranch        *b_ptbal;   //!
   TBranch        *b_ptasym;   //!
   TBranch        *b_logsumpt2;   //!
   TBranch        *b_limPullToConv;   //!
   TBranch        *b_nConv;   //!

   HggReduce(TTree *tree=0);
   virtual ~HggReduce();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HggReduce_cxx
HggReduce::HggReduce(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/hadoop/store/user/amott/Hgg2012/data/Prompt/Run2012B/DoubleElectron/Reduced/DoubleElectron_Run2012B_Prompt_50.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/hadoop/store/user/amott/Hgg2012/data/Prompt/Run2012B/DoubleElectron/Reduced/DoubleElectron_Run2012B_Prompt_50.root");
      }
      f->GetObject("HggReduce",tree);

   }
   Init(tree);
}

HggReduce::~HggReduce()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HggReduce::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HggReduce::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HggReduce::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pileupBunchX = 0;
   pileupNInteraction = 0;
   ggVerticesPerEvtMVA = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("evtNumber", &evtNumber, &b_evtNumber);
   fChain->SetBranchAddress("bunchX", &bunchX, &b_bunchX);
   fChain->SetBranchAddress("orbitNumber", &orbitNumber, &b_orbitNumber);
   fChain->SetBranchAddress("evtTime", &evtTime, &b_evtTime);
   fChain->SetBranchAddress("isRealData", &isRealData, &b_isRealData);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("vtxX", vtxX, &b_vtxX);
   fChain->SetBranchAddress("vtxY", vtxY, &b_vtxY);
   fChain->SetBranchAddress("vtxZ", vtxZ, &b_vtxZ);
   fChain->SetBranchAddress("vtxChi2", vtxChi2, &b_vtxChi2);
   fChain->SetBranchAddress("vtxNdof", vtxNdof, &b_vtxNdof);
   fChain->SetBranchAddress("vtxNormalizedChi2", vtxNormalizedChi2, &b_vtxNormalizedChi2);
   fChain->SetBranchAddress("vtxTrackSize", vtxTrackSize, &b_vtxTrackSize);
   fChain->SetBranchAddress("vtxIsFake", vtxIsFake, &b_vtxIsFake);
   fChain->SetBranchAddress("vtxIsValid", vtxIsValid, &b_vtxIsValid);
   fChain->SetBranchAddress("phyDeclared", &phyDeclared, &b_phyDeclared);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoEtaMax44", &rhoEtaMax44, &b_rhoEtaMax44);
   fChain->SetBranchAddress("pileupBunchX", &pileupBunchX, &b_pileupBunchX);
   fChain->SetBranchAddress("pileupNInteraction", &pileupNInteraction, &b_pileupNInteraction);
   fChain->SetBranchAddress("pileupTrueNumInterations", &pileupTrueNumInterations, &b_pileupTrueNumInterations);
   fChain->SetBranchAddress("nPho", &nPho, &b_nPho);
   fChain->SetBranchAddress("nPair", &nPair, &b_nPair);
   fChain->SetBranchAddress("Photons", &Photons_, &b_Photons_);
   fChain->SetBranchAddress("Photons.index", Photons_index, &b_Photons_index);
   fChain->SetBranchAddress("Photons.energy", Photons_energy, &b_Photons_energy);
   fChain->SetBranchAddress("Photons.eta", Photons_eta, &b_Photons_eta);
   fChain->SetBranchAddress("Photons.phi", Photons_phi, &b_Photons_phi);
   fChain->SetBranchAddress("Photons.correctedEnergy", Photons_correctedEnergy, &b_Photons_correctedEnergy);
   fChain->SetBranchAddress("Photons.correctedEnergyError", Photons_correctedEnergyError, &b_Photons_correctedEnergyError);
   fChain->SetBranchAddress("Photons.scaledEnergy", Photons_scaledEnergy, &b_Photons_scaledEnergy);
   fChain->SetBranchAddress("Photons.scaledEnergyError", Photons_scaledEnergyError, &b_Photons_scaledEnergyError);
   fChain->SetBranchAddress("Photons.finalEnergy", Photons_finalEnergy, &b_Photons_finalEnergy);
   fChain->SetBranchAddress("Photons.finalEnergyError", Photons_finalEnergyError, &b_Photons_finalEnergyError);
   fChain->SetBranchAddress("Photons.dEoE", Photons_dEoE, &b_Photons_dEoE);
   fChain->SetBranchAddress("Photons.dEoEErr", Photons_dEoEErr, &b_Photons_dEoEErr);
   fChain->SetBranchAddress("Photons.SC.BCSeed.index", Photons_SC_BCSeed_index, &b_Photons_SC_BCSeed_index);
   fChain->SetBranchAddress("Photons.SC.BCSeed.energy", Photons_SC_BCSeed_energy, &b_Photons_SC_BCSeed_energy);
   fChain->SetBranchAddress("Photons.SC.BCSeed.eta", Photons_SC_BCSeed_eta, &b_Photons_SC_BCSeed_eta);
   fChain->SetBranchAddress("Photons.SC.BCSeed.phi", Photons_SC_BCSeed_phi, &b_Photons_SC_BCSeed_phi);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e3x3", Photons_SC_BCSeed_e3x3, &b_Photons_SC_BCSeed_e3x3);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e5x5", Photons_SC_BCSeed_e5x5, &b_Photons_SC_BCSeed_e5x5);
   fChain->SetBranchAddress("Photons.SC.BCSeed.eTop", Photons_SC_BCSeed_eTop, &b_Photons_SC_BCSeed_eTop);
   fChain->SetBranchAddress("Photons.SC.BCSeed.eLeft", Photons_SC_BCSeed_eLeft, &b_Photons_SC_BCSeed_eLeft);
   fChain->SetBranchAddress("Photons.SC.BCSeed.eRight", Photons_SC_BCSeed_eRight, &b_Photons_SC_BCSeed_eRight);
   fChain->SetBranchAddress("Photons.SC.BCSeed.eBottom", Photons_SC_BCSeed_eBottom, &b_Photons_SC_BCSeed_eBottom);
   fChain->SetBranchAddress("Photons.SC.BCSeed.eMax", Photons_SC_BCSeed_eMax, &b_Photons_SC_BCSeed_eMax);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e2nd", Photons_SC_BCSeed_e2nd, &b_Photons_SC_BCSeed_e2nd);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e2x5Max", Photons_SC_BCSeed_e2x5Max, &b_Photons_SC_BCSeed_e2x5Max);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e2x5Left", Photons_SC_BCSeed_e2x5Left, &b_Photons_SC_BCSeed_e2x5Left);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e2x5Right", Photons_SC_BCSeed_e2x5Right, &b_Photons_SC_BCSeed_e2x5Right);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e2x5Top", Photons_SC_BCSeed_e2x5Top, &b_Photons_SC_BCSeed_e2x5Top);
   fChain->SetBranchAddress("Photons.SC.BCSeed.e2x5Bottom", Photons_SC_BCSeed_e2x5Bottom, &b_Photons_SC_BCSeed_e2x5Bottom);
   fChain->SetBranchAddress("Photons.SC.BCSeed.etaCrystal", Photons_SC_BCSeed_etaCrystal, &b_Photons_SC_BCSeed_etaCrystal);
   fChain->SetBranchAddress("Photons.SC.BCSeed.phiCrystal", Photons_SC_BCSeed_phiCrystal, &b_Photons_SC_BCSeed_phiCrystal);
   fChain->SetBranchAddress("Photons.SC.BCSeed.iEta", Photons_SC_BCSeed_iEta, &b_Photons_SC_BCSeed_iEta);
   fChain->SetBranchAddress("Photons.SC.BCSeed.iPhi", Photons_SC_BCSeed_iPhi, &b_Photons_SC_BCSeed_iPhi);
   fChain->SetBranchAddress("Photons.SC.BCSeed.thetaTilt", Photons_SC_BCSeed_thetaTilt, &b_Photons_SC_BCSeed_thetaTilt);
   fChain->SetBranchAddress("Photons.SC.BCSeed.phiTilt", Photons_SC_BCSeed_phiTilt, &b_Photons_SC_BCSeed_phiTilt);
   fChain->SetBranchAddress("Photons.SC.BCSeed.sigmaIEtaIEta", Photons_SC_BCSeed_sigmaIEtaIEta, &b_Photons_SC_BCSeed_sigmaIEtaIEta);
   fChain->SetBranchAddress("Photons.SC.BCSeed.sigmaIEtaIPhi", Photons_SC_BCSeed_sigmaIEtaIPhi, &b_Photons_SC_BCSeed_sigmaIEtaIPhi);
   fChain->SetBranchAddress("Photons.SC.BCSeed.sigmaIPhiIPhi", Photons_SC_BCSeed_sigmaIPhiIPhi, &b_Photons_SC_BCSeed_sigmaIPhiIPhi);
   fChain->SetBranchAddress("Photons.SC.nBCs", Photons_SC_nBCs, &b_Photons_SC_nBCs);
   fChain->SetBranchAddress("Photons.SC.index", Photons_SC_index, &b_Photons_SC_index);
   fChain->SetBranchAddress("Photons.SC.energy", Photons_SC_energy, &b_Photons_SC_energy);
   fChain->SetBranchAddress("Photons.SC.esEnergy", Photons_SC_esEnergy, &b_Photons_SC_esEnergy);
   fChain->SetBranchAddress("Photons.SC.eta", Photons_SC_eta, &b_Photons_SC_eta);
   fChain->SetBranchAddress("Photons.SC.phi", Photons_SC_phi, &b_Photons_SC_phi);
   fChain->SetBranchAddress("Photons.SC.e3x3", Photons_SC_e3x3, &b_Photons_SC_e3x3);
   fChain->SetBranchAddress("Photons.SC.e5x5", Photons_SC_e5x5, &b_Photons_SC_e5x5);
   fChain->SetBranchAddress("Photons.SC.e3x1", Photons_SC_e3x1, &b_Photons_SC_e3x1);
   fChain->SetBranchAddress("Photons.SC.e1x3", Photons_SC_e1x3, &b_Photons_SC_e1x3);
   fChain->SetBranchAddress("Photons.SC.e4x4", Photons_SC_e4x4, &b_Photons_SC_e4x4);
   fChain->SetBranchAddress("Photons.SC.eMax", Photons_SC_eMax, &b_Photons_SC_eMax);
   fChain->SetBranchAddress("Photons.SC.e2x2", Photons_SC_e2x2, &b_Photons_SC_e2x2);
   fChain->SetBranchAddress("Photons.SC.e2nd", Photons_SC_e2nd, &b_Photons_SC_e2nd);
   fChain->SetBranchAddress("Photons.SC.e1x5", Photons_SC_e1x5, &b_Photons_SC_e1x5);
   fChain->SetBranchAddress("Photons.SC.e2x5Max", Photons_SC_e2x5Max, &b_Photons_SC_e2x5Max);
   fChain->SetBranchAddress("Photons.SC.e2x5Left", Photons_SC_e2x5Left, &b_Photons_SC_e2x5Left);
   fChain->SetBranchAddress("Photons.SC.e2x5Right", Photons_SC_e2x5Right, &b_Photons_SC_e2x5Right);
   fChain->SetBranchAddress("Photons.SC.e2x5Top", Photons_SC_e2x5Top, &b_Photons_SC_e2x5Top);
   fChain->SetBranchAddress("Photons.SC.e2x5Bottom", Photons_SC_e2x5Bottom, &b_Photons_SC_e2x5Bottom);
   fChain->SetBranchAddress("Photons.SC.eLeft", Photons_SC_eLeft, &b_Photons_SC_eLeft);
   fChain->SetBranchAddress("Photons.SC.eRight", Photons_SC_eRight, &b_Photons_SC_eRight);
   fChain->SetBranchAddress("Photons.SC.eTop", Photons_SC_eTop, &b_Photons_SC_eTop);
   fChain->SetBranchAddress("Photons.SC.eBottom", Photons_SC_eBottom, &b_Photons_SC_eBottom);
   fChain->SetBranchAddress("Photons.SC.sigmaIEtaIEta", Photons_SC_sigmaIEtaIEta, &b_Photons_SC_sigmaIEtaIEta);
   fChain->SetBranchAddress("Photons.SC.sigmaIEtaIPhi", Photons_SC_sigmaIEtaIPhi, &b_Photons_SC_sigmaIEtaIPhi);
   fChain->SetBranchAddress("Photons.SC.sigmaIPhiIPhi", Photons_SC_sigmaIPhiIPhi, &b_Photons_SC_sigmaIPhiIPhi);
   fChain->SetBranchAddress("Photons.SC.esEffSigRR", Photons_SC_esEffSigRR, &b_Photons_SC_esEffSigRR);
   fChain->SetBranchAddress("Photons.SC.CaloPos.fUniqueID", Photons_SC_CaloPos_fUniqueID, &b_Photons_SC_CaloPos_fUniqueID);
   fChain->SetBranchAddress("Photons.SC.CaloPos.fBits", Photons_SC_CaloPos_fBits, &b_Photons_SC_CaloPos_fBits);
   fChain->SetBranchAddress("Photons.SC.CaloPos.fX", Photons_SC_CaloPos_fX, &b_Photons_SC_CaloPos_fX);
   fChain->SetBranchAddress("Photons.SC.CaloPos.fY", Photons_SC_CaloPos_fY, &b_Photons_SC_CaloPos_fY);
   fChain->SetBranchAddress("Photons.SC.CaloPos.fZ", Photons_SC_CaloPos_fZ, &b_Photons_SC_CaloPos_fZ);
   fChain->SetBranchAddress("Photons.SC.rawE", Photons_SC_rawE, &b_Photons_SC_rawE);
   fChain->SetBranchAddress("Photons.SC.phiWidth", Photons_SC_phiWidth, &b_Photons_SC_phiWidth);
   fChain->SetBranchAddress("Photons.SC.etaWidth", Photons_SC_etaWidth, &b_Photons_SC_etaWidth);
   fChain->SetBranchAddress("Photons.SC.HoverE", Photons_SC_HoverE, &b_Photons_SC_HoverE);
   fChain->SetBranchAddress("Photons.SC.r9", Photons_SC_r9, &b_Photons_SC_r9);
   fChain->SetBranchAddress("Photons.SC.s4ratio", Photons_SC_s4ratio, &b_Photons_SC_s4ratio);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.index", Photons_PFSC_BCSeed_index, &b_Photons_PFSC_BCSeed_index);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.energy", Photons_PFSC_BCSeed_energy, &b_Photons_PFSC_BCSeed_energy);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.eta", Photons_PFSC_BCSeed_eta, &b_Photons_PFSC_BCSeed_eta);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.phi", Photons_PFSC_BCSeed_phi, &b_Photons_PFSC_BCSeed_phi);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e3x3", Photons_PFSC_BCSeed_e3x3, &b_Photons_PFSC_BCSeed_e3x3);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e5x5", Photons_PFSC_BCSeed_e5x5, &b_Photons_PFSC_BCSeed_e5x5);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.eTop", Photons_PFSC_BCSeed_eTop, &b_Photons_PFSC_BCSeed_eTop);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.eLeft", Photons_PFSC_BCSeed_eLeft, &b_Photons_PFSC_BCSeed_eLeft);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.eRight", Photons_PFSC_BCSeed_eRight, &b_Photons_PFSC_BCSeed_eRight);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.eBottom", Photons_PFSC_BCSeed_eBottom, &b_Photons_PFSC_BCSeed_eBottom);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.eMax", Photons_PFSC_BCSeed_eMax, &b_Photons_PFSC_BCSeed_eMax);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e2nd", Photons_PFSC_BCSeed_e2nd, &b_Photons_PFSC_BCSeed_e2nd);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e2x5Max", Photons_PFSC_BCSeed_e2x5Max, &b_Photons_PFSC_BCSeed_e2x5Max);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e2x5Left", Photons_PFSC_BCSeed_e2x5Left, &b_Photons_PFSC_BCSeed_e2x5Left);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e2x5Right", Photons_PFSC_BCSeed_e2x5Right, &b_Photons_PFSC_BCSeed_e2x5Right);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e2x5Top", Photons_PFSC_BCSeed_e2x5Top, &b_Photons_PFSC_BCSeed_e2x5Top);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.e2x5Bottom", Photons_PFSC_BCSeed_e2x5Bottom, &b_Photons_PFSC_BCSeed_e2x5Bottom);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.etaCrystal", Photons_PFSC_BCSeed_etaCrystal, &b_Photons_PFSC_BCSeed_etaCrystal);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.phiCrystal", Photons_PFSC_BCSeed_phiCrystal, &b_Photons_PFSC_BCSeed_phiCrystal);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.iEta", Photons_PFSC_BCSeed_iEta, &b_Photons_PFSC_BCSeed_iEta);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.iPhi", Photons_PFSC_BCSeed_iPhi, &b_Photons_PFSC_BCSeed_iPhi);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.thetaTilt", Photons_PFSC_BCSeed_thetaTilt, &b_Photons_PFSC_BCSeed_thetaTilt);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.phiTilt", Photons_PFSC_BCSeed_phiTilt, &b_Photons_PFSC_BCSeed_phiTilt);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.sigmaIEtaIEta", Photons_PFSC_BCSeed_sigmaIEtaIEta, &b_Photons_PFSC_BCSeed_sigmaIEtaIEta);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.sigmaIEtaIPhi", Photons_PFSC_BCSeed_sigmaIEtaIPhi, &b_Photons_PFSC_BCSeed_sigmaIEtaIPhi);
   fChain->SetBranchAddress("Photons.PFSC.BCSeed.sigmaIPhiIPhi", Photons_PFSC_BCSeed_sigmaIPhiIPhi, &b_Photons_PFSC_BCSeed_sigmaIPhiIPhi);
   fChain->SetBranchAddress("Photons.PFSC.nBCs", Photons_PFSC_nBCs, &b_Photons_PFSC_nBCs);
   fChain->SetBranchAddress("Photons.PFSC.index", Photons_PFSC_index, &b_Photons_PFSC_index);
   fChain->SetBranchAddress("Photons.PFSC.energy", Photons_PFSC_energy, &b_Photons_PFSC_energy);
   fChain->SetBranchAddress("Photons.PFSC.esEnergy", Photons_PFSC_esEnergy, &b_Photons_PFSC_esEnergy);
   fChain->SetBranchAddress("Photons.PFSC.eta", Photons_PFSC_eta, &b_Photons_PFSC_eta);
   fChain->SetBranchAddress("Photons.PFSC.phi", Photons_PFSC_phi, &b_Photons_PFSC_phi);
   fChain->SetBranchAddress("Photons.PFSC.e3x3", Photons_PFSC_e3x3, &b_Photons_PFSC_e3x3);
   fChain->SetBranchAddress("Photons.PFSC.e5x5", Photons_PFSC_e5x5, &b_Photons_PFSC_e5x5);
   fChain->SetBranchAddress("Photons.PFSC.e3x1", Photons_PFSC_e3x1, &b_Photons_PFSC_e3x1);
   fChain->SetBranchAddress("Photons.PFSC.e1x3", Photons_PFSC_e1x3, &b_Photons_PFSC_e1x3);
   fChain->SetBranchAddress("Photons.PFSC.e4x4", Photons_PFSC_e4x4, &b_Photons_PFSC_e4x4);
   fChain->SetBranchAddress("Photons.PFSC.eMax", Photons_PFSC_eMax, &b_Photons_PFSC_eMax);
   fChain->SetBranchAddress("Photons.PFSC.e2x2", Photons_PFSC_e2x2, &b_Photons_PFSC_e2x2);
   fChain->SetBranchAddress("Photons.PFSC.e2nd", Photons_PFSC_e2nd, &b_Photons_PFSC_e2nd);
   fChain->SetBranchAddress("Photons.PFSC.e1x5", Photons_PFSC_e1x5, &b_Photons_PFSC_e1x5);
   fChain->SetBranchAddress("Photons.PFSC.e2x5Max", Photons_PFSC_e2x5Max, &b_Photons_PFSC_e2x5Max);
   fChain->SetBranchAddress("Photons.PFSC.e2x5Left", Photons_PFSC_e2x5Left, &b_Photons_PFSC_e2x5Left);
   fChain->SetBranchAddress("Photons.PFSC.e2x5Right", Photons_PFSC_e2x5Right, &b_Photons_PFSC_e2x5Right);
   fChain->SetBranchAddress("Photons.PFSC.e2x5Top", Photons_PFSC_e2x5Top, &b_Photons_PFSC_e2x5Top);
   fChain->SetBranchAddress("Photons.PFSC.e2x5Bottom", Photons_PFSC_e2x5Bottom, &b_Photons_PFSC_e2x5Bottom);
   fChain->SetBranchAddress("Photons.PFSC.eLeft", Photons_PFSC_eLeft, &b_Photons_PFSC_eLeft);
   fChain->SetBranchAddress("Photons.PFSC.eRight", Photons_PFSC_eRight, &b_Photons_PFSC_eRight);
   fChain->SetBranchAddress("Photons.PFSC.eTop", Photons_PFSC_eTop, &b_Photons_PFSC_eTop);
   fChain->SetBranchAddress("Photons.PFSC.eBottom", Photons_PFSC_eBottom, &b_Photons_PFSC_eBottom);
   fChain->SetBranchAddress("Photons.PFSC.sigmaIEtaIEta", Photons_PFSC_sigmaIEtaIEta, &b_Photons_PFSC_sigmaIEtaIEta);
   fChain->SetBranchAddress("Photons.PFSC.sigmaIEtaIPhi", Photons_PFSC_sigmaIEtaIPhi, &b_Photons_PFSC_sigmaIEtaIPhi);
   fChain->SetBranchAddress("Photons.PFSC.sigmaIPhiIPhi", Photons_PFSC_sigmaIPhiIPhi, &b_Photons_PFSC_sigmaIPhiIPhi);
   fChain->SetBranchAddress("Photons.PFSC.esEffSigRR", Photons_PFSC_esEffSigRR, &b_Photons_PFSC_esEffSigRR);
   fChain->SetBranchAddress("Photons.PFSC.CaloPos.fUniqueID", Photons_PFSC_CaloPos_fUniqueID, &b_Photons_PFSC_CaloPos_fUniqueID);
   fChain->SetBranchAddress("Photons.PFSC.CaloPos.fBits", Photons_PFSC_CaloPos_fBits, &b_Photons_PFSC_CaloPos_fBits);
   fChain->SetBranchAddress("Photons.PFSC.CaloPos.fX", Photons_PFSC_CaloPos_fX, &b_Photons_PFSC_CaloPos_fX);
   fChain->SetBranchAddress("Photons.PFSC.CaloPos.fY", Photons_PFSC_CaloPos_fY, &b_Photons_PFSC_CaloPos_fY);
   fChain->SetBranchAddress("Photons.PFSC.CaloPos.fZ", Photons_PFSC_CaloPos_fZ, &b_Photons_PFSC_CaloPos_fZ);
   fChain->SetBranchAddress("Photons.PFSC.rawE", Photons_PFSC_rawE, &b_Photons_PFSC_rawE);
   fChain->SetBranchAddress("Photons.PFSC.phiWidth", Photons_PFSC_phiWidth, &b_Photons_PFSC_phiWidth);
   fChain->SetBranchAddress("Photons.PFSC.etaWidth", Photons_PFSC_etaWidth, &b_Photons_PFSC_etaWidth);
   fChain->SetBranchAddress("Photons.PFSC.HoverE", Photons_PFSC_HoverE, &b_Photons_PFSC_HoverE);
   fChain->SetBranchAddress("Photons.PFSC.r9", Photons_PFSC_r9, &b_Photons_PFSC_r9);
   fChain->SetBranchAddress("Photons.PFSC.s4ratio", Photons_PFSC_s4ratio, &b_Photons_PFSC_s4ratio);
   fChain->SetBranchAddress("Photons.HoverE", Photons_HoverE, &b_Photons_HoverE);
   fChain->SetBranchAddress("Photons.HTowOverE", Photons_HTowOverE, &b_Photons_HTowOverE);
   fChain->SetBranchAddress("Photons.hasPixel", Photons_hasPixel, &b_Photons_hasPixel);
   fChain->SetBranchAddress("Photons.CaloPos.fUniqueID", Photons_CaloPos_fUniqueID, &b_Photons_CaloPos_fUniqueID);
   fChain->SetBranchAddress("Photons.CaloPos.fBits", Photons_CaloPos_fBits, &b_Photons_CaloPos_fBits);
   fChain->SetBranchAddress("Photons.CaloPos.fX", Photons_CaloPos_fX, &b_Photons_CaloPos_fX);
   fChain->SetBranchAddress("Photons.CaloPos.fY", Photons_CaloPos_fY, &b_Photons_CaloPos_fY);
   fChain->SetBranchAddress("Photons.CaloPos.fZ", Photons_CaloPos_fZ, &b_Photons_CaloPos_fZ);
   fChain->SetBranchAddress("Photons.photonTrkIsoFromVtx", Photons_photonTrkIsoFromVtx, &b_Photons_photonTrkIsoFromVtx);
   fChain->SetBranchAddress("Photons.photonWorstIsoDR03.first", Photons_photonWorstIsoDR03_first, &b_Photons_photonWorstIsoDR03_first);
   fChain->SetBranchAddress("Photons.photonWorstIsoDR03.second", Photons_photonWorstIsoDR03_second, &b_Photons_photonWorstIsoDR03_second);
   fChain->SetBranchAddress("Photons.photonWorstIsoDR04.first", Photons_photonWorstIsoDR04_first, &b_Photons_photonWorstIsoDR04_first);
   fChain->SetBranchAddress("Photons.photonWorstIsoDR04.second", Photons_photonWorstIsoDR04_second, &b_Photons_photonWorstIsoDR04_second);
   fChain->SetBranchAddress("Photons.conversion.index", Photons_conversion_index, &b_Photons_conversion_index);
   fChain->SetBranchAddress("Photons.conversion.pPair.fUniqueID", Photons_conversion_pPair_fUniqueID, &b_Photons_conversion_pPair_fUniqueID);
   fChain->SetBranchAddress("Photons.conversion.pPair.fBits", Photons_conversion_pPair_fBits, &b_Photons_conversion_pPair_fBits);
   fChain->SetBranchAddress("Photons.conversion.pPair.fX", Photons_conversion_pPair_fX, &b_Photons_conversion_pPair_fX);
   fChain->SetBranchAddress("Photons.conversion.pPair.fY", Photons_conversion_pPair_fY, &b_Photons_conversion_pPair_fY);
   fChain->SetBranchAddress("Photons.conversion.pPair.fZ", Photons_conversion_pPair_fZ, &b_Photons_conversion_pPair_fZ);
   fChain->SetBranchAddress("Photons.conversion.pRefittedPair.fUniqueID", Photons_conversion_pRefittedPair_fUniqueID, &b_Photons_conversion_pRefittedPair_fUniqueID);
   fChain->SetBranchAddress("Photons.conversion.pRefittedPair.fBits", Photons_conversion_pRefittedPair_fBits, &b_Photons_conversion_pRefittedPair_fBits);
   fChain->SetBranchAddress("Photons.conversion.pRefittedPair.fX", Photons_conversion_pRefittedPair_fX, &b_Photons_conversion_pRefittedPair_fX);
   fChain->SetBranchAddress("Photons.conversion.pRefittedPair.fY", Photons_conversion_pRefittedPair_fY, &b_Photons_conversion_pRefittedPair_fY);
   fChain->SetBranchAddress("Photons.conversion.pRefittedPair.fZ", Photons_conversion_pRefittedPair_fZ, &b_Photons_conversion_pRefittedPair_fZ);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fUniqueID", Photons_conversion_p4RefittedPair_fUniqueID, &b_Photons_conversion_p4RefittedPair_fUniqueID);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fBits", Photons_conversion_p4RefittedPair_fBits, &b_Photons_conversion_p4RefittedPair_fBits);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fP.fUniqueID", Photons_conversion_p4RefittedPair_fP_fUniqueID, &b_Photons_conversion_p4RefittedPair_fP_fUniqueID);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fP.fBits", Photons_conversion_p4RefittedPair_fP_fBits, &b_Photons_conversion_p4RefittedPair_fP_fBits);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fP.fX", Photons_conversion_p4RefittedPair_fP_fX, &b_Photons_conversion_p4RefittedPair_fP_fX);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fP.fY", Photons_conversion_p4RefittedPair_fP_fY, &b_Photons_conversion_p4RefittedPair_fP_fY);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fP.fZ", Photons_conversion_p4RefittedPair_fP_fZ, &b_Photons_conversion_p4RefittedPair_fP_fZ);
   fChain->SetBranchAddress("Photons.conversion.p4RefittedPair.fE", Photons_conversion_p4RefittedPair_fE, &b_Photons_conversion_p4RefittedPair_fE);
   fChain->SetBranchAddress("Photons.conversion.CaloPos.fUniqueID", Photons_conversion_CaloPos_fUniqueID, &b_Photons_conversion_CaloPos_fUniqueID);
   fChain->SetBranchAddress("Photons.conversion.CaloPos.fBits", Photons_conversion_CaloPos_fBits, &b_Photons_conversion_CaloPos_fBits);
   fChain->SetBranchAddress("Photons.conversion.CaloPos.fX", Photons_conversion_CaloPos_fX, &b_Photons_conversion_CaloPos_fX);
   fChain->SetBranchAddress("Photons.conversion.CaloPos.fY", Photons_conversion_CaloPos_fY, &b_Photons_conversion_CaloPos_fY);
   fChain->SetBranchAddress("Photons.conversion.CaloPos.fZ", Photons_conversion_CaloPos_fZ, &b_Photons_conversion_CaloPos_fZ);
   fChain->SetBranchAddress("Photons.conversion.eOverP", Photons_conversion_eOverP, &b_Photons_conversion_eOverP);
   fChain->SetBranchAddress("Photons.conversion.vtx.fUniqueID", Photons_conversion_vtx_fUniqueID, &b_Photons_conversion_vtx_fUniqueID);
   fChain->SetBranchAddress("Photons.conversion.vtx.fBits", Photons_conversion_vtx_fBits, &b_Photons_conversion_vtx_fBits);
   fChain->SetBranchAddress("Photons.conversion.vtx.fX", Photons_conversion_vtx_fX, &b_Photons_conversion_vtx_fX);
   fChain->SetBranchAddress("Photons.conversion.vtx.fY", Photons_conversion_vtx_fY, &b_Photons_conversion_vtx_fY);
   fChain->SetBranchAddress("Photons.conversion.vtx.fZ", Photons_conversion_vtx_fZ, &b_Photons_conversion_vtx_fZ);
   fChain->SetBranchAddress("Photons.conversion.vtxChi2", Photons_conversion_vtxChi2, &b_Photons_conversion_vtxChi2);
   fChain->SetBranchAddress("Photons.conversion.vtxChi2Prob", Photons_conversion_vtxChi2Prob, &b_Photons_conversion_vtxChi2Prob);
   fChain->SetBranchAddress("Photons.conversion.vtxIsValid", Photons_conversion_vtxIsValid, &b_Photons_conversion_vtxIsValid);
   fChain->SetBranchAddress("Photons.conversion.vtxNTracks", Photons_conversion_vtxNTracks, &b_Photons_conversion_vtxNTracks);
   fChain->SetBranchAddress("Photons.conversion.vtxMVA", Photons_conversion_vtxMVA, &b_Photons_conversion_vtxMVA);
   fChain->SetBranchAddress("Photons.conversion.trk1Dz", Photons_conversion_trk1Dz, &b_Photons_conversion_trk1Dz);
   fChain->SetBranchAddress("Photons.conversion.trk1DzError", Photons_conversion_trk1DzError, &b_Photons_conversion_trk1DzError);
   fChain->SetBranchAddress("Photons.conversion.trk1Charge", Photons_conversion_trk1Charge, &b_Photons_conversion_trk1Charge);
   fChain->SetBranchAddress("Photons.conversion.trk1Algo", Photons_conversion_trk1Algo, &b_Photons_conversion_trk1Algo);
   fChain->SetBranchAddress("Photons.conversion.trk1D0", Photons_conversion_trk1D0, &b_Photons_conversion_trk1D0);
   fChain->SetBranchAddress("Photons.conversion.trk1Pout", Photons_conversion_trk1Pout, &b_Photons_conversion_trk1Pout);
   fChain->SetBranchAddress("Photons.conversion.trk1Pin", Photons_conversion_trk1Pin, &b_Photons_conversion_trk1Pin);
   fChain->SetBranchAddress("Photons.conversion.trk2Dz", Photons_conversion_trk2Dz, &b_Photons_conversion_trk2Dz);
   fChain->SetBranchAddress("Photons.conversion.trk2DzError", Photons_conversion_trk2DzError, &b_Photons_conversion_trk2DzError);
   fChain->SetBranchAddress("Photons.conversion.trk2Charge", Photons_conversion_trk2Charge, &b_Photons_conversion_trk2Charge);
   fChain->SetBranchAddress("Photons.conversion.trk2Algo", Photons_conversion_trk2Algo, &b_Photons_conversion_trk2Algo);
   fChain->SetBranchAddress("Photons.conversion.trk2D0", Photons_conversion_trk2D0, &b_Photons_conversion_trk2D0);
   fChain->SetBranchAddress("Photons.conversion.trk2Pout", Photons_conversion_trk2Pout, &b_Photons_conversion_trk2Pout);
   fChain->SetBranchAddress("Photons.conversion.trk2Pin", Photons_conversion_trk2Pin, &b_Photons_conversion_trk2Pin);
   fChain->SetBranchAddress("Photons.dr03EcalRecHitSumEtCone", Photons_dr03EcalRecHitSumEtCone, &b_Photons_dr03EcalRecHitSumEtCone);
   fChain->SetBranchAddress("Photons.dr03HcalTowerSumEtCone", Photons_dr03HcalTowerSumEtCone, &b_Photons_dr03HcalTowerSumEtCone);
   fChain->SetBranchAddress("Photons.dr03TrkSumPtCone", Photons_dr03TrkSumPtCone, &b_Photons_dr03TrkSumPtCone);
   fChain->SetBranchAddress("Photons.dr03TrkSumPtHollowCone", Photons_dr03TrkSumPtHollowCone, &b_Photons_dr03TrkSumPtHollowCone);
   fChain->SetBranchAddress("Photons.dr04EcalRecHitSumEtCone", Photons_dr04EcalRecHitSumEtCone, &b_Photons_dr04EcalRecHitSumEtCone);
   fChain->SetBranchAddress("Photons.dr04HcalTowerSumEtCone", Photons_dr04HcalTowerSumEtCone, &b_Photons_dr04HcalTowerSumEtCone);
   fChain->SetBranchAddress("Photons.dr04TrkSumPtCone", Photons_dr04TrkSumPtCone, &b_Photons_dr04TrkSumPtCone);
   fChain->SetBranchAddress("Photons.dr04TrkSumPtHollowCone", Photons_dr04TrkSumPtHollowCone, &b_Photons_dr04TrkSumPtHollowCone);
   fChain->SetBranchAddress("Photons.nPV", Photons_nPV, &b_Photons_nPV);
   fChain->SetBranchAddress("Photons.dr01ChargedHadronPFIso[100]", Photons_dr01ChargedHadronPFIso, &b_Photons_dr01ChargedHadronPFIso);
   fChain->SetBranchAddress("Photons.dr02ChargedHadronPFIso[100]", Photons_dr02ChargedHadronPFIso, &b_Photons_dr02ChargedHadronPFIso);
   fChain->SetBranchAddress("Photons.dr03ChargedHadronPFIso[100]", Photons_dr03ChargedHadronPFIso, &b_Photons_dr03ChargedHadronPFIso);
   fChain->SetBranchAddress("Photons.dr04ChargedHadronPFIso[100]", Photons_dr04ChargedHadronPFIso, &b_Photons_dr04ChargedHadronPFIso);
   fChain->SetBranchAddress("Photons.dr05ChargedHadronPFIso[100]", Photons_dr05ChargedHadronPFIso, &b_Photons_dr05ChargedHadronPFIso);
   fChain->SetBranchAddress("Photons.dr06ChargedHadronPFIso[100]", Photons_dr06ChargedHadronPFIso, &b_Photons_dr06ChargedHadronPFIso);
   fChain->SetBranchAddress("Photons.dr01NeutralHadronPFIso", Photons_dr01NeutralHadronPFIso, &b_Photons_dr01NeutralHadronPFIso);
   fChain->SetBranchAddress("Photons.dr02NeutralHadronPFIso", Photons_dr02NeutralHadronPFIso, &b_Photons_dr02NeutralHadronPFIso);
   fChain->SetBranchAddress("Photons.dr03NeutralHadronPFIso", Photons_dr03NeutralHadronPFIso, &b_Photons_dr03NeutralHadronPFIso);
   fChain->SetBranchAddress("Photons.dr04NeutralHadronPFIso", Photons_dr04NeutralHadronPFIso, &b_Photons_dr04NeutralHadronPFIso);
   fChain->SetBranchAddress("Photons.dr05NeutralHadronPFIso", Photons_dr05NeutralHadronPFIso, &b_Photons_dr05NeutralHadronPFIso);
   fChain->SetBranchAddress("Photons.dr06NeutralHadronPFIso", Photons_dr06NeutralHadronPFIso, &b_Photons_dr06NeutralHadronPFIso);
   fChain->SetBranchAddress("Photons.dr01PhotonPFIso", Photons_dr01PhotonPFIso, &b_Photons_dr01PhotonPFIso);
   fChain->SetBranchAddress("Photons.dr02PhotonPFIso", Photons_dr02PhotonPFIso, &b_Photons_dr02PhotonPFIso);
   fChain->SetBranchAddress("Photons.dr03PhotonPFIso", Photons_dr03PhotonPFIso, &b_Photons_dr03PhotonPFIso);
   fChain->SetBranchAddress("Photons.dr04PhotonPFIso", Photons_dr04PhotonPFIso, &b_Photons_dr04PhotonPFIso);
   fChain->SetBranchAddress("Photons.dr05PhotonPFIso", Photons_dr05PhotonPFIso, &b_Photons_dr05PhotonPFIso);
   fChain->SetBranchAddress("Photons.dr06PhotonPFIso", Photons_dr06PhotonPFIso, &b_Photons_dr06PhotonPFIso);
   fChain->SetBranchAddress("Photons.genMatch.index", Photons_genMatch_index, &b_Photons_genMatch_index);
   fChain->SetBranchAddress("Photons.genMatch.energy", Photons_genMatch_energy, &b_Photons_genMatch_energy);
   fChain->SetBranchAddress("Photons.genMatch.pt", Photons_genMatch_pt, &b_Photons_genMatch_pt);
   fChain->SetBranchAddress("Photons.genMatch.eta", Photons_genMatch_eta, &b_Photons_genMatch_eta);
   fChain->SetBranchAddress("Photons.genMatch.phi", Photons_genMatch_phi, &b_Photons_genMatch_phi);
   fChain->SetBranchAddress("Photons.genMatch.mass", Photons_genMatch_mass, &b_Photons_genMatch_mass);
   fChain->SetBranchAddress("Photons.genMatch.Vx", Photons_genMatch_Vx, &b_Photons_genMatch_Vx);
   fChain->SetBranchAddress("Photons.genMatch.Vy", Photons_genMatch_Vy, &b_Photons_genMatch_Vy);
   fChain->SetBranchAddress("Photons.genMatch.Vz", Photons_genMatch_Vz, &b_Photons_genMatch_Vz);
   fChain->SetBranchAddress("Photons.genMatch.status", Photons_genMatch_status, &b_Photons_genMatch_status);
   fChain->SetBranchAddress("Photons.genMatch.id", Photons_genMatch_id, &b_Photons_genMatch_id);
   fChain->SetBranchAddress("Photons.genMatch.statusMother", Photons_genMatch_statusMother, &b_Photons_genMatch_statusMother);
   fChain->SetBranchAddress("Photons.genMatch.idMother", Photons_genMatch_idMother, &b_Photons_genMatch_idMother);
   fChain->SetBranchAddress("Photons.genMatch.indexMother", Photons_genMatch_indexMother, &b_Photons_genMatch_indexMother);
   fChain->SetBranchAddress("ggVerticesPhotonIndices", &ggVerticesPhotonIndices_, &b_ggVerticesPhotonIndices_);
   fChain->SetBranchAddress("ggVerticesPhotonIndices.first", ggVerticesPhotonIndices_first, &b_ggVerticesPhotonIndices_first);
   fChain->SetBranchAddress("ggVerticesPhotonIndices.second", ggVerticesPhotonIndices_second, &b_ggVerticesPhotonIndices_second);
   fChain->SetBranchAddress("ggVerticesVertexIndex", &ggVerticesVertexIndex_, &b_ggVerticesVertexIndex_);
   fChain->SetBranchAddress("ggVerticesVertexIndex.first", ggVerticesVertexIndex_first, &b_ggVerticesVertexIndex_first);
   fChain->SetBranchAddress("ggVerticesVertexIndex.second", ggVerticesVertexIndex_second, &b_ggVerticesVertexIndex_second);
   fChain->SetBranchAddress("ggVerticesVertexIndex2nd", &ggVerticesVertexIndex2nd_, &b_ggVerticesVertexIndex2nd_);
   fChain->SetBranchAddress("ggVerticesVertexIndex2nd.first", ggVerticesVertexIndex2nd_first, &b_ggVerticesVertexIndex2nd_first);
   fChain->SetBranchAddress("ggVerticesVertexIndex2nd.second", ggVerticesVertexIndex2nd_second, &b_ggVerticesVertexIndex2nd_second);
   fChain->SetBranchAddress("ggVerticesVertexIndex3rd", &ggVerticesVertexIndex3rd_, &b_ggVerticesVertexIndex3rd_);
   fChain->SetBranchAddress("ggVerticesVertexIndex3rd.first", ggVerticesVertexIndex3rd_first, &b_ggVerticesVertexIndex3rd_first);
   fChain->SetBranchAddress("ggVerticesVertexIndex3rd.second", ggVerticesVertexIndex3rd_second, &b_ggVerticesVertexIndex3rd_second);
   fChain->SetBranchAddress("ggVerticesPerEvtMVA", &ggVerticesPerEvtMVA, &b_ggVerticesPerEvtMVA);
   fChain->SetBranchAddress("photonMatchedElectron", photonMatchedElectron, &b_photonMatchedElectron);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("Muons", &Muons_, &b_Muons_);
   fChain->SetBranchAddress("Muons.index", Muons_index, &b_Muons_index);
   fChain->SetBranchAddress("Muons.energy", Muons_energy, &b_Muons_energy);
   fChain->SetBranchAddress("Muons.pt", Muons_pt, &b_Muons_pt);
   fChain->SetBranchAddress("Muons.eta", Muons_eta, &b_Muons_eta);
   fChain->SetBranchAddress("Muons.phi", Muons_phi, &b_Muons_phi);
   fChain->SetBranchAddress("Muons.charge", Muons_charge, &b_Muons_charge);
   fChain->SetBranchAddress("Muons.combinedIso", Muons_combinedIso, &b_Muons_combinedIso);
   fChain->SetBranchAddress("Muons.emIso", Muons_emIso, &b_Muons_emIso);
   fChain->SetBranchAddress("Muons.hadIso", Muons_hadIso, &b_Muons_hadIso);
   fChain->SetBranchAddress("Muons.trkIso", Muons_trkIso, &b_Muons_trkIso);
   fChain->SetBranchAddress("Muons.isGlobalMuon", Muons_isGlobalMuon, &b_Muons_isGlobalMuon);
   fChain->SetBranchAddress("Muons.isTrackerMuon", Muons_isTrackerMuon, &b_Muons_isTrackerMuon);
   fChain->SetBranchAddress("Muons.isPromptMuon", Muons_isPromptMuon, &b_Muons_isPromptMuon);
   fChain->SetBranchAddress("Muons.nTrackHits", Muons_nTrackHits, &b_Muons_nTrackHits);
   fChain->SetBranchAddress("Muons.nPixelHits", Muons_nPixelHits, &b_Muons_nPixelHits);
   fChain->SetBranchAddress("Muons.trackImpactPar", Muons_trackImpactPar, &b_Muons_trackImpactPar);
   fChain->SetBranchAddress("Muons.isLooseMuon", Muons_isLooseMuon, &b_Muons_isLooseMuon);
   fChain->SetBranchAddress("Muons.isTightMuon", Muons_isTightMuon, &b_Muons_isTightMuon);
   fChain->SetBranchAddress("Muons.genMatch.index", Muons_genMatch_index, &b_Muons_genMatch_index);
   fChain->SetBranchAddress("Muons.genMatch.energy", Muons_genMatch_energy, &b_Muons_genMatch_energy);
   fChain->SetBranchAddress("Muons.genMatch.pt", Muons_genMatch_pt, &b_Muons_genMatch_pt);
   fChain->SetBranchAddress("Muons.genMatch.eta", Muons_genMatch_eta, &b_Muons_genMatch_eta);
   fChain->SetBranchAddress("Muons.genMatch.phi", Muons_genMatch_phi, &b_Muons_genMatch_phi);
   fChain->SetBranchAddress("Muons.genMatch.mass", Muons_genMatch_mass, &b_Muons_genMatch_mass);
   fChain->SetBranchAddress("Muons.genMatch.Vx", Muons_genMatch_Vx, &b_Muons_genMatch_Vx);
   fChain->SetBranchAddress("Muons.genMatch.Vy", Muons_genMatch_Vy, &b_Muons_genMatch_Vy);
   fChain->SetBranchAddress("Muons.genMatch.Vz", Muons_genMatch_Vz, &b_Muons_genMatch_Vz);
   fChain->SetBranchAddress("Muons.genMatch.status", Muons_genMatch_status, &b_Muons_genMatch_status);
   fChain->SetBranchAddress("Muons.genMatch.id", Muons_genMatch_id, &b_Muons_genMatch_id);
   fChain->SetBranchAddress("Muons.genMatch.statusMother", Muons_genMatch_statusMother, &b_Muons_genMatch_statusMother);
   fChain->SetBranchAddress("Muons.genMatch.idMother", Muons_genMatch_idMother, &b_Muons_genMatch_idMother);
   fChain->SetBranchAddress("Muons.genMatch.indexMother", Muons_genMatch_indexMother, &b_Muons_genMatch_indexMother);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("Electrons", &Electrons_, &b_Electrons_);
   fChain->SetBranchAddress("Electrons.index", Electrons_index, &b_Electrons_index);
   fChain->SetBranchAddress("Electrons.pt", Electrons_pt, &b_Electrons_pt);
   fChain->SetBranchAddress("Electrons.energy", Electrons_energy, &b_Electrons_energy);
   fChain->SetBranchAddress("Electrons.eta", Electrons_eta, &b_Electrons_eta);
   fChain->SetBranchAddress("Electrons.phi", Electrons_phi, &b_Electrons_phi);
   fChain->SetBranchAddress("Electrons.charge", Electrons_charge, &b_Electrons_charge);
   fChain->SetBranchAddress("Electrons.correctedEnergy", Electrons_correctedEnergy, &b_Electrons_correctedEnergy);
   fChain->SetBranchAddress("Electrons.correctedEnergyError", Electrons_correctedEnergyError, &b_Electrons_correctedEnergyError);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.index", Electrons_SC_BCSeed_index, &b_Electrons_SC_BCSeed_index);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.energy", Electrons_SC_BCSeed_energy, &b_Electrons_SC_BCSeed_energy);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.eta", Electrons_SC_BCSeed_eta, &b_Electrons_SC_BCSeed_eta);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.phi", Electrons_SC_BCSeed_phi, &b_Electrons_SC_BCSeed_phi);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e3x3", Electrons_SC_BCSeed_e3x3, &b_Electrons_SC_BCSeed_e3x3);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e5x5", Electrons_SC_BCSeed_e5x5, &b_Electrons_SC_BCSeed_e5x5);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.eTop", Electrons_SC_BCSeed_eTop, &b_Electrons_SC_BCSeed_eTop);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.eLeft", Electrons_SC_BCSeed_eLeft, &b_Electrons_SC_BCSeed_eLeft);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.eRight", Electrons_SC_BCSeed_eRight, &b_Electrons_SC_BCSeed_eRight);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.eBottom", Electrons_SC_BCSeed_eBottom, &b_Electrons_SC_BCSeed_eBottom);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.eMax", Electrons_SC_BCSeed_eMax, &b_Electrons_SC_BCSeed_eMax);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e2nd", Electrons_SC_BCSeed_e2nd, &b_Electrons_SC_BCSeed_e2nd);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e2x5Max", Electrons_SC_BCSeed_e2x5Max, &b_Electrons_SC_BCSeed_e2x5Max);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e2x5Left", Electrons_SC_BCSeed_e2x5Left, &b_Electrons_SC_BCSeed_e2x5Left);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e2x5Right", Electrons_SC_BCSeed_e2x5Right, &b_Electrons_SC_BCSeed_e2x5Right);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e2x5Top", Electrons_SC_BCSeed_e2x5Top, &b_Electrons_SC_BCSeed_e2x5Top);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.e2x5Bottom", Electrons_SC_BCSeed_e2x5Bottom, &b_Electrons_SC_BCSeed_e2x5Bottom);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.etaCrystal", Electrons_SC_BCSeed_etaCrystal, &b_Electrons_SC_BCSeed_etaCrystal);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.phiCrystal", Electrons_SC_BCSeed_phiCrystal, &b_Electrons_SC_BCSeed_phiCrystal);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.iEta", Electrons_SC_BCSeed_iEta, &b_Electrons_SC_BCSeed_iEta);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.iPhi", Electrons_SC_BCSeed_iPhi, &b_Electrons_SC_BCSeed_iPhi);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.thetaTilt", Electrons_SC_BCSeed_thetaTilt, &b_Electrons_SC_BCSeed_thetaTilt);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.phiTilt", Electrons_SC_BCSeed_phiTilt, &b_Electrons_SC_BCSeed_phiTilt);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.sigmaIEtaIEta", Electrons_SC_BCSeed_sigmaIEtaIEta, &b_Electrons_SC_BCSeed_sigmaIEtaIEta);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.sigmaIEtaIPhi", Electrons_SC_BCSeed_sigmaIEtaIPhi, &b_Electrons_SC_BCSeed_sigmaIEtaIPhi);
   fChain->SetBranchAddress("Electrons.SC.BCSeed.sigmaIPhiIPhi", Electrons_SC_BCSeed_sigmaIPhiIPhi, &b_Electrons_SC_BCSeed_sigmaIPhiIPhi);
   fChain->SetBranchAddress("Electrons.SC.nBCs", Electrons_SC_nBCs, &b_Electrons_SC_nBCs);
   fChain->SetBranchAddress("Electrons.SC.index", Electrons_SC_index, &b_Electrons_SC_index);
   fChain->SetBranchAddress("Electrons.SC.energy", Electrons_SC_energy, &b_Electrons_SC_energy);
   fChain->SetBranchAddress("Electrons.SC.esEnergy", Electrons_SC_esEnergy, &b_Electrons_SC_esEnergy);
   fChain->SetBranchAddress("Electrons.SC.eta", Electrons_SC_eta, &b_Electrons_SC_eta);
   fChain->SetBranchAddress("Electrons.SC.phi", Electrons_SC_phi, &b_Electrons_SC_phi);
   fChain->SetBranchAddress("Electrons.SC.e3x3", Electrons_SC_e3x3, &b_Electrons_SC_e3x3);
   fChain->SetBranchAddress("Electrons.SC.e5x5", Electrons_SC_e5x5, &b_Electrons_SC_e5x5);
   fChain->SetBranchAddress("Electrons.SC.e3x1", Electrons_SC_e3x1, &b_Electrons_SC_e3x1);
   fChain->SetBranchAddress("Electrons.SC.e1x3", Electrons_SC_e1x3, &b_Electrons_SC_e1x3);
   fChain->SetBranchAddress("Electrons.SC.e4x4", Electrons_SC_e4x4, &b_Electrons_SC_e4x4);
   fChain->SetBranchAddress("Electrons.SC.eMax", Electrons_SC_eMax, &b_Electrons_SC_eMax);
   fChain->SetBranchAddress("Electrons.SC.e2x2", Electrons_SC_e2x2, &b_Electrons_SC_e2x2);
   fChain->SetBranchAddress("Electrons.SC.e2nd", Electrons_SC_e2nd, &b_Electrons_SC_e2nd);
   fChain->SetBranchAddress("Electrons.SC.e1x5", Electrons_SC_e1x5, &b_Electrons_SC_e1x5);
   fChain->SetBranchAddress("Electrons.SC.e2x5Max", Electrons_SC_e2x5Max, &b_Electrons_SC_e2x5Max);
   fChain->SetBranchAddress("Electrons.SC.e2x5Left", Electrons_SC_e2x5Left, &b_Electrons_SC_e2x5Left);
   fChain->SetBranchAddress("Electrons.SC.e2x5Right", Electrons_SC_e2x5Right, &b_Electrons_SC_e2x5Right);
   fChain->SetBranchAddress("Electrons.SC.e2x5Top", Electrons_SC_e2x5Top, &b_Electrons_SC_e2x5Top);
   fChain->SetBranchAddress("Electrons.SC.e2x5Bottom", Electrons_SC_e2x5Bottom, &b_Electrons_SC_e2x5Bottom);
   fChain->SetBranchAddress("Electrons.SC.eLeft", Electrons_SC_eLeft, &b_Electrons_SC_eLeft);
   fChain->SetBranchAddress("Electrons.SC.eRight", Electrons_SC_eRight, &b_Electrons_SC_eRight);
   fChain->SetBranchAddress("Electrons.SC.eTop", Electrons_SC_eTop, &b_Electrons_SC_eTop);
   fChain->SetBranchAddress("Electrons.SC.eBottom", Electrons_SC_eBottom, &b_Electrons_SC_eBottom);
   fChain->SetBranchAddress("Electrons.SC.sigmaIEtaIEta", Electrons_SC_sigmaIEtaIEta, &b_Electrons_SC_sigmaIEtaIEta);
   fChain->SetBranchAddress("Electrons.SC.sigmaIEtaIPhi", Electrons_SC_sigmaIEtaIPhi, &b_Electrons_SC_sigmaIEtaIPhi);
   fChain->SetBranchAddress("Electrons.SC.sigmaIPhiIPhi", Electrons_SC_sigmaIPhiIPhi, &b_Electrons_SC_sigmaIPhiIPhi);
   fChain->SetBranchAddress("Electrons.SC.esEffSigRR", Electrons_SC_esEffSigRR, &b_Electrons_SC_esEffSigRR);
   fChain->SetBranchAddress("Electrons.SC.CaloPos.fUniqueID", Electrons_SC_CaloPos_fUniqueID, &b_Electrons_SC_CaloPos_fUniqueID);
   fChain->SetBranchAddress("Electrons.SC.CaloPos.fBits", Electrons_SC_CaloPos_fBits, &b_Electrons_SC_CaloPos_fBits);
   fChain->SetBranchAddress("Electrons.SC.CaloPos.fX", Electrons_SC_CaloPos_fX, &b_Electrons_SC_CaloPos_fX);
   fChain->SetBranchAddress("Electrons.SC.CaloPos.fY", Electrons_SC_CaloPos_fY, &b_Electrons_SC_CaloPos_fY);
   fChain->SetBranchAddress("Electrons.SC.CaloPos.fZ", Electrons_SC_CaloPos_fZ, &b_Electrons_SC_CaloPos_fZ);
   fChain->SetBranchAddress("Electrons.SC.rawE", Electrons_SC_rawE, &b_Electrons_SC_rawE);
   fChain->SetBranchAddress("Electrons.SC.phiWidth", Electrons_SC_phiWidth, &b_Electrons_SC_phiWidth);
   fChain->SetBranchAddress("Electrons.SC.etaWidth", Electrons_SC_etaWidth, &b_Electrons_SC_etaWidth);
   fChain->SetBranchAddress("Electrons.SC.HoverE", Electrons_SC_HoverE, &b_Electrons_SC_HoverE);
   fChain->SetBranchAddress("Electrons.SC.r9", Electrons_SC_r9, &b_Electrons_SC_r9);
   fChain->SetBranchAddress("Electrons.SC.s4ratio", Electrons_SC_s4ratio, &b_Electrons_SC_s4ratio);
   fChain->SetBranchAddress("Electrons.esEnergy", Electrons_esEnergy, &b_Electrons_esEnergy);
   fChain->SetBranchAddress("Electrons.HoverE", Electrons_HoverE, &b_Electrons_HoverE);
   fChain->SetBranchAddress("Electrons.isEcalDriven", Electrons_isEcalDriven, &b_Electrons_isEcalDriven);
   fChain->SetBranchAddress("Electrons.isTrackerDriven", Electrons_isTrackerDriven, &b_Electrons_isTrackerDriven);
   fChain->SetBranchAddress("Electrons.vtxX", Electrons_vtxX, &b_Electrons_vtxX);
   fChain->SetBranchAddress("Electrons.vtxY", Electrons_vtxY, &b_Electrons_vtxY);
   fChain->SetBranchAddress("Electrons.vtxZ", Electrons_vtxZ, &b_Electrons_vtxZ);
   fChain->SetBranchAddress("Electrons.EOverP", Electrons_EOverP, &b_Electrons_EOverP);
   fChain->SetBranchAddress("Electrons.d0Track", Electrons_d0Track, &b_Electrons_d0Track);
   fChain->SetBranchAddress("Electrons.dzTrack", Electrons_dzTrack, &b_Electrons_dzTrack);
   fChain->SetBranchAddress("Electrons.dEtaSCTrackAtVtx", Electrons_dEtaSCTrackAtVtx, &b_Electrons_dEtaSCTrackAtVtx);
   fChain->SetBranchAddress("Electrons.dPhiSCTrackAtVtx", Electrons_dPhiSCTrackAtVtx, &b_Electrons_dPhiSCTrackAtVtx);
   fChain->SetBranchAddress("Electrons.dEtaSCTrackAtCalo", Electrons_dEtaSCTrackAtCalo, &b_Electrons_dEtaSCTrackAtCalo);
   fChain->SetBranchAddress("Electrons.dPhiSCTrackAtCalo", Electrons_dPhiSCTrackAtCalo, &b_Electrons_dPhiSCTrackAtCalo);
   fChain->SetBranchAddress("Electrons.dr03ChargedHadronPFIso", Electrons_dr03ChargedHadronPFIso, &b_Electrons_dr03ChargedHadronPFIso);
   fChain->SetBranchAddress("Electrons.dr03NeutralHadronPFIso", Electrons_dr03NeutralHadronPFIso, &b_Electrons_dr03NeutralHadronPFIso);
   fChain->SetBranchAddress("Electrons.dr03PhotonPFIso", Electrons_dr03PhotonPFIso, &b_Electrons_dr03PhotonPFIso);
   fChain->SetBranchAddress("Electrons.dr04ChargedHadronPFIso", Electrons_dr04ChargedHadronPFIso, &b_Electrons_dr04ChargedHadronPFIso);
   fChain->SetBranchAddress("Electrons.dr04NeutralHadronPFIso", Electrons_dr04NeutralHadronPFIso, &b_Electrons_dr04NeutralHadronPFIso);
   fChain->SetBranchAddress("Electrons.dr04PhotonPFIso", Electrons_dr04PhotonPFIso, &b_Electrons_dr04PhotonPFIso);
   fChain->SetBranchAddress("Electrons.dr03TkSumPt", Electrons_dr03TkSumPt, &b_Electrons_dr03TkSumPt);
   fChain->SetBranchAddress("Electrons.dr03EcalRecHitSumEt", Electrons_dr03EcalRecHitSumEt, &b_Electrons_dr03EcalRecHitSumEt);
   fChain->SetBranchAddress("Electrons.dr03HcalTowerSumEt", Electrons_dr03HcalTowerSumEt, &b_Electrons_dr03HcalTowerSumEt);
   fChain->SetBranchAddress("Electrons.dr04TkSumPt", Electrons_dr04TkSumPt, &b_Electrons_dr04TkSumPt);
   fChain->SetBranchAddress("Electrons.dr04EcalRecHitSumEt", Electrons_dr04EcalRecHitSumEt, &b_Electrons_dr04EcalRecHitSumEt);
   fChain->SetBranchAddress("Electrons.dr04HcalTowerSumEt", Electrons_dr04HcalTowerSumEt, &b_Electrons_dr04HcalTowerSumEt);
   fChain->SetBranchAddress("Electrons.idMVA", Electrons_idMVA, &b_Electrons_idMVA);
   fChain->SetBranchAddress("Electrons.hasMatchedConversion", Electrons_hasMatchedConversion, &b_Electrons_hasMatchedConversion);
   fChain->SetBranchAddress("Electrons.expInnerLayersHits", Electrons_expInnerLayersHits, &b_Electrons_expInnerLayersHits);
   fChain->SetBranchAddress("Electrons.genMatch.index", Electrons_genMatch_index, &b_Electrons_genMatch_index);
   fChain->SetBranchAddress("Electrons.genMatch.energy", Electrons_genMatch_energy, &b_Electrons_genMatch_energy);
   fChain->SetBranchAddress("Electrons.genMatch.pt", Electrons_genMatch_pt, &b_Electrons_genMatch_pt);
   fChain->SetBranchAddress("Electrons.genMatch.eta", Electrons_genMatch_eta, &b_Electrons_genMatch_eta);
   fChain->SetBranchAddress("Electrons.genMatch.phi", Electrons_genMatch_phi, &b_Electrons_genMatch_phi);
   fChain->SetBranchAddress("Electrons.genMatch.mass", Electrons_genMatch_mass, &b_Electrons_genMatch_mass);
   fChain->SetBranchAddress("Electrons.genMatch.Vx", Electrons_genMatch_Vx, &b_Electrons_genMatch_Vx);
   fChain->SetBranchAddress("Electrons.genMatch.Vy", Electrons_genMatch_Vy, &b_Electrons_genMatch_Vy);
   fChain->SetBranchAddress("Electrons.genMatch.Vz", Electrons_genMatch_Vz, &b_Electrons_genMatch_Vz);
   fChain->SetBranchAddress("Electrons.genMatch.status", Electrons_genMatch_status, &b_Electrons_genMatch_status);
   fChain->SetBranchAddress("Electrons.genMatch.id", Electrons_genMatch_id, &b_Electrons_genMatch_id);
   fChain->SetBranchAddress("Electrons.genMatch.statusMother", Electrons_genMatch_statusMother, &b_Electrons_genMatch_statusMother);
   fChain->SetBranchAddress("Electrons.genMatch.idMother", Electrons_genMatch_idMother, &b_Electrons_genMatch_idMother);
   fChain->SetBranchAddress("Electrons.genMatch.indexMother", Electrons_genMatch_indexMother, &b_Electrons_genMatch_indexMother);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jets", &Jets_, &b_Jets_);
   fChain->SetBranchAddress("Jets.index", Jets_index, &b_Jets_index);
   fChain->SetBranchAddress("Jets.energy", Jets_energy, &b_Jets_energy);
   fChain->SetBranchAddress("Jets.uncorrEnergy", Jets_uncorrEnergy, &b_Jets_uncorrEnergy);
   fChain->SetBranchAddress("Jets.pt", Jets_pt, &b_Jets_pt);
   fChain->SetBranchAddress("Jets.eta", Jets_eta, &b_Jets_eta);
   fChain->SetBranchAddress("Jets.phi", Jets_phi, &b_Jets_phi);
   fChain->SetBranchAddress("Jets.charge", Jets_charge, &b_Jets_charge);
   fChain->SetBranchAddress("Jets.type", Jets_type, &b_Jets_type);
   fChain->SetBranchAddress("Jets.vtxX", Jets_vtxX, &b_Jets_vtxX);
   fChain->SetBranchAddress("Jets.vtxY", Jets_vtxY, &b_Jets_vtxY);
   fChain->SetBranchAddress("Jets.vtxZ", Jets_vtxZ, &b_Jets_vtxZ);
   fChain->SetBranchAddress("Jets.area", Jets_area, &b_Jets_area);
   fChain->SetBranchAddress("Jets.chargedHadronFraction", Jets_chargedHadronFraction, &b_Jets_chargedHadronFraction);
   fChain->SetBranchAddress("Jets.neutralHadronFraction", Jets_neutralHadronFraction, &b_Jets_neutralHadronFraction);
   fChain->SetBranchAddress("Jets.jetIdMva", Jets_jetIdMva, &b_Jets_jetIdMva);
   fChain->SetBranchAddress("Jets.betaStar", Jets_betaStar, &b_Jets_betaStar);
   fChain->SetBranchAddress("Jets.betaStarIdMVA", Jets_betaStarIdMVA, &b_Jets_betaStarIdMVA);
   fChain->SetBranchAddress("Jets.betaStarClassicIdMVA", Jets_betaStarClassicIdMVA, &b_Jets_betaStarClassicIdMVA);
   fChain->SetBranchAddress("Jets.rmsCands", Jets_rmsCands, &b_Jets_rmsCands);
   fChain->SetBranchAddress("Jets.rmsCandsHand", Jets_rmsCandsHand, &b_Jets_rmsCandsHand);
   fChain->SetBranchAddress("Jets.combinedSecondaryVertex", Jets_combinedSecondaryVertex, &b_Jets_combinedSecondaryVertex);
   fChain->SetBranchAddress("Jets.simpleSecondaryVertexHighPur", Jets_simpleSecondaryVertexHighPur, &b_Jets_simpleSecondaryVertexHighPur);
   fChain->SetBranchAddress("Jets.simpleSecondaryVertexHighEff", Jets_simpleSecondaryVertexHighEff, &b_Jets_simpleSecondaryVertexHighEff);
   fChain->SetBranchAddress("CaloMET", &CaloMET, &b_CaloMET);
   fChain->SetBranchAddress("CaloMETPhi", &CaloMETPhi, &b_CaloMETPhi);
   fChain->SetBranchAddress("PFMET", &PFMET, &b_PFMET);
   fChain->SetBranchAddress("PFMETPhi", &PFMETPhi, &b_PFMETPhi);
   fChain->SetBranchAddress("TCMET", &TCMET, &b_TCMET);
   fChain->SetBranchAddress("TCMETPhi", &TCMETPhi, &b_TCMETPhi);
   fChain->SetBranchAddress("ptbal", &ptbal, &b_ptbal);
   fChain->SetBranchAddress("ptasym", &ptasym, &b_ptasym);
   fChain->SetBranchAddress("logsumpt2", &logsumpt2, &b_logsumpt2);
   fChain->SetBranchAddress("limPullToConv", &limPullToConv, &b_limPullToConv);
   fChain->SetBranchAddress("nConv", &nConv, &b_nConv);
   Notify();
}

Bool_t HggReduce::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HggReduce::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HggReduce::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HggReduce_cxx
