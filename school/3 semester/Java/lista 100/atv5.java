/*

    Faça um programa que leia as duas notas de um aluno em uma
    matéria e mostre na tela a sua média na disciplina.

*/

import java.util.Scanner;

public class atv5 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Insira as duas notas:");
        int nota1 = s.nextInt();
        int nota2 = s.nextInt();

        System.out.println((nota1 + nota2) / 2);

        System.out.println();

        s.close();
    }
}