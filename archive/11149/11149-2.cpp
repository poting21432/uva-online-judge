#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 40;
const int MAX_K = 1000000;

int N; // size of the matrix

struct Matrix
{
  int elements[MAX_N][MAX_N];

  static Matrix identity()
  {
    Matrix I;
    for ( int i=0; i<N; ++i )
      I.elements[i][i] = 1;
    return I;
  }

  Matrix()
  {
    memset(elements, 0, sizeof(elements));
  }

  Matrix& operator= (const Matrix &A)
  {
    memcpy(elements, A.elements, sizeof(int)*MAX_N*MAX_N);
    return *this;
  }

  void read()
  {
    for ( int i=0; i<N; ++i )
      for ( int j=0; j<N; ++j ) {
	scanf("%d", &elements[i][j]);
	elements[i][j] %= 10;
      }
  }

  void print()
  {
    for ( int i=0; i<N; ++i ) {
      printf("%d", elements[i][0]);
      for ( int j=1; j<N; ++j )
	printf(" %d", elements[i][j]);
      putchar('\n');
    }
    putchar('\n');
  }
  
};

Matrix operator+ (const Matrix &a, const Matrix &b)
{
  Matrix c;
  for ( int i=0; i<N; ++i )
    for ( int j=0; j<N; ++j ) {
      c.elements[i][j] = a.elements[i][j] + b.elements[i][j];
      c.elements[i][j] %= 10;
    }
  return c;
}

Matrix operator* (const Matrix &a, const Matrix &b)
{
  Matrix c;
  for ( int i=0; i<N; ++i )
    for ( int j=0; j<N; ++j ) {
      int sum = 0;
      for ( int k=0; k<N; ++k ) {
	sum += a.elements[i][k] * b.elements[k][j];
	sum %= 10;
      }
      c.elements[i][j] = sum;
    }
  return c;
}

// returns A^k
Matrix matrixPower(Matrix &A, int k)
{
  if ( k==1 )  {
    return A;
  }
  else if ( k%2==1 )  {
    return matrixPower(A,k-1)*A;
  }
  else {
    Matrix tmp = matrixPower(A,k/2);
    return tmp*tmp;
  }
}

// returns A + A^2 + ... + A^k
Matrix matrixSeries(Matrix &A, int k)
{
  if ( k==1 ) { 
    return A;
  }
  else if ( k%2==0 ) {
    Matrix L = Matrix::identity() + matrixPower(A,k/2);
    Matrix R = matrixSeries(A, k/2);
    return L * R;
  }
  else {
    Matrix L = matrixSeries(A, k-1);
    Matrix R = matrixPower (A, k);
    return L + R;
  }
}

int main()
{
  int K;
  while ( ~scanf("%d %d", &N, &K) && N!=0 ) {
    Matrix A;
    A.read();
    matrixSeries(A, K).print();
  }
}
