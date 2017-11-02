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
#define EVENT_CODE_MT_X   ABS_MT_POSITION_X
#define EVENT_CODE_Y    ABS_Y
#define EVENT_CODE_MT_Y    ABS_MT_POSITION_Y
#define EVENT_CODE_SLOT    ABS_MT_SLOT
#define EVENT_CODE_ID    ABS_MT_TRACKING_ID
#define EVENT_CODE_AREA    ABS_MT_TOUCH_MAJOR
#define EVENT_TYPE_REPORT   SYN_REPORT

using namespace std;

void inputMonitor::processUpdate(vector<int> state_update){
    //check if finger ID is -1, which means finger is lifted up
    //initialize_release counter;

    if (slot_flag){
        current_slot = state_update[0];
        // cout<< "slot flag" << current_slot<<endl;
    }

    if (current_slot == 0){
        // cout <<fingers[0].getPosition()[0]<< " "<<fingers[0].getPosition()[1]<<endl;
    }

    if (state_update[1] > 0){
        fingers[current_slot].updateID(state_update[1]);
        finger_counter += 1;
        if (finger_counter > max_fingers_seen){
            max_fingers_seen = finger_counter;
            cout<< "maxfingers" <<max_fingers_seen<<endl;
        }
        if (x_flag || y_flag){
            // cout << "gothere" <<endl;
            fingers[current_slot].updatePosition(state_update[2], state_update[3]);
            // cout <<fingers[current_slot].getPosition()[0]<< " "<<fingers[current_slot].getPosition()[1]<<endl;

        }
    }

    // fingers[current_slot].updateDiameter(state_update[4]);

    else if (state_update[1] == -1){

        //updates_current slot so know which finger is being erased//

        //finger being erased
        Finger released = fingers[current_slot];
        r_fingers[release_counter] = released;
        Vector2f position = released.getPosition();

        cout <<"current slot" << current_slot <<endl;
        cout << position[0] << " " << position[1] << endl;

        //set counters and get clean out slot in fingers
        release_counter += 1;
        finger_counter -=1;
        cout <<"finger counter"<<finger_counter <<endl;
        fingers.erase(current_slot);
        cout<< "maxfingers" <<max_fingers_seen<<endl;

        //nothing left
        if (finger_counter == 0){
            cout << "done" << endl;
            done_flag = true;
        }
    }
    else{
        if (x_flag || y_flag){
            // cout << "gothere" <<endl;
            fingers[current_slot].updatePosition(state_update[2], state_update[3]);
            // cout <<fingers[current_slot].getPosition()[0]<< " "<<fingers[current_slot].getPosition()[1]<<endl;

        }
    }
}
int inputMonitor::init(void)
{
    //initialize_variables;
    release_counter = 0;
    finger_counter = 0;
    done_flag = false;
    min_needed = 5;
    max_fingers_seen=0;

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

map<int, Finger> inputMonitor::update(void){

    // <slot number, tracking ID, x position, y position>
    vector<int> state_update(5);
    fill(state_update.begin(), state_update.end(), 0);
    //while loop.//
    for (;;) {
        //break out of loop if done flag is set
        if (done_flag){
            cout << "done flag set" <<endl;
            return r_fingers;
        }
        //setup stuff
        const size_t ev_size = sizeof(struct input_event);
        ssize_t size;
        size = read(fd, &ev, ev_size); //returns the number of bytes read
        // if (size < ev_size) {
        //     fprintf(stderr, "Error size when reading\n");
        //     goto err;
        // }
        //check if end of a report
        if (ev.type == EVENT_TYPE_REPORT){
            processUpdate(state_update);
            //clear the tracking ID for the next update
            state_update[1] = 0;
            slot_flag = false;
            x_flag = false;
            y_flag = false;
            // fill(state_update.begin(), state_update.end(), 0);

            // cout <<"current slot"<<current_slot<<endl;
            // cout <<"fingersize"<<fingers.size()<<endl;
        }
        else{
            if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_SLOT){
                state_update[0] = ev.value;
                slot_flag = true;
                // cout << "slot" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_ID){
                state_update[1] = ev.value;
                // cout << "ID" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && (ev.code == EVENT_CODE_X || ev.code == EVENT_CODE_MT_X)) {
                state_update[2] = ev.value;
                // cout << "ev value" << ev.value << endl;
                x_flag = true;
                // cout << "x" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && (ev.code == EVENT_CODE_X || ev.code == EVENT_CODE_MT_Y)) {
                state_update[3] = ev.value;
                y_flag = true;
                // cout << "y" << ev.value << endl;
            }
            else if (ev.type == EVENT_TYPE_ABS && ev.code == EVENT_CODE_AREA){
                state_update[4] == ev.value;
                // cout << "radius" << ev.value << endl;
            }
        }
    }
//     return EXIT_SUCCESS;
//
// err:
//     close(fd);
//     return EXIT_FAILURE;
}
