#include<stdio.h>
int main()
{
	int arr[]={2,43,11,9,4,12,1,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("Maximum number:%d\n",max);
	return 0;
}
