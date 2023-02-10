#include <stdio.h>
#include <math.h>
#include <string.h>

int longestPalindrome(const char *iStrPtr, int iLen, int *ioStartIdx)
{
    if (iStrPtr == NULL)
    {
        printf("NULL pointer detected \n");
        *ioStartIdx = 0;
        return 0;
    }
    
    if (ioStartIdx == NULL)
    {
        printf("NULL pointer detected \n");
        *ioStartIdx = 0;
        return 0;
    }

    int length = 0, tLength = 0, count, index = 1, pos = 0, tIndex, tCount;
    if (iLen == 1)
    {
        length = 1;
        pos = 0;
        *ioStartIdx = pos;
        return length;
    }

    for (index = 1; index < iLen - 1; index++)         // check for ODD case
    {

        tLength = 0;
        count = 0;
        tCount = 1;
        tIndex = index;

        do
        {
            count++;
            if (iStrPtr[tIndex - tCount] == iStrPtr[tIndex + tCount])
            {
                printf("%d == %d \n", tIndex - tCount, tIndex + tCount);
                tCount++;
                tLength += 2;
            }
            else
            {
                printf("%d != %d \n", tIndex - tCount, tIndex + tCount);
                // tCount ++;
                goto cntd2;
            }
        } while (count < index);
    cntd2:
        if (tLength > length)
        {
            length = tLength + 1;
            pos = tIndex - (tCount - 1);
        }
        continue;
    }
    //-------------------------------------------------------------------------------------------
    for (index = 1; index < iLen; index++)          // check for EVEN case
    {

        tLength = 0;
        count = 0;
        tCount = 1;
        tIndex = index;

        do
        {

            count++;
            if (iStrPtr[tIndex] == iStrPtr[tIndex - tCount])
            {
                printf("%d == %d \n", tIndex, tIndex - tCount);
                tCount += 2;
                tIndex++;
                tLength += 2;
            }
            else
            {
                printf("%d != %d \n", tIndex, tIndex - tCount);
                // tCount += 2;
                // tIndex++;
                goto cntd1;
            }
        } while (count < index && tIndex < iLen);
    cntd1:
        if (tLength > length)
        {
            length = tLength;
            pos = (tIndex - 1) - (tCount - 2);
        }
        continue;
    }
    //-----------------------------------------------------------------------------------------------------

    *ioStartIdx = pos;
    return length;
}

int main()
{
    char iStr[] = "pwkkwp";
    int iStrLen = strlen(iStr);
    int startIndex;
    int subStrLen = longestPalindrome(iStr, iStrLen, &startIndex);
    printf("Length of Longest Sub String  = %d \nStarting Position of substring = %d \n", subStrLen, startIndex);
    printf("%.*s\n", subStrLen, iStr + startIndex);
}