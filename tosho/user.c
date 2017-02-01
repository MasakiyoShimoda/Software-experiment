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

void bookSerch(char *, Book[]);
void mainMenu(Book[]);
int N;

int main(int argc, const char * argv[]) {
    // insert code here...
    N = readLine();
    
    Book book[500];
    readData(book, N);
    mainMenu(book);
    
    return 0;
}

void mainMenu(Book book[]){
    /* Main Menu*/
    char operand[30] = {};
    int i;
    
    while (-1) {
        memset(operand, '\0', 30);
        
        printf("[SearchLibrary] >");
        
        fgets(operand , 30 , stdin);
        for (i = 0; i < 30; i++)
            if (operand[i] == '\n')
                operand[i] = '\0';

        bookSerch(operand, book);
    }
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
            printf("STOCK\t:%d\n", book[i].isLend);
            count++;
        }
    }
}
