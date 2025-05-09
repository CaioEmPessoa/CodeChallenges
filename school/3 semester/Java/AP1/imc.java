import java.util.Scanner;

public class imc {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        System.out.println("Insira seu peso e altura, respectivamente:");
        double peso = s.nextFloat();
        double altura = s.nextFloat();

        double imc = peso/(Math.pow(altura, 2));

        System.out.println(imc);

    }
}
