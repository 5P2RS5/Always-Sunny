#include <iostream>

#define	INF		1000000000
#define NODE	16

using namespace std;
// graph : 그래프
int graph[NODE][NODE] = {
        {0, 112, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {112, 0, 145, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, 145, 0, 30, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, 30, 0, 44, INF, 24, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 44, 0, 54, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 54, 0, INF, INF, INF ,INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 24, INF, INF, 0, 78, 30, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, 78, 0, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, 30, INF, 0, 62, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 62, 0, 52, INF, INF, 60, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 52, 0, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 45, 40, INF, 53},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 45, 0, 75, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 60, INF, 40, 75, 0, 33, 66},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 33, 0, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 53, INF, 66, INF, 0}

};
// P : 출발점부터 도착점까지 가는 경로상의 강의동의 개수의 행렬
int P[NODE][NODE] = { 0, };
// building : 강의동의 이름
string building[16] = { "R", "K", "G", "Q",
                       "P", "I", "F", "U",
                       "E", "A", "D","S",
                       "Z1","Z2","X","T" };

void path(int src, int dst); // P를 이용한 최단경로 출력 함수
bool stringToInt(string strPath[], int* arr); // 입력값으로 준 출발강의동과 도착강의동이 올바른 입력인지 확인하고 올바르다면 입력값을 graph의 index로 바꿔주는 함수
void MatrixCheck(); // graph가 비방향성 그래프가 맞는지 확인해주는 함수
void timeCaculate(int time); // 시간 계산 출력 함수
void floyd2(int arr[]); // 플로이드2 알고리즘을 이용한 함수


int main()
{
    MatrixCheck();
    int arr[2];
    string srcDst[2];
    cout << "프로젝트 : 홍대생은 언제나 맑음입니다." << endl;
    cout << "비를 안맞고 현재 강의동부터 도착 강의동까지 최단경로를 알려줍니다." << endl;
    cout << "주의사항" << endl
        << "대문자로 입력해주세요" << endl
        << "G, H동은 같은 강의동입니다. G로 입력해주세요" << endl
        << "F, MH동은 같은 강의동입니다. F로 입력해주세요" << endl
        << "A, B, C동은 같은 강의동입니다. A로 입력해주세요" << endl
        << "Z2, Z3동은 같은 강의동입니다. Z2로 입력해주세요" << endl
        << "22년 6월 10일 M동, L동, J동, Z4동은 공사중으로 제외했습니다." << endl << endl;
    cout << "강의동 목록 : R, K, G, Q, P, I, F, U, E, A, D, S, Z1, Z2, X, T" << endl << endl;
    bool chk = true;

    while (chk)
    {
        cout << "출발 강의동을 입력해 주세요 : ";
        cin >> srcDst[0];
        cout << "도착 강의동을 입력해 주세요 : ";
        cin >> srcDst[1];
        chk = stringToInt(srcDst, arr);
    }
    cout << endl;
    floyd2(arr);
    system("pause");
    return 0;
}
void path(int src, int dst)
{
    if (P[src][dst] != 0)
    {
        path(src, P[src][dst]);
        cout << building[P[src][dst]] << " -> ";
        path(P[src][dst], dst);
    }
}
bool stringToInt(string strPath[], int* arr)
{
    arr[0] = -1;
    arr[1] = -1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (strPath[i] == building[j])
            {
                arr[i] = j;
                break;
            }
        }
        if (arr[i] == -1)
        {
            cout << "올바른 입력이 아니거나 공사중이거나 없는 강의동입니다."
                << endl << "다시 입력해주세요" << endl;
            return true;
        }
    }
    return false;
}

void MatrixCheck() {
    for (int i = 0; i < NODE; i++)
    {
        for (int j = 0; j < NODE; j++)
        {
            if (graph[i][j] != graph[j][i])
            {
                cout << i << "행 " << j << "열 " << "CPP파일의 매트릭스가 이상합니다. 확인해주세요!";
                return;
            }
        }
    }
}

void timeCaculate(int time) {
    cout << "총 소요시간은 " << time / 60 << "분 " << time % 60 << "초입니다." << endl;
}

void floyd2(int arr[])
{
    int D[NODE][NODE];
    for (int i = 0; i < NODE; i++)
        for (int j = 0; j < NODE; j++)
            D[i][j] = graph[i][j];
    for (int k = 0; k < NODE; k++)
        for (int i = 0; i < NODE; i++)
            for (int j = 0; j < NODE; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }

    cout << building[arr[0]] << " -> ";
    path(arr[0], arr[1]);
    cout << building[arr[1]] << endl;
    if (D[arr[0]][arr[1]] != INF)
        timeCaculate(D[arr[0]][arr[1]]);
    else // 해당 프로그램에 해당하진 않지만, 만약 출발점에서 도착점까지 경로가 없을 경우
        cout << building[arr[0]] << "에서" << building[arr[1]] << "는(은) 많은 비를 맞아야 합니다.";
}