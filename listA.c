#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listA.h"

int main()
{
    // listType 형태의 구조체를 가리키는 포인터 생성
    // malloc 함수를 이용하여 Heap 공간에 listType 크기의 동적 메모리 할당
    listType *listA = (listType *)malloc(sizeof(listType));
    int menu, sequence, value;
    char quit;

    while (1)
    {
        printf("(1) 리스트 초기화\n\n");
        printf("(2) 리스트 공백여부 확인\n\n");
        printf("(3) 리스트 원소 등록\n\n");
        printf("(4) 리스트 원소 개수 확인\n\n");
        printf("(5) 리스트 원소 삽입\n\n");
        printf("(6) 리스트 원소 삭제\n\n");
        printf("(7) 리스트 원소 변경\n\n");
        printf("(8) 리스트 원소 검색\n\n");
        printf("(9) 프로그램 종료\n\n");
        printf("--- 기능선택: ");

        scanf("%d", &menu);
        getchar(); // 버퍼에 남아있는 '\n' 을 받아내어 버퍼를 비움

        switch (menu)
        {
            case 1:
                // 리스트 초기화
                Init(listA);
                break;
            case 2:
                // 공백 여부 반환
                if (IsEmpty(listA)) {
                    printf("리스트가 비어있습니다.\n");
                }
                else {
                    printf("리스트가 비어있지 않습니다.\n");
                }
                break;
            case 3:
                // 원소 추가
                Add(listA);
                break;
            case 4:
                // 원소 개수 반환
                printf("리스트에 들어 있는 원소의 개수: %d\n", Length(listA));
                break;
            case 5:
                // 원소 삽입
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();
                printf("정수 값: ");
                scanf("%d", &value);
                getchar();

                Insert(listA, sequence, value);
                break;
            case 6:
                // 원소 삭제
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();

                Delete(listA, sequence);
                break;
            case 7:
                // 원소 변경
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();
                printf("정수 값: ");
                scanf("%d", &value);
                getchar();

                Update(listA, sequence, value);
                break;
            case 8:
                // 원소 검색
                printf("몇 번째? ");
                scanf("%d", &sequence);
                getchar();

                // 예외 처리
                if ((sequence < 1) || (sequence > listA->Count)) {
                    printf("Position is out of Range\n");
                }
                else {
                    printf("검색 결과: %d\n", Retrieve(listA, sequence));
                }
                break;
            case 9:
                printf("프로그램을 종료합니다.\n");

                // Heap 에서 사용하던 메모리 반납
                free(listA);
                return 0;
        }
    }
}

// Lptr이라는 주소가 가리키는 구조체의 Count 변수를 0으로 초기화
void Init(listType* Lptr) {
    Lptr->Count = 0;
}

// Lptr이 가리키고 있는 리스트가 비어있으면 ‘참‘을 '비어있지 않으면 ’거짓‘을 반환
bool IsEmpty(listType* Lptr) {
    return (Lptr->Count == 0);
}

void Add(listType* Lptr) {
    char again[4]; // Int형 또는 하나의 문자를 저장하기 위한 배열 선언
    while (1) {
        printf("현재 등록된 원소 개수: %d\n", Lptr->Count); // 현재 원소의 개수 출력
        printf("정수를 입력하시오(종료하려면 X): ");
        scanf("%s", again);
        getchar();

        if (strcmp(again, "X") == 0){
            printf("등록을 종료하겠습니다.\n");
            break;
        }
        else {
            // Count가 최대 개수에 도달했는지 확인
            if (Lptr->Count == MAX) {
                printf("List is Full\n");
            }
            else {
                int add_value = atoi(again);
                Lptr->Data[Lptr->Count] = add_value;
                Lptr->Count++;
            }
        }
    }
}

// Lptr이 가리키고 있는 리스트에 들어 있는 의미있는 값의 개수를 반환
int Length(listType* Lptr) {
    return Lptr->Count; // Lptr이 가리키는 구조체의 Count 값 반환
}

// Lptr이 가리키고 있는 리스트의 Position 번째에 Item 값을 삽입
void Insert(listType* Lptr, int Position, int Item) {
    // Count 가 최대 개수에 도달했는지 확인
    if (Lptr->Count == MAX) {
        printf("List is Full\n");
    }
    else if ((Position < 1) || (Position > Lptr->Count + 1)) {
        printf("Position is out of Range\n");
    }
    else {
        // 현재 마지막 배열부터 시작하여 삽입될 위치까지 뒤로 이동
        for (int i = (Lptr->Count) - 1;i >= Position - 1;i--) {
            Lptr->Data[i + 1] = Lptr->Data[i];
        }
        Lptr->Data[Position - 1] = Item;
        Lptr->Count += 1;
    }
}

// Lptr이 가리키고 있는 리스트의 Position 번째 값 삭제
void Delete(listType* Lptr, int Position) {
    if (Lptr->Count == 0) {
        printf("List is Empty\n");
    }
    else if ((Position < 1) || (Position > Lptr->Count)) {
        printf("Position is out of Range\n");
    }
    else {
        // 현재 마지막 배열부터 시작하여 삽입될 위치까지 앞으로 이동
        for (int i = Position - 1;i <= (Lptr->Count) - 1;i++) {
            Lptr->Data[i] = Lptr->Data[i + 1];
        }
        Lptr->Count -= 1;
    }
}

// Lptr이 가리키고 있는 리스트의 Position 번째 내용을 Item 값으로 변경
void Update(listType* Lptr, int Position, int Item) {
    if (Lptr->Count == 0) {
        printf("List is Empty\n");
    }
    else if ((Position < 1) || (Position > Lptr->Count)) {
        printf("Position is out of Range\n");
    }
    else {
        Lptr->Data[Position - 1] = Item;
    }
}

// Lptr이 가리키고 있는 리스트의 Position 번째 값 반환
int Retrieve(listType* Lptr, int Position) {
    if (Lptr->Count == 0) {
        printf("List is Empty\n");
    }
    else if ((Position < 1) || (Position > Lptr->Count)) {
        printf("Position is out of Range\n");
    }
    else {
        return Lptr->Data[Position - 1];
    }
}