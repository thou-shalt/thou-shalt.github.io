import p5 from './p5.min.js';
import convert from 'color-convert';
import ThouShalt_Module from '../assets/ThouShalt/js/ThouShalt.js'
import osc from 'osc';

let ws;
let port;
function makeOsc() {
  ws = new WebSocket('ws://52.18.50.138:8081');
  
 
  // ws.onclose = function(e) {
  //   setTimeout( function () {
  //     ws = null;
  //   console.log('reconnencting');   
  //     makeOsc();
  //   }, 100)
  // };
  ws.onerror = function(e) {
  setTimeout( function () {
    console.log('reconnencting');   
      makeOsc();
    }, 100) 
  };
  port = new osc.WebSocketPort({
    socket: ws
  });
  port.on("message", (oscMessage) => {
    console.log("message", oscMessage);
  });
}
makeOsc();

// import OSC from 'osc-js';

// const options = {
//   host: 'localhost',
//   port: 8081
// };
//   let plugin;;
// let osc;

// const makeOsc = () => {
//   plugin = new OSC.WebsocketClientPlugin(options);
  
//   osc = new OSC({ plugin: plugin });
//   osc.open();

//   osc.on('*', (msg) => {
//     console.log(msg)
//   });
  
// }
// makeOsc();
// plugin.notify = (msg) => {
//   if (msg === 'close') {
//     setTimeout(() => {
//       console.log("timeout")
//       osc.open();
//       osc.on('*', (msg) => {
//         // t = msg;
//         console.log(msg)
//       });

//     }, 5000);
//     console.error(`ws is ${msg}d -> reconnecting in 5 secs...`);
//   }
// };
new p5((s) => {
  const fragPath = 'assets/kwadrat_01.frag';
  const drawText = false;
  let font, kwadrat, strokeColor, heavyModule, loader, bc;
  let t = 'test';
  s.preload = () => {
    if (drawText) {
      font = s.loadFont('assets/OCR-ABT.otf');
    }
    kwadrat = s.loadShader('assets/basic.vert', fragPath);
  };
  s.setup = () => {
    let cnv = s.createCanvas(window.innerWidth, window.innerHeight, s.WEBGL);
    cnv.canvas.style.display = 'block';
    strokeColor = s.color(12, 3, 5);
    s.stroke(strokeColor);
    s.shader(kwadrat);
    bc = convert.cmyk.rgb(100.0, 40.0, 42.0, 85.0).map(x => x / 256);
    kwadrat.setUniform("uBackgroundColor", bc);
    console.log(bc);
  };

  s.draw = () => {
    // console.log(ws);
    let z = 1.0;
    kwadrat.setUniform("uResolution", [s.width, s.height]);
    kwadrat.setUniform("uMouse", [s.mouseX, s.mouseY]);
    kwadrat.setUniform("uTime", s.millis() % (s.width / 8.0));
    s.quad(-1, -1, z, 1, -1, z, 1, 1, z, -1, 1, z);

    if (drawText) {
      s.translate(-s.width / 2, -s.height / 2, 0);
      s.textSize(s.height / 4);
      s.textFont(font);
      s.fill(strokeColor);
      s.textAlign(s.CENTER);
      s.text('THOU SHALT', s.width / 2, s.height / 2);
    }
  };

  s.windowResized = () => {
    s.resizeCanvas(window.innerWidth, window.innerHeight);
  };
  const onModuleLoaded = () => {
    loader = new heavyModule.AudioLibLoader();

    loader.init({
      blockSize: 2048, // number of samples on each audio processing block
      // printHook: onPrint, // callback for [print] messages, can be null
      // sendHook: onFloatMessage // callback for output parameters [s {name} @hv_param], can be null
    });
  }
  s.mouseClicked = () => {
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

/*
import osc1 from 'osc'  ;
const port = new osc1.WebSocketPort({
  socket: new WebSocket('ws://localhost:8081')
});
port.on("message", (oscMessage) => {
    console.log("message", oscMessage);
});
*/