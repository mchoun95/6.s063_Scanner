#ifndef PROCESSTOUCH_H
#define PROCESSTOUCH_H

#include <vector>
#include "Vector2f.h"

using namespace std;

class processTouch {
public:
    void processEvent(vector<int>);
private:
    vector<Vector2f> fingers(100);
    int current_slot;
}
#endif
