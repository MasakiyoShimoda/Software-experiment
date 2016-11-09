import android.view.MotionEvent;
import ketai.ui.*;

KetaiGesture gesture;
Mogra mogra;

void setup(){
  size(displayWidth, displayHeight);
  smooth();
  noStroke();
  background(255);
  mogra = new Mogra();
  mogra.setMogra();
  gesture = new KetaiGesture(this);
}

public boolean surfaceTouchEvent(MotionEvent e){
  super.surfaceTouchEvent(e);
  return gesture.surfaceTouchEvent(e);
}

void draw(){
  
}
  
class Mogra{
  float speed, xMogra, yMogra, size;
  void setMogra(){
    xMogra = random(displayWidth);
    yMogra = random(displayHeight);
  }
  
  void getMogra(float x, float y){
    fill(0);
    ellipse(xMogra, yMogra, 10,10);
    textSize(50);
    size = dist(x, y, xMogra, yMogra);
    if(size < 50){
      text("あたり", xMogra, yMogra);
      setMogra();
    }
  }
}

void onTap(float x, float y){
  background(255);
  mogra.getMogra(x ,y);
}
