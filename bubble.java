import java.util.*;
import java.util.concurrent.*; 

public class bubble
{
    public static void main(String[] args)
    {
        long timeToSleep = 2L;
        TimeUnit time = TimeUnit.SECONDS;
        Random rand = new Random();
        int n = 10000;
        int[] C = new int[n];
        int[] A = new int[n];
        int[] B = new int[n];
        for(int i = 0; i < n; ++i)
        {
            C[i] = rand.nextInt(20000);
        }

        for(int i = 0; i < n; ++i)
        {
            A[i] = C[i];
        }
        //Sorting array A in increasing order using JAVA's built in Arrays.sort()  
        Arrays.sort(A);

        for(int i = 0; i < n; ++i)
        {
            B[i] = A[n - (i + 1)];
        }
    
        long total_time = 0;
        long start_time, end_time;
        int num;
        int pass = 0;
        int swap; // Helps us to check if array is already sorted or not
        start_time = System.nanoTime();
        for(int i = n - 1; i >= 0; --i)
        {
            swap = 1;
            for(int j = 0; j < i; ++j)
            {
                if(B[j] > B[j + 1])
                {
                    num = B[j];
                    B[j] = B[j+1];
                    B[j+1] = num;
                    swap = 0;
                }
            }
            if(swap == 1)
            {
                break;
            }
        }
        end_time = System.nanoTime();
        total_time = end_time - start_time;
        System.out.println(total_time);
        // // for(int i = 0; i <= N - 1 ; ++i)
        // // {
        // //     swap = 1;
        // //     for(int j = 0; j <= N - 1 && j != n; ++j)
        // //     {
        // //         if(arr[j] > arr[j + 1])
        // //         {
        // //             num = arr[j];
        // //             arr[j] = arr[j + 1];
        // //             arr[j + 1] = num;
        // //             swap = 0;
        // //         }
        // //     }
        // //     if(swap == 1)
        // //     {
        // //         break;
        // //     }
        // //     N -= 1;
        // //     for(int j = 0; j < n; ++j)
        // //     {
        // //         System.out.printf("%d ", arr[j]); 
        // //     }
        // // } 

        // System.out.println("The sorted array is -");
        // for(int i = 0; i < n; ++i)
        // {
        //    System.out.printf("%d ", arr[i]); 
        // }
        // System.out.println();
    }   
}