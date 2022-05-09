#include <stdio.h>
#include <string.h>
#include "menu.h"

int selectMenu(){
    int menu;
    printf(" \n*** 가격계산기 \n");
    printf("1. 조회 \n");
    printf("2. 추가 \n");
    printf("3. 수정 \n");
    printf("4. 삭제 \n");
    printf("5. 파일저장 \n");
    printf("6. 이름검색 \n");
    printf("0. 종료 \n\n");
    printf("=> 원하는 메뉴는 ? ");
    scanf("%d", &menu);
    return menu;
}

int addMenu(Menu *s){
    printf("예약자 이름은? \n");
    scanf("%10s", s->name);
    printf("사용할 시간은? \n");
    scanf("%d", &s->time);
    printf("좌석 종류는? \n");
    scanf("%d", &s->type);
    printf("좌석 번호는? \n");
    scanf("%10s", s->num);
    printf("=> 추가됨 \n");
    return 1;
}

void readMenu(Menu s){
    printf("%10s %d %d %10s ", s.name, s.time, s.type, s.num);
}

void listMenu(Menu *s, int count){
    printf("예약자 사용시간 좌석종류 좌석번호\n");
    printf("=====================================\n");
    for (int i = 0; i < count; i++){
        if(s[i].time == -1) continue;
        printf("%d ", i+1) 
        readMenu(s[i]); 
        printf("\n");
    }
    printf("\n");
}

int selectDataNo(Menu *s, int count){
    int no;
    listMenu(s, count);
    printf("번호는 (취소: 0)? ");
    scanf("%d", &no);
    return no;
}

int updateMenu(Menu *s){
    printf("예약자 이름은? \n");
    scanf("%10s", s->name);
    printf("사용할 시간은? \n");
    scanf("%d", &s->time);
    printf("좌석 종류는? \n");
    scanf("%d", &s->type);
    printf("좌석 번호는? \n");
    scanf("%10s", s->num);
    printf("=> 수정됨! \n");
    return 1;
}

int deleteMenu(Menu *s){ 
    s->time == -1;
    s->type == -1;
    return 1;
}

void saveData(Menu *s, int count){
    FILE *fp;
    fp = fopen("menu.txt", "wt"); 
    for (int i = 0; i <count; i++){ 
        if (s[i].time == -1) continue;
        fprintf(fp, "%10s %d %d %10s ", s[i].name, s[i].time, s[i].type, s[i].num);
    }
    fclose(fp); 
    printf("=> 저장됨! \n";
}

int loadData(Menu *s){
    int count = 0, i = 0; 
    FILE *fp; 
    fp = fopen("menu.txt", "rt"); 
    for (; i < 100; i++){ 
        fscanf(fp, "%10s", s[i].name); 
        if (feof(fp)) break; 
        fscanf(fp, "%d", &s[i].time); 
        fscanf(fp, "%d", &s[i].type); 
        fscanf(fp, "%10s", s[i].num); 
    }
    fclose(fp); 
    printf("=> 로딩성공!\n");
    return i; 
    
}
