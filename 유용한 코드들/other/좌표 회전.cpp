#include <stdio.h>
#include <math.h>

typedef struct _Point{
    double x;
    double y;
} Point;

Point RotateCoordinate(Point p, double theta, Point base){
    Point ret;

    ret.x = (p.x - base.x)*cos(theta*M_PI/180) - (p.y - base.y)*sin(theta*M_PI/180) + base.x;

    ret.y = (p.x - base.x)*sin(theta*M_PI/180) + (p.y - base.y)*cos(theta*M_PI/180) + base.y;

    return ret;
}

int main(void) {
    
    Point base, p;
    base.x = 1; base.y = 0;
    p.x = 0;    p.y = 2;
    p = RotateCoordinate(p, 9, base);

    printf("(%lf, %lf)\n", p.x, p.y);

    return 0;
}