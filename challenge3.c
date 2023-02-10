#include <stdio.h>

int rotatedSort(int *ioData, int iSize, int poz)
{
    if (ioData == NULL)
    {
        printf("NULL pointer detected \n");
        return 1;
    }

    if (poz > (iSize - 1) || poz <= 0)
    { 
        printf("Invalid Position \n");
        return 1;
    }

    int tempVar;
    int rotIndex = (iSize + 1) - poz;

    int rtdArr[iSize];
    for (int arrIndex1 = 0; arrIndex1 < iSize; arrIndex1++)
    {
        for (int arrIndex2 = arrIndex1 + 1; arrIndex2 < iSize; arrIndex2++)
        {
            if (ioData[arrIndex1] > ioData[arrIndex2])
            {
                tempVar = ioData[arrIndex1];
                ioData[arrIndex1] = ioData[arrIndex2];
                ioData[arrIndex2] = tempVar;
            }
        }
        rtdArr[iSize - rotIndex] = ioData[arrIndex1];
        // printf("%d--\n",(iSize - rotIndex));
        // printf("%d\n",ioData[arrIndex1]);

        if (rotIndex == 1)
            rotIndex = iSize + 1;
        rotIndex--;
    }
    for (int arrIndex1 = 0; arrIndex1 < iSize; arrIndex1++)
    {
        printf("%d \n", rtdArr[arrIndex1]);
    }
    return 0;
}

int main()
{

    int arr[10] = {10, 2, 6, 4, 1, 3, 7, 8, 9, 5};
    int pivotPos;
    printf("Enter position:\n");
    scanf("%d", &pivotPos);
    printf("Final Soted Arr:\n");

    int len = sizeof(arr) / sizeof(int);
    int val = rotatedSort(arr, len, pivotPos);
    if (val == 1)
    {
        printf("Error occured ...Try Again ...!");
    }
}