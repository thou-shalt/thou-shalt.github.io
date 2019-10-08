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

#include "Heavy_ThouShalt.hpp"

#define Context(_c) reinterpret_cast<Heavy_ThouShalt *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_ThouShalt_new(double sampleRate) {
    return new Heavy_ThouShalt(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_ThouShalt_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_ThouShalt(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_ThouShalt::Heavy_ThouShalt(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_OIhh4seD);
  numBytes += sLine_init(&sLine_dCk1opPl);
  numBytes += sPhasor_init(&sPhasor_iGwUD0b0, sampleRate);
  numBytes += sPhasor_init(&sPhasor_q83GHvxG, sampleRate);
  numBytes += sLine_init(&sLine_wjn5jyyr);
  numBytes += cDelay_init(this, &cDelay_Og5kCli4, 155.0f);
  numBytes += cRandom_init(&cRandom_aM6beex2, -1233028483);
  numBytes += cSlice_init(&cSlice_PqhIlHSi, 1, 1);
  numBytes += cDelay_init(this, &cDelay_iEgtDBS0, 75.0f);
  numBytes += cBinop_init(&cBinop_2QJoFodX, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_2DPVhnGA, 0.0f);
  numBytes += cVar_init_f(&cVar_PXVF9kIi, 110.0f);
  numBytes += cDelay_init(this, &cDelay_mEwhMAHF, 20.0f);
  numBytes += cDelay_init(this, &cDelay_QogXR16b, 5.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_ThouShalt::~Heavy_ThouShalt() {
  // nothing to free
}

HvTable *Heavy_ThouShalt::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_ThouShalt::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qSA3p2HQ_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_ThouShalt::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_ThouShalt::cCast_eBnsZYP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Db8V3est_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShalt::cMsg_us6alxd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  msg_setFloat(m, 1, 90.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dCk1opPl, 0, m, NULL);
}

void Heavy_ThouShalt::cMsg_SNmfe1dt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 80.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OIhh4seD, 0, m, NULL);
}

void Heavy_ThouShalt::cBinop_7Mk2ZnQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YhEUNIkF_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cCast_n8lYRiwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_B9cvCmH4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShalt::cMsg_wyO5z6fK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dCk1opPl, 0, m, NULL);
}

void Heavy_ThouShalt::cSwitchcase_2V55uzk7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_MoxxAHvK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_MoxxAHvK_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Og5kCli4, 1, m, &cDelay_Og5kCli4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zezULODn_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShalt::cMsg_MoxxAHvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Og5kCli4, 0, m, &cDelay_Og5kCli4_sendMessage);
}

void Heavy_ThouShalt::cCast_zezULODn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Og5kCli4, 0, m, &cDelay_Og5kCli4_sendMessage);
}

void Heavy_ThouShalt::cDelay_Og5kCli4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Og5kCli4, m);
  cMsg_SNmfe1dt_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cCast_rHCny1WW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lSPDrhBJ_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cMsg_YhEUNIkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wjn5jyyr, 0, m, NULL);
}

void Heavy_ThouShalt::cMsg_PS6CSvkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_ZoIK5orv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShalt::cCast_sGgAvIvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WJf2xVk8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShalt::cRandom_aM6beex2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_yfYskKjh_sendMessage);
}

void Heavy_ThouShalt::cSlice_PqhIlHSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aM6beex2, 1, m, &cRandom_aM6beex2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_ThouShalt::cUnop_70I8AQib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 500.0f, 0, m, &cBinop_Xq4UFrDU_sendMessage);
}

void Heavy_ThouShalt::cBinop_yfYskKjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_70I8AQib_sendMessage);
}

void Heavy_ThouShalt::cSwitchcase_T7f6hHGJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PqhIlHSi, 0, m, &cSlice_PqhIlHSi_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aM6beex2, 0, m, &cRandom_aM6beex2_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShalt::cCast_JG3B03JB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wyO5z6fK_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cMsg_9rywwGED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 4.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OIhh4seD, 0, m, NULL);
}

void Heavy_ThouShalt::cCast_JDB9mcm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iEgtDBS0, 0, m, &cDelay_iEgtDBS0_sendMessage);
}

void Heavy_ThouShalt::cDelay_iEgtDBS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iEgtDBS0, m);
  cMsg_us6alxd4_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cSwitchcase_Db8V3est_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_EsmawP2f_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_EsmawP2f_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_iEgtDBS0, 1, m, &cDelay_iEgtDBS0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JDB9mcm7_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShalt::cMsg_EsmawP2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iEgtDBS0, 0, m, &cDelay_iEgtDBS0_sendMessage);
}

