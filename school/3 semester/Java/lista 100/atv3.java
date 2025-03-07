import java.util.Scanner;

public class atv3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Insira o nome do funcionário:");
        String nome = s.nextLine();

        System.out.println("Insira o salário do funcionário:");
        int salario = s.nextInt();

        System.out.println("O(a) funcionário(a) " + nome + " possui um valor de R$" + salario + " de salário.");

    }
}
