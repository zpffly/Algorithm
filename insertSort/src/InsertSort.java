import java.util.Arrays;
import java.util.Random;

public class InsertSort {

    private static void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void insertSort(int[] array){
        int n = array.length;
        for (int i = 1; i < n; i++) {
            int v = array[i];
            int j = i-1;
            while (j >= 0 && array[j] > v){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = v;
        }
    }


    public static void main(String[] args) {
        Random random = new Random();
        int n = 100_000;
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(Integer.MAX_VALUE);
        }
        insertSort(array);
        for (int i = 0; i < n-1; i++) {
            if (array[i] > array[i+1])
                throw new IllegalArgumentException("sort error");
        }
        System.out.println("sort success");
//        int[] array = {1,4,6,3,8};
//        insertSort(array);
//        Arrays.stream(array).forEach(System.out::println);
    }
}
