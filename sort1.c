#include <stdio.h>
#include <stdlib.h>
#include "timer_nrp.h"

// Function to return the initial value in the array.
int findpivot(int *arr,int l)
{
	return arr[l];
}
// Function to perform partition.
int partition(int *arr, int l, int h)
{
	int pivot,i,j,t;
	pivot=findpivot(arr,l);
	i=l;
	j=h+1;
	while(1) 
	{
 		do
		{
		 i++;
		}while(arr[i]<=pivot && i<h);
		do
		{
		 j--;
		}while(arr[j]>pivot);
		if(i<j)
		{
		 t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;	
		}
		else
		{
		 t=arr[l];
		 arr[l]=arr[j];
		 arr[j]=t;
		 return j;
		}
	}
}		

// Function to perform quick Sort.
void quickSort(int *arr, int p,int r)
{
	int q;
	if(r>p)
	{
	q=partition(arr,p,r);
	quickSort(arr,p,q-1);
	quickSort(arr,q+1,r);
	}
}


// Function to perform Bubble Sort.
void bubbleSort(int *arr, int size)
{
	int i,j,temp;

	for (i=0; i < (size-1); i++)
    	{
        	for (j = 0; j < (size - 1 -i); j++)
        	{
            		if (arr[j] < arr[j+1])
            		{
                		temp = arr[j];
                		arr[j] = arr[j+1];
                		arr[j+1] = temp;
            		}
        	}
    	}
}

main(int argc, char **argv)
{
	int size;

	// Check command line arguments for number of elements.
	if (argc > 2)
	{
		printf(" Need one argument. Ignoring the rest.\n");
		size = atoi(argv[1]);
	}
	else if (argc == 2)
	{
		size = atoi(argv[1]);
	}
	else 
	{
		printf("Need one argument i.e. number of elements.\n");
		exit(3);
	}

	printf(" Experimenting with %d elements \n", size);

	// Allocate memory.
	int *arr = (int *)malloc(size* sizeof(int));
	if (arr == NULL)
	{
		printf(" Error allocating %d elements\n",size);
		exit(1);
	}

	// Generate random elements.
	int i,j;
	int temp;
	for(i=0; i < size; i++)
	{
		arr[i] = random() % 3465787;
	}


	// Bubble sort with timer enabled.
	double bubbleTime;
	timeStart();
	bubbleSort(arr,size);
	bubbleTime = timeStop("Bubble finish\n");
 
	// Verify whether the array is sorted.
	for (i=0; i < (size-1); i++)
	{
		if (arr[i] < arr[i+1])
		{
			printf("Descending order violation at index %d \n", i);
			exit(2);
		}
	}

	// Dump the actual time taken.
	FILE *sortFile = fopen("bubbleData.txt", "a");
	fprintf(sortFile, "%d  %f\n", size, bubbleTime);
	fclose(sortFile);


	// quickSort with timer enabled
	double quicktime;
	timeStart();
	quickSort(arr,0,size-1);
	quicktime = timeStop("quick finish\n");


	//dumping the actual time taken.
	FILE *sortfile = fopen("quickdata.txt","a");
	fprintf(sortfile,"%d %f\n",size,quicktime);
	fclose(sortfile);

}
