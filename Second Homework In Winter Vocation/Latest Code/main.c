#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SaveIP(long long IP,FILE *file);                   //将数据集的IP进行处理后存储为 Debugging Data 中的 PacketIP1.txt 和 PacketIP2.txt 的函数
void SaveDuanKou(int DuanKou,FILE *file);               //将数据集的端口进行处理后存储为 Debugging Data 中的 PacketDuanKou1.txt 和 PacketDuanKou2.txt 的函数
void SaveTCP(int TCP,FILE *file);                       //将数据集的协议号进行处理后存储为 Debugging Data 中的 PacketTCP.txt 的函数
void SaveRuleIP(int a,int b,int c,int d,FILE *file);    //将规则集的IP进行处理后存储为 Debugging Data 中的 RuleIP1.txt 和 RuleIP2.txt 的函数
void SaveRuleWeiShu(int WeiShu,FILE *file);             //将规则集的IP位数进行处理后存储为 Debugging Data 中的 RuleWeiShu1.txt 和RuleWeiShu2.txt 的函数
void SaveMinAndMax(int m,FILE *file);                   //将规则集的端口进行处理后存储为 Debugging Data 中的 RuleMin1.txt、RuleMax1.txt、RuleMin2.txt和RuleMax2.txt 的函数
void SaveTCPAndFlag(int n,FILE *file);                  //将规则集的协议号进行处理后存储为 Debugging Data 中的 RuleTCP.txt 和 RuleTCPFlag.txt 的函数
int Compare(char *PacketIP,char *RuleIP,int WeiShu);    //将数据集的IP与规则集的IP进行相应位数的匹配的函数
int CheckAnswer(FILE *MyAnswer,FILE *ReferenceAnswer);  //检查我的答案与参考答案是否相符的函数

