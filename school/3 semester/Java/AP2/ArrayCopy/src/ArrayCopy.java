class ArrayCopy {
    public static void main(String[] arguments) {
        int[] array1 = {7, 4, 8, 1, 4, 1, 4};
        float[] array2 = new float[array1.length];
        
        System.out.print("array1: [ ");
        for (int num : array1) {         // não tenho certeza se foi ensinado em aula
            System.out.print(num + " ");
        }
        System.out.println("]");
        
        System.out.print("array2: [ ");
        for (int j = 0; j < array1.length && array1[j] != 1; j++) {
            array2[j] = (float) array1[j];
            System.out.print(array2[j] + " ");
        }
        System.out.println("]");
    }
}

// ORIGINAL
/*
class ArrayCopier {
    public static void main(String[] arguments) {
        int[] array1 = { 7, 4, 8, 1, 4, 1, 4 };
        float[] array2 = new float[array1.length];
        
        System.out.print("array1: [ ");
        for (int i = 0; i < array1.length; i++) {
            System.out.print(array1[i] + " ");
        }
        System.out.println("]");
        
        System.out.print("array2: [ ");
        int count = 0;
        while (count < array1.length && array1[count] != 1) {
            array2[count] = (float) array1[count];
            System.out.print(array2[count++] + " ");
        }
        System.out.println("]");
    }
}
*/