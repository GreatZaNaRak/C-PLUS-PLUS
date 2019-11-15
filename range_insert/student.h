#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
#define loop(v) for (int i = 0 ; i < v.size() ; i++)

using namespace std;
template <typename T>
void CP::vector<T>::insert() {
  //write your code here
    CP::vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    *this = t;
}

void test(){

}

#endif
