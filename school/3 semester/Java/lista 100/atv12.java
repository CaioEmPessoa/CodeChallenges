
/*

    Crie um programa que leia o preço de um produto, calcule e
    mostre o seu PREÇO PROMOCIONAL, com 5% de desconto.

*/

import java.util.Scanner;
import java.math.*;

public class atv11 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        
        // 1 litro = 2x2

        System.out.println("Insira os 3 valores para calcular bhaskara, separados por enter.:");
        double numA = s.nextFloat();
        double numB = s.nextFloat();
        double numC = s.nextFloat();

        double delta = Math.pow(numB*numB - 4*numA*numC, 0.5);
        double x1 = (delta-numB)/(2*numA);
        double x2 = (delta+numB)/(2*numA);

        System.out.println("Delta = " + delta);
        System.out.println("X' = " + x1);
        System.out.println("X'' = " + x2);

    }

}
