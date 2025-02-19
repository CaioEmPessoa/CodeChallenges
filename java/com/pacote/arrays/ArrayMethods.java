package com.pacote.arrays;
import java.util.Arrays;

public class ArrayMethods {
    public int[] gerarRange(int rangeSize) {
        int[] range;
        range = new int[rangeSize];

        for (int i = rangeSize-1; i >= 0; i--) {
            range[i] = i;
        }

        return range;
    } 
    
    public char[] listaFixa() {
        char phrase[] = {'o', 'i', ' ', 't', 'd', ' ', 'b', 'e', 'm', '?'};
        
        return phrase;
    }

    public static void main(String[] args) {
        ArrayMethods arrayMethods = new ArrayMethods(); 

        int[] arrayOne = arrayMethods.gerarRange(10);
        char[] arrayTwo = arrayMethods.listaFixa();

        System.out.println(Arrays.toString(arrayOne));
        System.out.println(Arrays.toString(arrayTwo));

    }
}
