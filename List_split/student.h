#ifndef __STUDENT_H_
#define __STUDENT_H_


using namespace std;
template <typename T>
CP::list<T> CP::list<T>::split(iterator i, size_t pos) {
    //write your code here
    CP::list<T> result;

    if (pos == mSize) return res;

    node* tmp = end().ptr->prev;
    end().ptr->prev = i.ptr->prev;
    i.ptr->prev->next = end().ptr;

    result.end().ptr->next = i.ptr;
    i.ptr->prev = result.end().ptr;
    result.end().ptr->prev = tmp;
    tmp->next = result.end().ptr;

    result.mSize = mSize - pos;
    mSize = pos;

    return result;
}

#endif
