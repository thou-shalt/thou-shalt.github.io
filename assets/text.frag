precision mediump float;

varying vec2 vTexCoord;

uniform sampler2D tex0;
uniform vec3 uBackgroundColor;

void main() {

  vec2 coord = vTexCoord;
  coord.y = 1.0 - coord.y;
  vec4 tex = texture2D(tex0, coord);
  vec3 fc = vec3(0.3,0.2,1.0);
  vec3 bc = vec3(1., 0.5 ,0.7);
  // vec4 c = step(tex.x,0.0) * vec4(uBackgroundColor,1.0);
  // c = step(0.0, tex.x) * tex + c;// + ((1.0-step(0.01, tex.x)) * vec4(uBackgroundColor,1.0));
  gl_FragColor = vec4(mix(fc, bc, tex.a), 1.0);

  // gl_FragColor = tex;
}
