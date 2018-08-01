#include <stdio.h>
#define swap(a, b, type) { type temp = a; a= b; b = temp; }
int N;
int MinHeap[25000];
int MaxHeap[25000];
int MinLastnode;
int MaxLastnode;
int m;
void MaxPush(int n){
    MaxHeap[++MaxLastnode] = n;
    int tmp = MaxLastnode;
    while (tmp/2){
        if (MaxHeap[tmp / 2] < MaxHeap[tmp]) {
            swap(MaxHeap[tmp / 2], MaxHeap[tmp], int)
            tmp = tmp / 2;
        }
        else break;
    }
}
void Maxpop(int* n) {
    *n = MaxHeap[1];
    MaxHeap[1] = MaxHeap[MaxLastnode--];
    int tmp = 1;
    while (2*tmp <= MaxLastnode) {
        int c = 2 * tmp;
        if (2 * tmp + 1 <= MaxLastnode && MaxHeap[2 * tmp + 1] > MaxHeap[2 * tmp]) c = 2 * tmp + 1;
        if (MaxHeap[c] > MaxHeap[tmp]) {
            swap(MaxHeap[c], MaxHeap[tmp], int)
            tmp = c;
        }
        else break;
    }
}
void MinPush(int n) {
    int tmp;
    MinHeap[++MinLastnode] = n;
    tmp = MinLastnode;
    while (tmp / 2) {
        if (MinHeap[tmp / 2] > MinHeap[tmp]) {
            swap(MinHeap[tmp / 2], MinHeap[tmp], int)
            tmp = tmp / 2;
        }
        else break;
    }
}
void Minpop(int* n) {
    *n = MinHeap[1];
    MinHeap[1] = MinHeap[MinLastnode--];
    int tmp = 1;
    int c;
    while (2 * tmp <= MinLastnode) {
        c = 2 * tmp;
        if (2 * tmp + 1 <= MinLastnode && MinHeap[2 * tmp + 1] < MinHeap[2 * tmp]) c = 2 * tmp + 1;
        if (MinHeap[c] < MinHeap[tmp]) {
            swap(MinHeap[c], MinHeap[tmp],int)
            tmp = c;
        }
        else break;
    }
}
int main(void)
{
    int tmp1, tmp2;
    int move1, move2;
    scanf("%d", &N);
    scanf("%d", &m);
    printf("%d\n", m);
    for (int i = 0; i < (N - 1) / 2; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        if (m < tmp1 ) {
            move1 = 1;
        }
        else {
            move1 = -1;
        }
        if (m < tmp2) {
            move2 = 1;
        }
        else {
            move2 = -1;
        }
        if (move1 == move2) {
            if (move1 > 0) {
                MinPush(tmp1);
                MinPush(tmp2);
                MaxPush(m);
                Minpop(&m);
            }
            if (move1 < 0) {
                MaxPush(tmp1);
                MaxPush(tmp2);
                MinPush(m);
                Maxpop(&m);
            }
        }
        else {
            if (tmp1 < tmp2)
            {
                swap(tmp1, tmp2, int)
            }
            MaxPush(tmp2);
            MinPush(tmp1);
        }
        printf("%d\n", m);
    }
 
    return 0;
}