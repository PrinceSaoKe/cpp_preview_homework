#include <stdio.h>
#include <stdlib.h>

void ReadPacketData(FILE *Packet,FILE *PacketIP1InTwo,FILE *PacketIP2InTwo);
void ChangeLongLongToTwo(long long IP,FILE *PacketInTwo);

int main()
{
    FILE *Packet,*PacketInTwo,*Rule,*RuleInTwo;
    FILE *PacketIP1InTwo,*PacketIP2InTwo;
    int PacketDateID=0,RuleDateID=0,i=-1;
    int RuleDuanKou1List[10000],RuleDuanKou2List[10000];

    Packet=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/dataset/data/dataset1/packet1.txt","r");
    Rule=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/dataset/data/dataset1/rule1.txt","r");
    PacketIP1InTwo=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP1InTwo.txt","w");
    PacketIP2InTwo=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP2InTwo.txt","w");

    if(Packet==NULL||PacketInTwo==NULL)
        printf("Failed To Open Files!\n");
    else
        printf("Succeeded To Open Files!\n");

    while (!feof(Packet))
    {
        ReadPacketData(Packet,PacketIP1InTwo,PacketIP2InTwo);

        i++;//Debug
    }

    printf("%d",i);//Debug
    
    return 0;
}

//-----------------分割线---------------------

//读取数据包并将其输出为PacketInTwo.txt
void ReadPacketData(FILE *Packet,FILE *PacketIP1InTwo,FILE *PacketIP2InTwo)
{
    long long packetIP1,packetIP2;
    int PacketDuanKou1,PacketDuanKou2,PacketCTP;

    fscanf(Packet,"%lld %lld %d %d %d",&packetIP1,&packetIP2,&PacketDuanKou1,&PacketDuanKou2,&PacketCTP);

    ChangeLongLongToTwo(packetIP1,PacketIP1InTwo);
    ChangeLongLongToTwo(packetIP2,PacketIP2InTwo);
    //SaveDuanKou(RuleDuanKou1,&RuleDuanKou1List[0]);
    //SaveDuanKou(RuleDuanKou2,&RuleDuanKou2List[0]);
}



//把IP转化为超过long long长度的二进制数
void ChangeLongLongToTwo(long long IP,FILE *PacketInTwo)
{
    int i;
    long long t;
    int IPInTwo[32]={0};

    for(i=31;i>=0;i--)
    {
        t=IP%2;
        IP=IP/2;
        IPInTwo[i]=t;
    }

    for(i=0;i<32;i++)
    {
        fprintf(PacketInTwo,"%d",IPInTwo[i]);
        if((i+1)%32==0)
            fprintf(PacketInTwo,"\n");
    }
}



//将端口储存到数组中
//void SaveDuanKou(int DuanKou,int *DuanKouList)
//{
    
//}



//读取规则集并将其输出为RuleInTwo.txt
//void ReadRuleData(FILE *Rule,int *RuleDuanKou1List)
//{
//    int a,b,c,d;

//    fscanf(Rule,"@%d.%d.%d.%d/%d",&a,&b,&c,&d,RuleDuanKou1List);
//    RuleDuanKou1List++;
//}