#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main() {
    Book* head = NULL; // start of node 
    int choice;
    printf("Welcome to my library <3\n");
    while (1) {
        printf("1.add Book\n");
        printf("2.Display Books\n");
        printf("3.Search Book\n");
        printf("4.Borrow Book\n");
        printf("5.Return Book\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook(&head);
            break;
        case 2:
            displayBooks(head);
            break;
        case 3:
            searchBook(head);
            break;
        case 4:
            borrowBook(head);
            break;
        case 5:
            returnBook(head);
            break;
        case 6:
            printf("Exiting program\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}