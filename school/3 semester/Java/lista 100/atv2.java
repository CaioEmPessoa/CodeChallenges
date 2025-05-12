/*

    Faça um programa que leia o nome de uma pessoa e mostre uma
    mensagem de boas- vindas para ela.

*/

import java.util.Scanner;

public class atv2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Qual seu nome?");

        String nome = s.nextLine();

        s.close();

        System.out.println("Olá! " + nome + " tudo bem?");
    }
}