#include <iostream>

using namespace std;

int cutleaf(int loop_obj){
    if (condition) {
        //do something
        return cutleaf(loop_obj);
    } else {
        return loop_obj;
    }
}