import p5 from './p5.min.js';
import convert from 'color-convert';
import anime from 'animejs/lib/anime.es.js';
import OSC from 'osc-js';


const options = {
    host: 'localhost',
    port: 8081
};


let bc = convert.cmyk.rgb(0, 47, 36, 90),
    fc = convert.cmyk.rgb(3, 0, 0, 0);

const fragPath = 'assets/thou_shalt_scene_01.frag';

new p5((s) => {
    const normClr = x => 0.0 + (x / 256);
    var resetTimer = s.millis();

    const makeOsc = (frag) => {
        let plugin = new OSC.WebsocketClientPlugin(options);
        let osc = new OSC({
            plugin: plugin
        });

        osc.on('/thou-shalt/scene_01', (msg) => {
            // console.log(msg);
            anime({
                targets: uTime,
                keyframes: [
                    {value: 1.0, duration: 10},
                    {value: 0.0, delay: 50, duration: 100},
                ],
                direction: 'normal',
                easing: 'easeInQuad',
                // duration: 100,
                // loop: true,
                update: () => {
                    kwadrat.setUniform("uTime", uTime.value);
                }
            });
        });

        setInterval(() => {
            status = osc.status();
            if (status == -1 || status == 3) {
                osc.open();
            }
        }, 1000);
    };

    let kwadrat;

    let uTime = {
        value: 0.0,
    };

    s.preload = () => {
        kwadrat = s.loadShader('assets/basic.vert', fragPath);
        makeOsc(kwadrat);
    };

    s.setup = () => {
        let cnv = s.createCanvas(window.innerWidth, window.innerHeight, s.WEBGL);
        cnv.canvas.style.display = 'block';
        s.shader(kwadrat);
        s.noStroke();
        s.frameRate(25);
        console.log(bc);
        console.log(fc);
        console.log(bc.push(255));
        kwadrat.setUniform("uBackgroundColor", bc.map(normClr));
        kwadrat.setUniform("uForegroundColor", fc.map(normClr));

        console.log(bc);

        s.cursor(s.HAND);
        kwadrat.setUniform("uResolution", [s.width, s.height]);

        
    };

    s.draw = () => {
        // let z = ((135.0 / 60) * ((s.millis() - resetTimer) / 1000.0)) % 1.0;
        // kwadrat.setUniform("uTime", z);
        s.quad(-1, -1, 0, 1, -1, 0, 1, 1, 0, -1, 1, 0);

    };

    s.windowResized = () => {
        s.resizeCanvas(window.innerWidth, window.innerHeight);
        kwadrat.setUniform("uResolution", [s.width, s.height]);
    };
}, 'thou-shalt');
