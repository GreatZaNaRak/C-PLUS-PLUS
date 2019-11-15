

void replace(const T& x, list<T>& y)
{

        for (auto i = begin() ; i != end() ; i++) {
            if (*i == x) {
                list<T> tmp = y;

                i.ptr->prev->next = tmp.begin().ptr;
                tmp.begin().ptr->prev = i.ptr->prev;

                i.ptr->next->prev = tmp.end().ptr->prev;
                tmp.end().ptr->prev->next = i.ptr->next;

                delete i.ptr;
                mSize += tmp.mSize - 1;

                tmp.mSize = 0;
            }
        }

}
