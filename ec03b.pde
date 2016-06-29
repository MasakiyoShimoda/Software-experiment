Target t;
Ball b;
PFont font;
int count;
float xPoint, yPoint, x, y, score = 10000;
float pressTime, releaseTime;
float pressY, pressX, releaseX, releaseY;

void setup(){
  smooth();
  frameRate(60);
  size(900, 600, P3D);
  t = new Target();
  b = new Ball();
  font = loadFont("AgencyFB-Reg-48.vlw");
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

void draw(){
  background(255);
  t.setPoint();
  t.moveTarget(count);
  b.update();
  b.show();
  count++;
  if(count == 60 * 20)
    count = 0;
  if(score > dist(x, y, xPoint, yPoint))
    score = dist(x, y, xPoint, yPoint);
  textFont(font,50);
  text(score, 100, 100);
}

class Target{
  int i;
  float xDeff = 0, yDeff = 0;
  float[] x = new float[21];
  float[] y = new float[21];
  
  Target(){   //Set 20 point on random
    for(int u = 0; u < 20; u++){
      x[u] = random(800) + 30;
      y[u] = random(500) + 30;

    }
    x[20] = x[0];
    y[20] = y[0];
  }
  
  void setPoint(){
    for(int j = 0; j < 21; j++){
      strokeWeight(5);
      //point(x[j], y[j]);    //Draw point for confirmation
    }
  }
  void moveTarget(int count){
    if(count == 0){
      i = -1;
      xPoint = x[0];
      yPoint = y[0];
    }
    if(count % 60 == 0){
      i++;
      xDeff = (x[i+1] - x[i]) / 60.0;
      yDeff = (y[i+1] - y[i]) / 60.0;

    }
    xPoint += xDeff;
    yPoint += yDeff;

    ellipse(xPoint, yPoint, 50, 50);
  }
}

class Ball{
  float t, startTime, x0, y0;
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
    if(x < 10){
      x = 10;
    }
    if(x > 890){
      x = 890;
    }
  }
}
