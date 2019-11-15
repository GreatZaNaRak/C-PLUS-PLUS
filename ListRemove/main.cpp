#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"
//#pragma once



int main() {
  CP::list<int> l;
  int n,k;
  std::cin >> n ;
  while (n--) {
    int x;
    std::cin >> x;
    l.push_back(x);
  }
  cout << l[1] << endl;
}

