import p5 from './p5.min.js';

new p5((sk) => {
  let font; 
  sk.preload = () => {
    font = sk.loadFont('assets/OCR-ABT.otf');
  };
  sk.setup = () => {
    let cnv = sk.createCanvas(window.innerWidth, window.innerHeight);
    cnv.canvas.style.display = 'block';
    // console.log(cnv.canvas.style);
  };

  sk.draw = () => {
    sk.background(200, 233, 205);
    // sk.background(2, 23, 25);
    sk.textSize(sk.height/4);
    sk.textFont(font);
    sk.fill(12, 43, 45);
    sk.textAlign(sk.CENTER);
    sk.text('THOU SHALT', sk.width/2,sk.height/2);
   };

  sk.windowResized = () => {
    sk.resizeCanvas(window.innerWidth, window.innerHeight);
  };
}, 'thou-shalt');