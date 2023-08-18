//wap using quick sort algorithm

#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<dos.h>
#define max 500
using namespace std;
void qsort(int[], int ,int);
int partition (int[],int ,int);
int main()
{
	int a[max],i,n;
	clock_t s,e,z;
	s=clock();
	cout<<"Enter the value of n";
	cin>>n;
	for(i=0;i<n;i++)
	a[i]=rand()%300;
	cout<<"\n The array elements before sorting\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";
	qsort(a,0,n-1);
	cout<<"\n elements of the array after sorting are:\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";
	e=clock();
	z=e-s;
	cout<<"\n time taken:"<<z/CLOCKS_PER_SEC<<" seconds";
}
void qsort (int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		qsort(a,low,j-1);
		qsort(a,j+1,high);
	}
}
int partition(int a[],int low,int high)
{
	int pivot,i,j,temp;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(pivot>a[i] && i<=high)
		i++;
		while(pivot<a[j])
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[j];
			a[j]=a[low];
			a[low]=temp;
			return j;
		}
	}
}
