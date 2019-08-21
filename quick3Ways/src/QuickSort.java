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
        int n = 100_000_00;
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(10000);
        }
        long start = System.nanoTime();
        Quick3Way.quick3Way(array);
        long end = System.nanoTime();
        System.out.println("quick 3 way time: " + (end-start)/1000000000.0 + "s");

        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(10000);
        }
        start = System.nanoTime();
        quickSort(array);
        end = System.nanoTime();
        System.out.println("quick 2 way time: " + (end-start)/1000000000.0+ "s");
    }
}
