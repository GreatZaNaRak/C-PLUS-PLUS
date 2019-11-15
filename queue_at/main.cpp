#include <stdexcept>
#include <iostream>
#include "queue.h"
#include "student.h"
#include <vector>


int main() {
  CP::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.remove_kth(4);
  q.print();
}

