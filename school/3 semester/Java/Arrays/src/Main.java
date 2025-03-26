

public class Main {
    public static int[] add(int[] array, int value){

        int size = array.length;
        int[] newArray = new int[size];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        newArray[size] = value;
        return newArray
    }

    public static void main(String[] args) {
        int[] lista = {1, 2, 3, 4, 5};

        lista = add(lista, 5);

        for (int i = 0; i < lista.length; i++) {
            char ponto = i == lista.length-1 ? ',' : '.';
            System.out.println(lista[i] + ponto);
        }
    }
}