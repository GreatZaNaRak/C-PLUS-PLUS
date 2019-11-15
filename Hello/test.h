#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <queue>
#define loop1(d) while(!d.empty()) {cout << d.top() << endl;d.pop();}
#define loop2(d) while(!d.empty()) {cout << d.front() << endl;d.pop();}
using namespace std;

/// =================== Part 1 ======================== ///

///*







/// =================== Part 2 ======================== ///

void remove_2nd_max(priority_queue<int>& q)
{
    int temp = q.top();
    q.pop(); q.pop();
    q.push(temp);
}

void mafiaPush(queue<int>& q, int element)
{
    std::queue<int> temp;
    temp.push(element);
    while(!q.empty()) {temp.push(q.front()); q.pop();}
    q = temp;
}

bool less_test(pair<int,double>& a, pair<int,double>& b)
{
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}





#endif // TEST_H_INCLUDED
