#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node *blink;
    struct node *flink;
    int data;
};

void freel(struct node *head)
{
    struct node *temp;
    while (head->flink != NULL)
    {
        temp = head;
        head = head->flink;
        free(temp);
    }
    free(head);
}

void printl(struct node *head, struct node *current)
{
    struct node *temp;
    temp = head;
    printf("\n");
    while (temp->flink != NULL)
    {
        if (temp == current)
        {
            printf("*%d*-->", temp->data);
            temp = temp->flink;
        }
        else
        {

            printf("%d-->", temp->data);
            temp = temp->flink;
        }
    }
    if (temp == current)
        printf("*%d*", temp->data);
    else
        printf("%d", temp->data);
    sleep(1);
}

void new (struct node *head)
{
    char o[3];
    struct node *newn, *temp;
    temp = head;
repeat:
    printf("would you like to link new node...[yes/no] : ");
    fflush(stdin);
    scanf("%s", o);
    if (!strcmp(o, "yes"))
    {

        newn = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data to new node : ");
        scanf("%d", &newn->data);
        newn->flink = NULL;
        newn->blink = temp;
        temp->flink = newn;
        temp = temp->flink;
        goto repeat;
    }
    else if (!strcmp(o, "no"))
    {
        printl(head, head);
        printf("\nlinked list created successfully");
        return;
    }
    else
    {
        printf("Choosen incurrect option...choose again");
        goto repeat;
    }
}
struct node *insert(struct node *head, struct node *current)
{
    char o[3];
    struct node *temp, *newn;
repeat:
    newn = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to new node :");
    scanf("%d", &newn->data);
    temp = current->flink;
    newn->flink = temp;
    newn->blink = current;
    current->flink = newn;
    current = current->flink;
    printl(head, current);
    printf("\nwould you like to insert one more node [yes/no].. :");
    fflush(stdin);
    scanf("%s", o);
    if (!strcmp(o, "yes"))
    {
        goto repeat;
    }
    else
    {
        return current;
    }
}

struct node *delete (struct node *head, struct node *current)
{
    char o[3];

repeat:
    printf("conform to delete node [yes/no]... : ");
    fflush(stdin);
    scanf("%s", o);
    if (!strcmp(o, "yes"))
    {
        struct node *temp1, *temp2;
        if (current == head)
        {
            temp1 = head;
            head = head->flink;
            head->blink = NULL;
            current = head;
            printf("\nNode deleted successfully");
            printl(head, current);
        repeat1:
            printf("\nWhould you like to delete one more node [yes/no]..:  ");
            scanf("%s", o);
            if (!strcmp(o, "yes"))
            {
                goto repeat;
            }
            if (!strcmp(o, "no"))
            {
                return current;
            }
            else
            {
                printf("\nchoosen incurrect options....choose again");
                goto repeat1;
            }
        }
        else if (current->flink == NULL)
        {
            temp1 = current;
            current = current->blink;
            current->flink = NULL;
            free(temp1);
            printf("\nNode deleted successfully");
            printl(head, current);
            goto repeat1;
        }
        else
        {
            temp1 = current->blink;
            temp2 = current->flink;
            free(current);
            temp1->flink = temp2;
            temp2->blink = temp1;
            printf("\nNode deleted successfully");
            current = temp2;
            printl(head, current);
            goto repeat1;
        }
    }
}
void replace(struct node *current)
{
    printf("\n Enter data to replace the current node data : ");
    scanf("%d", &current->data);
}

struct node *movef(struct node *head, struct node *current)
{
    if (current->flink != NULL)
    {
        current = current->flink;
        printl(head, current);
        return current;
    }
    else
    {
        printf("\nno more forther nodes");
        printl(head, current);
        return current;
    }
}
struct node *moveb(struct node *head, struct node *current)
{
    if (current->blink != NULL)
    {
        current = current->blink;
        printl(head, current);
        return current;
    }
    else
    {
        printf("\nAction can't be done");
        printl(head, current);
        return current;
    }
}
struct node *move(struct node *head, struct node *current)
{
    char o[3];
repeat:
    printf("\npree +/- to move to farword/backword and = for carry on : ");
    fflush(stdin);
    scanf("%s", o);
    switch (o[0])
    {
    case 43:
        current = movef(head, current);
        goto repeat;
    case 45:
        current = moveb(head, current);
        goto repeat;
    case 61:
        return current;
    default:
        printf("choosen incurrect option.......choose again... ");
        goto repeat;
    }
}
void action(struct node *head, struct node *current)
{
    char o[3];
    int c;
repeat:
    printf("\nWould you like to move action to another node [yes/no]... : ");
    fflush(stdin);
    scanf("%s", o);
    if (!strcmp(o, "yes"))
    {
        current = move(head, current);
    }
    else if (!strcmp(o, "no"))
    {
        ;
    }
    else
    {
        printf("choosen incurrect option.......choose again... ");
        goto repeat;
    }

    while (1)
    {
    repeat1:
        printf("\noption : \n1]Insert new node\n2]Delete node\n3]Replace data\n4]Move action to another node\n5]Exit\n");
        fflush(stdin);
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            current = insert(head, current);
            break;
        case 2:
            current = delete (head, current);
            break;
        case 3:
            replace(current);
            printl(head, current);
            break;
        case 4:
            current = move(head, current);
            break;
        case 5:
            printf("\nDestroying linked list\n");
            freel(head);
            exit(0);
        default:
            printf("unknown option choosen......choose again");
            goto repeat1;
        }
    }
}

void main()
{
    struct node *head, *current;
    head = (struct node *)malloc(sizeof(struct node));
    printf("creating a linked list");
    printf("\nEnter data to head : ");
    scanf("%d", &head->data);
    head->blink = NULL;
    head->flink = NULL;
    current = head;
    new (head);
    action(head, current);
}
