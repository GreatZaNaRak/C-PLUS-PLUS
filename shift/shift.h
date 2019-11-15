
void shift(int k) {
	// TODO: Add your code here
	if (k == 0) return;

    begin().ptr->prev = end().ptr->prev;
    end().ptr->prev->next = begin().ptr;

    auto F = begin();
    auto L = --end();
   // std::cout << L->data << std::endl;

    if (k > 0) while(k--) {F++; L++;}
    else while(k++) {F--; L--;}

    mHeader->next = F.ptr;
    F.ptr->prev = mHeader;
    mHeader->prev = L.ptr;
    L.ptr->next = mHeader;
}
