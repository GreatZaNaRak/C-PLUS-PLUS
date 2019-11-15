#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,int a,int b) {
  std::vector<int> temp;
  std::vector<int> res;
  for (int i = b ; i >= a ; i--) {
      temp.push_back(v[i]);
  }
  for (auto i : temp) cout << i << endl;
  int j = 0;
  for (int i = 0 ; i < v.size() ; i++) {
      if (a <= i && i <= b) res.push_back(temp[j++]);
      else res.push_back(v[i]);
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
  reverse(v,a,b);
  //display content of the vector
  for (auto &x : v)
    cout << x << " ";
  cout << endl;
}