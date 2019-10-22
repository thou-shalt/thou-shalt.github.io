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

#include "Heavy_Test.hpp"

#define Context(_c) reinterpret_cast<Heavy_Test *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_Test_new(double sampleRate) {
    return new Heavy_Test(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_Test_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_Test(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_Test::Heavy_Test(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_fknco2KS, 440.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_hPPtCVoc, sampleRate);
  numBytes += sTabread_init(&sTabread_V8Hi1BFN, &hTable_8ezYnr7j, false);
  numBytes += sTabread_init(&sTabread_VSMW1qMw, &hTable_8ezYnr7j, false);
  numBytes += hTable_init(&hTable_8ezYnr7j, 515);
  numBytes += cDelay_init(this, &cDelay_lmx6XbDB, 0.0f);
  numBytes += cVar_init_f(&cVar_BWhep5X0, 1000.0f);
  numBytes += cBinop_init(&cBinop_YDffUN0e, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_TRtj55QD, 512.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_4O9nVjGd, "waveform");
  numBytes += sVarf_init(&sVarf_r3ADmD6m, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_MFy07hft, 1, 1);
  numBytes += sVarf_init(&sVarf_6myNNieP, 110.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_Test::~Heavy_Test() {
  hTable_free(&hTable_8ezYnr7j);
}

HvTable *Heavy_Test::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCE6D0368: return &hTable_8ezYnr7j; // waveform
    default: return nullptr;
  }
}

void Heavy_Test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rKBqHmFA_sendMessage);
      break;
    }
    case 0x2F18AC4C: { // phasorFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DQFzmxBH_sendMessage);
      break;
    }
    case 0x44E6072E: { // waveformLength
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RO5RxdwW_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_Test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "waveformLength";
        info->hash = 0x44E6072E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "phasorFreq";
        info->hash = 0x2F18AC4C;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
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
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_Test::hTable_8ezYnr7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_Test::cSend_ckSo8sBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "bang", 0xFFFFFFFF, m);
}

void Heavy_Test::cMsg_ROSYOhMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lmx6XbDB, 0, m, &cDelay_lmx6XbDB_sendMessage);
}

void Heavy_Test::cDelay_lmx6XbDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lmx6XbDB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lmx6XbDB, 0, m, &cDelay_lmx6XbDB_sendMessage);
  cSend_ckSo8sBc_sendMessage(_c, 0, m);
}

void Heavy_Test::cVar_BWhep5X0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YDffUN0e, HV_BINOP_MULTIPLY, 0, m, &cBinop_YDffUN0e_sendMessage);
}

void Heavy_Test::cCast_0nsUzsl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ROSYOhMe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lmx6XbDB, 0, m, &cDelay_lmx6XbDB_sendMessage);
  cSend_ckSo8sBc_sendMessage(_c, 0, m);
}

void Heavy_Test::cMsg_ZdHR4KD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4Hh6x2E2_sendMessage);
}

void Heavy_Test::cSystem_4Hh6x2E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aAPDR8oR_sendMessage);
}

void Heavy_Test::cBinop_aAPDR8oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YDffUN0e, HV_BINOP_MULTIPLY, 1, m, &cBinop_YDffUN0e_sendMessage);
}

void Heavy_Test::cSwitchcase_5vphzXG7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ROSYOhMe_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ROSYOhMe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0nsUzsl0_sendMessage);
      break;
    }
  }
}

void Heavy_Test::cBinop_ejhjteOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lmx6XbDB, 2, m, &cDelay_lmx6XbDB_sendMessage);
}

void Heavy_Test::cBinop_YDffUN0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ejhjteOe_sendMessage);
}

void Heavy_Test::cMsg_iru3kdYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_5vphzXG7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Test::cBinop_7sAA8a7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_r3ADmD6m, m);
}

void Heavy_Test::cVar_4O9nVjGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ReFfol3f_sendMessage(_c, 0, m);
}

void Heavy_Test::cSwitchcase_Cw03XX49_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MFy07hft, 0, m, &cSlice_MFy07hft_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_Test::cSystem_ob3NBEWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_7sAA8a7T_sendMessage);
}

void Heavy_Test::cSlice_MFy07hft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_V8Hi1BFN, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_VSMW1qMw, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_4O9nVjGd, 0, m, &cVar_4O9nVjGd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Test::cMsg_ReFfol3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ob3NBEWT_sendMessage);
}

void Heavy_Test::cReceive_DQFzmxBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6myNNieP, m);
  cPrint_onMessage(_c, m, "print");
}

void Heavy_Test::cReceive_RO5RxdwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TRtj55QD, m);
}

void Heavy_Test::cReceive_rKBqHmFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZdHR4KD7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BWhep5X0, 0, m, &cVar_BWhep5X0_sendMessage);
  cMsg_iru3kdYF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4O9nVjGd, 0, m, &cVar_4O9nVjGd_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_Test::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_phasor_k_f(&sPhasor_fknco2KS, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_6myNNieP, VOf(Bf3));
    __hv_phasor_f(&sPhasor_hPPtCVoc, VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_TRtj55QD, VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_r3ADmD6m, VOf(Bf1));
    __hv_min_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf0));
    __hv_max_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_V8Hi1BFN, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_VSMW1qMw, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_Test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_Test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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