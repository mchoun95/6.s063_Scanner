#include <iostream>
#include <fstream>
#include <vector>
#include <vecmath.h>
#include "writeFile.h"

void writeFile::writePoints(map<int, Finger> &touches){
    ofstream file;
    map<int, Finger>::iterator it;

    file.open("testing.txt");
    for (it = touches.begin(); it != touches.end(); it++){
        int index = it->first;
        Finger finger = it->second;
        Vector2f position = finger.getPosition();
        // int diameter = finger.getDiameter();
        file <<'(' <<position[0] <<","<<position[1] << ")" << "\n";
    }
    file.close();


};
