#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for storing student information
struct Student {
    int rollNo;
    char name[50];
    int age;
    char className[20];
    float marks;
};

// Array to store students
struct Student students[MAX];

int count = 0;

// Function to add a student
void addStudent() {
    if (count >= MAX) {
        printf("\nDatabase is full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Class: ");
    scanf(" %[^\n]", students[count].className);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}

// Function to display all students
void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", students[i].rollNo);
        printf("Name        : %s\n", students[i].name);
        printf("Age         : %d\n", students[i].age);
        printf("Class       : %s\n", students[i].className);
        printf("Marks       : %.2f\n", students[i].marks);
    }
}

// Function to search for a student
void searchStudent() {
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Age         : %d\n", students[i].age);
            printf("Class       : %s\n", students[i].className);
            printf("Marks       : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}

// Function to update student details
void updateStudent() {
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New Class: ");
            scanf(" %[^\n]", students[i].className);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nStudent details updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}

// Function to delete a student
void deleteStudent() {
    int roll, i, j;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {

        if (students[i].rollNo == roll) {

            // Shift all records one position left
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}

// Main function
int main() {

    int choice;

    while (1) {

        printf("\n\n====================================");
        printf("\n     SCHOOL DATABASE SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you for using the School Database System!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}