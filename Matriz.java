
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
	
	public static void mostraMatriz(int matriz[][], int tamX) {
		for(int i=0; i <= tamX-1; i++ ) {
			System.out.println(Arrays.toString(matriz[i]));
		}
	}
	
	public static int Multi(int matriz1[][], int matriz2[][]) {
		int matrizResultado[][] = new int[x][y];
		
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				matriz[i][j] = rand.nextInt(10)+1;
			}
		}
		return 0;
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
		
		int[][] matriz1 = GerarMatriz(tamX1, tamY1);
		mostraMatriz(matriz1, tamX1);
		int[][] matriz2 = GerarMatriz(tamX2, tamY2);
		mostraMatriz(matriz2, tamX2);
		
		
		
	}
}
