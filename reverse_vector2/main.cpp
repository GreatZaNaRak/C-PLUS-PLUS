#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
  //write your code only in this function
  vector<int>::iterator from = a, to = b - 1;
  cout << from-v.begin() << " " << to-v.begin() << endl;
  std::vector<int> temp, res;
  int j = 0;
  b--;
  for (auto& i = to ; i != from-1 ; i--) {temp.push_back(v[i- v.begin()]);}
  for (auto i = v.begin() ; i != v.end() ; i++) {
      if (a - v.begin() <= i - v.begin() && i - v.begin() <= b - v.begin()) res.push_back(temp[j++]);
      else res.push_back(v[i - v.begin()]);
  }
  v = res;
}
int main() {
  //read input
  int n,a,b;
  cin >> n;
  vector<int> v;
  for (int i = 0;i < n;i++) {
    int c;
    cin >> c;
    v.push_back(c);
  }
  cin >> a >> b;
  //call function
  reverse(v,v.begin()+a,v.begin()+b+1);
  //display content of the vector
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}