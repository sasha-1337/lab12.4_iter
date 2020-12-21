#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    int info;
};

void CreateCycle(Elem*& first, int N);
void Insert(Elem*& L, Info value);
void Scanning(Elem*& L, Info x);
void Remove(Elem*& L);
void Print(Elem*& L);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Elem* L = NULL;

    int N, x;
    cout << "Кількість елементів списку: "; cin >> N;
    cout << "Значення інформаційного поля: "; cin >> x;
    CreateCycle(L, N);
    cout << "Оригінальний список:" << endl;
    Print(L);
    cout << "Модифікований список:" << endl;
    Scanning(L, x);
    Print(L);

    system("pause");
    return 0;
}

void CreateCycle(Elem*& first, int N)
{
    for (int i = 0; i < N; i++)
    {
        int value = i;
        Insert(first, value);
    }
}

void Insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }
    tmp->link = L;
}

void Scanning(Elem*& L, Info x)
{
    if (L == NULL)
        return;
    Elem* tmp = NULL;
    Elem* first = L;
    while (L->link != first)
    {
        if (L->info == x) {
            tmp = L->link;
            Remove(tmp);
        }
        else
            L = L->link;
    }
}

void Remove(Elem*& L)
{
    Elem* T = L;
    while (T->link != L)
        T = T->link;

    if (T != L)
    {
        Elem* tmpp = L->link;
        delete L;
        L = tmpp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }
}

void Print(Elem*& L)
{
    if (L == NULL)
        return;

    Elem* first = L;
    cout << setw(4) << L->info;
    while (L->link != first)
    {
        L = L->link;
        cout << setw(4) << L->info;
    }
    cout << endl;
}