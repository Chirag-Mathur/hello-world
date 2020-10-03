import java.util.*;
import java.util.concurrent.*; 

public class binary
{
    public static void main(String[] args)
    {
        long timeToSleep = 1L; 
        TimeUnit time = TimeUnit.SECONDS;
        Random rand = new Random();
        // Scanner scan = new Scanner(System.in);
        int n = 10000;
        System.out.println(n);
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
// A 9045, 9120, 9300, 9435, 9785
// B 9280, 9375, 9560, 9955 ,10240 
// C 9410, 9531, 9686, 10276, 10370
        Arrays.sort(C);
        int key = rand.nextInt(4000);
        long total_time = 0;
        long start_time, end_time;
        for(int k = 0; k < 30; ++k)
        {
            start_time = System.nanoTime();
            int left = 0;
            int right = n - 1;
            int mid = (left + right) / 2;
            while(left <= right)
            {
                if(C[mid] == key)
                {
                    break;
                }
                else if(C[mid] > key)
                {
                    right = mid - 1;
                    mid = (left + right) / 2;
                }
                else
                {
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
            }

            end_time = System.nanoTime();
            total_time += (end_time - start_time);
            try{
                time.sleep(timeToSleep);
            } 
            catch(InterruptedException e)
            {
                System.out.println("Interrupted");
            }
        }
        long average_time = total_time / 30;
        System.out.printf("%d micro seconds \n", average_time);
    }
}