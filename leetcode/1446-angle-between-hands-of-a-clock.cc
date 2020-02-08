class Solution {
public:
    double angleClock(int hour, int minutes) {
      if(hour==12)
        hour==0;
      double hourBase=30*hour;
      double minutesIncremental=30*((double)minutes/60);
      double h=hourBase+minutesIncremental;
      double m=6*minutes;
      double angel=abs(h-m);
      if(angel>180){
        angel=360-angel;
      }
      return angel;
    }
};