#include "getTouch.h"
#include "finger.h"
#include "writeFile.h"
#include <iostream>
#include <thread>
using namespace std;

void other(){
    cout << "hello this is second thread\n" <<endl;
}
int main(void){
    // thread first (inputMonitor::);
    // thread second (other);
    // first.join();
    // second.join();
    // inputMonitor::init

    writeFile writer;
    inputMonitor monitor;
    monitor.init();
    vector<map<int, Finger>> all_touches = monitor.update();
    writer.writePoints(all_touches);
    writer.writeGnuplotPoints(all_touches);
    // cout << "doneflag"<< monitor.done_flag <<endl;
    // if (monitor.done_flag){
    //     cout<<"i'm done"<<endl;
    //     writer.writePoints();
    //     return(0);
    // }

}