int main()
{
    //打开或创建文件
    FILE *Packet=fopen("../dataset/data/dataset1/packet1.txt","r");
    FILE *Rule=fopen("../dataset/data/dataset1/rule1.txt","r");
    if(Packet!=NULL&&Rule!=NULL)
        printf("Succeeded To Open File!\n");

    FILE *PacketIP1File=fopen("../Debugging Data/PacketIP1.txt","w");
    FILE *PacketIP2File=fopen("../Debugging Data/PacketIP2.txt","w");
    FILE *PacketDuanKou1File=fopen("../Debugging Data/PacketDuanKou1.txt","w");
    FILE *PacketDuanKou2File=fopen("../Debugging Data/PacketDuanKou2.txt","w");
    FILE *PacketTCPFile=fopen("../Debugging Data/PacketTCP.txt","w");

    FILE *RuleIP1File=fopen("../Debugging Data/RuleIP1.txt","w");
    FILE *RuleIP2File=fopen("../Debugging Data/RuleIP2.txt","w");
    FILE *RuleWeiShu1File=fopen("../Debugging Data/RuleWeiShu1.txt","w");
    FILE *RuleWeiShu2File=fopen("../Debugging Data/RuleWeiShu2.txt","w");
    FILE *RuleMin1File=fopen("../Debugging Data/RuleMin1.txt","w");
    FILE *RuleMax1File=fopen("../Debugging Data/RuleMax1.txt","w");
    FILE *RuleMin2File=fopen("../Debugging Data/RuleMin2.txt","w");
    FILE *RuleMax2File=fopen("../Debugging Data/RuleMax2.txt","w");
    FILE *RuleTCPFile=fopen("../Debugging Data/RuleTCP.txt","w");
    FILE *RuleTCPFlagFile=fopen("../Debugging Data/RuleTCPFlag.txt","w");

    FILE *Packet1AnswerFile=fopen("../MyAnswers/Packet1Answer.txt","w");
    FILE *ReferenceAnswerFile=fopen("../dataset/data/dataset1/ans1.txt","r");

    //定义变量
    int i,j,PacketDuanKou1,PacketDuanKou2,PacketTCP;
    long long PacketIP1,PacketIP2;
    int a,b,c,d,e,f,g,h,WeiShu1,WeiShu2,min1,max1,min2,max2,RuleTCP,RuleTCPFlag;
    char PacketIP1Array[33]={0},PacketIP2Array[33]={0},RuleIP1Array[33]={0},RuleIP2Array[33]={0};
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,Flag=0;

    //处理数据集
    for(i=0;!feof(Packet);i++)
    {
        fscanf(Packet,"%lld %lld %d %d %d\n",&PacketIP1,&PacketIP2,&PacketDuanKou1,&PacketDuanKou2,&PacketTCP);

        SaveIP(PacketIP1,PacketIP1File);
        SaveIP(PacketIP2,PacketIP2File);
        SaveDuanKou(PacketDuanKou1,PacketDuanKou1File);
        SaveDuanKou(PacketDuanKou2,PacketDuanKou2File);
        SaveTCP(PacketTCP,PacketTCPFile);
    }

    //处理规则集
    for(i=0;!feof(Rule);i++)
    {
        fscanf(Rule,"@%d.%d.%d.%d/%d%d.%d.%d.%d/%d%d : %d%d : %d%X/%X\n",&a,&b,&c,&d,&WeiShu1,&e,&f,&g,&h,&WeiShu2,&min1,&max1,&min2,&max2,&RuleTCP,&RuleTCPFlag);

        SaveRuleIP(a,b,c,d,RuleIP1File);
        SaveRuleIP(e,f,g,h,RuleIP2File);
        SaveRuleWeiShu(WeiShu1,RuleWeiShu1File);
        SaveRuleWeiShu(WeiShu2,RuleWeiShu2File);
        SaveMinAndMax(min1,RuleMin1File);
        SaveMinAndMax(max1,RuleMax1File);
        SaveMinAndMax(min2,RuleMin2File);
        SaveMinAndMax(max2,RuleMax2File);
        SaveTCPAndFlag(RuleTCP,RuleTCPFile);
        SaveTCPAndFlag(RuleTCPFlag,RuleTCPFlagFile);
    }

    //关闭文件
    fclose(PacketIP1File);
    fclose(PacketIP2File);
    fclose(PacketDuanKou1File);
    fclose(PacketDuanKou2File);
    fclose(PacketTCPFile);

    fclose(RuleIP1File);
    fclose(RuleIP2File);
    fclose(RuleWeiShu1File);
    fclose(RuleWeiShu2File);
    fclose(RuleMin1File);
    fclose(RuleMax1File);
    fclose(RuleMin2File);
    fclose(RuleMax2File);
    fclose(RuleTCPFile);
    fclose(RuleTCPFlagFile);

    //重新打开文件
    PacketIP1File=fopen("../Debugging Data/PacketIP1.txt","r");
    PacketIP2File=fopen("../Debugging Data/PacketIP2.txt","r");
    PacketDuanKou1File=fopen("../Debugging Data/PacketDuanKou1.txt","r");
    PacketDuanKou2File=fopen("../Debugging Data/PacketDuanKou2.txt","r");
    PacketTCPFile=fopen("../Debugging Data/PacketTCP.txt","r");

    RuleIP1File=fopen("../Debugging Data/RuleIP1.txt","r");
    RuleIP2File=fopen("../Debugging Data/RuleIP2.txt","r");
    RuleWeiShu1File=fopen("../Debugging Data/RuleWeiShu1.txt","r");
    RuleWeiShu2File=fopen("../Debugging Data/RuleWeiShu2.txt","r");
    RuleMin1File=fopen("../Debugging Data/RuleMin1.txt","r");
    RuleMax1File=fopen("../Debugging Data/RuleMax1.txt","r");
    RuleMin2File=fopen("../Debugging Data/RuleMin2.txt","r");
    RuleMax2File=fopen("../Debugging Data/RuleMax2.txt","r");
    RuleTCPFile=fopen("../Debugging Data/RuleTCP.txt","r");
    RuleTCPFlagFile=fopen("../Debugging Data/RuleTCPFlag.txt","r");

    //进行数据集和规则集的匹配
    for(i=0;!feof(PacketIP1File);i++)
    {
        //先读取一组数据
        fscanf(PacketIP1File,"%s\n",PacketIP1Array);
        fscanf(PacketIP2File,"%s\n",PacketIP2Array);
        fscanf(PacketDuanKou1File,"%d\n",&PacketDuanKou1);
        fscanf(PacketDuanKou2File,"%d\n",&PacketDuanKou2);
        fscanf(PacketTCPFile,"%d\n",&PacketTCP);
         
         //再按顺序读取每一条规则与数据进行比较
        for(j=0;!feof(RuleIP1File);j++)
        {
            //比较源IP
            fscanf(RuleIP1File,"%s\n",RuleIP1Array);
            fscanf(RuleWeiShu1File,"%d\n",&WeiShu1);
            if(Compare(PacketIP1Array,RuleIP1Array,WeiShu1))
                flag1=1;

            //比较目的IP
            fscanf(RuleIP2File,"%s\n",RuleIP2Array);
            fscanf(RuleWeiShu2File,"%d\n",&WeiShu2);
            if(Compare(PacketIP2Array,RuleIP2Array,WeiShu2))
                flag2=1;

            //比较源端口
            fscanf(RuleMin1File,"%d\n",&min1);
            fscanf(RuleMax1File,"%d\n",&max1);
            if(min1<=PacketDuanKou1&&PacketDuanKou1<=max1)
                flag3=1;

            //比较目的端口
            fscanf(RuleMin2File,"%d\n",&min2);
            fscanf(RuleMax2File,"%d\n",&max2);
            if(min2<=PacketDuanKou2&&PacketDuanKou2<=max2)
                flag4=1;

            //比较协议号
            fscanf(RuleTCPFile,"%d\n",&RuleTCP);
            fscanf(RuleTCPFlagFile,"%d\n",&RuleTCPFlag);
            if(RuleTCPFlag==0)
                flag5=1;
            else if(RuleTCPFlag==255&&RuleTCP==PacketTCP)
                flag5=1;
            else if(RuleTCPFlag!=0&&RuleTCPFlag!=255)
                printf("%d: RuleTCPFlag is neither 0 nor 255!\n",j);

            //若匹配成功，则修改 Flag 并停止比较，否则继续
            if(flag1&&flag2&&flag3&&flag4&&flag5)
            {
                Flag=1;
                break;
            }

            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
            flag5=0;
        }

        //所有规则比较结束后判断该条数据是否匹配，已匹配则输出匹配序号，未匹配输出 -1
        if(Flag==1)
        {
            fprintf(Packet1AnswerFile,"%d\n",j);
            Flag=0;
        }
        else
            fprintf(Packet1AnswerFile,"-1\n");
        
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;

        //关闭规则集文件后再打开，从头开始读取文件数据
        fclose(RuleIP1File);
        fclose(RuleIP2File);
        fclose(RuleWeiShu1File);
        fclose(RuleWeiShu2File);
        fclose(RuleMin1File);
        fclose(RuleMax1File);
        fclose(RuleMin2File);
        fclose(RuleMax2File);
        fclose(RuleTCPFile);
        fclose(RuleTCPFlagFile);

        RuleIP1File=fopen("../Debugging Data/RuleIP1.txt","r");
        RuleIP2File=fopen("../Debugging Data/RuleIP2.txt","r");
        RuleWeiShu1File=fopen("../Debugging Data/RuleWeiShu1.txt","r");
        RuleWeiShu2File=fopen("../Debugging Data/RuleWeiShu2.txt","r");
        RuleMin1File=fopen("../Debugging Data/RuleMin1.txt","r");
        RuleMax1File=fopen("../Debugging Data/RuleMax1.txt","r");
        RuleMin2File=fopen("../Debugging Data/RuleMin2.txt","r");
        RuleMax2File=fopen("../Debugging Data/RuleMax2.txt","r");
        RuleTCPFile=fopen("../Debugging Data/RuleTCP.txt","r");
        RuleTCPFlagFile=fopen("../Debugging Data/RuleTCPFlag.txt","r");
    }

    //校对答案
    CheckAnswer(Packet1AnswerFile,ReferenceAnswerFile);

    return 0;
}



