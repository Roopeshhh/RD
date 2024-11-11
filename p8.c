#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Structure to represent an employee 
struct Employee { 
char SSN[20]; 
char Name[50]; 
char Dept[30]; 
char Designation[30]; 
double Sal; 
char PhNo[15]; 
struct Employee *prev; 
struct Employee *next; 
};
// Function to create a new employee node 
struct Employee *createEmployee(char SSN[], char Name[], char Dept[], char Designation[], double Sal, 
char PhNo[]) { 
struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee)); 
if (newEmployee == NULL) { 
printf("Memory allocation failed.\n"); 
exit(1); 
} 
strcpy(newEmployee->SSN, SSN); 
strcpy(newEmployee->Name, Name); 
strcpy(newEmployee->Dept, Dept); 
strcpy(newEmployee->Designation, Designation); 
newEmployee->Sal = Sal; 
strcpy(newEmployee->PhNo, PhNo); 
newEmployee->prev = NULL; 
newEmployee->next = NULL; 
return newEmployee; 
} 
// Function to insert an employee at the end of the doubly linked list 
struct Employee *insertEnd(struct Employee *head, struct Employee *newEmployee) { 
if (head == NULL) { 
return newEmployee; 
} 
struct Employee *current = head; 
 while (current->next != NULL) { 
        current = current->next; 
    } 
 
    current->next = newEmployee; 
    newEmployee->prev = current; 
    return head; 
} 
 
// Function to insert an employee at the front of the doubly linked list 
struct Employee *insertFront(struct Employee *head, struct Employee *newEmployee) { 
    if (head == NULL) { 
        return newEmployee; 
    } 
 
    newEmployee->next = head; 
    head->prev = newEmployee; 
    return newEmployee; 
} 
 
// Function to delete an employee from the end of the doubly linked list 
struct Employee *deleteEnd(struct Employee *head) { 
    if (head == NULL) { 
        printf("List is empty. Cannot delete.\n"); 
        return head;
} 
 
    if (head->next == NULL) { 
        free(head); 
        return NULL; 
    } 
 
    struct Employee *current = head; 
    while (current->next->next != NULL) { 
        current = current->next; 
    } 
 
    free(current->next); 
    current->next = NULL; 
    return head; 
} 
 
// Function to delete an employee from the front of the doubly linked list 
struct Employee *deleteFront(struct Employee *head) { 
    if (head == NULL) { 
        printf("List is empty. Cannot delete.\n"); 
        return head; 
    } 
 
    if (head->next == NULL) {
  free(head); 
        return NULL; 
    } 
 
    struct Employee *newHead = head->next; 
    newHead->prev = NULL; 
    free(head); 
    return newHead; 
} 
 
// Function to display the doubly linked list and count the number of nodes 
void displayAndCount(struct Employee *head) { 
    struct Employee *current = head; 
    int count = 0; 
 
    printf("Employee Data:\n"); 
    printf("--------------------------------------------------------------------------------------------\n"); 
    printf("SSN\t\tName\t\tDept\t\tDesignation\t\tSal\t\tPhNo\n"); 
    printf("--------------------------------------------------------------------------------------------\n"); 
 
    while (current != NULL) { 
        printf("%s\t\t%s\t\t%s\t\t%s\t\t\t%.2lf\t\t%s\n", current->SSN, current->Name, current->Dept, 
current->Designation, current->Sal, current->PhNo); 
        current = current->next; 
        count++; 
    } 

  printf("\nTotal Employees: %d\n", count); 
} 
 
int main() { 
    struct Employee *head = NULL; 
    int choice; 
 
    while (1) { 
        printf("\nDoubly Linked List Menu:\n"); 
        printf("1. Create an Employee\n"); 
        printf("2. Insert at End\n"); 
        printf("3. Insert at Front\n"); 
        printf("4. Delete from End (Double Ended Queue demonstration)\n"); 
        printf("5. Delete from Front (Double Ended Queue demonstration)\n"); 
        printf("6. Display List and Count Nodes\n"); 
        printf("7. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: { 
                char SSN[20], Name[50], Dept[30], Designation[30], PhNo[15]; 
                double Sal; 
                printf("Enter SSN: "); 
  scanf("%s", SSN); 
                printf("Enter Name: "); 
                scanf("%s", Name); 
                printf("Enter Department: "); 
                scanf("%s", Dept); 
                printf("Enter Designation: "); 
                scanf("%s", Designation); 
                printf("Enter Salary: "); 
                scanf("%lf", &Sal); 
                printf("Enter Phone Number: "); 
                scanf("%s", PhNo); 
                struct Employee *newEmployee = createEmployee(SSN, Name, Dept, Designation, Sal, PhNo); 
                head = insertEnd(head, newEmployee); 
                break; 
            } 
            case 2: { 
                char SSN[20], Name[50], Dept[30], Designation[30], PhNo[15]; 
                double Sal; 
                printf("Enter SSN: "); 
                scanf("%s", SSN); 
                printf("Enter Name: "); 
                scanf("%s", Name); 
                printf("Enter Department: "); 
                scanf("%s", Dept); 
                printf("Enter Designation: "); 
  scanf("%s", Designation); 
                printf("Enter Salary: "); 
                scanf("%lf", &Sal); 
                printf("Enter Phone Number: "); 
                scanf("%s", PhNo); 
                struct Employee *newEmployee = createEmployee(SSN, Name, Dept, Designation, Sal, PhNo); 
                head = insertEnd(head, newEmployee); 
                break; 
            } 
            case 3: { 
                char SSN[20], Name[50], Dept[30], Designation[30], PhNo[15]; 
                double Sal; 
                printf("Enter SSN: "); 
                scanf("%s", SSN); 
                printf("Enter Name: "); 
                scanf("%s", Name); 
                printf("Enter Department: "); 
                scanf("%s", Dept); 
                printf("Enter Designation: "); 
                scanf("%s", Designation); 
                printf("Enter Salary: "); 
                scanf("%lf", &Sal); 
                printf("Enter Phone Number: "); 
                scanf("%s", PhNo); 
                struct Employee *newEmployee = createEmployee(SSN, Name, Dept, Designation, Sal, PhNo); 
  head = insertFront(head, newEmployee); 
                break; 
            } 
            case 4: 
                head = deleteEnd(head); 
                break; 
            case 5: 
                head = deleteFront(head); 
                break; 
            case 6: 
                displayAndCount(head); 
                break; 
            case 7: 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
 
    return 0; 
} 