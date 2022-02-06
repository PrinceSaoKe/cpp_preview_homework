#include <stdio.h>
#include <string.h>
int Compare(char *packetIP,char *list,int WeiShu);
int main()
{
    FILE *packet=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/PacketIP1.txt","r");
    FILE *input=fopen("C:/Users/Lenovo/Desktop/Second Homework In Winter Vocation/Debugging Data/RuleMax2.txt","r");
    char list[33]={0},packetIP[33]={0};
    int i,max;
    /*fscanf(packet,"%s",packetIP);
    printf("packetIP:\n");
    puts(packetIP);
    for(i=0;!feof(input);i++)
    {
        fscanf(input,"%d\n",&max);
        printf("%d: %d\n",i,max);
    }*/

    gets(packetIP);
    gets(list);
    if(Compare(&packetIP[0],&list[0],32))
        printf("1");
    else
        printf("0");
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