//将数据集的IP进行处理后存储为 Debugging Data 中的 PacketIP1.txt 和 PacketIP2.txt 的函数
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



//将数据集的端口进行处理后存储为 Debugging Data 中的 PacketDuanKou1.txt 和 PacketDuanKou2.txt 的函数
void SaveDuanKou(int DuanKou,FILE *file)
{
    fprintf(file,"%d\n",DuanKou);
}



//将数据集的协议号进行处理后存储为 Debugging Data 中的 PacketTCP.txt 的函数
void SaveTCP(int TCP,FILE *file)
{
    fprintf(file,"%d\n",TCP);
}



//将规则集的IP进行处理后存储为 Debugging Data 中的 RuleIP1.txt 和 RuleIP2.txt 的函数
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



//将规则集的IP位数进行处理后存储为 Debugging Data 中的 RuleWeiShu1.txt 和RuleWeiShu2.txt 的函数
void SaveRuleWeiShu(int WeiShu,FILE *file)
{
    fprintf(file,"%d\n",WeiShu);
}



//将规则集的端口进行处理后存储为 Debugging Data 中的 RuleMin1.txt、RuleMax1.txt、RuleMin2.txt和RuleMax2.txt 的函数
void SaveMinAndMax(int m,FILE *file)
{
    fprintf(file,"%d\n",m);
}



//将规则集的协议号进行处理后存储为 Debugging Data 中的 RuleTCP.txt 和 RuleTCPFlag.txt 的函数
void SaveTCPAndFlag(int n,FILE *file)
{
    int a,b;

    a=n%16;
    b=n/16;
    n=a+b*16;

    fprintf(file,"%d\n",n);
}



//将数据集的IP与规则集的IP进行相应位数的匹配的函数
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



//检查我的答案与参考答案是否相符的函数
int CheckAnswer(FILE *MyAnswerFile,FILE *ReferenceAnswerFile)
{
    int i,flag=1,MyAnswer,ReferenceAnswer,ErrorNum=0;

    fclose(MyAnswerFile);
    MyAnswerFile=fopen("../MyAnswers/Packet1Answer.txt","r");

    for(i=0;!feof(ReferenceAnswerFile);i++)
    {
        fscanf(MyAnswerFile,"%d\n",&MyAnswer);
        fscanf(ReferenceAnswerFile,"%d\n",&ReferenceAnswer);

        if(MyAnswer!=ReferenceAnswer)
        {
            flag=0;
            printf("No.%d: Error!\n",i);
            ErrorNum++;
        }
    }

    if(flag==1)
        printf("Completely Correct!!! Congratulation!!!\n");
    else if(flag==0)
        printf("There are %d error(s)!\n",ErrorNum);
}