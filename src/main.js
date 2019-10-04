import p5 from './p5.min.js';

let thouShalt = new p5(( sketch ) => {

    sketch.setup = () => {
      sketch.createCanvas(window.outerWidth, window.outerHeight);
    };
  
    sketch.draw = () => {
      sketch.background(2,3,5);
    };
  }, 'thou-shalt');