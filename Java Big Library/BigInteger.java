/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package acm;

import java.util.*;
import java.math.*;
        
public class Main{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        Scanner scanf=new Scanner(System.in);
        while(scanf.hasNextBigInteger()){
            BigInteger big=BigInteger.ONE;
            BigInteger n=scanf.nextBigInteger();
            //System.out.println(" hello " + n);
            if(big.mod(n)==BigInteger.ZERO){
                System.out.println(big);
                continue;
            }
            for(int i=1; i<=100; i++){
                big=big.multiply(BigInteger.valueOf(10));
                if(big.mod(n)==BigInteger.ZERO){
                    System.out.println(big);
                    break;
                }
                big=big.add(BigInteger.ONE);
                if(big.mod(n)==BigInteger.ZERO){
                    System.out.println(big);
                    break;
                }
            }
        }
    }
}
