import ketai.sensors.*;
import ketai.ui.*;
import android.view.MotionEvent;

KetaiGesture gesture;
Paint paint;

double x, y, x2, y2, longitude, latitude, altitude;
  
KetaiLocation location;                  

//--------------------------------------------------------------------------
void setup(){
  size(displayWidth, displayHeight);
  smooth();
  strokeWeight(2);
  background(255);
  paint = new Paint();
  gesture = new KetaiGesture(this);
  location = new KetaiLocation(this);
  orientation(LANDSCAPE); 
  textSize(32);
  textAlign(LEFT, TOP);
  x = x2 = displayWidth/2;
  y = y2 = displayHeight/2;
  paint.setup();
}

public boolean surfaceTouchEvent(MotionEvent e){
  super.surfaceTouchEvent(e);
  return gesture.surfaceTouchEvent(e);
}

//--------------------------------------------------------------------------
void draw(){
  fill(50, 50, 255);
  paint.setPoint();
  if (location.getProvider() == "none"){
    fill(255, 0, 0);
    text("location data is unavailable", 50, 50);
    return;
  }
  fill(100);
  rect(0, 0, 400, 300);
  fill(0);
  text("経度(longitude) :\n " + longitude +
       "\n緯度(latitude):\n " + latitude +
       "\n高度(altitude):\n " + altitude +
       "\n取得方法: " + location.getProvider(), 0, 0);
}

//--------------------------------------------------------------------------

void onLocationEvent (double _latitude, double _longitude, double _altitude){
  longitude = _longitude;
  latitude  = _latitude;
  altitude  = _altitude;
}

class Paint{
  double  longitude0, latitude0;
  
  void setup(){
    longitude0 = longitude;
    latitude0 = latitude;
  }
  
  void setPoint(){
    strokeWeight(1);
    line((float)x2 , (float)y2, (float)x, (float)y);
    fill(26,196,255);
    ellipse((float)x, (float)y, 30, 30);
    if(longitude0 != longitude){
      x2 = x;
      x += (longitude - longitude0) * 300000;
      longitude0 = longitude;
    }
    if(latitude0 != latitude){
      y2 = y;
      y += (latitude - latitude0) * 300000;
      latitude0 = latitude;
    }
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
}
void onTap(){
  background(255);
  x = displayWidth/2;
  y = displayHeight/2;
}