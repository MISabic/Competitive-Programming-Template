import java.math.BigDecimal;
import java.util.Scanner;
import java.math.BigInteger;
 
public class Main{
    public static void main(String[] args) {
        Scanner scanf=new Scanner(System.in);
        int a=scanf.nextInt(),n=0;
        for(int i=0; i<a; i++)
        {
            BigDecimal res = new BigDecimal("0");
            while(true)
            {
                BigDecimal bigD = scanf.nextBigDecimal();
                if(bigD.equals(BigDecimal.ZERO)) break;
                res = res.add(bigD);
            }
            res = res.stripTrailingZeros();
            System.out.println(res.toPlainString());
	}
    }
}