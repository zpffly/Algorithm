//三路划分快排
public class Quick3Way {

    private static void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }




    //array[lo, lt-1] < v=array[lt, gt] < array[gt+1, hi]
    private static void quick3Way(int[] array, int lo, int hi){
        if (lo >= hi) return;
        int lt = lo, i = lo + 1, gt = hi;
        int v = array[lo];
        while (i <= gt){
            if (array[i] < v)
                swap(array, lt++, i++);
            else if (array[i] > v)
                swap(array, i, gt--);
            else
                i++;
        }
        quick3Way(array, lo, lt-1);
        quick3Way(array, gt+1, hi);
    }

    public static void quick3Way(int[] array){
        quick3Way(array, 0, array.length-1);
    }
}
