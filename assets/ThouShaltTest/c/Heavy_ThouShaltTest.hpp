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

#ifndef _HEAVY_CONTEXT_THOUSHALTTEST_HPP_
#define _HEAVY_CONTEXT_THOUSHALTTEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvTable.h"
#include "HvSignalLine.h"
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

class Heavy_ThouShaltTest : public HeavyContext {

 public:
  Heavy_ThouShaltTest(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_ThouShaltTest();

  const char *getName() override { return "ThouShaltTest"; }
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
  static void cMsg_PmcTeBFA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_7GzIlFgI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uK4X4U4K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PgsiE5Dr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_H7HUollR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m9JME2AO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0HQ5Xp16_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CJzVYN01_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xEhynqGq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uDMTBPh7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_49CqU5yB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9rWipsMy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Hc9u4Goq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RKpP3aqx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_VPF1XRrh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_B4yv8oP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ApzBDNFq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_jJnGqdVi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Do0iaZSA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HqD1oosz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mjSV52Zt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Pa07ij49_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PxHGv1PI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ILePX9Uf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lkrAaMeq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_kjcJlL4W_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_zGLFpCJi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2Y978wZX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_qWehDgb3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rKskl50Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uWUlXTmP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3KTRfbpC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_VzLWE8zN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XP3e0B6s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b8nLba6n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HhBDbikJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0UhNUAqW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lZc8u1WL_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_6FgXyVQl;
  SignalTabread sTabread_aGzPtEr4;
  SignalTabread sTabread_pQJseMC2;
  SignalPhasor sPhasor_1wSov0Ak;
  SignalLine sLine_M68Wq72B;
  HvTable hTable_7GzIlFgI;
  ControlSlice cSlice_uDMTBPh7;
  ControlVar cVar_49CqU5yB;
  ControlBinop cBinop_9rWipsMy;
  SignalVarf sVarf_477yCidD;
  ControlDelay cDelay_jJnGqdVi;
  ControlDelay cDelay_zGLFpCJi;
  ControlDelay cDelay_qWehDgb3;
  ControlBinop cBinop_rKskl50Q;
  ControlBinop cBinop_uWUlXTmP;
  ControlBinop cBinop_HhBDbikJ;
  ControlVar cVar_lZc8u1WL;
};

#endif // _HEAVY_CONTEXT_THOUSHALTTEST_HPP_
