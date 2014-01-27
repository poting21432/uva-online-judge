#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Term
{
  int index;
  int value;
  Term(int i, int v): index(i), value(v){}
};

bool operator< (const Term &a, const Term &b) { return a.value < b.value; }
bool operator> (const Term &a, const Term &b) { return a.value > b.value; }

int N; // size of A
vector<Term> A;
vector<Term> B;
vector<int>  pre;

void read()
{
  int x;
  A.clear();
  while ( ~scanf("%d", &x) )
    A.push_back( Term(A.size(), x) );
}

void printVector(const vector<int> &v)
{
  if ( v.empty() ) puts("{}");
  else {
    printf("{%d", v[0]);
    for ( int i=1; i<v.size(); ++i )
      printf(", %d", v[i]);
    puts("}");
  }
}

void printVector(const vector<Term> &v)
{
  if ( v.empty() ) puts("{}");
  else {
    printf("{%d[idx=%d]", v[0].value, v[0].index);
    for ( int i=1; i<v.size(); ++i )
      printf(", %d[idx=%d]", v[i].value, v[0].index);
    puts("}");
  }
}

void solve()
{
  N = A.size();
  pre.resize(N);

  B.push_back(A[0]);
  pre[0] = -1;

  int end = 0;

  for ( int i=1; i<N; ++i ) {
    if ( A[i] > B[B.size()-1] ) {
      pre[i] = B[B.size()-1].index;
      end = i;
      B.push_back(A[i]);
    }
    else {
      vector<Term>::iterator it = lower_bound(B.begin(), B.end(), A[i]);
      if ( it==B.begin() ) pre[i] = -1;
      else                 pre[i] = it[-1].index;

      if ( it==B.end()-1 )
	end = i;
      *it = A[i];
    }
    //printf("After i=%d, B = ", i); printVector(B);
  }

/*
  for ( int i=0; i<N; ++i )
    printf("A[%d].value = %d, pre[%d] = %d\n", i, A[i].value, i, pre[i]);
  printf("end = %d\n", end);
*/
  stack<int> stack;
  while ( true ) {
    stack.push(A[end].value);
    if ( pre[end]==-1 ) break;
    else end = pre[end];
  }

  printf("%zd\n-\n", B.size());
  while ( !stack.empty() ) {
    printf("%d\n", stack.top());
    stack.pop();
  }
}

int main()
{
  read();
  solve();
}
