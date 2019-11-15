#include <stdexcept>
#include <iostream>
#include "vector.h"
#include "student.h"


bool equal(CP::vector<int> &a,CP::vector<int> &b) {
  if (a.size() != b.size()) return false;
  for (size_t i = 0;i < a.size();i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
using namespace std;

void print(const CP::vector<int>& d)
{
    for (int i = 0 ; i < d.size() ; i++) {
        cout << d[i] << endl;
    }
}

int main() {
    CP::vector<int> d;
    d.push_back(9);
    d.push_back(2);
    d.push_back(6);
    d.push_back(8);
    d.push_back(1);
    d.push_back(7);
    CP::vector<CP::vector<int>::iterator> its;
    its.push_back(d.begin());
    its.push_back(d.begin()+3);
    its.push_back(d.begin()+5);
    d.duplicateElement(its);
    for (int i = 0 ; i < d.size() ; i++) {
        cout << d[i] << endl;
    }

}

