Ball b;
float pressTime, releaseTime;
float pressY, pressX, releaseX, releaseY;

void setup(){
  size(500, 900, P3D);
    b = new Ball();
}

void draw(){
  background(255);
  b.update();
  b.show();
}

void mousePressed(){
  pressTime = millis()/1000.0;
  pressX = mouseX;
  pressY = mouseY;
}
void mouseReleased(){
  releaseTime = millis()/1000.0;
  releaseX = mouseX;
  releaseY = mouseY;
  b = new Ball(mouseX, mouseY,(pressX - releaseX)/(pressTime - releaseTime), (pressY - releaseY)/(pressTime - releaseTime));
}

class Ball{
  float x, y, t, startTime, x0, y0;
  float vx, vy;
  float g = 980;
  
  Ball(){
    x = width/2;
    y = 0;
    t = 0;
  }
  
  Ball(float _x, float _y,float _vx,float _vy){
    pressTime = millis();
    pressY = _y;
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    x0 = _x;
    y0 = _y;
    startTime = millis();
  }
  
  void show(){
    fill(0, 255, 0);
    ellipse(x, y, 50, 50);
  }
  
  void update(){
    t = (millis() - startTime) / 1000.0;
    y = (vy * t) + (g * t * t)/2 + y0;
    x = (vx * t) + x0;
  }
}

