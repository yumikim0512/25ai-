#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define N 5
#define LOG "log.txt"
#define R 7

struct F { char* n; };
struct Q { char* t;int a;char* o;char* x; };

void get_s(int* t, int* c) {
    FILE* f = NULL;char b[100], r;
    fopen_s(&f, LOG, "r"); *t = 0;*c = 0;
    if (f == NULL)return;
    while (fgets(b, sizeof(b), f) != NULL) {
        if (fgets(b, sizeof(b), f) != NULL) {
            *t += 1;
            if (b[0] == 'O')*c += 1;
        }
    }
    fclose(f);
}

void save_l(char* n, char r) {
    FILE* f = NULL;fopen_s(&f, LOG, "a");
    if (f == NULL) { perror("L");return; }
    fprintf(f, "%s\n%c\n", n, r);
    fclose(f);
}

char yn_g() {
    char c;
    while (1) { c = (char)_getch();if (c == 'Y' || c == 'y') { printf("Y\n");return'Y'; }if (c == 'N' || c == 'n') { printf("N\n");return'N'; } }
}

int main() {
    struct F FN[N] = { {"돌돔"},{"참돔"},{"광어"},{"부시리"},{"감성돔"} };
    struct Q QB[N] = {
        {"C언어에서 메모리 주소를 저장하는 변수는?\n(1) int (2) char (3) 포인터 (4) 배열",3,"정답! 낚시 실력이 대단하군!","땡! 기본적인 것도 모르면서 낚시를 하다니."},
        {"반복문에서 다음 반복으로 즉시 건너뛰는 명령어는?\n(1) break (2) goto (3) continue (4) return",3,"정확해! 역시 고수구나.","에이, 아쉽지만 오답이야. 다음 기회에."},
        {"콘솔 화면을 지우는 Windows 함수 호출은?\n(1) cls() (2) system(\"cls\") (3) clear() (4) clean_screen()",2,"와우! 환경 설정까지 완벽하게 알고 있군!","틀렸어. 역시 낚시는 운인가?"},
        {"함수 호출 시 변수의 '주소'를 넘겨주는 방식을 무엇이라 하는가?\n(1) Call by Value (2) Call by Reference (3) Call by Address (4) Call by Pointer",2,"정답! 포인터의 핵심을 이해하고 있군!","오답이야... 머리가 복잡해졌군."},
        {"동적 할당된 메모리를 해제하는 함수는?\n(1) delete (2) release (3) free (4) clear",3,"마지막 문제까지 완벽하게 맞췄어!","틀렸어! 기본부터 다시 배워야겠어."}
    };

    int t, c, i, r_i, q_i, ch; char yn, l_r;
    float s;
    get_s(&t, &c);

    system("cls");
    s = t > 0 ? (float)c / t : 0.0f;
    printf("===================================\n%d번째 게임입니다!!\n", t + 1);
    printf("누적 정답률: %d/%d (%.1f%%)\n===================================\n\n찌를 던진다 (Y/N) >", c, t, s * 100);
    yn = yn_g();

    if (yn == 'Y') {
        printf("\n== 총 %d번의 퀴즈를 진행합니다. ==\n", R);
        srand((unsigned int)time(NULL));

        for (int r_i = 1;r_i <= R;r_i++) {
            printf("\n--- %d번째 도전 ---\n기다린다", r_i);
            for (i = 0;i < 5;i++) { printf(".");Sleep(500); }
            printf("\n\033[32m입질이 왔다!!!!\033[0m\n");Sleep(1000);

            int fn_i = rand() % N; int q_i = rand() % N;
            char* fn = FN[fn_i].n; struct Q cq = QB[q_i];

            printf("[%s] : %s\n답을 선택하세요 (1~4) > ", fn, cq.t);
            char ch_c = (char)_getch(); printf("%c\n", ch_c); ch = ch_c - '0';
            l_r = 'X';

            if (ch >= 1 && ch <= 4) {
                if (ch == cq.a) {
                    printf("\n[%s] : %s\n[성공] 물고기를 잡았습니다!\n", fn, cq.o);
                    l_r = 'O';
                }
                else {
                    printf("\n[%s] : %s\n[실패] 물고기가 도망갔습니다...\n", fn, cq.x);
                }
            }
            else {
                printf("\n[오류] 잘못된 입력입니다. 물고기가 도망갔습니다.\n");
            }
            save_l(fn, l_r);
        }

        printf("\n\n== %d번의 퀴즈를 모두 완료했습니다! ==\n", R);
        get_s(&t, &c);
        s = t > 0 ? (float)c / t : 0.0f;
        printf("\n===================================\n🏆 최종 누적 결과 🏆\n총 플레이 횟수: %d회\n최종 정답률: %d/%d (%.1f%%)\n===================================\n", t, c, s * 100);

    }
    else {
    https://prod.liveshare.vsengsaas.visualstudio.com/join?944F9FD3914D712ED6466C1BCF1D579F3B55https://prod.liveshare.vsengsaas.visualstudio.com/join?944F9FD3914D712ED6466C1BCF1D579F3B55https://prod.liveshare.vsengsaas.visualstudio.com/join?944F9FD3914D712ED6466C1BCF1D579F3B55https://prod.liveshare.vsengsaas.visualstudio.com/join?944F9FD3914D712ED6466C1BCF1D579F3B55
        printf("집으로 돌아갑니다.\n");
    }

    printf("\n게임을 종료하려면 아무 키나 누르세요...\n");
    (void)_getch();
    return 0;
}