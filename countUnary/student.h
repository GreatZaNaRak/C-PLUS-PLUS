#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename K, typename M, typename C>
size_t CP::map_bst<K,M,C>::process(node* p) const {
    //you may write additional code here
    if (!p) return 0;
    if (!p->left ^ !p->right) return process(p->left) + process(p->right) + 1;
    return process(p->left) + process(p->right);
}

template <typename K, typename M, typename C>
size_t CP::map_bst<K,M,C>::count_unary() const {
    return process(mRoot);
}

#endif
