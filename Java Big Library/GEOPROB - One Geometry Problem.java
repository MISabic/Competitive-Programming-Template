import java.util.Scanner;
import java.math.BigInteger;

public class Main {         // use Main.java for TOPH 

	public static void main(String[] args) {
		Scanner scanf=new Scanner(System.in);
		int a=scanf.nextInt();
		for(int i=0; i<a; i++){
			BigInteger b = scanf.nextBigInteger();
			BigInteger c = scanf.nextBigInteger();
			BigInteger d = scanf.nextBigInteger();
			BigInteger h = c.subtract(b);
			BigInteger j = c.subtract(d);
			BigInteger k = h.add(j);
			System.out.println(k);
		}
	}
}