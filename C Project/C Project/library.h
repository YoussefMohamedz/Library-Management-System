#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_ISBN 20

typedef struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char isbn[MAX_ISBN];
    int isBorrowed;
    struct Book* next;
} Book;

void addBook(Book** head);
void borrowBook(Book* head);
void returnBook(Book* head);
void searchBook(Book* head);
void displayBooks(Book* head);
void saveBooks(Book* head, const char* filename);
void loadBooks(Book** head, const char* filename);

#endif
