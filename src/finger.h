#ifndef FINGER_H
#define FINGER_H

#include <vector>
#include <vecmath.h>

using namespace std;
class Finger{

public:
    Finger(int, int);
    Finger() {};
    void updatePosition(int x, int y);
    void updateDiameter(int d);
    void updateID(int i);

    Vector2f getPosition();
    int getDiameter();
private:
    Vector2f position;
    int diameter;
    int id;
};
#endif
