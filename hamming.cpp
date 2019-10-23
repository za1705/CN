#include<iostream>
using namespace std;
void check_parity(int p[],int rec_bits[])
{
	p[0]=(rec_bits[0]+rec_bits[2]+rec_bits[4]+rec_bits[6])%2;
	p[1]=(rec_bits[1]+rec_bits[2]+rec_bits[5]+rec_bits[6])%2;
	p[2]=(rec_bits[3]+rec_bits[4]+rec_bits[5]+rec_bits[6])%2;
	cout<<p[0]<<p[1]<<p[2]<<"\n";
}
int main()
{
	int data[4],i;
	cout<<"\n Enter 4 bits of data (1 by 1) :";
	for(i=3;i>=0;--i)
		cin>>data[i];

	int red_bits[3];

	red_bits[0]=(data[0]+data[1]+data[3])%2;
	red_bits[1]=(data[0]+data[2]+data[3])%2;
	red_bits[2]=(data[1]+data[2]+data[3])%2;
	cout<<red_bits[2]<<" "<<red_bits[1]<<" "<<red_bits[0]<<"\n";
	int sent_dw[7];
	sent_dw[0]=red_bits[0];
	sent_dw[1]=red_bits[1];
	sent_dw[2]=data[0];
	sent_dw[3]=red_bits[2];
	sent_dw[4]=data[1];
	sent_dw[5]=data[2];
	sent_dw[6]=data[3];

	cout<<"\n Sent dataword is: ";
	for(i=6;i>=0;--i)
		cout<<sent_dw[i];

	cout<<"\n";



	cout<<"\n Enter recieved bits(1 by 1) : ";
	int rec_bits[7];
	for(i=6;i>=0;--i)
		cin>>rec_bits[i];


	int parity[3]={0};

	check_parity(parity,rec_bits);
	cout<<parity[0]<<" "<<parity[1]<<" "<<parity[2]<<"\n";
	if((parity[0]==0)&&(parity[1]==0)&&(parity[2]==0))
		cout<<"\n No error in transmission ";
	else
	{	int pos=0;
		for(i=6;i>=0;--i)
		{
			if(sent_dw[i]!=rec_bits[i])
				{
					pos=i+1;
					i=-1;
				}
		}
		cout<<"\n Error at position : "<<pos;
		cout<<"\n Sent dataword is: ";
		for(i=6;i>=0;--i)
			cout<<sent_dw[i];

		cout<<"\n";
		cout<<"\n Data recieved  is: ";
		for(i=6;i>=0;--i)
			cout<<rec_bits[i];

		cout<<"\n";

	}

	

}