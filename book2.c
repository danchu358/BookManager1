#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 매크로 설정
#define MAX_BOOKS 5

// 구조체 설정
struct bookInfo
{
    int book_num;
    char book_name[20];
    char writer[20];
    char company[20];
    int price;
};

// 동적으로 메모리를 할당할 구조체 포인터
struct bookInfo* books[MAX_BOOKS];
int count = 0;

// 함수 선언
int menu();
int input();
int search();
int list();
void freeMemory();

int main(void)
{
    menu();
    freeMemory(); // 프로그램 종료 전에 메모리 해제
    return 0;
}

int menu()
{
    int num;

    while (1)
    {
        printf("*****메뉴*****\n");
        printf("1. 등록\n");
        printf("2. 검색\n");
        printf("3. 목록\n");
        printf("0. 종료\n");

        scanf("%d", &num);
        getchar();

        switch (num)
        {
        case 1:
            input();
            break;
        case 2:
            search();
            break;
        case 3:
            list();
            break;
        case 0:
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}

int input()
{
    if (count >= MAX_BOOKS) {
        printf("도서 저장 공간이 가득 찼습니다.\n");
        return 0;
    }

    struct bookInfo* a = malloc(sizeof(struct bookInfo));
    if (a == NULL) {
        printf("메모리 할당 오류\n");
        return 1; // 오류 반환
    }

    printf("책을 등록하세요\n");
    printf("번호 : ");
    scanf("%d", &a->book_num);
    getchar();
    printf("책 이름 : ");
    fgets(a->book_name, sizeof(a->book_name), stdin);
    printf("저자 : ");
    fgets(a->writer, sizeof(a->writer), stdin);
    printf("출판사 : ");
    fgets(a->company, sizeof(a->company), stdin);
    printf("가격 : ");
    scanf("%d", &a->price);
    getchar();

    books[count] = a; // 구조체 포인터 배열에 저장
    count++;

    return 0;
}

int search()
{
    char title[20];
    int found = 0;

    printf("책 이름 또는 저자를 입력하세요: ");
    fgets(title, sizeof(title), stdin);

    for (int i = 0; i < count; i++) {
        if (strcmp(title, books[i]->book_name) == 0 || strcmp(title, books[i]->writer) == 0) {
            printf("책 번호: %d, 이름: %s, 저자: %s, 출판사: %s, 가격: %d\n",
                   books[i]->book_num, books[i]->book_name, books[i]->writer, books[i]->company, books[i]->price);
            found = 1;
        }
    }

    if (!found)
        printf("검색된 도서가 없습니다.\n");

    return 0;
}

int list()
{
    for (int i = 0; i < count; i++) {
        printf("책 번호: %d, 이름: %s, 저자: %s, 출판사: %s, 가격: %d\n",
               books[i]->book_num, books[i]->book_name, books[i]->writer, books[i]->company, books[i]->price);
    }
    if (count == 0) {
        printf("등록된 도서가 없습니다.\n");
    }
    return 0;
}

void freeMemory() {
    for (int i = 0; i < count; i++) {
        free(books[i]); // 할당된 메모리 해제
    }
}