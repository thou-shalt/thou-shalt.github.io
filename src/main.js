import p5 from './p5.min.js';
import convert from 'color-convert';
import ThouShalt_Module from '../assets/ThouShalt/js/ThouShalt.js';
import Test_Module from 'Test';
import OSC from 'osc-js';
import Tone from 'tone';


const options = {
    host: 'localhost',
    port: 8081
};

let synth = new Tone.FMSynth().toMaster();

let bc = convert.cmyk.rgb(18, 97, 4, 89),
    fc = convert.cmyk.rgb(76, 100, 5, 85);

// const fragPath = 'assets/text.frag';// 'assets/kwadrat_01.frag'
const fragPath = 'assets/kwadrat_01.frag';

new p5((s) => {
    synth.triggerAttackRelease("C2", 0.5, Tone.time);
    const normClr = x => 0.0 + (x / 256);

    const getAudio = (audioCtx, file) => {
        fetch(file)
            .then(response => response.arrayBuffer()
                  .then(arrBuf => {
                      console.log(arrBuf);
                      audioCtx.decodeAudioData(arrBuf, (audioBuf) => {
                          console.log('audioBuf.sampleRate '+audioBuf.sampleRate);
                          console.log(1.0/audioBuf.duration);
                          waveformDur = audioBuf.duration;
                          waveformBuf = audioBuf.getChannelData(0);
                          // console.log(audioBuf.getChannelData(0).length);
                          // audioBuf.getChannelData(0).slice(10000,11000).forEach(i => console.log(i));
                      });
                  }));
    };
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
        }, 1000*60);
    };

    const drawText = true;
    let font,
        kwadrat,
        strokeColor,
        heavyModule,
        loader,
        pg,
        waveformDur,
        waveformBuf;

    s.preload = () => {
        if (drawText) {
            font = s.loadFont('assets/OCRA.otf');
        }
        kwadrat = s.loadShader('assets/basic.vert', fragPath);
        makeOsc();

        let audioCtx = new (window.AudioContext || window.webkitAudioContext)();
        getAudio(audioCtx,'assets/wa_tanzbar_snare_01.ogg');

        Tone.Transport.start();

        let snare = new Tone.Buffer(
            'assets/wa_tanzbar_snare_01.ogg',
            ()=>{
                const seq = new Tone.Sequence((time, note) => {
                    // console.log([time, note]);
                    let s = new Tone.BufferSource(snare.get()).toMaster();
                    s.onended = () => s.dispose();
                    s.start();
                },[120,120] ,'8n');
                seq.start(0).stop(1);
            });
        /*
          fetch('assets/waveform.txt')
            .then(response => response.text())
            .then((data) => {
                waveformBuf = Float32Array.from(
                    data.split(/\r?\n/).map((v,i) => parseFloat(v)));
                waveformBuf = waveformBuf.slice(0,515);
                console.log(`waveformBuf.length = ${waveformBuf.length}`);
            });
         */
    };

    s.setup = () => {
        let cnv = s.createCanvas(window.innerWidth, window.innerHeight, s.WEBGL);
        cnv.canvas.style.display = 'block';
        s.shader(kwadrat);
        s.noStroke();
        s.frameRate(25);
        console.log(bc);
        console.log(fc);
        // fc = s.color(...fc);
        console.log(bc.push(255));
        kwadrat.setUniform("uBackgroundColor", bc.map(normClr));
        kwadrat.setUniform("uForegroundColor", fc.map(normClr));

        console.log(bc);
        pg = s.createGraphics(s.width,s.height);
        pg.background(0,0);
        pg.noStroke();
        pg.textFont(font);
        pg.textAlign(s.CENTER);
        pg.fill(0,255);
        pg.textSize(128);
        pg.text('thou shalt net',s.width / 2, s.height / 2);
        kwadrat.setUniform("tex0", pg);

        s.cursor(s.HAND);
    };

    s.draw = () => {
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
        console.log(loader);
        console.log(heavyModule.Test_AudioLib);
        loader.init({
            blockSize: 2048, // number of samples on each audio processing block
            printHook: (msg => {
                // console.log(msg);
            }),
            sendHook: (msg) => {
                console.log(""+msg);
            } // callback for output parameters [s {name} @hv_param], can be null
        });
        loader.audiolib.fillTableWithFloatBuffer('waveform', waveformBuf);
        loader.audiolib.setFloatParameter("waveformLength", waveformBuf.length);
        loader.audiolib.setFloatParameter("waveformDur", waveformDur*1);
        loader.start();
        s.noCursor();
    };
    s.mouseClicked = () => {
        if (loader) {
            loader.audiolib.fillTableWithFloatBuffer('waveform', waveformBuf);
            if (!loader.isPlaying) {
                loader.start();
                s.noCursor();
            } else {
                loader.stop();
                s.cursor(s.HAND);
            }
            // console.log(loader);
        } else {
            // heavyModule = ThouShalt_Module();
            heavyModule = Test_Module();
            heavyModule['onRuntimeInitialized'] = onModuleLoaded;

        }
    };
    s.mouseMoved = () => {
        if(loader) {
            let freq = s.map(s.mouseX,0,s.width, 110,220);
            loader.audiolib.setFloatParameter("phasorFreq", freq);
        }
    };
}, 'thou-shalt');
