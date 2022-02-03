#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SaveIP(long long IP,FILE *file);
void SaveDuanKou(int DuanKou,FILE *file);
void SaveCTP(int CTP,FILE *file);
void SaveRuleIP(int a,int b,int c,int d,FILE *file);
void SaveRuleWeiShu(int WeiShu,FILE *file);
void SaveMinAndMax(int m,FILE *file);
void SaveCTPAndFlag(int n,FILE *file);
int Compare(char *PacketIP,char *RuleIP,int WeiShu);

int main()
{
    FILE *Packet=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/dataset/data/dataset1/packet1.txt","r");
    FILE *Rule=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/dataset/data/dataset1/rule1.txt","r");
    if(Packet!=NULL&&Rule!=NULL)
        printf("Succeeded To Open File!\n");

    FILE *PacketIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP1.txt","w");
    FILE *PacketIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP2.txt","w");
    FILE *PacketDuanKou1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou1.txt","w");
    FILE *PacketDuanKou2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou2.txt","w");
    FILE *PacketCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketCTP.txt","w");

    FILE *RuleIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP1.txt","w");
    FILE *RuleIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP2.txt","w");
    FILE *RuleWeiShu1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu1.txt","w");
    FILE *RuleWeiShu2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu2.txt","w");
    FILE *RuleMin1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMin1.txt","w");
    FILE *RuleMax1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax1.txt","w");
    FILE *RuleMin2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMin2.txt","w");
    FILE *RuleMax2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax2.txt","w");
    FILE *RuleCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTP.txt","w");
    FILE *RuleCTPFlagFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTPFlag.txt","w");

    FILE *AnswerFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Answer.txt","w");
    FILE *TestFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/Test.txt","w");

    int i,j,PacketDuanKou1,PacketDuanKou2,PacketCTP;
    long long PacketIP1,PacketIP2;
    int a,b,c,d,e,f,g,h,WeiShu1,WeiShu2,min1,max1,min2,max2,RuleCTP,RuleCTPFlag;
    char PacketIP1Array[32]={0},PacketIP2Array[32]={0},RuleIP1Array[32]={0},RuleIP2Array[32]={0};
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;

    for(i=0;!feof(Packet);i++)
    {
        fscanf(Packet,"%lld %lld %d %d %d\n",&PacketIP1,&PacketIP2,&PacketDuanKou1,&PacketDuanKou2,&PacketCTP);

        SaveIP(PacketIP1,PacketIP1File);
        SaveIP(PacketIP2,PacketIP2File);
        SaveDuanKou(PacketDuanKou1,PacketDuanKou1File);
        SaveDuanKou(PacketDuanKou2,PacketDuanKou2File);
        SaveCTP(PacketCTP,PacketCTPFile);
    }

    for(i=0;!feof(Rule);i++)
    {
        fscanf(Rule,"@%d.%d.%d.%d/%d%d.%d.%d.%d/%d%d : %d%d : %d%X/%X\n",&a,&b,&c,&d,&WeiShu1,&e,&f,&g,&h,&WeiShu2,&min1,&max1,&min2,&max2,&RuleCTP,&RuleCTPFlag);

        SaveRuleIP(a,b,c,d,RuleIP1File);
        SaveRuleIP(e,f,g,h,RuleIP2File);
        SaveRuleWeiShu(WeiShu1,RuleWeiShu1File);
        SaveRuleWeiShu(WeiShu2,RuleWeiShu2File);
        SaveMinAndMax(min1,RuleMin1File);
        SaveMinAndMax(max1,RuleMax1File);
        SaveMinAndMax(min2,RuleMin2File);
        SaveMinAndMax(max2,RuleMax2File);
        SaveCTPAndFlag(RuleCTP,RuleCTPFile);
        SaveCTPAndFlag(RuleCTPFlag,RuleCTPFlagFile);
    }

    fclose(PacketIP1File);
    fclose(PacketIP2File);
    fclose(PacketDuanKou1File);
    fclose(PacketDuanKou2File);
    fclose(PacketCTPFile);

    fclose(RuleIP1File);
    fclose(RuleIP2File);
    fclose(RuleWeiShu1File);
    fclose(RuleWeiShu2File);
    fclose(RuleMin1File);
    fclose(RuleMax1File);
    fclose(RuleMin2File);
    fclose(RuleMax2File);
    fclose(RuleCTPFile);
    fclose(RuleCTPFlagFile);

    PacketIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP1.txt","r");
    PacketIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP2.txt","r");
    PacketDuanKou1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou1.txt","r");
    PacketDuanKou2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou2.txt","r");
    PacketCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketCTP.txt","r");

    RuleIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP1.txt","r");
    RuleIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP2.txt","r");
    RuleWeiShu1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu1.txt","r");
    RuleWeiShu2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu2.txt","r");
    RuleMin1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMin1.txt","r");
    RuleMax1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax1.txt","r");
    RuleMin2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMin2.txt","r");
    RuleMax2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax2.txt","r");
    RuleCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTP.txt","r");
    RuleCTPFlagFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTPFlag.txt","r");

    for(i=0;!feof(PacketIP1File);i++)
    {
        fscanf(PacketIP1File,"%s",PacketIP1Array);
        printf("packetIP1:\n");//Debug
        puts(PacketIP1Array);//Debug
        fscanf(PacketIP2File,"%s",PacketIP2Array);
        printf("packetIP2:\n");//Debug
        puts(PacketIP2Array);//Debug
        fscanf(PacketDuanKou1File,"%d",&PacketDuanKou1);
        fscanf(PacketDuanKou2File,"%d",&PacketDuanKou2);
        fscanf(PacketCTPFile,"%d",&PacketCTP);

        for(j=0;!feof(RuleIP1File);j++)
        {
            fscanf(RuleIP1File,"%s",RuleIP1Array);
            fscanf(RuleWeiShu1File,"%d",&WeiShu1);
            if(Compare(&PacketIP1Array[0],&RuleIP1Array[0],WeiShu1))
                flag1=1;
            printf("flag: %d",flag1);//Debug

            fscanf(RuleIP2File,"%s",RuleIP2Array);
            fscanf(RuleWeiShu2File,"%d",&WeiShu2);
            if(Compare(&PacketIP2Array[0],&RuleIP2Array[0],WeiShu2))
                flag2=1;
            printf("%d",flag2);//Debug

            fscanf(RuleMin1File,"%d",&min1);
            fscanf(RuleMax1File,"%d",&max1);
            if(min1<=PacketDuanKou1&&PacketDuanKou1<=max1)
                flag3=1;
            printf("%d",flag3);//Debug

            fscanf(RuleMin2File,"%d",&min2);
            fscanf(RuleMax2File,"%d",&max2);
            if(min2<=PacketDuanKou2&&PacketDuanKou2<=max2)
                flag4=1;
            printf("%d",flag4);//Debug

            fscanf(RuleCTPFile,"%d",&RuleCTP);
            fscanf(RuleCTPFlagFile,"%d",&RuleCTPFlag);
            if(RuleCTPFlag==0)
                flag5=1;
            else if(RuleCTPFlag==255&&RuleCTP==PacketCTP)
                flag5=1;
            else if(RuleCTPFlag!=0&&RuleCTPFlag!=255)
                printf("Neither 0x00 nor 0xFF!\n");
            printf("%d\n",flag5);//Debug

            if(flag1&&flag2&&flag3&&flag4&&flag5)
            {
                fprintf(AnswerFile,"%d\n",j);
                //flag1=0;
                //flag2=0;
                //flag3=0;
                //flag4=0;
                //flag5=0;
                //break;
            }
            else
            {
                flag1=0;
                flag2=0;
                flag3=0;
                flag4=0;
                flag5=0;
            }

            printf("J: %d\n",j);//Debug
        }
    }

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



void SaveMinAndMax(int m,FILE *file)
{
    fprintf(file,"%d\n",m);
}



void SaveCTPAndFlag(int n,FILE *file)
{
    int a,b;

    a=n%16;
    b=n/16;
    n=a+b*16;

    fprintf(file,"%d\n",n);
}



int Compare(char *PacketIP,char *RuleIP,int WeiShu)
{
    int i;
    for(i=0;i<WeiShu;i++)
    {
        if(*PacketIP!=*RuleIP)
            return 0;
        PacketIP++;
        RuleIP++;
    }
    return 1;
}