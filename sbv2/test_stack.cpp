#include <iostream>
#include <stack>
#include <assert.h>
#include "stack.h"
#include "student.h"

typedef CP::stack<int> Stack;
using namespace std;


bool test0() {
  //pop
  Stack s;

  cout << s.size() << " " << s.empty() << endl;
  s.push(10);
  cout << s.size() << " " << s.empty() << endl;
  s.pop();
  cout << s.size() << " " << s.empty() << endl;

  return true;
}


bool test1() {
  CP::stack<string> s;
  s.push("somchai");
  s.push("vishnu");
  s.push("nuttapong");
  s.push("nattee");
  cout << s.size() << " " << s.empty() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.size() << " " << s.empty() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.size() << " " << s.empty() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.size() << " " << s.empty() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.size() << " " << s.empty() << endl;
  return true;
}

bool test2() {
  Stack s;
  s.push(1);
  s.push(1);
  s.push(1);
  s.pop();
  s.pop();
  s.pop();

  Stack s2 = s;
  cout << s.size() << " " << s.empty() << endl;
  cout << s2.size() << " " << s2.empty() << endl;

  return true;
}

bool test3() {
  int nRun = 20;
  int nData = 1000000;
  for (int i = 0;i < nRun;i++) {
    Stack s;
    for (int j = 0;j < nData;j++) {
      s.push(j);
    }
    for (int j = 0;j < nData;j++) {
      s.pop();
    }
  }
  return true;
}

bool test4() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  s.pop();
  Stack s2(s);
  while (!s2.empty()) {
    cout << s2.top() << endl;
    s2.pop();
  }
  cout << s.size() << " " << s.empty() << endl;
  cout << s2.size() << " " << s2.empty() << endl;

  return true;
}
bool test5() {
  int n = 1000;
  Stack s1;
  for (int i = 0;i < n;i++) { s1.push(i); }
  for (int i = 0;i < n/2;i++) { s1.pop(); }
  Stack s2 = s1;
  while (!s1.empty()) { s1.pop(); }
  Stack s3(s1);

  cout << s1.size() << " " << s1.empty() << endl;
  cout << s2.size() << " " << s2.empty() << s2.top() << endl;
  cout << s3.size() << " " << s3.empty() << endl;
  return true;
}

bool test6() {
  int n = 1000000;
  Stack s1;
  for (int i = 0;i < n;i++) { s1.push(i); }
  for (int i = 0;i < n/2;i++) { s1.pop(); }
  Stack s2(s1);
  while (!s1.empty()) { s1.pop(); }
  Stack s3(s1);

  cout << s1.size() << " " << s1.empty() << endl;
  cout << s2.size() << " " << s2.empty() << s2.top() << endl;
  cout << s3.size() << " " << s3.empty() << endl;
  return true;
}

bool test7() {
  int n = 10000000;
  Stack s1;
  for (int i = 0;i < n;i++) { s1.push(i); }
  for (int i = 0;i < n/2;i++) { s1.pop(); }
  Stack s2(s1);
  while (!s1.empty()) { s1.pop(); }
  Stack s3(s1);

  cout << s1.size() << " " << s1.empty() << endl;
  cout << s2.size() << " " << s2.empty() << s2.top() << endl;
  cout << s3.size() << " " << s3.empty() << endl;
  return true;
}

bool test8() {
  return true;
}

bool test9() {
  return true;
}

void show(Stack i)
{
    while (!i.empty()) {
        cout << i.top() << " ";
        i.pop();
    }
}

#define loop(v) while(!v.empty()) {cout << v.top() << endl; v.pop();}

int main() {
    CP::stack<int> d;
    d.push(1);
    d.push(2);
    d.push(3);
    CP::stack<int> s;
    s.getReverse(d);
    loop(s);
}

