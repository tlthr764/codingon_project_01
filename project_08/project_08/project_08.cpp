#include <iostream>
#include <iomanip> // setw() 를 사용하기 위한 헤더
#include <Windows.h> // system("cls")를 사용하기 위한 헤더
#include <conio.h> // _getch()를 사용하기 위한 헤더 

#define SPACE 32 // 스페이스바와 엔터를 입력받기 위해 선언
#define ENTER 13

const int num = 15; // 오목판 가로, 세로 길이

using namespace std;

void CursorView(bool show) // 커서 깜빡임 제거
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void print(string square[][num], string stone, int areaX, int areaY) // 스트링의 2중 정적 배열은 열의 크기가 선언되어야 한다고 함(제캐 리더님 피셜)
{
    system("cls"); // 출력 화면을 클리어 해줌
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == areaX && j == areaY) { // areaX,Y = 현재 위치
                cout << setw(5) << "☆"; // "☆" 출력하여 현재 위치. 확인
            }
            else {
                cout << setw(5) << square[i][j];
            }
        }
        cout << endl;
    }
    cout << "*************************************************************" << endl;
    cout << "                             " << stone << " 차례" << endl;
    cout << "*************************************************************" << endl;
    cout << "                           이동방법" << endl;
    cout << "           " << setw(5) << "Q↖" << setw(6) << "↑W" << setw(5) << "↗E" << endl;
    cout << "           " << setw(5) << "A←" << setw(4) << "+" << setw(6) << "→D" << "     SPACE BAR : 바둑돌 두기 " << endl;
    cout << "           " << setw(5) << "Z↙" << setw(6) << "↓S" << setw(5) << "↘C" << endl;
    cout << "*************************************************************" << endl;
    cout << " 『ESC를 누르면 게임 종료』";
};


