/*

    Crie um programa que leia o número de dias trabalhados em um
    mês e mostre o salário de um funcionário, sabendo que ele trabalha
    8 horas por dia e ganha R$25 por hora trabalhada.

*/

import java.util.Scanner;

public class atv15 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        double porHora = 25;
        double porDia = porHora*8;

        System.out.println("Quantos dias trabalhou no mês?");
        int dias = s.nextInt();
        System.out.println(dias*porDia);

        s.close();
    }

}
