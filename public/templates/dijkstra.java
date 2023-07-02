import java.util.*;

class Pair implements Comparable<Pair> {
    long first;
    int second;

    public Pair(long first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair other) {
        return Long.compare(this.first, other.first);
    }
}

public class dijkstra {

    static final long INF = (long) 1e15;

    public static int[] dijsktra(int S, ArrayList<Pair>[] adj) {
        int n = adj.length;
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        int[] par = new int[n];
        Arrays.fill(par, -1);
        dist[S] = 0;
        par[S] = S;
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(0, S));

        while (!pq.isEmpty()) {
            Pair u = pq.poll();
            if (u.first > dist[u.second]) continue;
            for (Pair v : adj[u.second]) {
                if (dist[v.second] > dist[u.second] + v.first) {
                    dist[v.second] = dist[u.second] + v.first;
                    par[v.second] = u.second;
                    pq.add(new Pair(dist[v.second], v.second));
                }
            }
        }
        return par; // or dist according to needs
    }



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int D = n - 1;
        int S = 0;
        ArrayList<Pair>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        while (m-- > 0) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            long w = scanner.nextLong();
            adj[u].add(new Pair(w, v));
            adj[v].add(new Pair(w, u));
        }
        int[] par = dijsktra(S, adj);
        if (par[D] == -1) {
            System.out.println(-1);
        } else {
            int u = par[D];
            ArrayList<Integer> path = new ArrayList<>();
            path.add(D);
            while (path.get(path.size() - 1) != S) {
                path.add(u);
                u = par[u];
            }
            Collections.reverse(path);
            for (int node : path) {
                System.out.print((node + 1) + " ");
            }
        }
    }

}
