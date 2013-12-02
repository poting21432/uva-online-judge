#include <cstdio>

const int MAX_N = 200000;
int n;
int a[MAX_N];
int b[MAX_N];
unsigned long long count; // inversion count

void read()
{
  scanf("%d", &n);
  for ( int i=0; i<n; ++i )
    scanf("%d", &a[i]);
}

void mergeSort(int L, int R)
{
  if ( L==R ) return;
  else {
    int M = (L+R)/2;
    mergeSort(L,  M);
    mergeSort(M+1,R);
    int i = L;
    int j = M+1;
    int k = 0;
    while ( i<=M && j<=R ) {
      if ( a[i] <= a[j] ) b[k++] = a[i++], count += j-(M+1);
      else                b[k++] = a[j++];
    }
    while ( i<=M ) b[k++] = a[i++], count += j-(M+1);
    while ( j<=R ) b[k++] = a[j++];
    for ( int i=0; i<k; ++i ) a[L+i] = b[i];
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int test=1; test<=T; ++test ) {
    read();
    count = 0;
    mergeSort(0, n-1);
    printf("%llu\n", count);
  }
} 
