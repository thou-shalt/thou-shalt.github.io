import p5 from './p5.min.js';
import convert from 'color-convert';
import ThouShalt_Module from '../assets/ThouShalt/js/ThouShalt.js';
import OSC from 'osc-js';

const options = {
    host: 'localhost',
    port: 8081
};

new p5((s) => {

    const makeOsc = () => {
        let plugin = new OSC.WebsocketClientPlugin(options);
        let osc = new OSC({ plugin: plugin });

        osc.on('/dog/ferret', (msg) => {
            console.log(msg);
        });

        setInterval(() => {
            status = osc.status();
            if (status == -1 || status == 3) {
                osc.open();
            }
        }, 1000);
    };

    // const fragPath = 'assets/kwadrat_01.frag';
    const fragPath = 'assets/text.frag';
    const drawText = true;
    let font,
        kwadrat,
        strokeColor,
        heavyModule,
        loader,
        bc,
        fc,
        pg;
    s.preload = () => {
        if (drawText) {
            font = s.loadFont('assets/OCRA.otf');
        }
        kwadrat = s.loadShader('assets/basic.vert', fragPath);
        makeOsc();
        fetch('assets/waveform.txt')
            .then(response => response.text())
            .then((data) => {
                console.log(data);
            });
    };
    s.setup = () => {
        let cnv = s.createCanvas(window.innerWidth, window.innerHeight, s.WEBGL);
        cnv.canvas.style.display = 'block';
        s.shader(kwadrat);
        s.noStroke();
        s.frameRate(25);
        bc = convert.cmyk.rgb(40.0, 100.0, 42.0, 84.0);
        fc = convert.cmyk.rgb(50.0, 50.0, 42.0, 54.0);
        // kwadrat.setUniform("uBackgroundColor", bc.map(x => x / 256));
        console.log(bc);
        pg = s.createGraphics(s.width,s.height);
        pg.background(...bc);
        pg.noStroke();
        pg.textFont(font);
        pg.textAlign(s.CENTER);
        pg.fill(...fc);
        pg.textSize(48);
        pg.text('thou shalt net',s.width / 2, s.height / 2);
        kwadrat.setUniform("tex0", pg);
    };

    s.draw = () => {
        s.camera(0, 0, 20 + s.sin(s.frameCount * 0.01) * 10, 0, 0, 0, 0, 1, 0);
        // console.log(s.frameCount );
        let z = 1.0;
        // kwadrat.setUniform("tex0", pg);
        // kwadrat.setUniform("uResolution", [s.width, s.height]);
        // kwadrat.setUniform("uMouse", [s.mouseX, s.mouseY]);
        // kwadrat.setUniform("uTime", s.millis() % (s.width / 8.0));
        s.quad(-1, -1, z, 1, -1, z, 1, 1, z, -1, 1, z);

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
        loader.start();
    };
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
    };
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
