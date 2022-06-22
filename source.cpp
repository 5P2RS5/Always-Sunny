#include <iostream>

#define	INF		1000000000
#define NODE	16

using namespace std;
// graph : �׷���
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
// P : ��������� ���������� ���� ��λ��� ���ǵ��� ������ ���
int P[NODE][NODE] = { 0, };
// building : ���ǵ��� �̸�
string building[16] = { "R", "K", "G", "Q",
                       "P", "I", "F", "U",
                       "E", "A", "D","S",
                       "Z1","Z2","X","T" };

void path(int src, int dst); // P�� �̿��� �ִܰ�� ��� �Լ�
bool stringToInt(string strPath[], int* arr); // �Է°����� �� ��߰��ǵ��� �������ǵ��� �ùٸ� �Է����� Ȯ���ϰ� �ùٸ��ٸ� �Է°��� graph�� index�� �ٲ��ִ� �Լ�
void MatrixCheck(); // graph�� ����⼺ �׷����� �´��� Ȯ�����ִ� �Լ�
void timeCaculate(int time); // �ð� ��� ��� �Լ�
void floyd2(int arr[]); // �÷��̵�2 �˰����� �̿��� �Լ�


int main()
{
    MatrixCheck();
    int arr[2];
    string srcDst[2];
    cout << "������Ʈ : ȫ����� ������ �����Դϴ�." << endl;
    cout << "�� �ȸ°� ���� ���ǵ����� ���� ���ǵ����� �ִܰ�θ� �˷��ݴϴ�." << endl;
    cout << "���ǻ���" << endl
        << "�빮�ڷ� �Է����ּ���" << endl
        << "G, H���� ���� ���ǵ��Դϴ�. G�� �Է����ּ���" << endl
        << "F, MH���� ���� ���ǵ��Դϴ�. F�� �Է����ּ���" << endl
        << "A, B, C���� ���� ���ǵ��Դϴ�. A�� �Է����ּ���" << endl
        << "Z2, Z3���� ���� ���ǵ��Դϴ�. Z2�� �Է����ּ���" << endl
        << "22�� 6�� 10�� M��, L��, J��, Z4���� ���������� �����߽��ϴ�." << endl << endl;
    cout << "���ǵ� ��� : R, K, G, Q, P, I, F, U, E, A, D, S, Z1, Z2, X, T" << endl << endl;
    bool chk = true;

    while (chk)
    {
        cout << "��� ���ǵ��� �Է��� �ּ��� : ";
        cin >> srcDst[0];
        cout << "���� ���ǵ��� �Է��� �ּ��� : ";
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
            cout << "�ùٸ� �Է��� �ƴϰų� �������̰ų� ���� ���ǵ��Դϴ�."
                << endl << "�ٽ� �Է����ּ���" << endl;
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
                cout << i << "�� " << j << "�� " << "CPP������ ��Ʈ������ �̻��մϴ�. Ȯ�����ּ���!";
                return;
            }
        }
    }
}

void timeCaculate(int time) {
    cout << "�� �ҿ�ð��� " << time / 60 << "�� " << time % 60 << "���Դϴ�." << endl;
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
    else // �ش� ���α׷��� �ش����� ������, ���� ��������� ���������� ��ΰ� ���� ���
        cout << building[arr[0]] << "����" << building[arr[1]] << "��(��) ���� �� �¾ƾ� �մϴ�.";
}