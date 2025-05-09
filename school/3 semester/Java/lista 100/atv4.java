/*

    Desenvolva um algoritmo que leia dois números inteiros e
    mostre o somatório entre eles.

*/

import java.util.Scanner;

public class atv4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Insira dois número:");
        int num1 = s.nextInt();
        int num2 = s.nextInt();

        System.out.println(num1 + num2);

        System.out.println();
    }
}