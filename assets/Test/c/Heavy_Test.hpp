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
#include "HvTable.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvSignalTabread.h"

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
        WLEN = 0x1992B601, // wLen
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
  static void cMsg_UBbJuJiZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_9ZVNReGs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1QmtIFP7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_lZKdVTcn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yIsh21Og_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p76iuJs2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xwlQCFfJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_moi6sFuo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_pF42jVZi_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_5m72gf8a;
  SignalPhasor sPhasor_TaP6d5J8;
  SignalTabread sTabread_XUBhTk5O;
  SignalTabread sTabread_bW5JIqIE;
  SignalVarf sVarf_3QswrrgY;
  ControlVar cVar_lZKdVTcn;
  ControlSlice cSlice_yIsh21Og;
  ControlBinop cBinop_p76iuJs2;
  SignalVarf sVarf_z8V2jocq;
  HvTable hTable_moi6sFuo;
};

#endif // _HEAVY_CONTEXT_TEST_HPP_
