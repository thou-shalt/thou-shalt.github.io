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
uniform vec3 uBackgroundColor;
uniform vec3 uForegroundColor;
uniform sampler2D tex0;

float rct(in vec2 coord,
           in vec2 topLeft,
           in vec2 bottomRight,
           in vec4 blur) {

  vec4 blurClamped =  clamp(blur, vec4(0.0001), vec4(1.0));
  vec2 colorMix  =
    smoothstep(topLeft - blurClamped.xy, topLeft, coord)
    - smoothstep(bottomRight, bottomRight + blurClamped.zw, coord);

  return colorMix.x * colorMix.y;

}


float rctCntr(in vec2 coord,
                in vec2 rctCoord,
                in vec2 size,
                in vec4 blur){

  vec2 coordTranslated = coord - rctCoord;
  vec4 blurClamped =  clamp(blur, vec4(0.0001), vec4(1.0));

  vec2 endBlurLeft = -(size/2.0);
  vec2 startBlurLeft = endBlurLeft - blurClamped.xz;
  vec2 startBlurRight = endBlurLeft + size;
  vec2 endBlurRight = startBlurRight + blurClamped.yw;

  vec2 colorMix =
    smoothstep(startBlurLeft, endBlurLeft, coordTranslated) -
    smoothstep(startBlurRight, endBlurRight, coordTranslated);

  return colorMix.x * colorMix.y;
}


void main() {

  /* lokalizacja fragmentu */
  vec2 coord = vTexCoord;
  coord.y = 1.0 - coord.y;

  float ratioY = uResolution.y/uResolution.x;
  float ratioX = uResolution.x/uResolution.y;

  //coord.y = coord.y * ratioY;// -vec2(0.375,0.125)
  coord.x = coord.x * ratioX;// -vec2(0.375,0.125)

  vec3 textColor = uBackgroundColor;
  vec4 tex = texture2D(tex0, coord);

  vec2 topLeft = vec2(0.0,0.0);
  vec2 bottomRight = vec2(0.2, 0.2);
  vec4 blur = vec4(0.05, 0.0,0.05, 0.0);
  vec2 offset = vec2(0.45, 0.4);
  offset.x = offset.x * ratioX;
  float rect = rct(coord - offset, topLeft, bottomRight, blur);

  vec3 clr = mix(uBackgroundColor, uForegroundColor, rect);
  // vec3 clr = mix(uBackgroundColor, uForegroundColor, 0.2);
  // clr = mix(clr, textColor, tex.a);

  gl_FragColor = vec4(clr,1.0);
  // gl_FragColor = vec4(clr,1.0);
}
