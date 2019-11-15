#include <iostream>

using namespace std;

class B; // ��¹�ç������������ B �繤��� ���ѧ�����¹�����´

class A {
private:
    int a;
public:
    friend B;
    A() {}
    A(int a) {this->a = a;}
    int  get_a() { return this->a; }
};

class B {
public:
    void foo(A &obj_a) {
        obj_a.a += 100;
    }
};
int main() {
    A a(10);
    B b;
    b.foo(a);
    cout << a.get_a() << endl;
}

