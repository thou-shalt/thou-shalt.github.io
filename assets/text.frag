precision mediump float;

varying vec2 vTexCoord;

uniform sampler2D tex0;
uniform vec3 uBackgroundColor;

void main() {

  vec2 coord = vTexCoord;
  coord.y = 1.0 - coord.y;
  vec4 tex = texture2D(tex0, coord);
  // vec4 c = step(tex.x,0.0) * vec4(uBackgroundColor,1.0);
  // c = step(0.0, tex.x) * tex + c;// + ((1.0-step(0.01, tex.x)) * vec4(uBackgroundColor,1.0));
  // gl_FragColor = c;

  gl_FragColor = tex;
}
