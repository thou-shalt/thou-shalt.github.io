precision mediump float;

varying vec2 vTexCoord;

uniform sampler2D tex0;
uniform vec3 uBackgroundColor;
uniform vec3 uForegroundColor;

void main() {

  vec2 coord = vTexCoord;
  coord.y = 1.0 - coord.y;
  vec4 tex = texture2D(tex0, coord);
  vec3 fc = vec3(0.3,0.2,1.0);
  vec3 bc = vec3(1., 0.5 ,0.7);
  gl_FragColor = vec4(mix(uBackgroundColor, uForegroundColor, tex.a), 1.0);

  // gl_FragColor = tex;
}
