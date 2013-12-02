#include <cstdio>
#include <cstring>

const int MAX_N = 40;
const int MAX_K = 1000000;

bool computed[MAX_K+1]; // whether A^k has been computed

struct Matrix
{
  int n;
  int a[MAX_N][MAX_N];
  Matrix() { memset(a, 0, sizeof(a)); }

  void read()
  {
    for ( int i=0; i<n; ++i )
      for ( int j=0; j<n; ++j )
	scanf("%d", &a[i][j]);
  }

  void print()
  {
    for ( int i=0; i<n; ++i ) {
      printf("%d", a[i][0]);
      for ( int j=1; j<n; ++j ) {
	printf(" %d", a[i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
} powers[MAX_K+1];

Matrix operator+ (const Matrix &a, const Matrix &b)
{
  Matrix c; c.n = a.n;
  for ( int i=0; i<a.n; ++i )
    for ( int j=0; j<a.n; ++j )
      c.a[i][j] = a.a[i][j] + b.a[i][j];
  return c;
}

Matrix operator* (const Matrix &a, const Matrix &b)
{
  Matrix c; c.n = a.n;
  for ( int i=0; i<a.n; ++i )
    for ( int j=0; j<a.n; ++j )
      for ( int k=0; k<a.n; ++k )
	c.a[i][j] += a.a[i][k] * b.a[k][j];
  return c;
}

Matrix matrixPower(const Matrix &A, const int &i)
{
  if ( computed[i] ) return powers[i];
  else {
    if      ( i==1   ) powers[i] = A;
    else if ( i%2==0 ) powers[i] = matrixPower(A,i/2) * matrixPower(A,i/2);
    else               powers[i] = matrixPower(A,i-1) * A;
    computed[i] = true;
    return powers[i];
  }
}

void test()
{
  Matrix A, B;
  A.n = 2;
  A.a[0][0] = 1;
  A.a[0][1] = 2;
  A.a[1][0] = 3;
  A.a[1][1] = 4;

  B.n = 2;
  B.a[0][0] = 5;
  B.a[0][1] = 6;
  B.a[1][0] = 7;
  B.a[1][1] = 8;
  Matrix C = A+B; C.print();
  Matrix D = A*B; D.print();
}

int main()
{
  //test(); return 0;
  int N, K;
  while ( ~scanf("%d %d", &N, &K) && K!=0 ) {
    Matrix A, sum;
    A.n = sum.n = N;
    A.read();
    memset(computed, 0, sizeof(computed));
    for ( int i=1; i<=K; ++i ) {
      sum = sum + matrixPower(A, i);
    }
    sum.print();
  }
}
