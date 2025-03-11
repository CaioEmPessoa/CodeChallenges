/*

    A locadora de carros precisa da sua ajuda para cobrar seus
    serviços. Escreva um programa que pergunte a quantidade de Km
    percorridos por um carro alugado e a quantidade de dias pelos quais
    ele foi alugado. Calcule o preço total a pagar, sabendo que o carro
    custa R$90 por dia e R$0,20 por Km rodado.

*/

import java.util.Scanner;

public class atv14 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        double vlrDia = 90;
        double vlrKm = 0.20;

        // int propositalmente, quem insere deveria arredondar para cima
        System.out.println("Quantos dias ficou com o carro?");
        int dias = s.nextInt();
        System.out.println("Quantos km rodou com o carro?");
        int kms = s.nextInt();

        System.out.println("Deve pagar: R$" + (dias*vlrDia + kms*vlrKm) );

        s.close();
    }

}
