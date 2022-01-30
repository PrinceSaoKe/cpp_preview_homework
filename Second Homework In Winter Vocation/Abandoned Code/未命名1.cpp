#include <fstream>
#include <iostream>
using namespace std;

int IPCompare(long long part1,long long part2,long long partA,long long partB,int IP_num);
void ReturnIP_A(long long IP_A,long long *part1,long long *part2);
void ReturnIP_1B(FILE *rule,int *IP_num,long long *partA,long long *partB);
void ReturnIP_2B(FILE *rule,int *IP_num,long long *partA,long long *partB);
void ReturnRange(FILE *rule,int *min,int *max);
int CompareCTP(FILE *rule,int CTP_A);

int main()
{
	FILE *packet1,*rule1,*answer;
	long long int IP_1A,IP_2A,IP_1B,IP_2B,part1,part2,part3,part4,partA,partB,partC,partD;
	int DuanKou_1A,DuanKou_2A,CTP_A;
	int IP_num1,IP_num2;		//IP地址的位数
	int Flag=0,i=-1,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
	int min,max;
	
	packet1=fopen("C:/Users/Lenovo/Desktop/dataset/data/dataset1/packet1.txt","r");
	rule1=fopen("C:/Users/Lenovo/Desktop/dataset/data/dataset1/rule1.txt","r");
	answer=fopen("C:/Users/Lenovo/Desktop/answer.txt","w");
	
	while(!feof(packet1))
	{
		fscanf(packet1,"%lld",&IP_1A);
		fscanf(packet1,"%lld",&IP_2A);
		fscanf(packet1,"%d",&DuanKou_1A);
		fscanf(packet1,"%d",&DuanKou_2A);
		fscanf(packet1,"%d",&CTP_A);
		
		ReturnIP_A(IP_1A,&part1,&part2);
		ReturnIP_A(IP_2A,&part3,&part4);
		
		printf("\n\npart1:%lld part2:%lld ",part1,part2);//Debug
		printf("part3:%lld part4:%lld ",part3,part4);//Debug
		printf("%d ",DuanKou_1A);//Debug
		printf("%d ",DuanKou_2A);//Debug
		printf("%d\n",CTP_A);//Debug
		
		while(!feof(rule1))
		{
			i++;
			
			ReturnIP_1B(rule1,&IP_num1,&partA,&partB);
			printf("\n%d:\nrule1的原IP:%lld%lld IP_num1=%d\n",i,partA,partB,IP_num1);//Debug
			if(IPCompare(part1,part2,partA,partB,IP_num1))
				flag1=1;
			printf("flag1:%d\n",flag1);//Debug
			
			ReturnIP_2B(rule1,&IP_num2,&partC,&partD);
			printf("rule1的目的IP:%lld%lld IP_num2=%d\n",partC,partD,IP_num2);//Debug
			if(IPCompare(part3,part4,partC,partD,IP_num2))
				flag2=1;
			printf("flag2~4:%d ",flag2);//Debug
			
			ReturnRange(rule1,&min,&max);
			if(min<=DuanKou_1A&&DuanKou_1A<=max)
				flag3=1;
			printf("%d ",flag3);//Debug
			
			ReturnRange(rule1,&min,&max);
			if(min<=DuanKou_2A&&DuanKou_2A<=max)
				flag4=1;
			printf("%d ",flag4);//Debug
			
			if(CompareCTP(rule1,CTP_A))
				flag5=1;
			printf("%d\n",flag5);//Debug
			
			if(flag1&&flag2&&flag3&&flag4&&flag5)
			{
				fprintf(answer,"匹配项:%d\n",i);
				Flag=1;
				i=-1;
				flag1=0;
				flag2=0;
				flag3=0;
				flag4=0;
				flag5=0;
				break;
			}
			
			flag1=0;
			flag2=0;
			flag3=0;
			flag4=0;
			flag5=0;
		}
		
		if(Flag==0)
		{
			printf("找不到匹配\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		Flag=0;
	}
	
	return 0;
}

//--------分割线--------- 

int IPCompare(long long part1,long long part2,long long partA,long long partB,int IP_num)
{
	int i;
	long long x,y,m=1000000000000000;
	
	for(i=1;i<=IP_num;i++)
	{
		if(i<=16)
		{
			x=part1/m;
			part1=part1%m;
			y=partA/m;
			partA=partA%m;
			m=m/10;
			if(x!=y)
				return 0;
		}
		if(i==16)
			m=1000000000000000;
		if(i>16)
		{
			x=part2/m;
			part2=part2%m;
			y=partB/m;
			partB=partB%m;
			m=m/10;
			if(x!=y)
				return 0;
		}
	}
	
	return 1;
}



void ReturnIP_A(long long IP_A,long long *part1,long long *part2)
{
	int t;
	long long n,sum=0,i,k=1;
	n=IP_A;
	for(t=1;t<=32;t++)
	{
		i=n%2;
		n=n/2;
		sum=sum+i*k;
		k=k*10;
		if(t==16)
		{
			k=1;
			*part2=sum;
			sum=0;
		}
		else if(t==32)
		{
			*part1=sum;
		}
	}
}



void ReturnIP_1B(FILE *rule,int *IP_num,long long *partA,long long *partB)
{
	int a,b,c,d,i,t,sum=0,k=1;
	long long A,B,C,D;
	
	fscanf(rule,"@%d.%d.%d.%d/%d",&a,&b,&c,&d,IP_num);
	for(i=1;i<=8;i++)
	{
		t=a%2;
		a=a/2;
		sum=sum+t*k;
		k=k*10;
	}
	A=sum;
	//printf("A:%d",A);//Debug
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
	//printf("B:%d",B);//Debug
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
	//printf("C:%d",C);//Debug
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
	//printf("D:%d\n",D);//Debug
	*partA=A*100000000+B;
	*partB=C*100000000+D;
	//printf("partA:%lld ",*partA);//Debug
	//printf("partB:%lld\n",*partB);//Debug
}



void ReturnIP_2B(FILE *rule,int *IP_num,long long *partA,long long *partB)
{
	int a,b,c,d,i,t,sum=0,k=1;
	long long A,B,C,D;
	
	fscanf(rule,"%d.%d.%d.%d/%d",&a,&b,&c,&d,IP_num);
	for(i=1;i<=8;i++)
	{
		t=a%2;
		a=a/2;
		sum=sum+t*k;
		k=k*10;
	}
	A=sum;
	//printf("A:%d",A);//Debug
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
	//printf("B:%d",B);//Debug
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
	//printf("C:%d",C);//Debug
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
	//printf("D:%d\n",D);//Debug
	*partA=A*100000000+B;
	*partB=C*100000000+D;
	//printf("partA:%lld ",*partA);//Debug
	//printf("partB:%lld\n",*partB);//Debug
}



void ReturnRange(FILE *rule,int *min,int *max)
{
	fscanf(rule,"%d : %d",min,max);
}



int CompareCTP(FILE *rule,int CTP_A)
{
	int value,sign,a;
	fscanf(rule,"%X/%X\n",&value,&sign);
	if(sign==0x00)
		return 1;
	else if(sign==0xFF)
	{
		//先把value转为十进制数
		value=value%16;
		a=value/16;
		value=a*16+value;
		
		if(CTP_A==value)
			return 1;
		else
			return 0;
	}
	else
		printf("TCP既不是0x00也不是0xFF\n");
}
