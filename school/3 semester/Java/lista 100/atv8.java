import java.util.Scanner;

public class atv8 {
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);

        System.out.println("Digite um valor em metros!!!!");

        float num = s.nextFloat();

        System.out.println((num/1000)+ "km");
        System.out.println((num/100)+ "Hm");
        System.out.println((num/10)+ "Dam");

        System.out.println((num*10)+ "dm");
        System.out.println((num*100)+ "cm");
        System.out.println((num*1000)+ "mm");

    }

}
