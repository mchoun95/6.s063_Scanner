#include <iostream>
#include <fstream>
#include <vector>
#include <vecmath.h>
#include "writeFile.h"

void writeFile::writePoints(vector<map<int, Finger>> &v_touches){
    ofstream file;
    map<int, Finger> touches_1 = v_touches[0];
    map<int, Finger> touches_2 = v_touches[1];

    file.open("testing.txt");
    map<int, Finger>::iterator it_1;
    for (it_1 = touches_1.begin(); it_1 != touches_1.end(); it_1++){
        int index = it_1->first;
        Finger finger = it_1->second;
        Vector2f position = finger.getPosition();
        // int diameter = finger.getDiameter();
        file <<'(' <<position[0] <<","<<position[1] << ")" << "\n";
    }

    map<int, Finger>::iterator it_2;
    for (it_2 = touches_2.begin(); it_2 != touches_2.end(); it_2++){
        int index = it_2->first;
        Finger finger = it_2->second;
        Vector2f position = finger.getPosition();
        // int diameter = finger.getDiameter();
        file <<'(' <<position[0] <<","<<position[1] << ")" << "\n";
    }
    file.close();
};

void writeFile::writeGnuplotPoints(vector<map<int, Finger>> &v_touches){
    ofstream file;
    map<int, Finger> touches_1 = v_touches[0];
    map<int, Finger> touches_2 = v_touches[1];

    file.open("gnu_display.txt");
    map<int, Finger>::iterator it_1;
    for (it_1 = touches_1.begin(); it_1 != touches_1.end(); it_1++){
        int index = it_1->first;
        Finger finger = it_1->second;
        Vector2f position = finger.getPosition();
        //rectify it
        position[1] = 2112 - position[1];
        // int diameter = finger.getDiameter();
        file <<position[0] <<" "<<position[1] << "\n";
    }

    map<int, Finger>::iterator it_2;
    for (it_2 = touches_2.begin(); it_2 != touches_2.end(); it_2++){
        int index = it_2->first;
        Finger finger = it_2->second;
        Vector2f position = finger.getPosition();
        //rectify it
        position[1] = 2112 - position[1];
        // int diameter = finger.getDiameter();
        file <<position[0] <<" "<<position[1] << "\n";
    }
    file.close();
};
