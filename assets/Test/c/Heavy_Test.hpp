/**
 * Copyright (c) 2019 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_TEST_HPP_
#define _HEAVY_CONTEXT_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlPrint.h"
#include "HvTable.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvSignalTabread.h"
#include "HvControlCast.h"

class Heavy_Test : public HeavyContext {

 public:
  Heavy_Test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_Test();

  const char *getName() override { return "Test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        PHASORFREQ = 0x2F18AC4C, // phasorFreq
        WAVEFORMLENGTH = 0x44E6072E, // waveformLength
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        BANG = 0xFFFFFFFF, // bang
      };
    };
  };
  enum Table : hv_uint32_t {
    WAVEFORM = 0xCE6D0368, // waveform
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void hTable_8ezYnr7j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_ckSo8sBc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ROSYOhMe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_lmx6XbDB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BWhep5X0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0nsUzsl0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZdHR4KD7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4Hh6x2E2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aAPDR8oR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5vphzXG7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ejhjteOe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YDffUN0e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iru3kdYF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7sAA8a7T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4O9nVjGd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Cw03XX49_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_ob3NBEWT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_MFy07hft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ReFfol3f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DQFzmxBH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_RO5RxdwW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rKBqHmFA_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_fknco2KS;
  SignalPhasor sPhasor_hPPtCVoc;
  SignalTabread sTabread_V8Hi1BFN;
  SignalTabread sTabread_VSMW1qMw;
  HvTable hTable_8ezYnr7j;
  ControlDelay cDelay_lmx6XbDB;
  ControlVar cVar_BWhep5X0;
  ControlBinop cBinop_aAPDR8oR;
  ControlBinop cBinop_ejhjteOe;
  ControlBinop cBinop_YDffUN0e;
  SignalVarf sVarf_TRtj55QD;
  ControlBinop cBinop_7sAA8a7T;
  ControlVar cVar_4O9nVjGd;
  SignalVarf sVarf_r3ADmD6m;
  ControlSlice cSlice_MFy07hft;
  SignalVarf sVarf_6myNNieP;
};

#endif // _HEAVY_CONTEXT_TEST_HPP_
