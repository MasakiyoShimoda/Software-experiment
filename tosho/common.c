//
// 図書館プログラムのサンプル（来客者用と司書用の共通部分）
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DATAFILE "/Users/MasakiyoS/Desktop/Experimentation/Software/tosho/tosho/library.dat"
#define STR_MAX   256
#define BM_TABLE_SIZE 256

//------------------------------------------------
// 顧客データの構造体
//
typedef struct _Book {
    int id;                  // 本のID番号
    char title[STR_MAX];     // 本のタイトル
    char author[STR_MAX];    // 本の著者
    int isLend;              // 0=在庫有り、1=貸し出し中を示すフラグ
    int temp;
} Book;

//------------------------------------------------
// 蔵書情報を読み込む
// [引数]
//   book[] ... 蔵書情報を入れる配列
//   *N        ... 蔵書数を入れる変数
//
static void readData(Book book[], int N){
    FILE *fp;
    int i;
    char buf[256];
    
    if ((fp = fopen(DATAFILE, "r")) == NULL){
        fprintf (stderr, "error: %s not found.\n", DATAFILE);
        exit(1);
    }
    
    for (i = 0; i < N + 1; i++){
        fgets(buf, 256, fp);
        book[i].id = atoi(buf);
        
        fgets(book[i].title, STR_MAX, fp);
        book[i].title [ strlen(book[i].title ) - 1] = '\0';
        
        fgets(book[i].author, STR_MAX, fp);
        book[i].author[ strlen(book[i].author) - 1] = '\0';
        
        fgets(buf, 256, fp);
        book[i].isLend = atoi(buf);
    }
    fclose(fp);
}

//------------------------------------------------
// 顧客情報を書き込む
//   book[] ... 蔵書情報の入った配列
//   N         ... 蔵書数
//
static void writeData(Book book[], int N){
    FILE *fp;
    int i;
    
    if ((fp = fopen(DATAFILE, "w")) == NULL){
        fprintf (stderr, "error: 蔵書ファイル%sに書き込めません\n", DATAFILE);
        exit(1);
    }
    
    for (i = 0; i < N; i++){
        fprintf(fp, "%06d\n", book[i].id);
        fprintf(fp, "%s\n", book[i].title);
        fprintf(fp, "%s\n", book[i].author);
        fprintf(fp, "%d\n", book[i].isLend);
    }
    fclose(fp);
}

//------------------------------------------------
// 蔵書情報をすべて表示する
//
static void printData(Book book[], int N){
    int i;
    for (i = 0; i < N; i++){
        printf("------------\n");
        printf("ID  :\t%06d\n", book[i].id);
        printf("書名:\t%s\n", book[i].title);
        printf("著者:\t%s\n", book[i].author);
        printf("在庫:\t%s\n", (book[i].isLend ? "貸し出し中" : "在庫有り"));
    }
}

//------------------------------------------------
//蔵書検索アルゴリズム
//
static void bm_table_init(int *table, const char *pattern, int ptn_len){
    int cnt = 0;
    
    for(cnt = 0; cnt < BM_TABLE_SIZE; cnt++)
        table[cnt] = ptn_len;
    for(cnt = 0; cnt < ptn_len; cnt++)
        table[(int)pattern[cnt]] = ptn_len - cnt - 1;
}

static int next_step(int *table, char target, int remain){
    if(table[(int)target] > remain)
        return(table[(int)target]);
    else
        return(remain);
}

static char * bm_search(const char *text, const char *pattern){
    int table[BM_TABLE_SIZE], txt_len = 0, ptn_len = 0, i = 0, j = 0;
    
    ptn_len = strlen(pattern);
    txt_len = strlen(text);
    
    bm_table_init(table, pattern, ptn_len);
    
    i = j = ptn_len - 1;
    while((i < txt_len) && (j >= 0)){
        if(text[i] != pattern[j]){
            i += next_step(table, text[i], (ptn_len - j));
            j = ptn_len - 1;
        }else{
            j--;
            i--;
        }
    }
    
    if(j < 0)
        return((char *)text );
    return(NULL);
}

static int readLine(){
    FILE *fp;
    int line = 0;
    char c;
    
    if ((fp = fopen(DATAFILE, "r")) == NULL){
        fprintf (stderr, "error: 蔵書ファイル%sに書き込めません\n", DATAFILE);
        exit(1);
    }
    while((c = getc(fp)) != EOF)
        if(c == '\n')
            line++;
    
    return line/4;
}

