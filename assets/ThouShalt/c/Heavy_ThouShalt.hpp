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

#ifndef _HEAVY_CONTEXT_THOUSHALT_HPP_
#define _HEAVY_CONTEXT_THOUSHALT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"

class Heavy_ThouShalt : public HeavyContext {

 public:
  Heavy_ThouShalt(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_ThouShalt();

  const char *getName() override { return "ThouShalt"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cCast_eBnsZYP9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_us6alxd4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SNmfe1dt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7Mk2ZnQ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_n8lYRiwY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wyO5z6fK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_2V55uzk7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_MoxxAHvK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zezULODn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Og5kCli4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rHCny1WW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YhEUNIkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PS6CSvkp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sGgAvIvL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_aM6beex2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PqhIlHSi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_70I8AQib_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yfYskKjh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_T7f6hHGJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_JG3B03JB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9rywwGED_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JDB9mcm7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_iEgtDBS0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Db8V3est_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_EsmawP2f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2QJoFodX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TF8PsSNd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_u044jqEj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ZoIK5orv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_5WrbDuNf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_2DPVhnGA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KBIOJsLf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pdOpw0T8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_p8qgIN59_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PXVF9kIi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WqSkxfX9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZQBDM9cz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_mEwhMAHF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WJf2xVk8_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_lSPDrhBJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_QogXR16b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oy4CNrEg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_B9cvCmH4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_0MP40a21_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qSA3p2HQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xq4UFrDU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DSqVyMaf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cOfb8P0K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NCamAlTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_OIhh4seD;
  SignalLine sLine_dCk1opPl;
  SignalPhasor sPhasor_iGwUD0b0;
  SignalPhasor sPhasor_q83GHvxG;
  SignalLine sLine_wjn5jyyr;
  ControlBinop cBinop_7Mk2ZnQ1;
  ControlDelay cDelay_Og5kCli4;
  ControlRandom cRandom_aM6beex2;
  ControlSlice cSlice_PqhIlHSi;
  ControlBinop cBinop_yfYskKjh;
  ControlDelay cDelay_iEgtDBS0;
  ControlBinop cBinop_2QJoFodX;
  ControlBinop cBinop_5WrbDuNf;
  ControlDelay cDelay_2DPVhnGA;
  ControlBinop cBinop_KBIOJsLf;
  ControlVar cVar_PXVF9kIi;
  ControlDelay cDelay_mEwhMAHF;
  ControlDelay cDelay_QogXR16b;
  ControlBinop cBinop_Xq4UFrDU;
  ControlBinop cBinop_DSqVyMaf;
};

#endif // _HEAVY_CONTEXT_THOUSHALT_HPP_
