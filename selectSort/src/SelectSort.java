import java.util.Random;

public class SelectSort {

    private static void swap(int[] array, int i, int j){
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }

    public static void sort(int[] array){
        int n = array.length;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++){
                if (array[j] < array[min])
                    min = j;
            }
            swap(array, i, min);
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        int n = 100_000;
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(Integer.MAX_VALUE);
        }
        sort(array);
        for (int i = 0; i < n-1; i++) {
            if (array[i] > array[i+1])
                throw new IllegalArgumentException("sort error");
        }
        System.out.println("sort success");
    }
}