void Heavy_ThouShalt::cBinop_2QJoFodX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_KBIOJsLf_sendMessage);
}

void Heavy_ThouShalt::cMsg_TF8PsSNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u044jqEj_sendMessage);
}

void Heavy_ThouShalt::cSystem_u044jqEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5WrbDuNf_sendMessage);
}

void Heavy_ThouShalt::cSwitchcase_ZoIK5orv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_pdOpw0T8_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_pdOpw0T8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p8qgIN59_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShalt::cBinop_5WrbDuNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2QJoFodX, HV_BINOP_MULTIPLY, 1, m, &cBinop_2QJoFodX_sendMessage);
}

void Heavy_ThouShalt::cDelay_2DPVhnGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2DPVhnGA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2DPVhnGA, 0, m, &cDelay_2DPVhnGA_sendMessage);
  cSwitchcase_T7f6hHGJ_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eBnsZYP9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sGgAvIvL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JG3B03JB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NCamAlTd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n8lYRiwY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rHCny1WW_sendMessage);
}

void Heavy_ThouShalt::cBinop_KBIOJsLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2DPVhnGA, 2, m, &cDelay_2DPVhnGA_sendMessage);
}

void Heavy_ThouShalt::cMsg_pdOpw0T8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2DPVhnGA, 0, m, &cDelay_2DPVhnGA_sendMessage);
}

void Heavy_ThouShalt::cCast_p8qgIN59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pdOpw0T8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2DPVhnGA, 0, m, &cDelay_2DPVhnGA_sendMessage);
  cSwitchcase_T7f6hHGJ_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eBnsZYP9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sGgAvIvL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JG3B03JB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NCamAlTd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n8lYRiwY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rHCny1WW_sendMessage);
}

void Heavy_ThouShalt::cVar_PXVF9kIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2QJoFodX, HV_BINOP_MULTIPLY, 0, m, &cBinop_2QJoFodX_sendMessage);
}

void Heavy_ThouShalt::cMsg_WqSkxfX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mEwhMAHF, 0, m, &cDelay_mEwhMAHF_sendMessage);
}

void Heavy_ThouShalt::cCast_ZQBDM9cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mEwhMAHF, 0, m, &cDelay_mEwhMAHF_sendMessage);
}

void Heavy_ThouShalt::cDelay_mEwhMAHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mEwhMAHF, m);
  cMsg_cOfb8P0K_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cSwitchcase_WJf2xVk8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WqSkxfX9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WqSkxfX9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_mEwhMAHF, 1, m, &cDelay_mEwhMAHF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZQBDM9cz_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShalt::cMsg_lSPDrhBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OIhh4seD, 0, m, NULL);
}

void Heavy_ThouShalt::cDelay_QogXR16b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QogXR16b, m);
  cMsg_9rywwGED_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cCast_oy4CNrEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QogXR16b, 0, m, &cDelay_QogXR16b_sendMessage);
}

void Heavy_ThouShalt::cSwitchcase_B9cvCmH4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_0MP40a21_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_0MP40a21_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QogXR16b, 1, m, &cDelay_QogXR16b_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oy4CNrEg_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShalt::cMsg_0MP40a21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QogXR16b, 0, m, &cDelay_QogXR16b_sendMessage);
}

void Heavy_ThouShalt::cReceive_qSA3p2HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TF8PsSNd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PXVF9kIi, 0, m, &cVar_PXVF9kIi_sendMessage);
  cMsg_PS6CSvkp_sendMessage(_c, 0, m);
}

void Heavy_ThouShalt::cBinop_Xq4UFrDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_DSqVyMaf_sendMessage);
}

void Heavy_ThouShalt::cBinop_DSqVyMaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.25f, 0, m, &cBinop_7Mk2ZnQ1_sendMessage);
}

void Heavy_ThouShalt::cMsg_cOfb8P0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.18f);
  msg_setFloat(m, 1, 40.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dCk1opPl, 0, m, NULL);
}

void Heavy_ThouShalt::cCast_NCamAlTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2V55uzk7_onMessage(_c, NULL, 0, m, NULL);
}




/*
 * Context Process Implementation
 */

int Heavy_ThouShalt::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_line_f(&sLine_OIhh4seD, VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_dCk1opPl, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 444.0f, 444.0f, 444.0f, 444.0f, 444.0f, 444.0f, 444.0f, 444.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_iGwUD0b0, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 1040.0f, 1040.0f, 1040.0f, 1040.0f, 1040.0f, 1040.0f, 1040.0f, 1040.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_q83GHvxG, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_line_f(&sLine_wjn5jyyr, VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf4));
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_ThouShalt::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_ThouShalt::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
