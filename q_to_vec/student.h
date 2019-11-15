#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
#include <iterator>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    std::vector<T> res;
    //write your code only here
    //
    if (k > this -> size()) k = this -> size();
    for (int i = 0 ; i < k ; i++) {
        res.push_back(this ->mData[mFront+i]);
    }
    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from, iterator to) {
    //write your code only here
    int cap = distance(from, to);
    this -> mCap = cap;
    this -> mSize = cap;
    this -> mFront = 0;
    T *arr = new T[cap];
    int j = 0;
    for (auto i = from ; i != to ; i++) {
        arr[j++] = *i;
    }
    this -> mData = arr;
}

#endif
