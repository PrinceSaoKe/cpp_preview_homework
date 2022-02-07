#include <stdio.h>
#include <string.h>
int Compare(char *packetIP,char *list,int WeiShu);
int main()
{
    FILE *PacketIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP1.txt","r");
    FILE *PacketIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP2.txt","r");
    FILE *PacketDuanKou1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou1.txt","r");
    FILE *PacketDuanKou2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketDuanKou2.txt","r");
    FILE *PacketCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketCTP.txt","r");

    FILE *RuleIP1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP1.txt","r");
    FILE *RuleIP2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleIP2.txt","r");
    FILE *RuleWeiShu1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu1.txt","r");
    FILE *RuleWeiShu2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleWeiShu2.txt","r");
    FILE *RuleMin1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMin1.txt","r");
    FILE *RuleMax1File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax1.txt","r");
    FILE *RuleMin2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMin2.txt","r");
    FILE *RuleMax2File=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax2.txt","r");
    FILE *RuleCTPFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTP.txt","r");
    FILE *RuleCTPFlagFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleCTPFlag.txt","r");

    FILE *TestFile=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/Test.txt","w");

    int i,j,WeiShu1,WeiShu2;
    char PacketIP1Array[33]={0},PacketIP2Array[33]={0},RuleIP1Array[33]={0},RuleIP2Array[33]={0};
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,Flag=0;

    for(i=0;i<1;i++)
    {
        fscanf(PacketIP1File,"%s\n",PacketIP1Array);
        fscanf(PacketIP2File,"%s\n",PacketIP2Array);

        for(j=0;!feof(RuleIP1File);j++)
        {
            fscanf(RuleIP1File,"%s\n",RuleIP1Array);
            fscanf(RuleWeiShu1File,"%d\n",&WeiShu1);
            if(Compare(PacketIP1Array,RuleIP1Array,WeiShu1))
                flag1=1;
            fprintf(TestFile,"%d: %d:%d",i,j,flag1);//Debug

            fscanf(RuleIP2File,"%s\n",RuleIP2Array);
            fscanf(RuleWeiShu2File,"%d\n",&WeiShu2);
            if(Compare(PacketIP2Array,RuleIP2Array,WeiShu2))
                flag2=1;
            fprintf(TestFile,"%d\n",flag2);//Debug

            flag1=0;
            flag2=0;
            flag3=0;
            flag4=0;
            flag5=0;
        }

        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;

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
    }

    /*gets(PacketIP1Array);
    gets(RuleIP1Array);
    //scanf("%d",&WeiShu1);
    WeiShu1=30;

    if(Compare(PacketIP1Array,RuleIP1Array,WeiShu1))
        printf("same");
    else
        printf("different");

    getchar();*/

    return 0;
}


int Compare(char *packetIP,char *list,int WeiShu)
{
    int i;
    for(i=0;i<WeiShu;i++)
    {
        if(*packetIP!=*list)
        {
            return 0;
        }
        packetIP++;
        list++;
    }
    return 1;
}