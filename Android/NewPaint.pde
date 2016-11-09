import android.view.MotionEvent;
import ketai.ui.*;

KetaiGesture gesture;
Paint paint;

void setup(){
  size(displayWidth, displayHeight);
  textSize(50);
  smooth();
  strokeWeight(2);
  background(255);
  paint = new Paint();
  gesture = new KetaiGesture(this);
}

public boolean surfaceTouchEvent(MotionEvent e){
  super.surfaceTouchEvent(e);
  return gesture.surfaceTouchEvent(e);
}

void draw(){
  paint.paintLine();
  paint.setMap();
}
  
class Paint{
  float x, y, size;
  
  void setMap(){
    fill(0);
    text("PENCIL", width/4, height-100);
    text("ERASER", width/4*3, height-100);
    fill(255);
  }
  
  void paintLine(){
    //fill(0);
    line(mouseX, mouseY, pmouseX, pmouseY);
  }
}

void onDoubleTap(float x, float y){
  background(255);
}

void onTap(float x, float y){
  if(y > (displayHeight - 200)){
    if(x > (displayWidth/2)){
      stroke(255);
      strokeWeight(100);
    }else if(x < (displayWidth/2)){
      strokeWeight(2);
      stroke(0);
    }
  }
}
