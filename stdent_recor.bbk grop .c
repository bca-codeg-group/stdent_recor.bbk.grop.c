#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    int age;
    float marks;
} Student;

void addStudent(Student students[], int *numStudents) {
    if (*numStudents == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student newStudent;

    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Enter name: ");
    scanf("%s", newStudent.name);

    printf("Enter age: ");
    scanf("%d", &newStudent.age);

    printf("Enter marks: ");
    scanf("%f", &newStudent.marks);

    students[*numStudents] = newStudent;
    (*numStudents)++;

    printf("Student added successfully.\n");
}

void displayStudents(Student students[], int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Roll Number\tName\t\tAge\tMarks\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("%d\t\t%s\t\t%d\t%.2f\n", students[i].rollNumber, students[i].name, students[i].age, students[i].marks);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("--------------------------------\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
