#ifndef _CP_QUEUE_INCLUDED_
#define _CP_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
#include <vector>
//#pragma once
using namespace std;

namespace CP {

template <typename T>
class queue
{
  protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    size_t mFront;

    typedef typename std::vector<T>::iterator iterator;


    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[(mFront + i) % mCap];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
      mFront = 0;
    }

    void ensureCapacity(size_t capacity) {
      if (capacity > mCap) {
        size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
        expand(s);
      }
    }


  public:
    //-------------- constructor ----------


    // default constructor
    queue() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
      mFront = 0;
    }

    queue(iterator from, iterator to);
    queue(int x);


    // copy assignment operator
    queue<T>& operator=(queue<T> other) {
      using std::swap;
      swap(mSize,other.mSize);
      swap(mCap,other.mCap);
      swap(mData,other.mData);
      return *this;
    }

    ~queue() {
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    //----------------- access -----------------
    const T& front() const {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[mFront];
    }
    const T& back() const {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[(mFront + mSize - 1) % mCap];
    }

    std::vector<T> to_vector(int k) const;

    //----------------- modifier -------------
    void push(const T& element) {
      ensureCapacity(mSize+1);
      mData[(mFront + mSize) % mCap] = element;
      mSize++;
    }

    void pop() {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      mFront = (mFront + 1) % mCap;
      mSize--;
    }

     // copy constructor
    queue(const std::vector<queue<T>>& a) {
        int cap = 0 ;
        for (int i = 0 ; i < a.size() ; i++) {
            cap += a[i].size();
        }
        this->mCap = cap;
        this->mSize = cap;
        this->mFront = 0;
        T* arr = new T[cap];
        int pos = 0; int j = 0; int run = -1; int round = 0;
        while (true){
            bool check = true;
            if (round % a.size() == 0) run++;
            for (int i = 0 ; i < a.size() ; i++) {
                if (run < a[i].size()) {
                    check = false; break;
                }
            }
            if (check) break;
            if (run < a[j%a.size()].size()) {
                arr[pos++] = a[j%a.size()].mData[mFront+run];
            }
            j++; round++;
        }
        this->mData = arr;
    }

    void push_front(const T& element)
    {
        this->mCap = mCap+1;
        this->mSize = mSize+1;
        T* arr = new T[mSize];
        arr[0] = element;
        for (int i = 1 ; i < mSize ; i++) {
            arr[i] = mData[i-1];
        }
        this->mData = arr;
    }

    void push_back(const T& element)
    {
        this->mCap = mCap+1;
        this->mSize = mSize+1;
        T* arr = new T[mSize];
        for (int i = 0 ; i < mSize ; i++) {
            arr[i] = mData[i];
        }
        arr[mSize-1] = element;
        this->mData = arr;
    }


    void print() {
        for (int i = 0 ; i < size() ; i++) {
            std::cout << mData[mFront+i] << " ";
        }
        std::cout << std::endl;
    }

    void pop_front()
    {
        this->mSize--;
        this->mCap--;
        T* arr = new T[mSize];
        for (int i = 0 ; i < mSize ; i++) {
            arr[i] = mData[i+1];
        }
        this->mData = arr;
    }

    void pop_back() {
        this->mSize--;
    }

};

}

#endif


