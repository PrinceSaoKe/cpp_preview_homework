#include <stdio.h>
/*int main()
{
	int t;
	long long n,sum=0,part1,part2,i,k=1;
	
	scanf("%lld",&n);
	for(t=1;t<=32;t++)
	{
		i=n%2;
		n=n/2;
		sum=sum+i*k;
		k=k*10;
		if(t==16)
		{
			k=1;
			part2=sum;
			sum=0;
		}
		else if(t==32)
			part1=sum;
	}
	printf("%lld%lld",part1,part2);
	return 0;
}*/


/*
int main()
{
	int i,t,sum=0,a,b,c,d,IP_num,k=1,A,B,C,D;
	
	scanf("%d.%d.%d.%d/%d",&a,&b,&c,&d,&IP_num);
	
	for(i=1;i<=8;i++)
	{
		t=a%2;
		a=a/2;
		sum=sum+t*k;
		k=k*10;
	}
	A=sum;
	sum=0;
	k=1;
	for(i=1;i<=8;i++)
	{
		t=b%2;
		b=b/2;
		sum=sum+t*k;
		k=k*10;
	}
	B=sum;
	sum=0;
	k=1;
	for(i=1;i<=8;i++)
	{
		t=c%2;
		c=c/2;
		sum=sum+t*k;
		k=k*10;
	}
	C=sum;
	sum=0;
	k=1;
	for(i=1;i<=8;i++)
	{
		t=d%2;
		d=d/2;
		sum=sum+t*k;
		k=k*10;
	}
	D=sum;
	sum=0;
	k=1;
	printf("%d%d%d%d",A,B,C,D);
	
	return 0;
}*/

int main()
{
	FILE *answer;
	answer=fopen("C:/Users/Lenovo/Desktop/answer.txt","w");
	fprintf(answer,"%d\n",0);
	return 0;
}
