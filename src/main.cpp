#include "getTouch.h"
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
    // monitor.init();
    // monitor.update();
    writer.writePoints();

}
