#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

using namespace std;

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
    //your code here
    bool check = false;
    for (int i = 0 ; i < size() ; i++) {
        if (mData[i] == k) {
            check = true;
            break;
        }
    }
    return check ? true : false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
    //your code here
    int max_pos = -1;
    for (int i = 0 ; i < size() ; i++) {
        if (mData[i] == k) {
            max_pos = (int) (floor(log2(i+1))) ;
        }
    }
    return max_pos;
}

#endif

