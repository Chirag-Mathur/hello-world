import java.util.*;

class Quick
{
    void quickSort(ArrayList<Float> arr, int start, int end)
    {
        if(start < end)
        {
            int pivot_position = partioning(arr, start, end);
            // System.out.println(pivot_position);
            quickSort(arr, start, pivot_position - 1);
            quickSort(arr, pivot_position + 1, end);
        }
    }

    int partioning(ArrayList<Float> arr,int start,int end)
    {
        float pivot = arr.get(start);
        float temp;
        int i = start;
        int j = end + 1;
        while(i < j)
        {
            do
            {
                ++i;
            }while(i <= end && arr.get(i) <= pivot);


            do
            {
                --j;
            }while(arr.get(j) > pivot);

            if(i < j)
            {
                temp = arr.get(i);
                arr.set(i, arr.get(j));
                arr.set(j, temp); 
            }
        }
        arr.set(start, arr.get(j));
        arr.set(j, pivot);
        return j;  
    }
}
class Bucket
{
    void bucketSort(float A[], int n)
    {

        Quick quick_obj = new Quick();
        //Creating 10 buckets as the base used is 10
        @SuppressWarnings("unchecked")
        ArrayList<Float>[] buckets = new ArrayList[10];
        //Stores size of each bucket
        int buckets_size[] = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i < 10; ++i)
        {
            buckets[i] = new ArrayList<Float>();
        }

        //Storing our array elements in the buckets
        for(int i = 0; i < n; ++i)
        {
            buckets[(int)A[i] * 10].add(A[i]);
            ++buckets_size[(int)A[i] * 10];
        }

        // Sorting each bucket using quick sort
        for(int i = 0; i < 10; ++i)
        {
            quick_obj.quickSort(buckets[i], 0, buckets_size[i] - 1);
        }

        int current_index = 0;
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < buckets_size[i]; ++j)
            {
                A[current_index] = buckets[i].get(j);
                ++current_index;
            }
        }
    }
}

class Q3Bucket
{
    public static void main(String[] args)
    {
        Bucket obj = new Bucket();
        Random rand = new Random();
        int n = 10000;
        float A[] = new float[n];
        for(int i = 0; i < n; ++i)
        {
            A[i] = rand.nextFloat();
        }
        long start_time, end_time;
        start_time = System.nanoTime();
        obj.bucketSort(A, n);
        end_time = System.nanoTime();
        System.out.println(((float)end_time - start_time) / 1000);
    }
}