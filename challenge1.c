#include <stdio.h>
#include <ctype.h>
#include "operations.h"
int (*gOperation[])(int, int) = {add, subtract, multiply, divide, modulo};

int main()
{
    int oprType,num1,num2,valid;

    // array of function pointers having all above pointers of all above functions

    valid = getInput(&oprType, &num1, &num2);

    if(1 == valid)
    {
        printf("Invalid Input Value !!\n");
        return 0;
    }
    valid = doOperation(&oprType, &num1, &num2);
    if(1 == valid)
    {
        printf("Error Occured\n");
        return 0;
    }
}


// 5 Labor functions

int add(int num1, int num2)
{
    return num1 + num2;
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

int divide(int num1, int num2)
{   
    if( num2 == 0)
    {
        printf("0 Detected as denominator (Divide by 0 error !)\n");
        // return 1;
    }
    return num1 / num2;
}

int modulo(int num1, int num2)
{
    return num1 % num2;
}

int doOperation(int *operationType, int *num1, int *num2)
{   
    if(NULL==num2)
    {
        printf("[%s]:[%d] NULL pointer detected as num2\n", __func__, __LINE__);
        return 1;
    }if(NULL==num1)
    {
        printf("[%s]:[%d] NULL pointer detected as num1\n", __func__, __LINE__);
        return 1;
    }if(NULL==operationType)
    {
        printf("[%s]:[%d] NULL pointer detected as operationType\n", __func__, __LINE__);
        return 1;
    }
    
    int ioResult;
    if(!(0 == *operationType || 1 == *operationType || 2 == *operationType || 3 == *operationType || 4 == *operationType))
    {
        printf("Enter Valid Opration Type !\n(An Int Number Between 0 to 4 )\n");
        return 1;
    }

    ioResult=(*gOperation[*operationType])(*num1, *num2);
    printf("Final Result of operation between %d & %d is : %d\n",*num1, *num2, ioResult);
    return 0;   
}

int getInput(int* operationType, int* num1, int* num2)
{   
    if(NULL==num2)
    {
        printf("[%s]:[%d] NULL pointer detected as num2\n", __func__, __LINE__);
        return 1;
    }if(NULL==num1)
    {
        printf("[%s]:[%d] NULL pointer detected as num1\n", __func__, __LINE__);
        return 1;
    }if(NULL==operationType)
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
    scanf("%d",num1);
    printf("Please Enter Second int Operand \n");
    scanf("%d",num2);
    return 0;
}