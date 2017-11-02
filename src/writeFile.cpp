#include <iostream>
#include <fstream>
#include <vector>
#include <vecmath.h>
#include "writeFile.h"

void writeFile::writePoints(void){
    ofstream file;
    file.open("testing.txt");
    file << "random shit \n";
    file << "Hi Mark";
    file.close();
};
