#include<stdio.h>
#include<stdlib.h>

void merge(int[], int, int, int);
void mergesort(int[], int, int);

int main()
{
  int n, l=0,r;
  printf("Enter size\n");
  scanf("%d",&n);           //n to store the size of array
  int a[n];                 //declare the array

  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

  mergesort(a, 0, n-1);             //call merge sort
  printf("The sorted array is:\n");

  for(int i=0;i<n;i++)
    printf("%d ",a[i]);

  return 0;
}

void mergesort(int arr[], int l, int r)
{
  if(l<r)
  {
    int mid=(l+r)/2;                //divide the array and get midpoint
    mergesort(arr, l, mid);         //call mergesort with lefthalf
    mergesort(arr, mid+1, r);       //call mergesort with righthalf
    merge(arr, l, mid, r);          //merge the left and right part
  }
}

void merge(int ar[],int l, int m, int r)
{
  int len1, len2, i, j, k;
  len1=m-l+1;       //size of left array
  len2=r-m;         //size of right array

  int a1[len1+1], a2[len2+1];

  for(i=0;i<len1;i++)
    a1[i]=ar[l+i];        //get left array from 0 to mid
  for(j=0;j<len2;j++)
    a2[j]=ar[m+1+j];    //get right array from mid+1 to r

    a1[i]=9999;
    a2[j]=9999;

  i=0,j=0;
  for(k=l;k<=r;k++)
  {
    if(a1[i] <= a2[j])
    {
      ar[k]=a1[i];
      i++;
    }
    else
    {
      ar[k]=a2[j];
      j++;
    }
  }
}
