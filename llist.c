#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;fggggg
    struct node *link;
};

int printn(struct node *head)
{
    printf("Enter node number to display:\t");
    int o;
    struct node *temp;
    scanf("%d", &o);
    temp = head;
    for (int i = 1; i < o; i++)
    {
        temp = temp->link;
    }
    printf("\n Data : %d\n", temp->data);
    return 0;
}

int printl(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp->link != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    printf("%d\n", temp->data);
    return 0;
}
int print(struct node *head)
{
    int o;
    printf("options:\n1]print node\n2]print entair list");
    scanf("%d", &o);
    switch (o)
    {
    case 1:
        printn(head);
        break;
    case 2:
        printl(head);
        break;
    }
}

int new (struct node *head)
{
    char c[3];
    struct node *newnode, *temp;
    temp = head;
create:
    newnode = (struct node *)malloc(sizeof(struct node));

    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    printf("enter data to the new node\n");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    temp->link = newnode;
    printl(head);
    printf("node added successfully.\n");
    printf("would you like to add one more node....yes/no\n");
    scanf("%s", c);
    if (!strcmp(c, "yes"))
    {
        goto create;
    }
    else
    {
        free(newnode);
        return 0;
    }
}

int del(struct node *head)
{
    int o;
    char c[3];
    struct node *temp, *temp2;
repeat:
    printf("options:\n\t1]delete last created node\n\t2]delete in between node");
    scanf("%d", &o);
    temp = head;
    switch (o)
    {
    case 1:
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        printf("node deleted successfully\n");
        printl(head);
        printf("do you want to delete one more node...yes/no\n");
        scanf("%s", c);
        if (!strcmp(c, "yes"))
            goto repeat;
        else
            return 0;
    case 2:
        printf("enter node number to delete\t");
        scanf("%d", &o);
        for (int i = 1; i < o; i++)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = temp->link;
        printf("node deleted successfully\n");
        printl(head);
        printf("do you want to delete one more node....yes/no\n");
        scanf("%s", c);
        if (!strcmp(c, "yes"))
            goto repeat;
        else
            return 0;
    }
}

int insert(struct node *head)
{
    char c[3];
    int n;
    struct node *temp, *newnode;
repeat:
    printf("enter node number after which a node is inserted");
    scanf("%d", &n);
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    for (int i = 1; i < n; i++)
    {
        temp = temp->link;
    }
    printf("enter data to the new node\n");
    scanf("%d", &newnode->data);
    newnode->link = temp->link;
    temp->link = newnode;
    printf("\nnode inserted successfully\n");
    print(head);
    printf("do you want to insert one more node...yes/no\n");
    scanf("%s", c);
    if (!strcmp(c, "yes"))
        goto repeat;
    else
        free(newnode);
    return 0;
}

int swap(struct node *head)
{
    int n1, n2;
    struct node *temp1, *temp2, *temp3, *temp4;
    printf("\nenter nodes to swap\n");
    scanf("%d%d", &n1, &n2);
    temp2 = head;
    for (int i = 1; i < n1; i++)
    {
        temp1 = temp2;
        temp2 = temp2->link;
    }
    temp4 = head;
    for (int i = 1; i < n2; i++)
    {
        temp3 = temp4;
        temp4 = temp4->link;
    }
    temp1->link = temp4;
    temp3->link = temp2;
    temp2->link = temp4->link;
    temp4->link = temp3;
    print(head);
    printf("\nswaping is successfull\n");
    return 0;
}
void main()
{
    int o;
    printf("creating link list......\n");
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL;
    printf("Enter data to head node:\t");
    scanf("%d", &head->data);
    while (1)
    {
        printf("choose the options:\n\t1]add a new node.\n\t2]delete a node\n\t3]print data\n\t4]insert a node\n\t5]swap nodes\n\t6]Exit linked list\n:");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            new (head);
            break;
        case 2:
            del(head);
            break;
        case 3:
            print(head);
            break;
        case 4:
            insert(head);
            break;
        case 5:
            swap(head);
            break;
        default:
            free(head);
            exit(0);
        }
    }
}
