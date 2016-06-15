Ball b;

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
  b = new Ball(mouseX, mouseY);
}

class Ball{
  float x, y, g, t, startTime, y0;
  
  Ball(){
    g = 980;
    t = 0;
  }
  
  Ball(float _x, float _y){
    x = _x;
    y = 0;
    y0 = _y;
    g = 980;
    startTime = millis();
  }
  
  void show(){
    fill(0, 255, 0);
    ellipse(x, y, 50, 50);
  }
  
  void update(){
    t = (millis() - startTime) / 1000.0;
    y = g * t * t + y0;
  }
}

