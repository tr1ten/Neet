// source : https://algs4.cs.princeton.edu/24pq/IndexMinPQ.java.html
import java.util.Arrays;

/**
 * Min Priority Queue
 * @param Key - Generic Key for PQ array
 */
class IndexPriorityQueue<Key extends Comparable<Key>> {
    Key[] keys;
    int[] pq; 
    int[] qp;
    int N=0;
    IndexPriorityQueue(){}
    IndexPriorityQueue(int maxN){
        keys = (Key[]) new Comparable[maxN+1]; // no need of +1 in len since user index will be [0...N-1]
        pq = new int[maxN+1]; // actual priority queue wted by keys [1...N]
        qp = new int[maxN+1]; // map client key index to pq index that is inverse of pq [0...N-1]
        Arrays.fill(qp, -1);
        Arrays.fill(pq, -1);
    }
    // i, j are the indices shown to client
    // no need to swap actual keys
    private void swap(int i,int j){
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }
    // key of pq[i] < key of pq[j] ?
    boolean less(int i,int j){
        return (keys[pq[i]].compareTo(keys[pq[j]])<0);
    }
    // start from k, go up the tree maintaining the heap property
    private void swim(int k){
        while (k>1 && less(k, k/2)) {
            swap(k/2, k);                
            k /=2;
        }
    }
    // start from k, go down tree maintaining the heap property
    private void sink(int k){
        while (2*k<=N) {
            int child = 2*k;
            if(child<N && less(child+1, child)) child++;
            if(!less(child, k)) break;
            swap(child, k);
            k = child;
        }
    }
    public void insert(int index,Key k){
        pq[++N] = index;
        qp[index] = N;
        keys[index] = k;
        swim(N);
    }
    public int peek() {return pq[1];}
    public int extractMin(){
        int min = pq[1]; // save min from top
        swap(1, N--); // replace top with last element
        sink(1); // restore heap property
        assert min==pq[N+1];
        qp[min] = -1;
        pq[N+1] = -1; // avoid loitering 
        // keys[min] = null; 
        return min;
    }
    public void increaseKey(int index,Key newKey){
        if(newKey.compareTo(keys[index])<0) throw new IllegalArgumentException("Key must be greator than previous key");
        keys[index] =newKey;
        sink(qp[index]);
    }
    public void decreaseKey(int index,Key newKey){
        if(newKey.compareTo(keys[index])>0) throw new IllegalArgumentException("Key must be less than previous key");
        keys[index] = newKey;
        swim(qp[index]);
    }   
    public boolean isEmpty(){return N==0;}
    public Key keyOf(int index){return keys[index];}
    public boolean contains(int index){return qp[index]!=-1;}
    // Unit testing
    public static void main(String[] args) {
        IndexPriorityQueue<Integer> pq = new IndexPriorityQueue<>(4);
        pq.insert(2,0);
        pq.insert(3,1);
        pq.insert(1,2);
        pq.insert(10,3);
        pq.increaseKey(0, 4);
        pq.decreaseKey(3, -1);
        while (!pq.isEmpty()) {
            System.out.println(pq.keyOf(pq.extractMin()));
        }

    }
}
