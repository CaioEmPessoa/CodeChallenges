import java.util.Scanner;

public class atv9 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        System.out.println("conversor pra dolar em 2013!");

        float num = s.nextFloat();

        String formatNum = String.format("%.2f", num/3.5);

        System.out.println("$" + formatNum);

    }

}
