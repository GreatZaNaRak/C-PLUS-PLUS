#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <queue>
#include <vector>

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  //write your code here
  //
  // YOU CANNOT CALL push or pop
  if (this->mSize != other.mSize) return false;
  bool check = true;
  for (int i = 0 ; i < this->mSize ; i++) {
    std::cout << mData[mFront+i] << " " << other.mData[other.mFront+i] << std::endl;
    if (this->mData[i] != other.mData[i])
        check = false;
  }
  return check ? true : false;
}

#endif
