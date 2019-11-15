#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <algorithm>
#include <set>
using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
    //do someting here
    vector<T> res, data(*this);
    set<T> temp;
    for (auto& i : data) {
        if (temp.count(i) == 0) {
            res.push_back(i); temp.insert(i);
        }
    }
    *this = res;
}

#endif
