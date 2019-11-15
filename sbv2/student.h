#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  if (!v.empty()) {
    return v[v.size()-1];
  }
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
    auto it = v.begin();
    if (depth == 0 || depth < 0) {
        v.push_back(element);
        return;
    }
    if (depth > v.size()-1) {
        v.emplace(it,element);
        return;
    }
    int target = v.size() - depth;
    v.emplace(it+target, element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  for (auto i : w) {
    v.push_back(i);
  }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  while (!v.empty()) {
    if (v[v.size()-1] == e) break;
    v.pop_back();
  }
}
#endif

