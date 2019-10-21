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

#include "Heavy_ThouShaltTest.hpp"

#define Context(_c) reinterpret_cast<Heavy_ThouShaltTest *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_ThouShaltTest_new(double sampleRate) {
    return new Heavy_ThouShaltTest(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_ThouShaltTest_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_ThouShaltTest(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_ThouShaltTest::Heavy_ThouShaltTest(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_6FgXyVQl, 110.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_aGzPtEr4, &hTable_7GzIlFgI, false);
  numBytes += sTabread_init(&sTabread_pQJseMC2, &hTable_7GzIlFgI, false);
  numBytes += sPhasor_k_init(&sPhasor_1wSov0Ak, 110.0f, sampleRate);
  numBytes += sLine_init(&sLine_M68Wq72B);
  numBytes += hTable_init(&hTable_7GzIlFgI, 515);
  numBytes += cSlice_init(&cSlice_uDMTBPh7, 1, 1);
  numBytes += cVar_init_s(&cVar_49CqU5yB, "waveform");
  numBytes += sVarf_init(&sVarf_477yCidD, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_jJnGqdVi, 250.0f);
  numBytes += cDelay_init(this, &cDelay_zGLFpCJi, 500.0f);
  numBytes += cDelay_init(this, &cDelay_qWehDgb3, 0.0f);
  numBytes += cBinop_init(&cBinop_rKskl50Q, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lZc8u1WL, 1000.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_ThouShaltTest::~Heavy_ThouShaltTest() {
  hTable_free(&hTable_7GzIlFgI);
}

HvTable *Heavy_ThouShaltTest::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCE6D0368: return &hTable_7GzIlFgI; // waveform
    default: return nullptr;
  }
}

void Heavy_ThouShaltTest::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mjSV52Zt_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_ThouShaltTest::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_ThouShaltTest::cMsg_PmcTeBFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_M68Wq72B, 0, m, NULL);
}

void Heavy_ThouShaltTest::hTable_7GzIlFgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_ThouShaltTest::cMsg_uK4X4U4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(4);
  msg_init(m, 4, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "waveform");
  msg_setSymbol(m, 1, "sinesum");
  msg_setFloat(m, 2, 515.0f);
  msg_setFloat(m, 3, 0.9f);
}

void Heavy_ThouShaltTest::cMsg_PgsiE5Dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 55.0f);
  msg_setFloat(m, 1, 1000.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_M68Wq72B, 0, m, NULL);
}

void Heavy_ThouShaltTest::cCast_H7HUollR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PmcTeBFA_sendMessage(_c, 0, m);
}

void Heavy_ThouShaltTest::cMsg_m9JME2AO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "waveform");
  msg_setSymbol(m, 1, "read");
  msg_setSymbol(m, 2, "waveform.txt");
}

void Heavy_ThouShaltTest::cCast_0HQ5Xp16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_ThouShaltTest::cCast_CJzVYN01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3KTRfbpC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShaltTest::cCast_xEhynqGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0HQ5Xp16_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CJzVYN01_sendMessage);
}

void Heavy_ThouShaltTest::cSlice_uDMTBPh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_aGzPtEr4, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_pQJseMC2, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_49CqU5yB, 0, m, &cVar_49CqU5yB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_ThouShaltTest::cVar_49CqU5yB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hc9u4Goq_sendMessage(_c, 0, m);
}

void Heavy_ThouShaltTest::cBinop_9rWipsMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_477yCidD, m);
}

void Heavy_ThouShaltTest::cMsg_Hc9u4Goq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VPF1XRrh_sendMessage);
}

void Heavy_ThouShaltTest::cSwitchcase_RKpP3aqx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uDMTBPh7, 0, m, &cSlice_uDMTBPh7_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_ThouShaltTest::cSystem_VPF1XRrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_9rWipsMy_sendMessage);
}

void Heavy_ThouShaltTest::cCast_B4yv8oP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ApzBDNFq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShaltTest::cSwitchcase_ApzBDNFq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Do0iaZSA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Do0iaZSA_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_jJnGqdVi, 1, m, &cDelay_jJnGqdVi_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HqD1oosz_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShaltTest::cDelay_jJnGqdVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jJnGqdVi, m);
  cMsg_PxHGv1PI_sendMessage(_c, 0, m);
}

void Heavy_ThouShaltTest::cMsg_Do0iaZSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jJnGqdVi, 0, m, &cDelay_jJnGqdVi_sendMessage);
}

void Heavy_ThouShaltTest::cCast_HqD1oosz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jJnGqdVi, 0, m, &cDelay_jJnGqdVi_sendMessage);
}

