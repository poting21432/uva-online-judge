#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int MAX_CAPACITY = 30;

int N; // number of objects
int G; // number of people in the family
int value [MAX_N+1];
int weight[MAX_N+1];
int f[MAX_CAPACITY+1];

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d", &N);
    for ( int i=1; i<=N; ++i ) scanf("%d %d", &value[i], &weight[i]);
    scanf("%d", &G);
    int total_value = 0;
    for ( int g=1; g<=G; ++g ) {
      int capacity;
      scanf("%d", &capacity);
      for ( int j=0; j<=capacity; ++j ) f[j]= 0;
      for ( int i=1; i<=N; ++i ) {
	for ( int j=capacity; j>=weight[i]; --j ) {
	  f[j] = max(f[j], f[j-weight[i]] + value[i] );
	}
      }
      //printf("%d\n", f[capacity]);
      total_value += f[capacity];
    }
    printf("%d\n", total_value);
  }
}
