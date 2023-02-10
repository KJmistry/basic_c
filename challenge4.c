#include <stdio.h>
#include <math.h>
#include <string.h>
#define toInt(x) x - '0'

void reverseStr(char *str, int strLen)
{
    char temp;
    for(int index = 0 ; index < strLen/2 ; index++ )
    {
        temp = str[index];
        str[index] = str[strLen - (index + 1)];
        str[strLen - (index + 1)] = temp;
    }
}

int addStr(char *str1,char *str2,int len1,int len2, char *finalSum)
{
    int maxLen = len1;

    if(len1 < len2)
    {
        maxLen = len2;
        for(int i = len1; i < len2;i++)
        {   
           str1[i] = '0'; 
        }
        reverseStr(str1,maxLen);
    }
    
    if(len2 < len1)
    {
        for(int i = len2; i < len1;i++)
        {   
           str2[i] = '0'; 
        }
        reverseStr(str2,maxLen);
    }

    int tSum = 0,carry = 0, index = 0,tIndex = 0;
    finalSum[maxLen+1] = '\0';
    for(index = maxLen - 1 ; index >= 0  ; index-- )
    {
        tSum = (toInt(str1[index]))+(toInt(str2[index]))+carry;  
        carry = 0 ;
        if( tSum > 9)
        {
            finalSum[tIndex] = (tSum % 10) + '0';            
            carry = 1;
        }
        else
        {
            finalSum[tIndex] = tSum + '0';            
        }
        tIndex++;
    }

    if( carry == 1)
    {
        finalSum[tIndex] = 1 + '0';
    } 
    finalSum[tIndex+1] = '\0';
    return 0;
}

int power(int base, int power)
{
    int ans = 1;
    for (int i = 0; i < power; i++)
    {
        ans *= base;
    }
    return ans;
}

int main()
{
    char num1[10]; // len = m
    printf("Enter First Number:\n");
    scanf("%s", num1);
    char num2[10]; // len = n
    printf("Enter Second Number:\n");
    scanf("%s", num2);

    int num1len = strlen(num1);
    int num2len = strlen(num2);

    // performing  (num1*num2) /// m*n
    char finalMul[100], tStr[11][11];
    int decTB = power(10, (num2len - 1));

    for (int topBotIndex = 0; topBotIndex < num2len; topBotIndex++)
    {
        int tempOne = 0,carry = 0, decLR = power(10, (num1len - 1)),lefRgtIndex;
        char t1[100] = "0",t2[10]="0",tFinal[100];
        for (lefRgtIndex = 0; lefRgtIndex < num1len; lefRgtIndex++)
        {
            tempOne = (((toInt(num1[lefRgtIndex])) * (toInt(num2[topBotIndex]))) * decLR)+carry;
            carry = 0;
            if(tempOne > 9)
            {
                t2[0] = tempOne%10 + '0';
                carry = 1;
            }
            // printf("%d--\n",tempOne);
            t2[0] = tempOne + '0';
            decLR /= 10;
            addStr(t1,t2,strlen(t1),strlen(t2),tFinal);
            strcpy(t1,tFinal);
        }
        if(carry == 1)
        {
            t2[0] = 1 + '0';
            addStr(t1,t2,strlen(t1),strlen(t2),tFinal);
        }
        strcpy(tStr[topBotIndex][lefRgtIndex],tFinal);
        // finalMul += (tempOne)*decTB;
        // decTB /= 10;
    }

    printf("%s",tStr[0]);
    // printf("%d",finalMul);
    // char ans[50];
    // sprintf(ans, "%d", finalMul);
    // printf("Final Ans in String Format : %s\n", ans);
}