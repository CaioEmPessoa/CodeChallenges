import java.util.Scanner;

public class triangulo {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        System.out.println("Descubra área do triangulo!!!!\nInsira altura e base, respectivamente:");
        double altura = s.nextFloat();
        double base = s.nextFloat();

        System.out.println("Área: " + (base*altura)/2);
    }
}
