
/*

    Faça um programa que leia um número inteiro e mostre o seu
    antecessor e seu sucessor.

*/

import java.util.Scanner;

public class atv6 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Digite um número e descubra qual veio antes e depois! WEEEE");

        int num = s.nextInt();

        System.out.println("Anterior: " + (num-1));
        System.out.println("Posterior: " + (num+1));

    }
}