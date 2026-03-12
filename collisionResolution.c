#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

struct node
{
    int key;
    struct node *next;
};

struct node *table[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void initialize()
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        table[i] = NULL;
    }
}

void insert(int key)
{
    int index = hash(key);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;

    if(table[index] == NULL)
    {
        table[index] = newnode;
    }
    else
    {
        struct node *temp = table[index];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("Inserted %d at chain index %d\n", key, index);
}

void search(int key)
{
    int index = hash(key);
    struct node *temp = table[index];

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }

    printf("Key not found\n");
}

void deleteKey(int key)
{
    int index = hash(key);
    struct node *temp = table[index];
    struct node *prev = NULL;

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            if(prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Key not found\n");
}

void display()
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        printf("[%2d]: -> ", i);

        struct node *temp = table[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice, key, mainChoice;

    printf("Choose collision resolution technique:\n");
    printf("1. Separate chaining\n");
    printf("2. Linear probing (open addressing)\n");
    printf("3. Quadratic probing (open addressing)\n");
    printf("0. Exit\n");

    printf("Selection: ");
    scanf("%d", &mainChoice);

    if(mainChoice == 1)
    {
        initialize();
        printf("\nInitialized separate chaining table (size %d)\n", SIZE);

        do
        {
            printf("\n-- Chaining Menu --\n");
            printf("1: Insert 2: Search 3: Delete 4: Display 0: Back\n");

            printf("Choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    printf("Key to insert: ");
                    scanf("%d", &key);
                    insert(key);
                    break;

                case 2:
                    printf("Key to search: ");
                    scanf("%d", &key);
                    search(key);
                    break;

                case 3:
                    printf("Key to delete: ");
                    scanf("%d", &key);
                    deleteKey(key);
                    break;

                case 4:
                    display();
                    break;
            }

        } while(choice != 0);
    }

    return 0;
}
