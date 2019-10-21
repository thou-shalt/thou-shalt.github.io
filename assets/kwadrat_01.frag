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

/*
  zwraca 0 jesli coord jest poza granicami prostokata
 */
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

  vec3 backgroundColor = uBackgroundColor;
  vec3 foregroundColor = uForegroundColor;
  vec3 textColor = uBackgroundColor;
  vec4 tex = texture2D(tex0, coord);

  vec2 rctCoord = vec2(0.5, 0.5);
  float rctMx =
    rctCntr(coord, rctCoord, vec2(0.5,0.75), vec4(vec2(0.1,0.4),vec2(0.05)));

  vec3 clr = mix(backgroundColor, foregroundColor, rctMx);

  rctMx =
    rctCntr(coord, rctCoord, vec2(0.75,0.5), vec4(vec2(0.1),vec2(0.1)));

  clr = mix(clr, foregroundColor, rctMx *0.15);

  clr = mix(clr, textColor, tex.a);

  gl_FragColor = vec4(clr,1.0);
}
