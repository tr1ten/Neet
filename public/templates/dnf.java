import java.util.Arrays;

public class dnf {
    //sort the array of 0 ,1 and 2 using dutch national flag algo

    static void sort(int a[], int arr_size)
    {
        int lo = 0;
        int hi = arr_size - 1;
        int mid = 0, temp = 0;

        while (mid <= hi) {


        switch (a[mid]) {
            // If the element is 0
            case 0 -> {
                temp = a[lo];
                a[lo] = a[mid];
                a[mid] = temp;
                lo++;
                mid++;
                break;
            }
            case 1 -> mid++;
            case 2 -> {
                temp = a[mid];
                a[mid] = a[hi];
                a[hi] = temp;
                hi--;
                break;
            }
        }
        }
    }
    public static void main(String[] args){


        int [] arr = new int[]{0,1,1,0,2,1,1,1,2,2,2,0,2,1};
        int n = arr.length;

        sort(arr, n);
        System.out.println(Arrays.toString(arr));

    }
}
