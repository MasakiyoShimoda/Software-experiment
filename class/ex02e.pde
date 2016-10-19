Ball b;
float pressTime, releaseTime;
float pressY, releaseY;

void setup(){
  size(500, 600, P3D);
    b = new Ball();
}

void draw(){
  background(255);
  b.update();
  b.show();
}

void mousePressed(){
  pressTime = millis()/1000.0;
  pressY = mouseY;
}
void mouseReleased(){
  releaseTime = millis()/1000.0;
  releaseY = mouseY;
  b = new Ball(mouseX, mouseY,(pressY - releaseY)/(pressTime - releaseTime));
}

class Ball{
  float x, y, t, startTime, y0, v0;
  float g = 980;
  
  Ball(){
    x = width/2;
    y = 0;
    t = 0;
  }
  
  Ball(float _x, float _y,float _v0){
    pressTime = millis();
    pressY = _y;
    x = _x;
    y = _y;
    v0 = _v0;
    y0 = _y;
    startTime = millis();
  }
  
  void show(){
    fill(0, 255, 0);
    ellipse(x, y, 50, 50);
  }
  
  void update(){
    t = (millis() - startTime) / 1000.0;
    y = (v0 * t) + (g * t * t)/2 + y0;
  }
}
