import java.util.Scanner;
import java.math.BigInteger;

class Main
{
  static final BigInteger zero = new BigInteger("0");

  static BigInteger makeOnes(int n)
  {
    String str = "";
    for ( int i=0; i<n; ++i )
      str += "1";
    return new BigInteger(str);
  }

  public static void main(String[] args)
  {
    //Scanner in = new Scanner(System.in);
    //while ( in.hasNextInt() ) {
    //int n = in.nextInt();
    int max_ans = 0;
    for ( int n=1; n<=9999; ++n ) if ( n%2!=0 && n%5!=0 ) {
      BigInteger N = new BigInteger(String.format("%d",n));
      for ( int i=1; ; ++i ) {
	BigInteger M = Main.makeOnes(i);
	if ( M.mod(N).equals(zero) ) {
	  if ( i>max_ans ) max_ans = i;
	  System.out.printf("f(%d) = %d\n", n, i);
	  break;
	}
      }
    }
    System.out.printf("max_ans = %d\n", max_ans);
  }
}