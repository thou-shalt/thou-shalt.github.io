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
        WAVEFORMDUR = 0xD8701EA9, // waveformDur
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
  static void cMsg_g2bubYwg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZRj8lGlw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JbMJG1Mm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vTxeg0wR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_K8XFS8Xc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J6c6CDuI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Ve5UyGeN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_plmbapIC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bRzTsdKo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XXKdZT2g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_85bEbFnF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dCHzn9ha_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HbyeykAj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2Bxf1xY0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eNBUax1x_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_CNwYm7bz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sYjmlCQX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Mz4YpvkH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_mLpwnduP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hb0NabES_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BuSiOGDw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JXYcUK3F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_W7AIr53L_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_lhNGQsuz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JXnRSEw0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eO54lC4J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wWJjlGcW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gWSfSWxM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_cPq591D1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Gnhdgrh8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_H6V7LDdb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_X3tZ5bu9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GYnz0xHr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6ECupWta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ZxoqXS5x_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cReceive_7rLQ39Gl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QFWEn5XV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Caiz520f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1T9shNPT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XkCHGH7k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1N5LNmXn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jZHalq3q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_NQhFnVXF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3wtIy9yf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uP8TzdT6_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_7sL0PDMQ;
  SignalTabread sTabread_BVjUj85K;
  SignalTabread sTabread_JY3UYOEU;
  SignalLine sLine_OSaLHAVd;
  SignalTabread sTabread_2bfeiEwu;
  SignalVarf sVarf_EewcNcbm;
  ControlSlice cSlice_ZRj8lGlw;
  ControlVar cVar_vTxeg0wR;
  ControlBinop cBinop_J6c6CDuI;
  SignalVarf sVarf_0hkPIAyl;
  ControlVar cVar_85bEbFnF;
  ControlVar cVar_dCHzn9ha;
  ControlBinop cBinop_Mz4YpvkH;
  HvTable hTable_mLpwnduP;
  ControlBinop cBinop_BuSiOGDw;
  ControlVar cVar_JXYcUK3F;
  ControlBinop cBinop_lhNGQsuz;
  ControlBinop cBinop_gWSfSWxM;
  ControlDelay cDelay_cPq591D1;
  ControlSlice cSlice_Gnhdgrh8;
  SignalVarf sVarf_W3ZzUH2V;
  ControlVar cVar_X3tZ5bu9;
  ControlBinop cBinop_6ECupWta;
  ControlVar cVar_Caiz520f;
  ControlBinop cBinop_1T9shNPT;
  ControlBinop cBinop_1N5LNmXn;
  SignalVarf sVarf_VQdZou3o;
};

#endif // _HEAVY_CONTEXT_TEST_HPP_
