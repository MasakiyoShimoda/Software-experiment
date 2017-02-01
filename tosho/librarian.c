//
//  main.c
//  tosho
//
//  Created by 下田将斉 on 2017/01/25.
//  Copyright © 2017年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "common.c"

#define BM_TABLE_SIZE 256

void auth();
void bookSerch(char *, Book[]);
void bookLend(char *, Book[]);
void bookReturn(char *, Book[]);
void bookRegistration(Book[]);
void mainMenu(Book[]);
int reSelect(int, int);
int N;

int main(int argc, const char * argv[]) {
    // insert code here...
    N = readLine();
    
    Book book[500];
    auth();
    readData(book, N);
    mainMenu(book);
    //printData(book, N);
    writeData(book, N);
    
    return 0;
}

void auth(){
    char pass[20];
    char authPass[] = "1234";
    int count = 0;
    
    /* Auth Paddword */
    printf("-----Librarian Program-----\n");
    printf("Librarian's password:");
    scanf("%s" ,pass);
    while (strcmp(authPass, pass) != 0) {
        printf("Permission denied, please try again:");
        scanf("%s" ,pass);
        count++;
        if (count == 2)
            exit(9);
    }
}

void mainMenu(Book book[]){
    /* Main Menu*/
    char select[40] = {}, operand[30] = {}, command[10] = {};
    int i, j = 0, flag = 0;
    
    getchar();
    while (-1) {
        j = flag = 0;
        memset(operand, '\0', 30);
        memset(command, '\0', 10);
        memset(select, '\0', 40);
        
        printf("[Librarian@MainMenu] >");
        
        fgets(select , 256 , stdin);
        for (i = 0;select[i] != '\n'; i++) {
            if (select[i] == ' ')
                flag = 1;
            if (flag == 1 && select[i+1] != '\n'){
                operand[j] = select[i + 1];
                j++;
            } else if (flag == 0)
                command[i] = select[i];
        }
        
        flag = strcmp(operand, " ");
        
        if (strcmp(select, "help\n") == 0) {
            printf("How to use\n");
            printf("search OPERAND\n\tSearch search and select NUMBER\n");
            printf("lend NUMBER\n\tLend books in stock\n");
            printf("return NUMBER\n\tReturn books\n");
            printf("add\n\tAdd books in library\n");
            printf("exit\n");
        } else if (strcmp(command, "search") == 0){
            if (flag != -32 && flag != 0)
                bookSerch(operand, book);
            else
                puts("search BOOKS...");
        }else if (strcmp(command, "lend") == 0){
            if (flag != -32 && flag != 0)
                bookLend(operand, book);
            else
                puts("lend NUMBER...");
        }else if (strcmp(command, "return") == 0){
            if (flag != -32 && flag != 0)
                bookReturn(operand, book);
            else
                puts("return NUMBER...");
        }else if (strcmp(command, "add") == 0){
            if (flag != -32 && flag != 0)
                bookRegistration(book);
            else
                bookRegistration(book);
        }else if (strcmp(command, "exit") == 0)
            return;
        else
            printf("Not found.\n");
    }
}

int reSelect(int min, int max){
    char select[100];
    int selectNumber;
    fgets(select, 100, stdin);
    selectNumber = atoi(select);
    while(min > selectNumber || selectNumber > max){
        printf("Please try again >");
        memset(select, '\0', 100);
        fgets(select, 100, stdin);
        selectNumber = atoi(select);
    }
    return selectNumber;
}

void bookSerch(char *operand, Book book[]){
    char *tp = NULL, *ap = NULL;
    int i, count = 0;
    
    printf("[pattern]:%s\n", operand);
    
    for (i = 0; i < N; i++){
        tp = bm_search(book[i].title, operand);
        ap = bm_search(book[i].author, operand);
        if(tp != NULL || ap != NULL){
            book[count].temp = book[i].id;
            printf("---------------%d---------------\n", count+1);
            printf("ID\t\t:%d\n", book[i].id);
            printf("TITLE\t:%s\n", book[i].title);
            printf("AUTHER\t:%s\n", book[i].author);
            printf("STOCK\t:%s\n", (book[i].isLend ? "Out of stock" : "In stock"));
            count++;
        }
    }
}

void bookLend(char *operand, Book book[]){
    if (atoi(operand) == 0){
        puts("Please serach books.");
        return;
    }
    if (book[book[atoi(operand)-1].temp-1].isLend == 1) {
        printf("Sorry, out of stock\n");
        return;
    }else if (book[book[atoi(operand)-1].temp-1].isLend == 0){
        book[book[atoi(operand)-1].temp-1].isLend = 1;
        printf("Complete\n");
    }
}

void bookReturn(char *operand, Book book[]){
    if (atoi(operand) == 0){
        puts("Please serach books.");
        return;
    }
    if (book[book[atoi(operand)-1].temp-1].isLend == 0) {
        printf("Sorry, in stock\n");
        return;
    }else if (book[book[atoi(operand)-1].temp-1].isLend == 1){
        book[book[atoi(operand)-1].temp-1].isLend = 0;
        printf("Complete\n");
    }
}

void bookRegistration(Book book[]){
    int i, ids = 500;
    
    printf("[Librarian@AddMenu]:\n");
    
    printf("ID >");
    ids = reSelect(1, 500);
    for (i = 0; i < N; i++){
        if (ids == book[i].id) {
            puts("ID exixts");
            return;
        }
    }
    
    printf("TITLE >");
    fgets(book[N].title, 100, stdin);
    for (i = 0; i < 100; i++)
        if (book[N].title[i] == '\n')
            book[N].title[i] = '\0';
    
    printf("AUTHER >");
    fgets(book[N].author, 100, stdin);
    for (i = 0; i < 100; i++)
        if (book[N].author[i] == '\n')
            book[N].author[i] = '\0';
    
    printf("---------------COMPLETE---------------\n");
    book[N].id = ids;
    printf("ID\t\t:%d\n", book[N].id);
    printf("TITLE\t:%s\n", book[N].title);
    printf("AUTHER\t:%s\n", book[N].author);
    book[N].isLend = 0;
    N++;
}
