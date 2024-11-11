#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Structure to represent a student 
struct Student { 
char USN[20]; 
char Name[50]; 
char Programme[20]; 
int Sem; 
char PhNo[15]; 
struct Student *next; 
}; 
// Function to create a new student node 
struct Student *createStudent(char USN[], char Name[], char Programme[], int Sem, char PhNo[]) { 
struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student)); 
 if (newStudent == NULL) { 
        printf("Memory allocation failed.\n"); 
        exit(1); 
    } 
    strcpy(newStudent->USN, USN); 
    strcpy(newStudent->Name, Name); 
    strcpy(newStudent->Programme, Programme); 
    newStudent->Sem = Sem; 
    strcpy(newStudent->PhNo, PhNo); 
    newStudent->next = NULL; 
    return newStudent; 
} 
 
// Function to insert a student at the front of the linked list 
struct Student *insertFront(struct Student *head, struct Student *newStudent) { 
    newStudent->next = head; 
    return newStudent; 
} 
 
// Function to insert a student at the end of the linked list 
struct Student *insertEnd(struct Student *head, struct Student *newStudent) { 
    if (head == NULL) { 
        return newStudent; 
    }
 struct Student *current = head; 
    while (current->next != NULL) { 
        current = current->next; 
    } 
 
    current->next = newStudent; 
    return head; 
} 
 
// Function to delete a student from the front of the linked list 
struct Student *deleteFront(struct Student *head) { 
    if (head == NULL) { 
        printf("List is empty. Cannot delete.\n"); 
        return head; 
    } 
 
    struct Student *temp = head; 
    head = head->next; 
    free(temp); 
    return head; 
} 
 
// Function to display the linked list and count the number of nodes 
void displayAndCount(struct Student *head) { 
    struct Student *current = head;
  int count = 0; 
 
    printf("Student Data:\n"); 
    printf("-------------------------------------------------------------------------------------------\n"); 
    printf("USN\t\t Name\t\t Programme\t\t Sem\t\t PhNo\n"); 
    printf("-------------------------------------------------------------------------------------------\n"); 
 
    while (current != NULL) { 
        printf("%s\t %s\t\t %s\t\t\t %d\t\t %s\n", current->USN, current->Name, current->Programme, 
current->Sem, current->PhNo); 
        current = current->next; 
        count++; 
    } 
 
    printf("\nTotal Students: %d\n", count); 
} 
 
int main() { 
    struct Student *head = NULL; 
    int choice; 
 
    while (1) { 
        printf("\nSingly Linked List Menu:\n"); 
        printf("1. Create a Student\n"); 
        printf("2. Insert at Front\n"); 
        printf("3. Insert at End\n");
   printf("4. Delete from Front (Stack demonstration)\n"); 
        printf("5. Display List and Count Nodes\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: { 
                char USN[20], Name[50], Programme[20], PhNo[15]; 
                int Sem; 
                printf("Enter USN: "); 
                scanf("%s", USN); 
                printf("Enter Name: "); 
                scanf("%s", Name); 
                printf("Enter Programme: "); 
                scanf("%s", Programme); 
                printf("Enter Semester: "); 
                scanf("%d", &Sem); 
                printf("Enter Phone Number: "); 
                scanf("%s", PhNo); 
                struct Student *newStudent = createStudent(USN, Name, Programme, Sem, PhNo); 
                head = insertFront(head, newStudent); 
                break; 
            } 
            case 2: { 
   char USN[20], Name[50], Programme[20], PhNo[15]; 
                int Sem; 
                printf("Enter USN: "); 
                scanf("%s", USN); 
                printf("Enter Name: "); 
                scanf("%s", Name); 
                printf("Enter Programme: "); 
                scanf("%s", Programme); 
                printf("Enter Semester: "); 
                scanf("%d", &Sem); 
                printf("Enter Phone Number: "); 
                scanf("%s", PhNo); 
                struct Student *newStudent = createStudent(USN, Name, Programme, Sem, PhNo); 
                head = insertFront(head, newStudent); 
                break; 
            } 
            case 3: { 
                char USN[20], Name[50], Programme[20], PhNo[15]; 
                int Sem; 
                printf("Enter USN: "); 
                scanf("%s", USN); 
                printf("Enter Name: "); 
                scanf("%s", Name); 
                printf("Enter Programme: "); 
                scanf("%s", Programme); 
  printf("Enter Semester: "); 
                scanf("%d", &Sem); 
                printf("Enter Phone Number: "); 
                scanf("%s", PhNo); 
                struct Student *newStudent = createStudent(USN, Name, Programme, Sem, PhNo); 
                head = insertEnd(head, newStudent); 
                break; 
            } 
            case 4: 
                head = deleteFront(head); 
                break; 
            case 5: 
                displayAndCount(head); 
                break; 
            case 6: 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
 
    return 0; 
}