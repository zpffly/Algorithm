import java.util.Random;

public class MergeSort {

    //merge array[left, mid]和array[mid+1, right]
    private static void merge(int[] array, int[] temp, int left, int mid, int right){
        int i = left, j = mid + 1;
        for (int k = left; k <= right; ++k){
            //左边用完
            if (i > mid)
                temp[k] = array[j++];
            //右边用完
            else if (j > right)
                temp[k] = array[i++];
            else if (array[i] > array[j])
                temp[k] = array[j++];
            else
                temp[k] = array[i++];
        }
        //将排序后的 temp -> array
        System.arraycopy(temp, left, array, left, right-left+1);
    }

    //自顶向下归并排序
    private static void mergeSort1(int[] array, int[] temp, int left, int right){
        if (right <= left)
            return;
        int mid = left + (right - left) / 2;
        mergeSort1(array, temp, left, mid);
        mergeSort1(array, temp, mid+1, right);
        merge(array, temp, left, mid, right);
    }

    public static void mergeSort1(int[] array){
        int[] temp = new int[array.length];
        mergeSort1(array, temp, 0, array.length-1);
    }

    public static void main(String[] args) {
        Random random = new Random();
        int n = 100_000_0;
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(Integer.MAX_VALUE);
        }
        mergeSort1(array);

        for (int i = 0; i < n-1; i++) {
            if (array[i] > array[i+1])
                throw new IllegalArgumentException("sort error");
        }
        System.out.println("sort success");
    }


}
