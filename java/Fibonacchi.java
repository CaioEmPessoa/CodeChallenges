import java.util.Scanner;

public class Fibonacchi {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Hello and welcome!");
        int fib1 = 0;
        int fib2 = 1;
        int fib = 0;

        System.out.print("Qual tamanho da sequencia desejada?");
        int tamSeq = scan.nextInt();

        for (int i = 0; i < tamSeq; i++) {
            fib = fib2 + fib1;
            fib2 = fib1;
            fib1 = fib;
        }

        System.out.println("numero final: " + fib);

    }
}