#include <stdio.h>
#include <math.h>
#include <string.h>
#define toInt(x) (x - '0')

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
    reverseStr(finalSum,strlen(finalSum));

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
    char num1[10] = "8888888"; // len = m
    // printf("Enter First Number:\n");
    // scanf("%s", num1);
    char num2[10] = "8888888"; // len = n
    // printf("Enter Second Number:\n");
    // scanf("%s", num2);
    int num1len = strlen(num1);
    int num2len = strlen(num2);
    
    char ans[num1len+num2len],tAns[num1len+num2len],fAns[num1len+num2len];
    memset(ans,'0',sizeof(ans));
    memset(tAns,'0',sizeof(tAns));
    memset(tAns,'0',sizeof(fAns));
    reverseStr(num1,num1len);   // num1 = 51

    int ansIndex = num1len + num2len - 1;
    
    ans[ansIndex + 1] = 0 ;
    tAns[ansIndex + 1] = 0 ;
    fAns[ansIndex + 1] = 0 ;

    // performing  (num1*num2) /// m*n
   
    int zeroCnt = num2len - 1;

    for (int topBotIndex = 0; topBotIndex < num2len; topBotIndex++)
    {
        if(zeroCnt<0)
            zeroCnt = 0;

        int tempOne = 0,carry = 0, decLR = power(10, (num1len - 1)),lefRgtIndex;
        ansIndex = num1len + num2len - 1;

        for (lefRgtIndex = 0; lefRgtIndex < num1len; lefRgtIndex++)
        {
            tempOne = toInt(num2[topBotIndex])*toInt(num1[lefRgtIndex])+carry;
                    printf("tempOne = %d\n",tempOne);

            carry = 0;
            tAns[ansIndex - zeroCnt] = (tempOne % 10) + '0';
            printf("tempOne - mod - 10 = %d\n",(tempOne % 10));
            printf("INdex = %d\n",ansIndex - zeroCnt);

            if(tempOne > 9)          
                carry = tempOne/10;
            
            ansIndex--;
        }

        if(carry != 0)
            tAns[ansIndex-zeroCnt] = carry + '0' ;
        
        zeroCnt--;
        printf("Tans %s\n",tAns);
        printf("ans %s\n",ans);
        addStr(ans,tAns,strlen(ans),strlen(tAns),fAns);
        strcpy(ans,fAns);
        memset(tAns,'0',sizeof(tAns));


        printf("final : %s\n",fAns);
    }

    
    // printf("%d",finalMul);
    // char ans[50];
    // sprintf(ans, "%d", finalMul);
    // printf("Final Ans in String Format : %s\n", ans);
}