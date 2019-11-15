#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    //write your code here
    CP::vector<T> dum;
    int j = 0;
    ///cout << pos[0] << endl;
    for (int i = 0 ; i < this->size() ; i++) {
        if (i == pos[j]) j++;
        else dum.push_back(this->at(i));
    }
    *this = dum;
}

#endif
