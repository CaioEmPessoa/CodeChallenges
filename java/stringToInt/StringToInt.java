// Java program to convert numbers in full to equivalent in intergers
// for example, twenty four to 24

package stringToInt;

import java.util.Scanner;

public class StringToInt {

    public static void main(String[] args) {

        numberTextValues numTxt = new numberTextValues();
        numTxt.generateArray();

        Scanner s = new Scanner(System.in);

        Boolean loop = true;
        while (loop) {
            String linha = s.nextLine();

            if (linha == "fim") {
                loop = false;
                break;
            }

            System.out.println(numTxt.getNumber(linha));
        }

        s.close();
    }
}