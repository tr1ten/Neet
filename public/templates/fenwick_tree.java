class fenw{


    void update(long [] farr, int idx, long val, int n){
        while(idx<n){
            farr[idx]+=val;
            idx = idx + ((idx)&(-idx));
        }
    }

    long  sum(long [] farr, int idx ){
        long res=0;
        while(idx>0){
            res+=farr[idx];
            idx = idx - ((idx)&(-idx));
        }
        return res;
    }


}
public class fenwick_tree {

    public static void main(String [] args){
        long [] arr = new long[] {0,4,-3,2,6,7,8,14,-9};

        fenw f = new fenw();
        int n = arr.length;
        long [] farr = new long [n];
        for(int i=1;i<n;i++){
            f.update(farr,i,arr[i],n);
        }
        System.out.println(f.sum(farr,5));
        System.out.println("sum between idx 3 to 5 is :"+(f.sum(farr,5)-f.sum(farr,3)));

    }

}
