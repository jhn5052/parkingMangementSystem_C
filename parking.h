#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//차 정보 구조체
typedef struct Car {
    int car_no, sec_y, sec_x; //차 번호, (y, x)구역에 차 주차
    int day; //요금 정산, 내차 조회
    int hour;
    int min;
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

void car_init(clist* car_list, int parkinglot[][20]);
void mem_init(mlist* mem_list);
void init_parkinglot(clist* car_list, int parkinglot[][20]);
void Select(mlist* mem_list);
int Signup(mlist* mem_list);
void Delete_customer(mlist* mem_list);

void Enter(clist* car_list, int(*parkinglot)[20]);
void Car_Exit(clist* car_list, mlist* mem_list, int(*parkinglot)[20]);

int general_calc(Car* car);

int disp_menu();
void disp_parkinglot(int(*parkinglot)[20]);

void Find_Car(clist* car_lsit);
void disp_Car(clist* car_list);
void disp_Mem(mlist* mem_list);

Car* findCarNode(clist* car_list, int car_no);
Car* findPrevCarNode(clist* car_list, int car_no);
Mem* findMemNode(mlist* mem_list, int car_no);
void Car_WriteOneLine(Car* car);
void Mem_WriteOneLine(Mem* mem);
void Car_FileRead(clist* car_list);
void insertCarNode(Car* car, clist* car_list);
void insertMemNode(Mem* mem, mlist* mem_list);
void RemoveCarFile(clist* car_list);
void RemoveMemFile(mlist* mem_list);
void WriteCarAll(clist* car_list);
void WriteMemAll(mlist*mem_list);
