#include<iostream>
using namespace std;
void bubsort(int arr[], int n){
   if (n == 1)
      return;
   for (int i=0; i<n-1; i++)
      if (arr[i] > arr[i+1])
   swap(arr[i], arr[i+1]);
   bubsort(arr, n-1);
}
main() {
   int array[] = {54, 74, 98, 154, 98, 32, 20, 13, 35, 40};
   int n = sizeof(array)/sizeof(array[0]);
   cout << "Sorted Sequence ";
   bubsort(array, n);
   for(int i = 0; i <n;i++){
      cout << array[i] << " ";
   }
}
