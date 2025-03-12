import java.util.Scanner;

public class celcius {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        System.out.println("Insira o valor em Celcius");
        double c = s.nextFloat();
        double f = (c * 9/5) + 32;
        System.out.println(f);

    }
}
