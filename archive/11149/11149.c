#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 40;
const int MAX_K = 1000000;

void readMatrix(int **A, int N)
{
  int i, j;
  for ( i=0; i<N; ++i )
    for ( j=0; j<N; ++j )
      scanf("%d", &A[i][j]);
}

void printMatrix(int **A, int N)
{
  int i, j;
  for ( i=0; i<N; ++i ) {
    printf("%d", A[i][0]);
    for ( j=1; j<N; ++j ) 
      printf(" %d", A[i][j]);
    putchar('\n');
  }
  putchar('\n');
}

void addMatrix(int **C, int **A, int **B, int N)

{
  int i, j;
  for ( i=0; i<N; ++i )
    for ( j=0; j<N; ++j )
      C[i][j] = (A[i][j] + B[i][j]) % 10;
}

void mulMatrix(int **C, int **A, int **B, int N)
{
  int i, j, k;
  for ( i=0; i<N; ++i )
    for ( j=0; j<N; ++j ) {
      C[i][j] = 0;
      for ( k=0; k<N; ++k )
	C[i][j] += A[i][k] * B[k][j];
      C[i][j] %= 10;
    }
}

void cpyMatrix(int **B, int **A, int N)
{
  int i, j;
  for ( i=0; i<N; ++i )
    for ( j=0; j<N; ++j )
      B[i][j] = A[i][j];
}

void powMatrix(int **C, int **A, int k, 
	       int  ***powers,
	       char *computed,
	       int  N)
{
  int **T, i;
  T = (int **) malloc(MAX_N * sizeof(int *));
  for ( i=0; i<MAX_N; ++i )
    T[i] = (int *) malloc(MAX_N * sizeof(int));

  if ( (int)computed[k] ) cpyMatrix(C, A, N);
  else {
    if ( k==1 )
      cpyMatrix(powers[k], A, N);
    else if ( k%2==0 ) {
      powMatrix(T, A, k/2, powers, computed, N);
      mulMatrix(powers[k], T, T, N);
    }
    else {
      powMatrix(T, A, k-1, powers, computed, N);
      mulMatrix(powers[k], A, T, N);
    }
    computed[k] = 1;
    cpyMatrix(C, powers[k], N);
  }

  for ( i=0; i<MAX_N; ++i )
    free(T[i]);
  free(T);
}

int main()
{
  int  N, K, i, j, k;
  
  int  **A;
  int  **S;
  int  **T;
  int  ***powers;
  char *computed;

  A = (int **) malloc(MAX_N * sizeof(int *));
  for ( i=0; i<MAX_N; ++i ) 
    A[i] = (int *) malloc(MAX_N * sizeof(int));

  S = (int **) malloc(MAX_N * sizeof(int *));
  for ( i=0; i<MAX_N; ++i ) 
    S[i] = (int *) malloc(MAX_N * sizeof(int));

  T = (int **) malloc(MAX_N * sizeof(int *));
  for ( i=0; i<MAX_N; ++i ) 
    T[i] = (int *) malloc(MAX_N * sizeof(int));

  powers = (int ***) malloc((MAX_K+1) * sizeof(int **));
  for ( i=0; i<MAX_K+1; ++i ) {
    powers[i] = (int **) malloc((MAX_N) * sizeof(int *));
    for ( j=0; j<MAX_N; ++j ) {
      powers[i][j] = (int *) malloc((MAX_N) * sizeof(int));
    }
  }

  computed = (char *) malloc((MAX_K+1) * sizeof(char));

  while ( ~scanf("%d %d", &N, &K) && N!=0 ) {
    readMatrix(A, N);
    for ( k=1; k<=K; ++k ) computed[k] = 0;
    for ( i=0; i<N; ++i )
      for ( j=0; j<N; ++j )
	S[i][j] = 0;
    for ( k=1; k<=K; ++k ) {
      powMatrix(T, A, k, powers, computed, N);
      addMatrix(S, S, T, N);
    }
    printMatrix(S, N);
  }
}
