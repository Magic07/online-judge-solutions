class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
      // Center of rectangle.
      double rx=(x1+x2)/2.0;
      double ry=(y1+y2)/2.0;
      // Distance of circle and rectangle.
      double dx=abs(x_center-rx);
      double dy=abs(y_center-ry);

      double rxl=(x2-x1)/2.0;
      double ryl=(y2-y1)/2.0;

      double d=sqrt(pow(max(0.0,dx-rxl),2)+pow(max(0.0,dy-ryl),2));
      if(d<=radius)
        return true;
      return false;
    }
};