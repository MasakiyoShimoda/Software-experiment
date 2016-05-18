//
//  main.c
//  Rock-Paper-Scissors
//
//  Created by 下田将斉 on 2016/05/18.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setPlayerHand();
int setComputerHand();
int judge(int playerHand, int computerHand);
int match();
int score(int, int, int);

int main(int argc, const char * argv[]) {
    int start = 0, win = 0, lose = 0, draw = 0;
    do{
        printf("\nじゃんけんをする:1\n成績を見る:2\nゲームを終わる:3\n>>");
        scanf("%d", &start);
        switch(start){
            case 1:
                switch(match()){
                    case 3:
                        printf("あなたの勝ちです\n");
                        win++;
                        break;
                    case 4:
                        printf("あなたの負けです\n");
                        lose++;
                        break;
                    case 5:
                        printf("引き分けです\n");
                        draw++;
                        break;
                }
                break;
            case 2:
                score(win, lose, draw);
                break;
            case 3:
                return 0;
        }
    }while(start != 3);
}

int match(){
    int i, j;
    i = setPlayerHand();
    j = setComputerHand();
    return judge(i, j);
}

int setPlayerHand(){
    int playerHand = 0;
    printf("\nグー:0  チョキ:1  パー:2\nあなたの手を選択してください : ");
    scanf("%d", &playerHand);
    for (;playerHand != 0 && playerHand != 1 && playerHand != 2; ) {
        printf("正しくない数値です \nもう1度選びなおしてください : ");
        scanf("%d", &playerHand);
    }
    return playerHand;
}

int setComputerHand(){
    int computerHand = 0;
    srand((unsigned int)time(NULL));
    computerHand = rand()%3;
    if(computerHand == 0)
        printf("コンピューター : グー\n");
    else if(computerHand == 1)
        printf("コンピューター : チョキ\n");
    else
        printf("コンピューター : パー\n");
    return computerHand;
}

int judge(int playerHnad, int computerHand){
    int judgement = 0;
    if(playerHnad == computerHand)
        judgement = 5;
    else if(computerHand == (playerHnad + 1) % 3)
        judgement = 3;
    else
        judgement = 4;
    return judgement;
}

int score(win, lose, draw){
    int i = 0;
    printf("勝ち:%d\n負け:%d\n引き分け:%d\n", win, lose, draw);
    printf("戻るにはなにか数字を押してください\n>>");
    scanf("%d",&i);
    return i;
}
