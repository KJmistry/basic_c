#include <stdio.h>
#include <math.h>
#include <string.h>

int getLongestSubstring(const char *iStrPtr, int iLen, int *ioStartIdx)
{
    if (ioStartIdx == NULL)
    {
        printf("NULL pointer detected \n");
        *ioStartIdx = 0;
        return 0;
    }
    int length = 1, tLength, count, index = 1, compare, tPos, pos = 0;
    if (iLen == 1)
    {
        length = 1;
        pos = 0;
        *ioStartIdx = pos;
        return length;
    }

label2:
    compare = 1; // start of next iteration if matching found
                 /*compare = 1 ; first iteration check 1 char
                 for further checking increment compare by one for each iteration  (check compare++ after do while)
                 if match detected re-init it by 1*/

    if (length < tLength) // update Pos and Length if new lenghth > old length
    {
        length = tLength;
        pos = tPos;
    }
    tLength = 1;
label1:
    count = 1; // continue checking further indexes if all char are diff
    do
    {
        if (compare == 1)
        {
            tPos = index - 1;
        }
        if (iStrPtr[index] != iStrPtr[index - count])
        {
            // printf("%d ! = %d   \n",index,(index - count));
            // printf("%c ! = %c   \n",iStrPtr[index],iStrPtr[index - count]);

            count++;
        }
        else
        {
            // printf("%d = = %d   \n",index,(index - count));
            // printf("%c = = %c   \n",iStrPtr[index],iStrPtr[index - count]);

            index = index - count + 2;
            if (index == iLen)
                goto end;
            goto label2;
        }

    } while (count <= compare);

    tLength++;
    compare++; // controlling do while for further iteration
                /* i.e if no match found (all char is unique) say string = abcd
                iteration1 = check 1 time b == a ?
                iteration2 = check 2 time c == b ? && c == a ?
                iteration3 = check 3 time d == c ? && d == b ? && d == a ?
                iteration4 = check 4 time .......(ctd. if needed)

                if match found start checking index + 2 from where match is found (check index = index - count + 2; in else part )
                .... */
    index++;
    if (index == iLen)
    {
        goto end;
    }
    goto label1;

end:            //end if comparision 
    if (length < tLength)
    {
        length = tLength;
        pos = tPos;
    }

    // printf("L = %d ---- P = %d \n",length,pos);
    *ioStartIdx = pos;
    return length;
    // ioStartIdx = starting DummyIndex of LongestSubstring in array iStringPtr
}

int main()
{
    char iStr[] = "aafacytionbb";
    int iStrLen = strlen(iStr);
    int startIndex;
    int subStrLen = getLongestSubstring(iStr, iStrLen, &startIndex);
    printf("Length of Longest Sub String  = %d \nStarting Position of substring = %d \n", subStrLen, startIndex);
    printf("%.*s\n", subStrLen, iStr + startIndex);
}