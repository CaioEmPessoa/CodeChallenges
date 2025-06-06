// TODO:
// Store size of num text, eg:
// quinhentos = 500 = 3 = 2 zeros.

// TODO 2:
// Support for hundreds, mil, dois mil, tres mil etc...

package stringToInt;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class numberTextValues{

    protected String value;
    Map<String, String[]> textMap;

    public void generateArray() {

        String[] normalNumbs = {
            "zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove",
            "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa",
            "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seicentos", "setecentos", "oitocentos", "novecentos",
            "mil"
        };

        String[][] specialNumbs = {
            {"cento", "1", "3"},
            {"onze", "11", "2"}, {"doze", "12", "2"}, {"treze", "13", "2"}, {"quatorze", "14", "2"}, {"quinze", "15", "2"}, {"desesseis", "16", "2"},
            {"dessessete", "17", "2"}, {"dezoito", "18", "2"}, {"dezenove", "19", "2"}
        };

        textMap = new HashMap<>();

        int numValue = 0;
        int digits = 1;
        for (int i = 0; i < normalNumbs.length; i++) {
            String[] list = {String.valueOf(numValue), String.valueOf(digits)};

            textMap.put(normalNumbs[i], list);

            numValue++;
            if (numValue > 9) {
                numValue = 1;
                digits+=1;
            }

        }

        for (int i = 0; i < specialNumbs.length; i++) {
            String[] numInfo = {specialNumbs[i][1], specialNumbs[i][2]};
            textMap.put(specialNumbs[i][0], numInfo);
        }

    }

    public String getNumber(String value) {
        String[] numbers = value.split(" e ");

        int arraySize = Integer.parseInt(textMap.get(numbers[0])[1]);

        char[] finalNum = new char[arraySize];
        Arrays.fill(finalNum, '0');

        for (String numTxt : numbers) {
            int i = Integer.parseInt(textMap.get(numTxt)[1]);
            int inv_i = Math.abs(i-arraySize);

            char[] numValue = textMap.get(numTxt)[0].toCharArray();

            if (numValue.length >= 2) {
                finalNum = numValue;
                break;
            }

            System.out.println(i);
            System.out.println(inv_i);
            System.out.println(arraySize);

            finalNum[inv_i] = numValue[0];
        }

        return String.valueOf(finalNum);
    }

    public void main(String[] args) {
        generateArray();

    }
}