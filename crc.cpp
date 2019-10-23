#include<iostream>
using namespace std;
int gp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,10};

void checksum(int temp[], int dw[], int size)
{
	int i=1;
	for(;i<=size;++i)
	{
		if(temp[0]==1)
		{
			for(int j=1;j<17;++j)
				temp[j-1]=temp[j]^gp[j];
		}
		else
		{
			for(int j=1;j<17;++j)
				temp[j-1]=temp[j]^0;
		}

		if(i==size)
			return;

		temp[16]=dw[i+16];
	}
}

int main()
{
	int size,i,j;
	cout<<"\nEnter size of dataword :";
	cin>>size;

	cout<<"\nEnter dataword (1 by 1)";
	int dw[size+16];
	
	for(i=0;i<size;++i)
		cin>>dw[i];

	for(;i<size+16;++i)
		dw[i]=0;

	cout<<"\nModified dataword is :";
	for(i=0;i<size+16;++i)
		cout<<dw[i];

	cout<<"\n";

	int temp[17];
	for(int i=0;i<17;++i)
		temp[i]=dw[i];

	checksum(temp,dw,size);

	cout<<"\nChecksum is : ";
	for(i=0;i<16;++i)
		cout<<temp[i];
	cout<<"\n";


	for(i=size,j=0;i<size+16;++i)
		dw[i]=temp[j++];

	cout<<"\nSent dataword is :";
	for(i=0;i<size+16;++i)
		cout<<dw[i];

	cout<<"\n";


	int check=0;
	cout<<"\nWant  to check error?(1/0)";
	cin>>check;

	if(check==1)
	{
		int pos,flag=0;
		cout<<"\nEnter position to introduce error !!! ";
		cin>>pos;

		dw[pos-1]=dw[pos-1]&0;
		
		for(int i=0;i<17;++i)
			temp[i]=dw[i];

		checksum(temp,dw,size);

		cout<<"\nChecksum is : ";
		for(i=0;i<16;++i)
		{	
			cout<<temp[i];
			if(temp[i]==1)
				flag=-1;
		}
		cout<<"\n";
		if (flag==-1 )
			cout<<"\n Error detected";
		else 
			cout<<"\n Error not detected";
	}
	else
	{
		int flag=0;
		for(int i=0;i<17;++i)
			temp[i]=dw[i];

		checksum(temp,dw,size);

		cout<<"\nChecksum is : ";
		for(i=0;i<16;++i)
		{	
			cout<<temp[i];
			if(temp[i]==1)
				flag=-1;
		}
		cout<<"\n";
		if (flag==-1 )
			cout<<"\n Error detected";
		else 
			cout<<"\n Error not detected";		
	}

	
}