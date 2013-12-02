#include <cstido>

const int MAX_N = 40;
const int MAX_K = 1000000;

int  n; // size of the matrix
int  k; // power A^k
bool computed[MAX_K+1]; // whether A^k has been computed

struct Matrix
{
  int a[MAX_N][MAX_N];

  Matrix() { memset(a, 0, sizeof(a)); }

  void read()
  {
    for ( int i=0; i<n; ++i )
      for ( int j=0; j<n; ++j )
	scanf("%d", &A[i][j]);
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

Matrix matrixPower(const Matrix &A, const int &i)
{
  if ( computed[i] ) return powers[i];
  else {
    if      (  i==1  ) powers[i] = A;
    else if ( i%2==0 ) power[i] = matrixPower(A,i/2) * matrixPower(A,i/2);
    else               power[i] = matrixPower(A,i-1) * A;
    computed[i] = true;
    return powers[i];
  }
}

int main()
{
  while ( ~scanf("%d %d", &n, &k) && n!=0 ) {
    Matrix A, sum;
    A.read();
    memset(computed, 0, sizeof(computed));
    for ( int i=1; i<=k; ++i )
      sum = sum + matrixPower(A, i);
    A.print();
  }
}
