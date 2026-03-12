#include <stdio.h>
#include <stdlib.h>

int heap[100];
int size = 0;

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(int i)
{
    while(i>0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[(i-1)/2],&heap[i]);
        i=(i-1)/2;
    }
}

void heapifyDown(int i)
{
    int smallest,left,right;

    while(1)
    {
        left=2*i+1;
        right=2*i+2;
        smallest=i;

        if(left<size && heap[left] < heap[smallest])
            smallest=left;

        if(right<size && heap[right] < heap[smallest])
            smallest=right;

        if(smallest!=i)
        {
            swap(&heap[i],&heap[smallest]);
            i=smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[size]=x;
    heapifyUp(size);
    size++;

    int i;
    printf("After insertion MinHeap elements are:");
    for(i=0;i<size;i++)
        printf("%d ",heap[i]);
    printf("\n");
}

void deleteMin()
{
    if(size==0)
        return;

    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
}

void display()
{
    int i;
    printf("Heap elements:");
    for(i=0;i<size;i++)
        printf(" %d",heap[i]);
    printf("\n");
}

void heapSort()
{
    int temp[100];
    int n=size;
    int i;

    for(i=0;i<n;i++)
        temp[i]=heap[i];

    printf("Sorted elements:");
    for(i=0;i<n;i++)
    {
        printf(" %d",heap[0]);
        deleteMin();
    }
    printf("\n");

    for(i=0;i<n;i++)
        heap[i]=temp[i];

    size=n;
}

int main()
{
    int choice,n,i,x;

    while(1)
    {
        printf("1. Insert in Min Heap\n");
        printf("2. Delete from Min Heap\n");
        printf("3. Display Heap\n");
        printf("4. Perform Heap Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of elements to be insert in Min Heap: ");
                scanf("%d",&n);
                printf("Enter elements to insert in Min Heap: ");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&x);
                    insert(x);
                }
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                display();
                break;

            case 4:
                heapSort();
                break;

            case 5:
                exit(0);
        }
    }
}
