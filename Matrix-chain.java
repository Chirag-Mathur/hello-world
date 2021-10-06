package matrix_chain;
import java.util.*;
public class Min_mul 
{
	
	int matOrder(int array[], int n) 
	{
		   int minMul[][] = new int[n][n];         
		   for (int i=1; i<n; i++)
		      minMul[i][i] = 0;          
		   for (int length=2; length<n; length++) 
		   {       
		      for (int i=1; i<n-length+1; i++) 
		      {
		         int j = i+length-1;
		         minMul[i][j] = Integer.MAX_VALUE;     
		         for (int k=i; k<=j-1; k++)
		         {
		            int q = minMul[i][k] + minMul[k+1][j] + array[i- 1]*array[k]*array[j];
		            if (q < minMul[i][j])
		               minMul[i][j] = q;
		         }
		      }
		   }
		   return minMul[1][n-1];
		}
	public static void main(String args[])
	{
		int n;
		System.out.println("Enter size of arrray");
		Scanner sc =  new Scanner(System.in);
		n=sc.nextInt();
		int p[] =  new int[n];
		System.out.println("Enter elements in an array");
		for(int i=0;i<n;i++)
		{
			p[i]= sc.nextInt();
		}
		 Min_mul obj = new  Min_mul ();
		   System.out.println("Minimum number of matrix multiplications:" + obj.matOrder(p, n));
	}



}
