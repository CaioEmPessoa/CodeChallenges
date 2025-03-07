import java.util.Scanner;

public class atv7 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        System.out.println("Digite um número e descubra qual é o seu dobro e sua 1/3 parte! WEEEE");

        float num = s.nextFloat();

        System.out.println("Dobro: " + (num*2));
        System.out.println("Terça parte: " + (num/3));

    }



}
