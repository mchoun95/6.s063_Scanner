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
    map<int, Finger> update(void);
    void processUpdate(vector<int> state_update);
    bool done_flag;
    map<int, Finger> fingers;
    map<int, Finger> r_fingers; //released fingers but still need to keep track

private:
    int current_slot;
    input_event ev;
    int max_fingers_seen;
    int min_needed;
    int fd;
    bool slot_flag;
    bool x_flag;
    bool y_flag;
    int release_counter;
    int finger_counter;
};

#endif
