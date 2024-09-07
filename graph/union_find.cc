#include <iostream>

using namespace std;

int getParent(int parent[], int x) {
  if(parent[x] == x) return x;
  return parent[x] = getParent(parent, x);
}

void unionParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);

  if(a < b) parent[b] = a;
  else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
  return getParent(parent, a) == getParent(parent, b);
}

int main() {

  return 0;
}