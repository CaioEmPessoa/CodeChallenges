// TODO:
// Store size of num text, eg:
// quinhentos = 500 = 3 = 2 zeros.

// TODO 2:
// Support for hundreds, mil, dois mil, tres mil etc...

package stringToInt;

import java.util.HashMap;
import java.util.Map;

public class numberTextValues{

    protected String value;
    Map<String, String> textMap;

    public void generateArray() {

        String[] normalNumbs = {
            "zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove",
            "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa",
            "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seissentos", "setessentos", "oitossentos", "novessentos"
        };

        String[][] specialNumbs = {
            {"cento", "1", "3"},
            {"onze", "11", "2"}, {"doze", "12", "2"}, {"treze", "13", "2"}, {"quatorze", "14", "2"}, {"quinze", "15", "2"}, {"desesseis", "16", "2"},
            {"dessessete", "17", "2"}, {"dezoito", "18", "2"}, {"dezenove", "19", "2"}
        };

        textMap = new HashMap<>();

        int numValue = 0;
        for (int i = 0; i<normalNumbs.length; i++) {
            textMap.put(normalNumbs[i], String.valueOf(numValue));
            numValue++;
            if (numValue > 9) {
                numValue = 1;
            }

        }

        for (int i = 0; i < specialNumbs.length; i++) {
            textMap.put(specialNumbs[i][0], specialNumbs[i][1]);
        }

    }

    public String getNumber(String value) {
        String[] numbers = value.split(" e ");
        String finalNum = "";

        for (String numTxt : numbers) {
            finalNum += textMap.get(numTxt);
        }

        return finalNum;
    }

    public void main(String[] args) {
        generateArray();

    }
}