#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <iostream>
#include "getTouch.h"
#include "finger.h"


#define EVENT_DEVICE    "/dev/input/event9"
#define EVENT_TYPE_ABS      EV_ABS
#define EVENT_CODE_X    ABS_X
#define EVENT_CODE_Y    ABS_Y
#define EVENT_CODE_SLOT    ABS_MT_SLOT
#define EVENT_CODE_ID    ABS_MT_TRACKING_ID
#define EVENT_CODE_AREA    ABS_MT_TOUCH_MAJOR
#define EVENT_TYPE_REPORT   SYN_REPORT

using namespace std;

void inputMonitor::processUpdate(vector<int> state_update){
    //check if finger ID is -1, which means finger is lifted up
    if (state_update[1] == -1){
        fingers.erase(current_slot);
    }
    else{
        current_slot = state_update[0];
        if (state_update[1] > 0){
            fingers[current_slot].updateID(state_update[1]);
        }
        fingers[current_slot].updatePosition(state_update[2], state_update[3]);
        fingers[current_slot].updateDiameter(state_update[4]);
    }
        //if it is, remove the finger at that slot
}
int inputMonitor::init(void)
{
    //initialize the fingers//
    char name[256] = "Unknown";

    if ((getuid ()) != 0) {
        fprintf(stderr, "You are not root! This may not work...\n");
        return EXIT_SUCCESS;
    }

    /* Open Device */
    fd = open(EVENT_DEVICE, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "%s is not a vaild device\n", EVENT_DEVICE);
        return EXIT_FAILURE;
    }

    /* Print Device Name */
    ioctl(fd, EVIOCGNAME(sizeof(name)), name);
    printf("Reading from:\n");
    printf("device file = %s\n", EVENT_DEVICE);
    printf("device name = %s\n", name);
}

int inputMonitor::update(void){
    // <slot number, tracking ID, x position, y position>
    vector<int> state_update(5);
    fill(state_update.begin(), state_update.end(), 0);
    //while loop.//
    for (;;) {
        //setup stuff
        const size_t ev_size = sizeof(struct input_event);
        ssize_t size;
        size = read(fd, &ev, ev_size); //returns the number of bytes read
        if (size < ev_size) {
            fprintf(stderr, "Error size when reading\n");
            goto err;
        }

        // cout<<state_update[0]<<" "<<state_update[1]<<" "
        //     <<state_update[2]<<" "<<state_update[3]<<endl;

        //check if end of a report
        if (ev.type == EVENT_TYPE_REPORT){
            //TODO update fingers and states with another function
            processUpdate(state_update);
            //clear the tracking ID for the next update
            state_update[1] = 0;
            cout <<"current slot"<<current_slot<<endl;
            cout <<"fingersize"<<fingers.size()<<endl;
        }
        else{
            if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_SLOT){
                state_update[0] = ev.value;
                cout << "slot" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_ID){
                state_update[1] = ev.value;
                cout << "ID" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_X) {
                state_update[2] = ev.value;
                cout << "x" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_Y) {
                state_update[3] = ev.value;
                cout << "y" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_AREA){
                state_update[4] == ev.value;
                cout << "radius" << ev.value << endl;
            }
        }
    }
    return EXIT_SUCCESS;

err:
    close(fd);
    return EXIT_FAILURE;
}
