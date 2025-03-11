/*

    Crie um programa que leia o número de dias trabalhados em um
    mês e mostre o salário de um funcionário, sabendo que ele trabalha
    8 horas por dia e ganha R$25 por hora trabalhada.

*/

import java.util.Scanner;

public class atv16 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        int mPC = 10; // minutes per cigarrete xD

        System.out.println("Quantos cigarros voce fuma por dia?");
        int cgrrDia = s.nextInt();

        System.out.println("A quantos anos voce fuma?");
        int anos = s.nextInt();

        int diasFumados;
        if (anos%4 == 0) diasFumados = (anos*365) + (anos/4); // considerando anos bissextos em média
        else diasFumados = (anos*365);

        int cigarrosFumados = cgrrDia*diasFumados;

        System.out.println(diasFumados);
        System.out.println(cigarrosFumados);
        

        s.close();
    }

}
