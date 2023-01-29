#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "operations2.h"
int (*gOperation[])(int, int, int *) = {add, subtract, multiply, divide, modulo};

int main()
{
    int oprType,num1,num2,valid,finalAns;

    // array of function pointers having all above pointers of all above functions

    valid = getInput(&oprType, &num1, &num2);

    if(1 == valid)
    {
        printf("Invalid Input Value !!\n");
        return 0;
    }

    void *funPtr = selectOperation(oprType);
    if(NULL == funPtr)
    {
        printf("Error occured due to invalid index of function (NULL received)!\n");
        exit(0);
    }

    valid = doOperation(funPtr , num1, num2, &finalAns);

    if(1 == valid)
    {
        printf("Error Occured\n");
        return 0;
    }
    printf("Final Result of operation between %d & %d is : %d\n",num1, num2, finalAns);
}


// 5 Labor functions

int add(int num1, int num2, int *resultPtr )
{   
    if(NULL==resultPtr)
    {
        printf("[%s]:[%d] NULL pointer detected \n", __func__, __LINE__);
        return 1;
    }
    *resultPtr = num1 + num2;
    return 0;
}

int subtract(int num1, int num2, int *resultPtr)
{   
    if(NULL==resultPtr)
    {
        printf("[%s]:[%d] NULL pointer detected \n", __func__, __LINE__);
        return 1;
    }
    *resultPtr = num1 - num2;
    return 0;
}

int multiply(int num1, int num2, int *resultPtr)
{   
    if(NULL==resultPtr)
    {
        printf("[%s]:[%d] NULL pointer detected \n", __func__, __LINE__);
        return 1;
    }
    *resultPtr = num1 * num2;
    // if(num1 * num2 > INT_MAX || num1 * num2 < INT_MIN)
    // // if((num1 > 0 && num2 > 0 && *resultPtr < 0) | (num1 < 0 && num2 < 0 && *resultPtr > 0) | (num1 > 0 && num2 < 0 && *resultPtr > 0) | (num1 < 0 && num2 > 0 && *resultPtr > 0))
    // {
    //     printf("OverFlow Occured \n");
    //     exit(0);
    // }
    return 0;
}

int divide(int num1, int num2, int *resultPtr)
{   
    if(NULL==resultPtr)
    {
        printf("[%s]:[%d] NULL pointer detected \n", __func__, __LINE__);
        return 1;
    }
    if( num2 == 0)
    {
        printf("Zero Detected as denominator (Divide by 0 error !)\n");
        exit(0);
    }
    *resultPtr = num1 / num2;
    return 0;
}

int modulo(int num1, int num2, int *resultPtr)
{   
    if(NULL==resultPtr)
    {
        printf("[%s]:[%d] NULL pointer detected \n", __func__, __LINE__);
        return 1;
    }
    if( num2 == 0)
    {
        printf("Zero Detected as denominator (Divide by 0 error !)\n");
        exit(0);
    }
    *resultPtr = num1 % num2;
}

void *selectOperation( int operationType )
{
    if(!(0 == operationType || 1 == operationType || 2 == operationType || 3 == operationType || 4 == operationType))
    {
        printf("InValid function Index !\n");
        return NULL;
    }
    else
        return gOperation[operationType];
}
int doOperation(int (*operationType)(), int num1, int num2 , int *result)
{   
    
    if(NULL==operationType)
    {
        printf("[%s]:[%d] NULL pointer detected as operationType\n", __func__, __LINE__);
        return 1;
    }
    
    int ioResult;

    ioResult=(*operationType)(num1, num2, result);
    return 0;   
}

int getInput(int* operationType, int* num1, int* num2)
{   
    if(NULL==num2)
    {
        printf("[%s]:[%d] NULL pointer detected as num2\n", __func__, __LINE__);
        return 1;
    }
    if(NULL==num1)
    {
        printf("[%s]:[%d] NULL pointer detected as num1\n", __func__, __LINE__);
        return 1;
    }
    if(NULL==operationType)
    {
        printf("[%s]:[%d] NULL pointer detected as operationType\n", __func__, __LINE__);
        return 1;
    }

    printf("Please Enter An Integer Number According to operation You want to perform: \n");
    printf("Enter 0 for ADDITION\nEnter 1 for SUBTRACTION\nEnter 2 for MULTIPLY\nEnter 3 for DIVIDE\nEnter 4 for MODULO\n");

    scanf("%d",operationType);
    
    if(!(0 == *operationType || 1 == *operationType || 2 == *operationType || 3 == *operationType || 4 == *operationType))
    {
        printf("Enter Valid Opration Type !\n(An Int Number Between 0 to 4 )\n");
        return 1;
    }
    printf("Please Enter First int Operand \n");
    
    if(scanf("%d",num1) == 0)
    {
        printf("First operand is not an integer !\n");
        return 1;
    }
    //fflush(stdin);
    printf("Please Enter Second int Operand \n");
    if(scanf("%d",num2) == 0)
    {
        printf("second operand is not an integer !\n");
        return 1;
    }
    return 0;
}