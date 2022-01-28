#include <fstream>
#include <iostream>
using namespace std;

int IPCompare(long long IP_A,long long IP_B,int IP_num);
long long ReturnIP1(FILE *rule,int *IP_num);
long long ReturnIP2(FILE *rule,int *IP_num);
void ReturnRange(FILE *rule,int *min,int *max);
int CompareCTP(FILE *rule,int CTP_A);

int main()
{
	FILE *packet1,*rule1;
	long long int IP_1A,IP_2A,IP_1B,IP_2B;
	int DuanKou_1A,DuanKou_2A,CTP_A;
	int IP_num1,IP_num2;		//IP地址的位数
	int flag=0,i=-1,key;
	int min,max;
	
	packet1=fopen("C:/Users/Lenovo/Desktop/dataset/data/dataset1/packet1.txt","r");
	rule1=fopen("C:/Users/Lenovo/Desktop/dataset/data/dataset1/rule1.txt","r");
	
	while(!feof(packet1))
	{
		fscanf(packet1,"%lld",&IP_1A);
		fscanf(packet1,"%lld",&IP_2A);
		fscanf(packet1,"%d",&DuanKou_1A);
		fscanf(packet1,"%d",&DuanKou_2A);
		fscanf(packet1,"%d",&CTP_A);
		
		while(!feof(rule1))
		{
			i++;
			
			IP_1B=ReturnIP1(rule1,&IP_num1);
			printf("进入循环 %d\n",IP_num1);//Debug
			key=IPCompare(IP_1A,IP_1B,IP_num1);
			printf("%d",key);//Debug
			if(key==1)
			{
				printf("1");//Debug
				IP_2B=ReturnIP2(rule1,&IP_num2);
				if(IPCompare(IP_2A,IP_2B,IP_num2))
				{
					ReturnRange(rule1,&min,&max);
					if(min<=DuanKou_1A&&DuanKou_1A<=max)
					{
						ReturnRange(rule1,&min,&max);
						if(min<=DuanKou_2A&&DuanKou_2A<=max)
						{
							if(CompareCTP(rule1,CTP_A))
								flag=1;
						}
					}
				}
			}
		}
		
		printf("%d",flag);//Debug
		
		if(flag==0)
		{
			//说明匹配不到
			printf("-1");
		}
		else if(flag==1)
		{
			//说明匹配到了
			printf("%d",i);
		}
		
		i=-1;
		flag=0;
	}
	
	return 0;
}

//--------分割线--------- 

int IPCompare(long long IP_A,long long IP_B,int IP_num)
{
	printf("进入IPCompare\n");//Debug
	int i,x,y;
	long long int m=100000000000;
	
	for(i=1;i<=IP_num;i++)
	{
		x=IP_A/m;
		IP_A=IP_A%m;
		
		y=IP_B/m;
		IP_B=IP_B%m;
		
		m=m/10;
		
		printf("%d %d\n",x,y);//Debug
		
		if(x!=y)
			return 0;
	}
	
	return 1;
}



long long ReturnIP1(FILE *rule,int *IP_num)
{
	long long a,b,c,d;
	long long IP_1B;
	
	fscanf(rule,"@%d.%d.%d.%d/%d",&a,&b,&c,&d,IP_num);
	IP_1B=a*1000000000+b*1000000+c*1000+d;
	printf("%lld \n",IP_1B);//Debug
	
	return IP_1B;
}



long long ReturnIP2(FILE *rule,int *IP_num)
{
	long long a,b,c,d;
	long long IP_2B;
	
	fscanf(rule,"%d.%d.%d.%d/%d",&a,&b,&c,&d,IP_num);
	IP_2B=a*1000000000+b*1000000+c*1000+d;
	
	return IP_2B;
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
