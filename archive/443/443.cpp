#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

using namespace std;

typedef unsigned long long ull;

vector<int> humble;

bool overflow(int a, int b) // a*b
{
  return a*b/b != a || b*a/a!=b;
}

void prepare()
{
  int base[4] = {2,3,5,7};

  stack<int> stack;
  stack.push(1);

  set<int> set;
  set.insert(1);

  while ( !stack.empty() ) {
    int x = stack.top(); stack.pop();
    for ( int i=0; i<4; ++i ) {
      if ( !overflow(x, base[i]) ) {
	int y = x*base[i];
	if ( !set.count(y) ) {
	  set.insert(y);
	  stack.push(y);
	}
      }
    }
  }

  humble.resize(set.size());
  copy(set.begin(), set.end(), humble.begin());
}

const char* suffix(int n)
{
  if ( n > 100 ) n %= 100;
  if ( n>=4 && n<=20 ) return "th";
  if ( n%10 == 1 ) return "st";
  if ( n%10 == 2 ) return "nd";
  if ( n%10 == 3 ) return "rd";
  return "th";
}

void test()
{
  int n;
  while ( ~scanf("%d", &n) && n!=0 )
    printf("The %d%s humble number is %d.\n", n, suffix(n), humble[n-1]);
}

int main()
{
  prepare();
  test();
}
