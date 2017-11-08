#ifndef WRITEFILE_H
#define WRITEFILE_H

#include "finger.h"
#include<map>


using namespace std;
class writeFile{
public:
    void writePoints(vector<map<int, Finger>> &v_touches);
    void writeGnuplotPoints(vector<map<int, Finger>> &v_touches);
private:
};

#endif
