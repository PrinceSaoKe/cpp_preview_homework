#include <fstream>
#include <iostream>
using namespace std;

long long int ReturnIP1(FILE *rule,int *a,int *b,int *c,int *d);
long long int ReturnIP2(FILE *rule,int *A,int *B,int *C,int *D);
void ReturnRange1(FILE *rule,int *Min,int *Max);
void ReturnRange2(FILE *rule,int *Min,int *Max);
int ReturnTCP(FILE *rule);
long long int DecimalToBinary(int Decimal);
int BinaryToDecimal(int Binary);

int main()
{
	FILE *rule1 = fopen("C:/Users/Lenovo/Desktop/dataset/data/dataset1/rule1.txt","r");
	int i=1,j=0;
	long long int IP;
	int Min,Max,TCP;
	int a,b,c,d;
	int A,B,C,D; 
	while(!feof(rule1))
	{
		if(i%5==1)
		{
			IP=ReturnIP1(rule1,&a,&b,&c,&d);
			printf("%d:  %d.%d.%d.%d  ",j,a,b,c,d);
		}
		else if(i%5==2)
		{
			IP=ReturnIP2(rule1,&A,&B,&C,&D);
			printf("%d.%d.%d.%d  ",A,B,C,D);
		}
		else if(i%5==3)
		{
			ReturnRange1(rule1,&Min,&Max);
			printf("%d %d ",Min,Max);
		}
		else if(i%5==4)
		{
			ReturnRange2(rule1,&Min,&Max);
			printf("%d %d ",Min,Max);
		}
		else if(i%5==0)
		{
			TCP=ReturnTCP(rule1);
			printf("%d\n",TCP);
			j++;
		}
		i++;
	} 
	
	return 0;
}

long long int ReturnIP1(FILE *rule,int *a,int *b,int *c,int *d)
{
	int e,IP=0;
	fscanf(rule,"@%d.%d.%d.%d/%d",a,b,c,d,&e);
	//IP=a;
	
	return IP;
}

long long int ReturnIP2(FILE *rule,int *A,int *B,int *C,int *D)
{
	int a,b,c,d,e,IP;
	fscanf(rule,"%d.%d.%d.%d/%d",A,B,C,D,&e);
	//IP=a;
	
	return IP;
}

void ReturnRange1(FILE *rule,int *Min,int *Max)
{
	int min,max;
	fscanf(rule,"%d : %d",Min,Max);
}

void ReturnRange2(FILE *rule,int *Min,int *Max)
{
	int min,max;
	fscanf(rule,"%d : %d",Min,Max);
}

int ReturnTCP(FILE *rule)
{
	unsigned int value,flag;
	fscanf(rule,"%X/%X\n",&value,&flag);
	if(flag==0xFF)
		return value;
	else if(flag==0x00)
		return -1;
	else
		printf("TCP既不是0x00也不是0xFF");
}
