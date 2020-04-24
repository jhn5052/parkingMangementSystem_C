#include <stdio.h>
#include <stdlib.h>


typedef struct tm {
    int tm_sec;         /* 초,  range 0 to 59            */
    int tm_min;         /* 분, range 0 to 59             */
    int tm_hour;        /* 시간, range 0 to 23            */
    int tm_mday;        /* 일, range 1 to 31             */
    int tm_mon;         /* 월, range 0 to 11             */
    int tm_year;        /* 1900년 부터의 년                */
    int tm_wday;        /* 요일, range 일(0) to 토(6)      */
    int tm_yday;        /* 1년 중 경과 일, range 0 to 365  */
    int tm_isdst;       /* 써머타임                        */
}tm;


//차 정보 구조체
typedef struct Car {
    int car_no, sec_y, sec_x; //차 번호, (y, x)구역에 차 주차
    struct tm* date; //요금 정산, 내차 조회
    struct Car* next;
}Car;

//주차 회원 구조체
typedef struct Mem {
    int car_no;
    char* name;
    struct Mem* next;
}Mem;

//주차 리스트
typedef struct car_list {
    Car* head;
    int size;
}clist;

//회원 리스트
typedef struct mem_list {
    Mem* head;
    int size;
}mlist;

void car_init(clist* car_list);
void mem_init(mlist* mem_list);

void Select(mlist* mem_list);
int Signup(mlist* mem_list);
void Delete_customer(mlist* mem_list);

void Enter(clist* car_list, int parkinglot[][20]);
void Exit(clist* car_list);
int Calc(mlist * mlist, Car * car);
int general_calc(Car *car);

int disp_menu();
void disp_parkinglot(int parkinglot[][20]);

void Find_Car(clist* car_lsit);


Car* findCarNode(clist* car_list, int car_no);
Car* findPrevCarNode(clist* car_list, int car_no);
Mem* findMemNode(mlist* mem_list, int car_no);