import java.util.Random;

public class QuickSort {


    private static void swap(int[] array, int i, int j){
        int v = array[i];
        array[i] = array[j];
        array[j] = v;
    }
    private static int partition(int[] array, int lo, int hi){
        int i = lo, j = hi, temp = array[i];
        while (i < j){
            while (i < j && array[j] >= temp) j--;
            swap(array, i, j);
            while (i < j && array[i] <= temp) i++;
            swap(array, i, j);
        }
        array[i] = temp;
        return i;
    }

    private static void quickSort(int[] array, int lo, int hi){
        if (lo >= hi) return;
        int pivot = partition(array, lo, hi);
        quickSort(array, lo, pivot-1);
        quickSort(array, pivot+1, hi);
    }

    public static void quickSort(int[] array){
        quickSort(array, 0, array.length-1);
    }


    public static void main(String[] args) {
        Random random = new Random();
        int n = 100_000_0;
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(Integer.MAX_VALUE);
        }
        quickSort(array);
        for (int i = 0; i < n-1; i++) {
            if (array[i] > array[i+1])
                throw new IllegalArgumentException("sort error");
        }
        System.out.println("sort success");
    }
}
