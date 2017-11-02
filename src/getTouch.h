#ifndef GETTOUCH_H
#define GETTOUCH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <vector>
#include <map>
#include <vecmath.h>
#include "finger.h"

using namespace std;
class inputMonitor{

public:
    int init(void);
    int update(void);
    void processUpdate(vector<int> state_update);
private:
    int current_slot;
    input_event ev;
    int fd;
    map<int, Finger> fingers;
};

#endif
