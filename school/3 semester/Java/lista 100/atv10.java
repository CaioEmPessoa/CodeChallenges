
/*

    Faça um algoritmo que leia a largura e altura de uma parede,
    calcule e mostre a área a ser pintada e a quantidade de tinta
    necessária para o serviço, sabendo que cada litro de tinta pinta
    uma área de 2metros quadrados.

*/

import java.util.Scanner;

public class atv10 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        
        // 1 litro = 2x2

        System.out.println("Insira a altura da parede em metros:");
        float numY = s.nextFloat();

        System.out.println("Insira a largura da parede em metros:");
        float numX = s.nextFloat();

        System.out.println((numY*numX)/4);

    }

}
