import java.util.Scanner;

class Main
{
  final int MAX_N = 40;
  final int MAX_K = 1000000;

  boolean[] computed = new boolean[MAX_K+1];

  class Matrix
  {
    int n; // size of the matrix
    int a[][] = new int[MAX_N][MAX_N];
    Matrix()
    {
      for ( int i=0; i<MAX_N; ++i )
	for ( int j=0; j<MAX_N; ++j )
	  a[i][j] = 0;
    }

    public void read(Scanner in)
    {
      for ( int i=0; i<n; ++i )
	for ( int j=0; j<n; ++j )
	  a[i][j] = in.nextInt();
    }

    public void print()
    {
      for ( int i=0; i<n; ++i ) {
	System.out.printf("%d", a[i][0]);
	for ( int j=1; j<n; ++j ) {
	  System.out.printf(" %d", a[i][j]);
	}
	System.out.printf("\n");
      }
      System.out.printf("\n");
    }

    public int getSize() { return n; }
    public void setSize(int new_size) { n = new_size; }
    public int get(int i, int j) { return a[i][j]; }
    public void set(int i, int j, int k) { a[i][j] = k; }
  }

  Matrix[] powers = new Matrix[MAX_K+1];

  Matrix add(Matrix A, Matrix B)
  {
    Matrix C = new Matrix();
    C.setSize(A.getSize());
    for ( int i=0; i<A.n; ++i )
      for ( int j=0; j<A.n; ++j ) {
	int sum = A.get(i,j) + B.get(i,j);
	sum %= 10;
	C.set(i, j, sum);
      }
    return C;
  }

  Matrix mul(Matrix A, Matrix B)
  {
    Matrix C = new Matrix();
    C.setSize(A.getSize());
    for ( int i=0; i<A.n; ++i )
      for ( int j=0; j<A.n; ++j ) {
	int sum = 0;
	for ( int k=0; k<A.n; ++k )
	  sum += A.get(i,k) * B.get(k,j);
	sum %= 10;
	C.set(i,j,sum);
      }
    return C;
  }

  Matrix matrixPower(Matrix A, int i)
  {
    if ( computed[i] ) return powers[i];
    else {
      if      ( i==1   ) powers[i] = A;
      else if ( i%2==0 ) powers[i] = mul(matrixPower(A,i/2), matrixPower(A,i/2));
      else               powers[i] = mul(matrixPower(A,i-1), A);
      computed[i] = true;
      return powers[i];
    }
  }

  public void solve()
  {
    Scanner in = new Scanner(System.in);
    int N, K;
    while ( true ) {
      N = in.nextInt();
      K = in.nextInt();
      if ( N==0 ) break;
      Matrix A = new Matrix();
      Matrix S = new Matrix();
      A.setSize(N);
      S.setSize(N);
      A.read(in);
      for ( int k=1; k<=K; ++k ) computed[k] = false;
      for ( int k=1; k<=K; ++k ) S = add(S, matrixPower(A,k));
      S.print();
    }
  }

  public static void main(String[] args)
  {
    Main problem = new Main();
    problem.solve();
  }
}

