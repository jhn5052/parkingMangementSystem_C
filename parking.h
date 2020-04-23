#include <stdio.h>
#include <stdlib.h>
#include "parking.c"

//차 정보 구조체
typedef struct Car{
  int car_no,sec_y,sec_x; //차 번호, (y, x)구역에 차 주차
  char * date; //요금 정산, 내차 조회
  struct Car * next;
}Car;

//주차 회원 구조체
typedef struct Mem{
  int car_no;
  char* name;
  struct Mem * next;
}Mem;

//주차 리스트
typedef struct car_list{
  Car* head;
  int size;
}clist;

//회원 리스트
typedef struct mem_list{
  Mem *head;
  int size;
}mlist;



void car_init(clist *car_list);
void mem_init(mlist *mem_list);
int Signup(mlist *mem_list, Mem *element);
int disp_menu();
void disp_parkinglot(int parkinglot[][20]);

void Enter();
void Exit();
int Calc();

Car * findCarNode(clist * car_list,int car_no);
Mem * findMemNode(mlist * mem_list,int car_no);