//
//  main.c
//  Number guessing game
//
//  Created by 下田将斉 on 2016/05/18.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_WIN 4;
#define COMPUTER_WIN 7;
#define UNDER_VALUE 5;
#define OVER_VALUE 6;

int score(int, int);
int setPlayerNum();
int setComputerNum();
int selectPlayerNum();
int selectComputerNum(int);
int matchingPvC(int, int);
int matchingCvP(int, int);
int game();

int main(int argc, const char * argv[]) {
    int start = 0, win = 0, lose = 0;
    do{
        printf("\n数当てゲームをする:1\n成績を見る:2\nゲームを終わる:3\n>>");
        scanf("%d", &start);
        switch(start){
            case 1:
                if(game() == 4){
                    win++;
                    break;
                }else{
                    lose++;
                    break;
                }
            case 2:
                score(win, lose);
                break;
            case 3:
                return 0;
        }
    }while(start != 3);
}

int score(win, lose){
    int i = 0;
    printf("勝ち:%d\n負け:%d\n", win, lose);
    printf("戻るにはなにか数字を押してください>>");
    scanf("%d",&i);
    
    return i;
}

int setPlayerNum(){
    int playerNum = 0;
    while(playerNum <= 0 || playerNum >= 21){
        printf("1〜20までの数字を選んでね >>");
        scanf("%d", &playerNum);
    }
    return playerNum;
}

int setComputerNum(){
    int computerNum = 0;
    srand((unsigned int)time(NULL));
    while(computerNum == 0)
        computerNum = rand()%20;
    printf("コンピューターが数字を選びました\n%d(普通は見えないけど確認用)\n", computerNum);
    
    return computerNum;
}

int selectPlayerNum(){
    int selectedPlayerNum = 0;
    while(selectedPlayerNum <= 0 || selectedPlayerNum >= 21){
        printf("1〜20までのCPUが選んだと思う数字を入力してね >>");
        scanf("%d", &selectedPlayerNum);
    }
    return selectedPlayerNum;
}

int selectComputerNum(level){
    int selectedComputerNum = 0, tmp;
    srand((unsigned int)time(NULL));
    if(level == 0){
		printf("a^\n");
        while(selectedComputerNum == 0)
            selectedComputerNum = rand()%20;
        printf("コンピューターはあなたの数字を%dだと予測しました\n", selectedComputerNum);
		tmp = selectedComputerNum;
    }else if(level == 5){
		printf("b^\n");
        while(selectedComputerNum >= tmp && selectedComputerNum == 0)
            selectedComputerNum  = rand()%20;
        printf("コンピューターはあなたの数字を%dだと予測しました\n", selectedComputerNum);
		tmp = selectedComputerNum;
    }else if(level == 6){
		printf("c^\n");
        while(selectedComputerNum <= tmp && selectedComputerNum == 0){
            selectedComputerNum  = rand()%20;
			printf("d^\n");
		}
        printf("コンピューターはあなたの数字を%dだと予測しました\n", selectedComputerNum);
		tmp = selectedComputerNum;
    }
    return selectedComputerNum;
}

int matchingPvC(int num1, int num2){
    if(num1 == num2){
        printf("正解です！\n");
        return PLAYER_WIN;
    }else if(num1 < num2){
        printf("もっと大きい値です\n");
        return OVER_VALUE;
    }else if(num1 > num2){
        printf("もっと小さな値です\n");
        return UNDER_VALUE;
    }
    return -1;
}

int matchingCvP(int num1, int num2){
    if(num1 == num2){
        printf("あなたの負けです\n");
        return COMPUTER_WIN;
    }else if(num1 < num2){
        return OVER_VALUE;
    }else if(num1 > num2)
        return UNDER_VALUE;
    return -1;
}

int game(){
    int result1, result2, level = 0, i, j, k, l;
    j = setComputerNum();
    k = setPlayerNum();
    do{
        i = selectPlayerNum();
        result1 = matchingPvC(i, j);
        l = selectComputerNum(level);
        result2 =  matchingCvP(k, l);
		level = result2;
    }while (result1 != 4 && result2 != 7);
	if(result1 == 4) 
		return result1;
	else if(result2 == 7)
		return result2;
}
