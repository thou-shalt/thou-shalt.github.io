#ifdef GL_ES
precision mediump float;
precision highp int;
#endif

// #define PROCESSING_COLOR_SHADER
// #define PI 3.14159265359

varying vec2 vTexCoord;

uniform vec2 uResolution;
uniform vec2 uMouse;
uniform float uTime;
uniform float uStartTime;
uniform vec3 uBackgroundColor;
uniform vec3 uForegroundColor;
uniform float uEasing;
uniform float uTarget;
uniform sampler2D tex0;


void main() {

  /* lokalizacja fragmentu */
  vec2 coord = vTexCoord;
  coord.y = 1.0 - coord.y;

  float ratioY = uResolution.y/uResolution.x;
  float ratioX = uResolution.x/uResolution.y;
  //coord.y = coord.y * ratioY;// 
  coord.x = coord.x * ratioX; // 

  float time = uTime - (uTarget * uTime); // 0 jesli uTarget = 1


  vec3 clr = mix(uBackgroundColor, uForegroundColor, uTime);

  gl_FragColor = vec4(clr,1.0);
}
