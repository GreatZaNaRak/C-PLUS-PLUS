#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <queue>

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
    //write your code here
    if (K < 0) K = 0; if (K > size()) K = size();
    while(K--) this->pop();
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
    //write your code here
    //
    //don't forget to return an std::stack
    std::stack<T> res, temp;
    std::cout << mData[0] << std::endl;
    std::cout << mData[1] << std::endl;
    std::cout << mData[2] << std::endl;
    return res;
}

#endif
