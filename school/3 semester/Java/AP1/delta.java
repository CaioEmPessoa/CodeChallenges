import java.util.Scanner;

public class delta {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        System.out.println("Calculador de delta!\n Insira os valores de A, B e C respectivamente:");
        double a = s.nextFloat();
        double b = s.nextFloat();
        double c = s.nextFloat();

        System.out.println("/_\\= " + ((b*b)-4*a*c));
    }
}