void Heavy_ThouShaltTest::cReceive_mjSV52Zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XP3e0B6s_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lZc8u1WL, 0, m, &cVar_lZc8u1WL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0HQ5Xp16_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CJzVYN01_sendMessage);
  cMsg_m9JME2AO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_49CqU5yB, 0, m, &cVar_49CqU5yB_sendMessage);
}

void Heavy_ThouShaltTest::cCast_Pa07ij49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kjcJlL4W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_ThouShaltTest::cMsg_PxHGv1PI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_M68Wq72B, 0, m, NULL);
}

void Heavy_ThouShaltTest::cMsg_ILePX9Uf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(18);
  msg_init(m, 18, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "waveform");
  msg_setSymbol(m, 1, "sinesum");
  msg_setFloat(m, 2, 515.0f);
  msg_setFloat(m, 3, 0.9f);
  msg_setFloat(m, 4, -0.125f);
  msg_setFloat(m, 5, 0.3f);
  msg_setFloat(m, 6, 0.0f);
  msg_setFloat(m, 7, 0.2f);
  msg_setFloat(m, 8, 0.0f);
  msg_setFloat(m, 9, 0.1f);
  msg_setFloat(m, 10, 0.0f);
  msg_setFloat(m, 11, 0.05f);
  msg_setFloat(m, 12, 0.0f);
  msg_setFloat(m, 13, 0.025f);
  msg_setFloat(m, 14, -0.0125f);
  msg_setFloat(m, 15, -0.0125f);
  msg_setFloat(m, 16, 0.0125f);
  msg_setFloat(m, 17, -0.0125f);
}

void Heavy_ThouShaltTest::cCast_lkrAaMeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zGLFpCJi, 0, m, &cDelay_zGLFpCJi_sendMessage);
}

void Heavy_ThouShaltTest::cSwitchcase_kjcJlL4W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_2Y978wZX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_2Y978wZX_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_zGLFpCJi, 1, m, &cDelay_zGLFpCJi_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lkrAaMeq_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShaltTest::cDelay_zGLFpCJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zGLFpCJi, m);
  cMsg_PgsiE5Dr_sendMessage(_c, 0, m);
}

void Heavy_ThouShaltTest::cMsg_2Y978wZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zGLFpCJi, 0, m, &cDelay_zGLFpCJi_sendMessage);
}

void Heavy_ThouShaltTest::cDelay_qWehDgb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qWehDgb3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qWehDgb3, 0, m, &cDelay_qWehDgb3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H7HUollR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B4yv8oP3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pa07ij49_sendMessage);
}

void Heavy_ThouShaltTest::cBinop_rKskl50Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uWUlXTmP_sendMessage);
}

void Heavy_ThouShaltTest::cBinop_uWUlXTmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qWehDgb3, 2, m, &cDelay_qWehDgb3_sendMessage);
}

void Heavy_ThouShaltTest::cSwitchcase_3KTRfbpC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_0UhNUAqW_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_0UhNUAqW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b8nLba6n_sendMessage);
      break;
    }
  }
}

void Heavy_ThouShaltTest::cSystem_VzLWE8zN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HhBDbikJ_sendMessage);
}

void Heavy_ThouShaltTest::cMsg_XP3e0B6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VzLWE8zN_sendMessage);
}

void Heavy_ThouShaltTest::cCast_b8nLba6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0UhNUAqW_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qWehDgb3, 0, m, &cDelay_qWehDgb3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H7HUollR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B4yv8oP3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pa07ij49_sendMessage);
}

void Heavy_ThouShaltTest::cBinop_HhBDbikJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rKskl50Q, HV_BINOP_MULTIPLY, 1, m, &cBinop_rKskl50Q_sendMessage);
}

void Heavy_ThouShaltTest::cMsg_0UhNUAqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qWehDgb3, 0, m, &cDelay_qWehDgb3_sendMessage);
}

void Heavy_ThouShaltTest::cVar_lZc8u1WL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rKskl50Q, HV_BINOP_MULTIPLY, 0, m, &cBinop_rKskl50Q_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_ThouShaltTest::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4;
  hv_bufferi_t Bi0, Bi1;

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
    __hv_phasor_k_f(&sPhasor_6FgXyVQl, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_477yCidD, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_aGzPtEr4, VIi(Bi1), VOf(Bf0));
    __hv_tabread_if(&sTabread_pQJseMC2, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_1wSov0Ak, VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_line_f(&sLine_M68Wq72B, VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_ThouShaltTest::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_ThouShaltTest::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
