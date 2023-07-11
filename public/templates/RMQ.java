import java.util.Scanner;
/**
 * Range Minimum Query
 * Find the minimum element in a range of an array
 * Preprocessing: O(NlogN)
 * Query: O(1)
 * @param arr - input array
 */
class RMQ { 
    int[][] m;
    RMQ(int[] arr){
        // preprocessing
        int N = arr.length;
        int LOG = (int)Math.floor((Math.log(N)/Math.log(2)));
        m = new int[N][LOG+1];
        for (int i = 0; i < N; i++) m[i][0] = arr[i]; // base case for size 1 subarrays
        for (int j = 1; j <= LOG; j++) {
            for (int i = 0; i < N-(1<<j)+1; i++) m[i][j] = Math.min(m[i][j-1], m[i+(1<<(j-1))][j-1]);
        }
    }
    // Find min in range [L,R]
    int query(int L,int R){
        int len = R-L+1;
        int j = (int)Math.floor((Math.log(len)/Math.log(2)));
        return Math.min(m[L][j], m[R-(1<<j)+1][j]);
    }
    public static void main(String[] args) {
        // testing
        // take input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) arr[i] = sc.nextInt();
        RMQ rmq = new RMQ(arr);
        for (int i = 0; i < Q; i++) {
            int L = sc.nextInt()-1;
            int R = sc.nextInt()-1;
            System.out.println(rmq.query(L, R));
        }
        sc.close();
        
    }
}
