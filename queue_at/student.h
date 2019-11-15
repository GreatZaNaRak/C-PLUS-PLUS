#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
T CP::queue<T>::operator[](int idx) {
    int n = idx < 0 ? mSize+idx : idx;
    return this->mData[n%mCap];
}

#endif
