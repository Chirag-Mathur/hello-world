// Prim's Algorithm in Java

import java.util.Arrays;

class PGraph {

  public void Prim(int G[][], int V) {

    int INF = 9999999;

    int no_edge; 
    boolean[] selected = new boolean[V];

    Arrays.fill(selected, false);
    no_edge = 0;
    selected[0] = true;
    System.out.println("Edge : Weight");

    while (no_edge < V - 1) 
    {
      int min = INF;
      int x = 0; 
      int y = 0; 

      for (int i = 0; i < V; i++)
      {
        if (selected[i] == true) 
        {
          for (int j = 0; j < V; j++) {
            if (!selected[j] && G[i][j] != 0)
            {
              if (min > G[i][j]) {
                min = G[i][j];
                x = i;
                y = j;
              }
            }
          }
        }
      }
      System.out.println(x + " - " + y + " :  " + G[x][y]);
      selected[y] = true;
      no_edge++;
    }
  }

  public static void main(String[] args) {
    PGraph g = new PGraph();

    int V = 3;
    int[][] G = { { 2, 3, 4}, { 3, 6, 5}, { 4, 5, 7} };
    long starttime = System.nanoTime();
    g.Prim(G, V);
    long lasttime = System.nanoTime();
	System.out.println((lasttime-starttime)/1000);

  }
}
