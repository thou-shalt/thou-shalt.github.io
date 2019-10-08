#ifdef GL_ES
precision mediump float;
precision highp int;
#endif

#define PROCESSING_COLOR_SHADER
#define PI 3.14159265359

varying vec2 vTexCoord;

uniform vec2 uResolution;
uniform vec2 uMouse;
uniform float uTime;

vec3 hsv2rgb(in vec3 c){
  vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
  vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
  return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void translate2d(inout vec2 pos,
                  in vec2 xy){
  pos -= xy;
}

float rectangle(in vec2 pos,
                in vec2 rectPos,
                in vec2 size,
                in vec4 blur){


  vec2 posTranslated = pos - rectPos;
  vec4 blurClamped =  clamp(blur, vec4(0.0001), vec4(1.0));

  vec2 endBlurLeft = -(size/2.0);
  vec2 startBlurLeft = endBlurLeft - blurClamped.xz;
  vec2 startBlurRight = endBlurLeft + size;
  vec2 endBlurRight = startBlurRight + blurClamped.yw;

  vec2 colorMix =
    smoothstep(startBlurLeft, endBlurLeft, posTranslated) -
    smoothstep(startBlurRight, endBlurRight, posTranslated);

  return colorMix.x * colorMix.y;
}


void main() {

  vec3 backgroundColor = hsv2rgb(vec3(0.61, 0.5, 0.01));

  vec3 rectColor = hsv2rgb(vec3(0.81, 1.0, 0.04));


  float screenRatio = uResolution.x/uResolution.y;
  vec2 posNorm = vTexCoord;
  posNorm.x *= screenRatio;

  vec2 rectPos = vec2(0.5*screenRatio, 0.5);
  float rectMix = rectangle(posNorm, rectPos, vec2(1.0,0.75), vec4(vec2(0.1),vec2(0.01)));

  vec3 fillColor = mix(backgroundColor, rectColor, rectMix);

  // rectMix = rectangle(posNorm, rectPos, vec2(uMouse.x/uResolution.x,0.5), vec4(vec2(0.0), vec2(0.1)));
  // rectMix = rectangle(posNorm, rectPos, vec2(10.0*uTime/uResolution.x,0.5), vec4(vec2(0.0), vec2(0.1)));

  fillColor = mix(fillColor, hsv2rgb(vec3(0.3,0.0,0.02)), rectMix);

  gl_FragColor = vec4(fillColor,1.0);
}
