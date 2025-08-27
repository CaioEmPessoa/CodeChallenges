
import java.util.*;

public class Matriz {

	public static int[][] GerarMatriz(int x, int y) {
		Random rand = new Random();
		int matriz[][] = new int[x][y];

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				matriz[i][j] = rand.nextInt(10)+1;
			}
		}

		return matriz;
	}

	public static void mostraMatriz(int matriz[][]) {
		int tam = matriz.length;

		for(int i=0; i < tam; i++ ) {
			System.out.println(Arrays.toString(matriz[i]));
		}
	}

	public static int[][] Multi(int matriz1[][], int matriz2[][]) {
		int x = matriz1.length;
		int y1 = matriz1[0].length;
		int y2 = matriz2[0].length;

		int matrizResultado[][] = new int[x][y2];

		for (int i = 0; i < x; i++) {          // linha

			for (int j = 0; j < y2; j++) {     // colunas matriz 2

				for (int o = 0; o < y1; o++) { // colunas matriz 1
					matrizResultado[i][j] += matriz1[i][o] * matriz2[o][j];
				}

			}

		}
		return matrizResultado;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int tamX1 = 0, tamY1 = 0,
			tamX2 = 0, tamY2 = 0;

		boolean aceito = true;

		while(aceito) {
			System.out.println("Qual a quantidade de linhas na primeira matriz?");
			tamX1 = sc.nextInt();

			System.out.println("Qual a quantidade de colunas na primeira matriz?");
			tamY1 = sc.nextInt();

			System.out.println("Qual a quantidade de linhas na segunda matriz?");
			tamX2 = sc.nextInt();

			System.out.println("Qual a quantidade de colunas na segunda matriz?");
			tamY2 = sc.nextInt();

			if (tamX1 != tamY2 || tamY1 != tamX2) {
				System.out.println("Valores inválidos!");
			}
			else aceito = false;
		}

		System.out.println("Valores corretos!");
		sc.close();

		System.out.println("\n------ Matriz 1:");

		int[][] matriz1 = GerarMatriz(tamX1, tamY1);
		mostraMatriz(matriz1);

		System.out.println("\n------ Matriz 2:");

		int[][] matriz2 = GerarMatriz(tamX2, tamY2);
		mostraMatriz(matriz2);

		System.out.println("\nMultiplicacao de ambas:");

		int[][] result = Multi(matriz1, matriz2);

		mostraMatriz(result);

	}
}
