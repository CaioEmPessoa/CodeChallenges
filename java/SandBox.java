import java.util.Arrays;

public class SandBox {
    public static void main(String[] args) {

        int newSize = 5;

        int[] range;
        range = new int[newSize];

        for (int i = newSize-1; i >= 0; i--) {
            range[i] = i;
            System.out.println(i);
        }

        System.out.println(Arrays.toString(range));

    }
}