import java.util.*;

class Count
{
    void countingSort(int[] A, int[] B, int n)
    {
        int r = A[0];
        for(int i = 1; i < n; ++i)
        {
            if(A[i] > r)
            {
                r = A[i];
            }
        }
        int C[] = new int[r + 1];
        for(int i = 0; i < r + 1; ++i)
        {
            C[i] = 0;
        }
        
        for(int i = 0; i < n; ++i)
        {
            C[A[i]] += 1;
        }
        for(int i = 1; i < r + 1; ++i)
        {
            C[i] += C[i - 1]; 
        }
        for(int i = n - 1; i >= 0; --i)
        {
            B[C[A[i]] - 1] = A[i];
            C[A[i]] -= 1;
        }
    }
}

class Q1Count
{
    public static void main(String[] args)
    {   
        Count obj = new Count();
        Random rand = new Random();
        int n = 10000;
        int A[] = new int[n];
        int B[] = new int[n];
        for(int i = 0; i < n; ++i)
        {
            A[i] = rand.nextInt(100);
        }
        long start_time, end_time;
        start_time = System.nanoTime();
        obj.countingSort(A, B, n);
        end_time = System.nanoTime();
        System.out.println(end_time - start_time);
    }
}