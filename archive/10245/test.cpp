#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;
  v.resize(56);
  printf("v.size() = %d\n", (int)v.size());

  v.reserve(77);
  printf("v.size() = %d\n", (int)v.size());


}
