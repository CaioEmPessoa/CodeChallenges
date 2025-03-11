/*

Desenvolva uma lógica que leia os valores de A, B e C de
uma equação do segundo grau e mostre o valor de Delta.

*/

import java.util.Scanner;

public class atv11 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        System.out.println("Calculadora de bhaskara!\n Insira o valor de A, B e C. Respectivamente.");

        double numA = s.nextFloat();
        double numB = s.nextFloat();
        double numC = s.nextFloat();

        double delta = (numB*numB - 4*numA*numC);

        double x1 = (-numB + Math.pow(delta, 0.5)) / (2 * numA);
        double x2 = (-numB - Math.pow(delta, 0.5)) / (2 * numA);

        System.out.println("Δ=" + delta);
        System.out.println("x'=" + x1 + " " + "x''=" + x2);

        s.close();
    }

}
