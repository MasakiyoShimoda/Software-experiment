Target t;
int count;
void setup(){
  frameRate(30);
  size(900, 600, P3D);
  t = new Target();
  t.set();
  b = new Ball();
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
}

class Target{
  int i;
  float xDeff = 0, yDeff = 0, xPoint, yPoint;
  float[] x = new float[21];
  float[] y = new float[21];
  
  void set(){   //Set 20 point on random
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
      println(i, count, x[i], y[i], xDeff, yDeff);
    }
    xPoint += xDeff;
    yPoint += yDeff;

    ellipse(xPoint, yPoint, 20, 20);
  }
}
