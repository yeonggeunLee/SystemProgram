#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int midterm_score;
    int final_score;
    struct Student* left;
    struct Student* right;
};

struct Student* createStudent(char name[], int midterm_score, int final_score) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->midterm_score = midterm_score;
    newStudent->final_score = final_score;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

struct Student* insertStudent(struct Student* root, char name[], int midterm_score, int final_score) {
    if (root == NULL) {
        return createStudent(name, midterm_score, final_score);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insertStudent(root->left, name, midterm_score, final_score);
    } else {
        root->right = insertStudent(root->right, name, midterm_score, final_score);
    }

    return root;
}

struct Student* searchStudent(struct Student* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchStudent(root->left, name);
    } else {
        return searchStudent(root->right, name);
    }
}

void inOrderTraversal(struct Student* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Name: %s, Midterm: %d, Final: %d\n", root->name, root->midterm_score, root->final_score);
        inOrderTraversal(root->right);
    }
}

void deleteTree(struct Student* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct Student* root = NULL;

    for (int i = 0; i < num_students; i++) {
        char name[50];
        int midterm_score, final_score;
        printf("Enter student name: ");
        scanf("%s", name);
        printf("Enter midterm score: ");
        scanf("%d", &midterm_score);
        printf("Enter final score: ");
        scanf("%d", &final_score);

        root = insertStudent(root, name, midterm_score, final_score);
    }

    printf("Student Information:\n");
    inOrderTraversal(root);

    char search_name[50];
    printf("Enter a name to search: ");
    scanf("%s", search_name);
    struct Student* found_student = searchStudent(root, search_name);
    if (found_student != NULL) {
        printf("Student found: Name: %s, Midterm: %d, Final: %d\n", found_student->name, found_student->midterm_score, found_student->final_score);
    } else {
        printf("Student not found.\n");
    }

    deleteTree(root);

    return 0;
}

