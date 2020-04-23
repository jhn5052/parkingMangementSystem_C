#include "parking.h"
#include<string.h>


int disp_menu(void)
{
    int num;

    printf("\n===[ 주차 관리 시스템 ]===\n");
    printf("1. 회원 등록/삭제\n");
    printf("2. 주차하기\n");
    printf("3. 출차하기\n");
    printf("4. 주차 현황 보기\n");
    printf("5. 내 차 조회하기\n");
    printf("0. 종료\n");
    printf("---------------------------\n");

    printf("> 번호 선택 : ");
    scanf("%d", &num);

    return num;
}

void car_init(clist *car_list){
  car_list->size = 0;
  car_list->head = NULL;
}

void mem_init(mlist *mem_list){
  mem_list->size = 0;
  mem_list->head = NULL;
}

Car * findCarNode(clist * car_list,int car_no){
  Car * tmp = car_list->head;
  while(tmp){
    if(tmp->car_no==car_no)
      return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

Mem * findMemNode(mlist * mem_list,int car_no){
  Mem * tmp = mem_list->head;
  while(tmp){
    if(tmp->car_no==car_no)
      return tmp;
    tmp = tmp->next;
  }
  return NULL;
}

int Signup(mlist *mem_list, Mem *element){
  Mem *new_element;
  int car_num;
  char str[15];
  char *name = NULL;
  
  if(element == NULL && mem_list->size != 0){
    return -1;
  }
  if ((new_element = (Mem *)malloc(sizeof(Mem))) == NULL){
    return -1;
  }

  printf("==========회원 등록==========");
  printf(">> 이름을 입력하세요 : ");
  scanf(" %s", str);
  printf(">> 차량 번호를 입력하세요 : ");
  scanf(" %d", &car_num);

  if ((name = (char *)malloc(sizeof(strlen(str)))) == NULL) {
    return -1;
  }
  strcpy(name, str);
  
  if(findMemNode(mem_list, car_num)){
    printf("이미 등록된 회원입니다.");
    return -1;
  }

  if(mem_list->size == 0){
    mem_list->head = new_element;
    mem_list->head->next = NULL;
    strcpy(mem_list->head->name, (char*)name);
    mem_list->head->car_no = car_num;
  }

}

void disp_parkinglot(int parkinglot[][20]){
  const char *arr[2];
	arr[0] = "□";
	arr[1] = "■";

  for(int i=0;i<10;++i){
    for(int j=0;j<20;++j)
      if(parkinglot[i][j])
        printf("%c", *arr[1]);
      else
        printf("%c", *arr[0]);
        
    printf("\n");
  }
}

