#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    long long sapID;
    char rollNo[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
};

struct Student students[100];
int count = 0;

void addStudent() {
    if (count >= 100) {
        printf("Storage full. Cannot add more students.\n");
        return;
    }

    struct Student s;

    printf("Enter SAP ID: ");
    scanf("%lld", &s.sapID);

    printf("Enter Roll No: ");
    scanf("%s", s.rollNo);

    printf("Enter Name: ");
    scanf(" ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Phone No: ");
    scanf("%s", s.phone);

    printf("Enter Email: ");
    scanf("%s", s.email);

    do {
        printf("Enter Year (1/2/3/4): ");
        scanf("%d", &s.year);
        if (s.year < 1 || s.year > 4)
            printf("Invalid year. Enter 1, 2, 3, or 4.\n");
    } while (s.year < 1 || s.year > 4);

    do {
        printf("Enter Current Semester (1-8): ");
        scanf("%d", &s.semester);
        if (s.semester < 1 || s.semester > 8)
            printf("Invalid semester. Enter a value between 1 and 8.\n");
    } while (s.semester < 1 || s.semester > 8);

    printf("Enter SGPA for completed semesters (enter 0 if not done):\n");
    int i;
    for (i = 0; i < 8; i++) {
        printf("  Semester %d SGPA: ", i + 1);
        scanf("%f", &s.sgpa[i]);
    }

    students[count] = s;
    count++;
    printf("Student added successfully!\n");
}

void printStudent(struct Student s) {
    printf("\n-----------------------------\n");
    printf("SAP ID    : %lld\n", s.sapID);
    printf("Roll No   : %s\n", s.rollNo);
    printf("Name      : %s\n", s.name);
    printf("Phone     : %s\n", s.phone);
    printf("Email     : %s\n", s.email);
    printf("Year      : %d\n", s.year);
    printf("Semester  : %d\n", s.semester);
    printf("SGPA      : ");
    int i;
    for (i = 0; i < 8; i++) {
        if (s.sgpa[i] > 0)
            printf("S%d:%.2f  ", i + 1, s.sgpa[i]);
    }
    printf("\n-----------------------------\n");
}

void displayAll() {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }
    int i;
    for (i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

void searchStudent() {
    long long id;
    printf("Enter SAP ID to search: ");
    scanf("%lld", &id);

    int i;
    for (i = 0; i < count; i++) {
        if (students[i].sapID == id) {
            printStudent(students[i]);
            return;
        }
    }
    printf("Student with SAP ID %lld not found.\n", id);
}

void deleteStudent() {
    long long id;
    printf("Enter SAP ID to delete: ");
    scanf("%lld", &id);

    int i, found = -1;
    for (i = 0; i < count; i++) {
        if (students[i].sapID == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Student not found.\n");
        return;
    }

    for (i = found; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    printf("Student deleted successfully.\n");
}

float calcCGPA(int index) {
    float total = 0;
    int done = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (students[index].sgpa[i] > 0) {
            total += students[index].sgpa[i];
            done++;
        }
    }
    if (done == 0) return 0;
    return total / done;
}

void showCGPA() {
    long long id;
    printf("Enter SAP ID: ");
    scanf("%lld", &id);

    int i;
    for (i = 0; i < count; i++) {
        if (students[i].sapID == id) {
            float cgpa = calcCGPA(i);
            printf("CGPA of %s: %.2f\n", students[i].name, cgpa);
            return;
        }
    }
    printf("Student not found.\n");
}

void avgCGPAByYear() {
    int y;
    for (y = 1; y <= 4; y++) {
        float total = 0;
        int cnt = 0;
        int i;
        for (i = 0; i < count; i++) {
            if (students[i].year == y) {
                total += calcCGPA(i);
                cnt++;
            }
        }
        if (cnt > 0)
            printf("Year %d Average CGPA: %.2f (from %d students)\n", y, total / cnt, cnt);
        else
            printf("Year %d: No students found.\n", y);
    }
}

void sortBySAPID() {
    int i, j;
    struct Student temp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (students[j].sapID > students[j + 1].sapID) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Records sorted by SAP ID:\n");
    displayAll();
}

void sortByName() {
    int i, j;
    struct Student temp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Records sorted by Name:\n");
    displayAll();
}

void academicAdvisor() {
    long long id;
    printf("Enter SAP ID: ");
    scanf("%lld", &id);

    int i;
    for (i = 0; i < count; i++) {
        if (students[i].sapID == id) {
            float cgpa = calcCGPA(i);
            printf("\nStudent: %s | CGPA: %.2f\n", students[i].name, cgpa);
            printf("Academic Advice: ");

            if (cgpa >= 8.5) {
                printf("Excellent performance. Keep up your current study routine.\n");
            } else if (cgpa >= 7.0) {
                printf("Good performance. Try to push a bit harder in weaker subjects.\n");
            } else if (cgpa >= 5.5) {
                printf("Needs improvement. Focus on subjects where your SGPA is low.\n");
            } else {
                printf("Requires immediate attention. Please talk to your faculty advisor.\n");
            }
            return;
        }
    }
    printf("Student not found.\n");
}

void showMenu() {
    printf("\n========= STUDENT RECORD SYSTEM =========\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Display All Students\n");
    printf("4. Delete Student\n");
    printf("5. Show CGPA of a Student\n");
    printf("6. Average CGPA by Year\n");
    printf("7. Sort by SAP ID\n");
    printf("8. Sort by Name\n");
    printf("9. AI Academic Advisor\n");
    printf("0. Exit\n");
    printf("=========================================\n");
    printf("Enter choice: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: displayAll(); break;
            case 4: deleteStudent(); break;
            case 5: showCGPA(); break;
            case 6: avgCGPAByYear(); break;
            case 7: sortBySAPID(); break;
            case 8: sortByName(); break;
            case 9: academicAdvisor(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
