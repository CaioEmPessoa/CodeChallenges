/*

Faça um algoritmo que leia a largura e altura de uma parede,
calcule e mostre a área a ser pintada e a quantidade de tinta
necessária para o serviço, sabendo que cada litro de tinta pinta
uma área de 2metros quadrados.

*/

import java.util.Scanner;

public class atv10 {
    public static void main(String[] args) {
        
        int litrosLata = 2;

        Scanner s = new Scanner(System.in);

        System.out.println("Qual largura da sua parede?");
        float x = s.nextFloat();
        
        System.out.println("Qual altura da sua parede?");
        float y = s.nextFloat();

        System.out.println("Serão necessárias " + ((x*y) / (litrosLata*litrosLata)) + " latas de tinta");

        s.close();
    }

}
