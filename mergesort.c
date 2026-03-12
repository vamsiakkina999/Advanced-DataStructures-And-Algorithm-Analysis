#include<stdio.h>
void divide(int a[],int l,int r);
void merge(int a[],int l,int m,int r);
int n;
int main()
{
	int a[10],i;
	printf("Enter the number of elements to be sorted : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	divide(a,0,n-1);
	printf("\nSorted array is : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
void divide(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		divide(a,l,m);
		divide(a,m+1,r);
		merge(a,l,m,r);
	}
}
void merge(int a[],int l,int m,int r)
{
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		 L[i]=a[l+i]; 
	}
		for(j=0;j<n2;j++)
	{
		 R[j]=a[m+1+j]; 
	}
	i=0,j=0,k=l;
	  while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}	
}
	
