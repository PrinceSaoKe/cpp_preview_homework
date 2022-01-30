#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SaveIP(long long IP,FILE *file);
void SaveDuanKou(int DuanKou,FILE *file);
void SaveCTP(int CTP,FILE *file);
void SaveRuleIP(int a,int b,int c,int d,FILE *file);
void SaveRuleWeiShu(int WeiShu,FILE *file);
void SaveMinAndMax(int min,int max,FILE *file);
void SaveDuanKouAndFlag(int DuanKou,int DuanKouFlag,FILE *file);

int main()
{
    FILE *Packet=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/dataset/data/dataset1/packet1.txt","r");
    FILE *Rule=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/dataset/data/dataset1/rule1.txt","r");
    if(Packet!=NULL&&Rule!=NULL)
        printf("Succeeded To Open File!");

    FILE *PacketIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP1.txt","w");
    FILE *PacketIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP2.txt","w");
    FILE *PacketDuanKou1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou1.txt","w");
    FILE *PacketDuanKou2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou2.txt","w");
    FILE *PacketCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketCTP.txt","w");

    FILE *RulePartFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RulePart.txt","wt+");
    FILE *RuleIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP1.txt","w");
    FILE *RuleIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP2.txt","w");
    FILE *RuleWeiShu1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu1.txt","w");
    FILE *RuleWeiShu2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu2.txt","w");
    FILE *RuleMinAndMax1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMinAndMax1.txt","w");
    FILE *RuleMinAndMax2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMinAndMax2.txt","w");
    FILE *RuleDuanKouAndFlagFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleDuanKouAndFlag.txt","w");
    FILE *RuleCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTP.txt","w");

    int i,PacketDuanKou1,PacketDuanKou2,PacketCTP;
    long long PacketIP1,PacketIP2;
    int a,b,c,d,e,f,g,h,WeiShu1,WeiShu2,min1,max1,min2,max2,RuleDuanKou,RuleDuanKouFlag;
    char j[33]={0},k[33]={0},l[33]={0};
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0,flag11=0;

    for(i=0;!feof(Packet);i++)
    {
        fscanf(Packet,"%lld %lld %d %d %d",&PacketIP1,&PacketIP2,&PacketDuanKou1,&PacketDuanKou2,&PacketCTP);

        SaveIP(PacketIP1,PacketIP1File);
        SaveIP(PacketIP2,PacketIP2File);
        SaveDuanKou(PacketDuanKou1,PacketDuanKou1File);
        SaveDuanKou(PacketDuanKou2,PacketDuanKou2File);
        SaveCTP(PacketCTP,PacketCTPFile);
    }

    for(i=0;!feof(Rule);i++)
    {
        fscanf(Rule,"@%d.%d.%d.%d/%d%d.%d.%d.%d/%d%d : %d%d : %d%X/%X\n",&a,&b,&c,&d,&WeiShu1,&e,&f,&g,&h,&WeiShu2,&min1,&max1,&min2,&max2,&RuleDuanKou,&RuleDuanKouFlag);

        SaveRuleIP(a,b,c,d,RuleIP1File);
        SaveRuleIP(e,f,g,h,RuleIP2File);
        SaveRuleWeiShu(WeiShu1,RuleWeiShu1File);
        SaveRuleWeiShu(WeiShu2,RuleWeiShu2File);
        SaveMinAndMax(min1,max1,RuleMinAndMax1File);
        SaveMinAndMax(min2,max2,RuleMinAndMax2File);
        SaveDuanKouAndFlag(RuleDuanKou,RuleDuanKouFlag,RuleDuanKouAndFlagFile);
    }

    //要加双重循环
    fscanf(PacketIP1File,"%s",j);
    fscanf(RuleIP1File,"%s",k);
    if(strcmp(j,k)==0)
        flag1=1;
    
    fscanf(PacketIP2File,"%s",j);
    fscanf(RuleIP2File,"%s",k);
    if(strcmp(j,k)==0)
        flag2=1;

    fscanf(PacketDuanKou1File,"%s",j);
    fscanf(RuleMinAndMax1File,"%s",k);
    if(strcmp(j,k)==0)
        flag3=1;

    fscanf(PacketDuanKou2File,"%s",j);
    fscanf(RuleMinAndMax2File,"%s",k);
    if(strcmp(j,k)==0)
        flag4=1;

    fscanf(PacketCTPFile,"%s",j);
    fscanf(RuleDuanKouAndFlagFile,"%s",k);
    fscanf(RuleDuanKouAndFlagFile,"%s",l);
    //if(strcmp(j,k)==0)
    //    flag5=1;

    return 0;
}



void SaveIP(long long IP,FILE *file)
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
        fprintf(file,"%d",IPInTwo[i]);
        if((i+1)%32==0)
            fprintf(file,"\n");
    }
}



void SaveDuanKou(int DuanKou,FILE *file)
{
    fprintf(file,"%d\n",DuanKou);
}



void SaveCTP(int CTP,FILE *file)
{
    fprintf(file,"%d\n",CTP);
}



void SaveRuleIP(int a,int b,int c,int d,FILE *file)
{
    char list[8]={0};
    int i,t;

    for(i=7;i>=0;i--)
    {
        t=a%2;
        a=a/2;
        list[i]=t;
    }
    for(i=0;i<8;i++)
    {
        fprintf(file,"%d",list[i]);
    }
    for(i=0;i<8;i++)
        list[i]=0;

    for(i=7;i>=0;i--)
    {
        t=b%2;
        b=b/2;
        list[i]=t;
    }
    for(i=0;i<8;i++)
    {
        fprintf(file,"%d",list[i]);
    }
    for(i=0;i<8;i++)
        list[i]=0;

    for(i=7;i>=0;i--)
    {
        t=c%2;
        c=c/2;
        list[i]=t;
    }
    for(i=0;i<8;i++)
    {
        fprintf(file,"%d",list[i]);
    }
    for(i=0;i<8;i++)
        list[i]=0;

    for(i=7;i>=0;i--)
    {
        t=d%2;
        d=d/2;
        list[i]=t;
    }
    for(i=0;i<8;i++)
    {
        fprintf(file,"%d",list[i]);
    }
    for(i=0;i<8;i++)
        list[i]=0;

    fprintf(file,"\n");
}



void SaveRuleWeiShu(int WeiShu,FILE *file)
{
    fprintf(file,"%d\n",WeiShu);
}



void SaveMinAndMax(int min,int max,FILE *file)
{
    fprintf(file,"%d\n",min);
    fprintf(file,"%d\n",max);
}



void SaveDuanKouAndFlag(int DuanKou,int DuanKouFlag,FILE *file)
{
    fprintf(file,"%X\n",DuanKou);
    fprintf(file,"%X\n",DuanKouFlag);
}