//wap using merge sort algorithm

#include<time.h>
#include<stdlib.h>
#include<iostream>
#define max 100
using namespace std;
void mergesort(int[100],int ,int);
void merge(int[100],int ,int,int);
int a[max];
int main()
{
	int i,n;
	clock_t s,e,z;
	s=clock();
	cout<<"Enter the no.of elements\n";
	cin>>n;
	cout<<"Elements of the array before sorting\n";
	for(i=0;i<n;i++)
	{
		a[i]=rand()%1000;
		cout<<a[i]<<"\t";
	}
	mergesort(a,0,n-1);
	cout<<"\n Elements of the arrrya after sorting\n";
	for(i=0;i<n;i++)
	
	
	cout<<a[i]<<"\t";
	e=clock();
	z=e-s;
	cout<<"\n the time taken="<<z%CLOCKS_PER_SEC<<"seconds";
   
	}
	void mergesort(int a [100],int low,int high)
	{
		int mid;
		if(high>low)
		{
	mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
		}
	}

void merge(int a[100],int low,int mid,int high)
{
	int h=low,j=mid+1,i=low,b[max],k;
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else 
		{
			b[i]=a[j];
			j=j+1;
			
		}
		i=i+1;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	a[k]=b[k];
}

