import java.util.Scanner;

public class fahrenheit {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        System.out.println("Insira o valor em Fahrenheit");
        double f = s.nextFloat();
        double c = (f - 32) * 5/9;
        System.out.println(c);

    }
}
