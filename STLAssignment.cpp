#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

vector<int> v;

bool enterringIntegers = true;

while (enterringIntegers){
  int newInt;
  cout << "Enter interger or enter non-integer to finish." << endl;
  if (cin >> newInt) {
    v.push_back(newInt);
  }
  else {
    enterringIntegers = false;
    break;
  }
}
cout << "Unsorted Vector: ";
for (auto i : v) {
  cout << i << " ";
}
cout << endl;
sort(v.begin(), v.end());
cout << "Sorted Vector: ";
for (auto i : v) {
  cout << i << " ";
}
cout << endl;


  return 0;
}
