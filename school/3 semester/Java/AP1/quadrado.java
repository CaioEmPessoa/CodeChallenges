import java.util.Scanner;

public class quadrado {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        System.out.println("Insira o valor pra descobrir ele ao quadrado:");
        double valor = s.nextFloat();

        System.out.println("Quadrado: " + valor*valor);
        System.out.println("Cubo: " + valor*valor*valor);
    }
}
