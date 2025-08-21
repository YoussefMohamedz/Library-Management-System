#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void addBook(Book** head) { // pointer to pointer
    Book* newBook = malloc(sizeof(Book)); // ha7gz mkan fel memory lel new book

    printf("enter book title: ");
    scanf(" %[^\n]", newBook->title);// title gwa el node

    printf("Enter author name: ");
    scanf(" %[^\n]", newBook->author);// author gwa el node

    printf("Enter ISBN: ");
    scanf(" %[^\n]", newBook->isbn); // isbn gwa el node

    newBook->isBorrowed = 0; // hanstart in hwa mesh borrowed
    newBook->next = *head;   // next y4awr 3la el node el 2adema and head hayro7 y4awr 3la el gded ely hya new book
    *head = newBook;         // han5leh y4awr 3la node gdeda
    printf("Book added successfully!\n");
}

void displayBooks(Book* head) {
    if (head == NULL) { // law el head mesh by4awr 3la 7aga ma3naha eno mesh a6d ay ktab aw 3ml ay 7aga
        printf("\mNo books available.\n");
        return;
    }
    Book* temp = head; // pointer temp hay4awr 3la el address bta3 el head
    printf("\nLibrary Books:\n");
    while (temp != NULL) { // tol ma feh valus 3and el temp (bet4awr 3la el pointer head) yb2a aked feh values added 
        printf("\nTitle: %s\nAuthor: %s\nISBN: %s\nStatus: %s\n",
            temp->title,
            temp->author,
            temp->isbn,
            temp->isBorrowed ? "Borrowed" : "Available"); // da condition law hwa borrowed hayprint "borrowed" law la2 hayprint "available"
        temp = temp->next;// el temp hat4awr 3la el next
    }
}

void searchBook(Book* head) {
    if (head == NULL) { // m3naha lesa mafesh 7aga added 
        printf("\nNo books available.\n");

    }

    char keyword[MAX_TITLE];// max title 3amlo define 100
    printf("\nEnter title or author to search: ");
    scanf(" %[^\n]", keyword);
    Book* temp = head;
    int found = 0;

    while (temp != NULL) { // law null hya asln mfha4 7aga 
        if (strstr(temp->title, keyword) != NULL || strstr(temp->author, keyword) != NULL)// dawrly 3la el keyword fel node ely m4awr 3leha temp 4of fel title or author mawgood wla la 
        {
            printf("\nTitle: %s\nAuthor: %s\nISBN: %s\nStatus: %s\n",
                temp->title,
                temp->author,
                temp->isbn,
                temp->isBorrowed ? "Borrowed" : "Available");// nafs el ask hay4of law borrowed hyzharlo borrowed else hayb2a available
            found = 1;
        }
        temp = temp->next;// hayfdl y4awr 3la next l7d ma el list t5ls w yb2a by4awr 3la null
    }

    if (!found) { // ana m5aly found 1 lama bysearch law still zero f keda mad5l4 el condition asln w found still = 0 f mafesh books bel data deh 
        printf("no matching book found\n");
    }
}
void borrowBook(Book* head) {
    char isbn[MAX_ISBN]; // max bin 3amlo define b 20 
    printf("\nEnter ISBN of the book to borrow: ");
    scanf(" %[^\n]", isbn);

    Book* temp = head; // pointer temp y4awr 3la el head
    while (temp != NULL) {
        if (strcmp(temp->isbn, isbn) == 0) { // hay4of law el two strings are exactly same = zero de fekrt el function string compare 
            if (temp->isBorrowed) { // han3ml condition b2a n4of hwa borrwed wla la2 by mafrod law temp el node ely m4awr 3leha law feha value 3and is borrwed hay2olo hwa allready borrwed
                printf("book is already borrowed\n");
            }
            else {
                temp->isBorrowed = 1;
                printf("Book borrowed successfully\n");
            }
            return;
        }
        temp = temp->next;// 3ayzeno y4awr 3la next node 
    }

    printf("Book with ISBN %s not found.\n", isbn); // law asln ma da5l el condition ely fo2 so he isnt in the library
}
void returnBook(Book* head) {
    char isbn[MAX_ISBN]; // maxisbn i defined it as 100 value 
    printf("\nEnter ISBN of the book to return: ");
    scanf(" %[^\n]", isbn);

    Book* temp = head;
    while (temp != NULL) { // law bysawy null so node isnt have any value
        if (strcmp(temp->isbn, isbn) == 0) {
            if (!temp->isBorrowed) { // if he asln mesh borrwed so he cant return the book so we ask n4of el node fel is borrwed feh value or not it its not so he cant return 
                printf("Book was not borrowed.\n");
            }
            else {
                temp->isBorrowed = 0; // we will change the value into 0 so book is returned u can borrow it
                printf("Book returned successfully.\n");
            }
            return;
        }
        temp = temp->next; // n5aly temp y4awr 3la el node el gdeda 
    }

    printf("book with ISBN %s not found.\n", isbn); // law asln ma da5l4 f ay condition el book asln not mawgood
}