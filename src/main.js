import p5 from './p5.min.js';
import ThouShalt_Module from '../assets/ThouShalt/js/ThouShalt.js'

new p5((sk) => {
  const fragPath = 'assets/kwadrat_01.frag';
  const drawText = false;
  let font, kwadrat, strokeColor, heavyModule, loader;
  sk.preload = () => {
    if (drawText) {
      font = sk.loadFont('assets/OCR-ABT.otf');
    }
    kwadrat = sk.loadShader('assets/basic.vert', fragPath);

  };
  sk.setup = () => {
    let cnv = sk.createCanvas(window.innerWidth, window.innerHeight, sk.WEBGL);
    cnv.canvas.style.display = 'block';
    strokeColor = sk.color(12, 3, 5);
    sk.stroke(strokeColor);
    sk.shader(kwadrat);
  };

  sk.draw = () => {
    let z = 1.0;
    kwadrat.setUniform("uResolution", [sk.width, sk.height]);
    kwadrat.setUniform("uMouse", [sk.mouseX, sk.mouseY ]);
    kwadrat.setUniform("uTime", sk.millis()%(sk.width/8.0));
    sk.quad(-1, -1, z, 1, -1, z, 1, 1, z, -1,1, z);

    if (drawText) {
      sk.translate(-sk.width / 2, -sk.height / 2, 0);
      sk.textSize(sk.height / 4);
      sk.textFont(font);
      sk.fill(strokeColor);
      sk.textAlign(sk.CENTER);
      sk.text('THOU SHALT', sk.width / 2, sk.height / 2);
    }
  };
  
  sk.windowResized = () => {
    sk.resizeCanvas(window.innerWidth, window.innerHeight);
  };
  const onModuleLoaded = () => {
    loader = new heavyModule.AudioLibLoader();

    loader.init({
      blockSize: 2048, // number of samples on each audio processing block
      // printHook: onPrint, // callback for [print] messages, can be null
      // sendHook: onFloatMessage // callback for output parameters [s {name} @hv_param], can be null
    });
  }
  sk.mouseClicked = () => {
    if (loader) {
      if (!loader.isPlaying) {
        loader.start();
      } else {
        loader.stop();
      }
      // console.log(loader);
    } else {
      heavyModule = ThouShalt_Module();
      heavyModule['onRuntimeInitialized'] = onModuleLoaded;
    }
  }
  
  
}, 'thou-shalt');