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
  static void cReceive_PvjozGho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ABYnkVmX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_JJsYa5L1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GIRXRAGp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_qaxPBZ3W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mKWtqxDd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PLHeDsdv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_4KXIplrY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xe0l8MIc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HZ4kNd4O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_r47LqdvH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_EeOtNlQs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qqBcEYhO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HnS6sFAi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_RhCvvrHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xkPRdGl3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0aYIc8ir_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zT1iYwFd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RHF801CU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_P0xHpIaj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aClf6FEL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PmG89anN_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_dWwKNQ0z;
  SignalTabread sTabread_npsq6GOI;
  SignalTabread sTabread_u9CEbGVS;
  SignalPhasor sPhasor_EHpVVFL4;
  ControlSlice cSlice_qaxPBZ3W;
  ControlVar cVar_mKWtqxDd;
  ControlBinop cBinop_4KXIplrY;
  SignalVarf sVarf_GIhKxAtt;
  SignalVarf sVarf_Uv6VL2Yh;
  HvTable hTable_r47LqdvH;
  SignalVarf sVarf_kaZFZd0Z;
  ControlDelay cDelay_EeOtNlQs;
  ControlVar cVar_RhCvvrHP;
  ControlBinop cBinop_xkPRdGl3;
  ControlBinop cBinop_0aYIc8ir;
  ControlBinop cBinop_aClf6FEL;
};

#endif // _HEAVY_CONTEXT_TEST_HPP_
