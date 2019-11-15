#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;
template <typename T>
void CP::list<T>::remove_all(const T& value) {
    //write your code here
    for (auto i = begin() ; i != end() ; i++) {
        if (*i == value) {
            i.ptr->prev->next = i.ptr->next;
            i.ptr->next->prev = i.ptr->prev;
            delete i.ptr;
           // mSize--;
        }
    }
}

#endif
