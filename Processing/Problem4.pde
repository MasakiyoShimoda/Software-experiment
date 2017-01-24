import processing.video.*;
Capture camera;
PImage inImg, outImg, outImg2, outImg3;

void setup() {
  size(640, 480);
  camera = new Capture(this, width/2, height/2, 12);
  camera.start();
}

public void stop() {
  camera.stop();
  super.stop();
}

void draw() {
  camera.loadPixels();
  outImg = createImage(width/2, height/2, RGB);
  inImg = createImage(width/2, height/2, RGB);
  for(int y = 0 ; y < height/2 ; y++) {
    for(int x = 0  ; x < width/2 ; x++) {
      int p1 = y * width/2 + x;
      int p2 = y * width/2 + (width/2 - 1 - x);
      inImg.pixels[p1] = camera.pixels[p1];
      outImg.pixels[p1] = camera.pixels[p2];
    }
  }
  
  outImg2 = createImage(width/2, height/2, RGB);
  for (int y = 0; y < height/2; y++) {
    for (int x = 0; x < width/2; x++) {
      int p1 = y * width/2 + x;
      int p2 = (height/2 - y - 1) * width/2 + x;
      outImg2.pixels[p1] = camera.pixels[p2];
    }
  }
  
  image(inImg, 0, 0);
  image(outImg, width/2, 0);
  image(outImg2, 0, height/2);
  
}

void captureEvent(Capture camera) {
  camera.read();
}
