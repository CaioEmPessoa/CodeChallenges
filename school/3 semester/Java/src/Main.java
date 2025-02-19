import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        char[] jogo = {
            '_', '_', '_',
            '_', '_', '_',
            '_', '_', '_'
        };
        boolean jogador = true;
        boolean end = true;
        int ins;

        while (end) {
            System.out.println("Em qual coluna (1-9) vai querer inserir?");
            ins = scan.nextInt();

            if (jogador) {
                jogo[ins] = 'X';
                jogador = false;
            } 
            else {
                jogo[ins] = 'O';
                jogador = true;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    System.out.print(jogo[i]);
                }
                System.out.println();
            }

        }


    }
}