int main()
{
    char moove;
    string square[num][num], stone;
    int player = 1, p = 0, areaX = 7, areaY = 7, end = 0, turn = 0; // areaX,Y = 7 : 현재 위치의 인덱스(가운데에서 시작)

    CursorView(false); // 커서 깜빡임 제거

    while (1) { // 게임 오프닝
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "*************************************************************" << endl;
        cout << "                          오목" << endl;
        cout << "*************************************************************" << endl;
        cout << "               → Enter키를 입력해서 시작" << endl;
        cout << "*************************************************************" << endl;
        moove = _getch(); // 입력값을 버퍼에 저장되지 않고 입력된 값을 바로바로 반환해주는 함수
        if (moove == ENTER) {
            break;
        }
    }


    ////////// 오목판 이동, 바둑돌을 두는 기능 //////////


    for (int i = 0; i < num; i++) // 바둑판(2차원 정적 배열)에 모두 "┼"를 입력하여 초기화
    {
        for (int j = 0; j < num; j++)
        {
            square[i][j] = "┼";
        }
    }

    square[areaX][areaY] = "○"; // 흑돌이 가운데에서 시작(7,7)

    while (end == 0) // 게임이 끝나기 전까지 반복되는 큰 반복문
    {
        // 턴에 따라 플레이어 변수 p와 돌 변수 stone 입력
        player++; //턴이 끝날 때 마다 +1
        if (player % 2 == 0) // 나머지 = 0 -> 흑돌
        {
            p = 1;
            stone = "●";
        }
        else // 나머지 = 1 -> 백돌
        {
            p = 2;
            stone = "○";
        }

        print(square, stone, areaX, areaY);

        while (turn == 0) // 한 턴을 기준으로 반복하는 작은 반복문
        {
            moove = _getch();
            if ((moove == 87) || (moove == 119)) // 북 w
            {
                if (areaX - 1 < 0) // 이동 될 위치가 바둑판 밖으로 나간다면
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaX--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 65) || (moove == 97)) // 서 a
            {
                if (areaY - 1 < 0)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaY--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 83) || (moove == 115)) // 남 s
            {
                if (areaX + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaX++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 68) || (moove == 100)) // 동 d
            {
                if (areaY + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaY++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 69) || (moove == 101)) // 북동 e
            {
                if (areaX - 1 < 0 || areaY + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaX--, areaY++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 81) || (moove == 113)) // 북서 q
            {
                if (areaX - 1 < 0 || areaY - 1 < 0)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaX--, areaY--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 67) || (moove == 99)) // 남동 c
            {
                if (areaX + 1 > 14 || areaY + 1 > 14)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaX++, areaY++;
                    print(square, stone, areaX, areaY);
                }
            }
            else if ((moove == 90) || (moove == 122)) // 남서 z
            {
                if (areaX + 1 > 14 || areaY - 1 < 0)
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 밖으로 나갈 수 없습니다!" << endl << endl;
                }
                else
                {
                    areaX++, areaY--;
                    print(square, stone, areaX, areaY);
                }
            }
            else if (moove == SPACE) // 바둑돌 놓기
            {
                if (square[areaX][areaY] == "┼") // 현재 위치에 바둑돌이 없다면
                {
                    if (p == 1)
                    {
                        square[areaX][areaY] = "●"; // 현재 위치에 바둑돌을 놓고
                        turn = 1; // 작은 반복문 탈출로 턴을 넘김
                        print(square, stone, areaX, areaY);
                    }
                    else
                    {
                        square[areaX][areaY] = "○";
                        turn = 1;
                        print(square, stone, areaX, areaY);
                    }
                }
                else
                {
                    print(square, stone, areaX, areaY);
                    cout << setw(5) << " ※경고 : 바둑돌이 있습니다!" << endl << endl;
                }
            }
            else if (moove == 27) // esc
            {
                cout << endl << endl << "《 게임을 종료합니다... 》" << endl;
                turn = 1;
                end = 1;
            }
            else // 지금까지 입력받은 것과 다른 아스키 코드를 입력받았다면
            {
                print(square, stone, areaX, areaY);
                cout << setw(5) << " ※경고 : 잘못 입력하셨습니다." << endl << endl;
            }
        }


        ////////// 5목 검사 기능 //////////


        int flagCase = 0; // 스위치문 인자로 사용하기 위한 변수
        int countWin = 0; // 현재 놓은 돌과 연속된 같은 돌 카운트
        while (flagCase < 4) // flagCase => 0:세로, 1:가로, 2:↖대각선, 3:↗대각선, 4:검사 종료
        {
            switch (flagCase)
            {

            case 0: // ↕ 검사
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX + k][areaY] == stone) // x축 ++ => ↓ 검사 (이동한 인덱스에 현재 놓은돌과 같은 돌이 놓여 있었다면)
                    {
                        countWin++;
                    }
                    else if (square[areaX + k][areaY] != stone || (areaX + k) > num - 1) // 돌이 다르거나, 없거나, 바둑판을 벗어난다면
                    {
                        break; // for문 탈출 => 다음 인덱스로 이동 안하고 종료
                    }
                }
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX - k][areaY] == stone) // ↑ 검사
                    {
                        countWin++;
                    }
                    else if (square[areaX - k][areaY] != stone || (areaX - k) < 0)
                    {
                        break;
                    }
                }
                if (countWin == 4) // 5목이라면 (6목 제외)
                {
                    flagCase = 4; // case 4 -> default -> 스위치 문 탈출
                }
                flagCase++; // 0 -> 1 케이스로 넘어가서 검사
                break;

            case 1: // ↔ 검사
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX][areaY + k] == stone) // → 검사
                    {
                        countWin++;
                    }
                    else if (square[areaX][areaY + k] != stone || (areaY + k) >= num)
                    {
                        break;
                    }
                }
                for (int k = 1; k < 5; k++) // ← 검사
                {
                    if (square[areaX][areaY - k] == stone)
                    {
                        countWin++;
                    }
                    else if (square[areaX][areaY - k] != stone || (areaY - k) < 0)
                    {
                        break;
                    }
                }

                if (countWin == 4)
                {
                    flagCase = 4;
                    break;
                }
                flagCase++;
                break;

            case 2: // 대각선 검사
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX - k][areaY - k] == stone) // ↖ 검사
                    {
                        countWin++;
                    }
                    else if (square[areaX - k][areaY - k] != stone || (areaX - k) < 0 || (areaY - k) < 0)
                    {
                        break;
                    }
                }
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX + k][areaY + k] == stone) // ↘ 검사
                    {
                        countWin++;
                    }
                    else if (square[areaX + k][areaY + k] != stone || (areaX + k) >= num || (areaY + k) >= num)
                    {
                        break;
                    }
                }

                if (countWin == 4)
                {
                    flagCase = 4;
                    break;
                }

                flagCase++;
                break;

            case 3: // 반대 대각선 검사
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX - k][areaY + k] == stone) // ↗ 검사
                    {
                        countWin++;
                    }
                    else if (square[areaX - k][areaY + k] != stone || (areaX - k) < 0 || (areaY + k) >= num)
                    {
                        break;
                    }
                }
                for (int k = 1; k < 5; k++)
                {
                    if (square[areaX + k][areaY - k] == stone) // ↙ 검사
                    {
                        countWin++;
                    }
                    else if (square[areaX + k][areaY - k] != stone || (areaX + k) >= num || (areaY - k) < 0)
                    {
                        break;
                    }
                }

                if (countWin == 4)
                {
                    flagCase = 4;
                    break;
                }
                flagCase++;
                break;

            default: // flagCase == 4
                break;
            }
        }

        if (countWin == 4) // 승리 조건 만족 == 게임 종료
        {
            if (stone == "●") { // 마지막에 둔 돌이 백돌이라면
                cout << endl << "『 ● (백) 의 승리! 』" << endl;
            }
            else {
                cout << endl << " 『 ○ (흑) 의 승리! 』 " << endl;
            }
            cout << "《 게임을 종료합니다... 》" << endl;
            end = 1; // 게임 종료를 결정짓는 큰 while문의 false 조건
        }

        turn = 0; // 한 턴을 결정짓는 작은 while문의 true 조건 = 초기화
    }
}