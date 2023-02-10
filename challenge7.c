#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int num1, int num2)
{
    if(num1 > num2)
        return num1;
    return num2;
}

struct node
{
    int data;
    struct node *next;
};

void *addNode(struct node *ptr, int value)
{
    if (NULL == ptr)
    {
        printf("NULL pointer detected \n");
        return NULL;
    }
    ptr->next = (struct node *)malloc(sizeof(struct node));
    ptr->data = value - '0';
    ptr->next->next = NULL;
    return ptr->next;
}

int creatlist(struct node *head, char *list, int maxLen)
{
    if (NULL == head)
    {
        printf("NULL structure pointer detected \n");
        return 1;
    }
    if (NULL == list)
    {
        printf("NULL arry pointer detected \n");
        return 1;
    }
    struct node *temp;
    temp = addNode(head, list[strlen(list)-1]);

    for (int index = strlen(list)-2 ; index >= 0 ; index--)
    {
        temp = addNode(temp, list[index]);
    }
    if(strlen(list)<maxLen)
    {
        for (int index = 0 ; index < maxLen - strlen(list); index++)
        {
            temp = addNode(temp, '0');
        }
    }
    return 0;
}

int printList(struct node *ptr)
{
    if (NULL == ptr)
    {
        printf("NULL pointer detected \n");
        return 1;
    }

    printf("[ ");
    while (ptr->next != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
    return 0;
}

void* addTwoNumbers(struct node* iList1_Ptr, struct node* iList2_Ptr)
{   
    int carry = 0 , temp ;
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    struct node *tempPtr = head3;

    while (iList1_Ptr->next != NULL)
    {   
        temp = (iList1_Ptr->data + iList2_Ptr -> data) + carry;
        carry = 0;
        if(temp > 9)
        {
            temp %= 10;
            carry = 1;
        }
        // printf("%d\n", temp );
        tempPtr = addNode(tempPtr,temp+'0');
        iList1_Ptr = iList1_Ptr -> next;
        iList2_Ptr = iList2_Ptr -> next;
    }
    if(carry == 1)
    {
        // printf("1\n");
        tempPtr = addNode(tempPtr,1 +'0');

    }

    return head3;
}

void freeList(struct node *ptr)
{
    struct node *tPtr;
    while( ptr -> next != NULL)
    {
        tPtr = ptr -> next ;
        free(ptr); 
        ptr = tPtr;
    }
}

int main()
{

    char list1[] = "9999998";
    char list2[] = "999";

    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));

    struct node *ptr = NULL;
    int maxLen = max(strlen(list1),strlen(list2)),valid;

    valid = creatlist(head1, list1, maxLen);
    if( valid == 1)
    {
        printf("List creation failed..!\n");
        return 1;
    }

    valid = creatlist(head2, list2, maxLen);
    if( valid == 1)
    {
        printf("List creation failed..!\n");
        return 1;
    }
    
    printf("List1 (Number 1):  "); valid = printList(head1);
    if( valid == 1)
    {
        printf("Unable to print List ..!\n");
        return 1;
    }

    printf("List2 (Number 2):  "); valid = printList(head2);
    if( valid == 1)
    {
        printf("Unable to print List ..!\n");
        return 1;
    }

    ptr = addTwoNumbers(head1,head2);
    printf("List3 (Addition):  "); valid = printList(ptr);
    if( valid == 1)
    {
        printf("Unable to print List ..!\n");
        return 1;
    }

    freeList(head1);
    head1 = NULL;
    freeList(head2);
    head2 = NULL;
    freeList(ptr);
    ptr = NULL;
}