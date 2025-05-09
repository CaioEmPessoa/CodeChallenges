/*

    Faça um algoritmo que leia o salário de um funcionário,
    calcule e mostre o seu novo salário, com 15% de aumento.

*/

import java.util.Scanner;

public class atv12 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        System.out.println("Insira valor do produto:");
        double preco = s.nextFloat();
        
        System.out.println("Insira valor do desconto:");
        double desconto = s.nextFloat();

        desconto = Math.abs((desconto-100)/100);

        System.out.println("Preco final: R$" + preco*desconto );

        s.close();
    }

}
