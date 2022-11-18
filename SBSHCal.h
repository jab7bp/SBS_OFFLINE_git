#ifndef SBSHCal_h
#define SBSHCal_h

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// SBSHCal                                                                   //
//                                                                           //
// A sub-class of SBSCalorimeter that has Multi-valued ADC + TDC             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "SBSCalorimeter.h"

class SBSHCal : public SBSCalorimeter {
public:
  explicit SBSHCal( const char* name, const char* description = "",
                    THaApparatus* a = nullptr);
  virtual ~SBSHCal();
  virtual Int_t  ReadDatabase( const TDatime& date );
  virtual Int_t  Decode( const THaEvData& evdata );
  virtual Int_t  CoarseProcess(TClonesArray& tracks );
  virtual Int_t  DefineVariables( EMode mode = kDefine );
  virtual void   Clear( Option_t* opt="" );

protected:
  Bool_t fWithLED;
  Int_t fLEDCrate;
  Int_t fLEDSlot;
  Int_t fLEDBit;
  Int_t fLEDCount;

  ClassDef(SBSHCal,0)     // HCal detector class
};
#endif // SBSHCal_h
