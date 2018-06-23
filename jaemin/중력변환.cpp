#include <stdio.h>
#define SWAP(a, b, type) { type temp; temp = a;  a = b; b = temp;  } 
int N, M;
struct NODE
{
    int x;
    int y;
    int cnt;
    int g;
};
char arr[500][500];
int up_arr[500][500];
int down_arr[500][500];
int visit[500][500];
int start_x, start_y;
int lastnode;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 1,-1,0,0 };
NODE tree[20000];
void heap_push(NODE node) {
    NODE swap;
    int tmp = ++lastnode;
    tree[tmp] = node;
    for (;;) {
        if (tmp / 2 > 0 && tree[tmp/2].cnt > tree[tmp].cnt) {
            SWAP(tree[tmp / 2], tree[tmp], NODE);
            tmp /= 2;
        }
        else return;
    }
}
NODE heap_pop() {
    int tmp=1,rc=3,lc=2;
    NODE node;
    if (lastnode == 0) return {0,0,-1, 1 };
    node = tree[1];
    tree[1] = tree[lastnode--];
    while (lc<=lastnode) {
        if (rc <= lastnode && tree[lc].cnt > tree[rc].cnt) lc = rc;
        if (tree[lc].cnt < tree[tmp].cnt) { SWAP(tree[lc], tree[tmp], NODE); tmp = lc; lc = 2 * tmp; rc = 2 * tmp + 1; }
        else break;
    }
    return node;
}
void check_node(NODE* node) {
    int i_new;
    visit[node->x][node->y] = 1;
    if(node->g == 1) i_new = up_arr[node->x][node->y];
    else i_new = down_arr[node->x][node->y];
    if (i_new >= 0 && arr[i_new][node->y] == 'D')  heap_push(NODE{ i_new, node->y, node->cnt+1, -1 * node->g });
    if (i_new >= 0 && arr[i_new + node->g][node->y] != '#' && visit[i_new + node->g][node->y] == 0) heap_push(NODE{ i_new + node->g, node->y, node->cnt+1, -1*node->g });
     
    if (node->y + 1 < M && arr[node->x][node->y + 1] != '#') {
        if (node->g == 1) i_new = down_arr[node->x][node->y + 1];
        else i_new = up_arr[node->x][node->y + 1];
        if (i_new >= 0 && arr[i_new][node->y+1] == 'D')  heap_push(NODE{ i_new, node->y+1, node->cnt,node->g });
        if (i_new >= 0 && arr[i_new - node->g][node->y+1] != '#' && visit[i_new - node->g][node->y+1] == 0) heap_push(NODE{ i_new - node->g, node->y + 1, node->cnt ,  node->g });
    }
    if (node->y - 1 >= 0 && arr[node->x][node->y - 1] != '#') {
        if (node->g == 1) i_new = down_arr[node->x][node->y - 1];
        else i_new = up_arr[node->x][node->y - 1];
        if (i_new >= 0 && arr[i_new][node->y - 1] == 'D')  heap_push(NODE{ i_new, node->y - 1, node->cnt,node->g });
        if (i_new >= 0 && arr[i_new - node->g][node->y - 1] != '#' && visit[i_new - node->g][node->y - 1] == 0) heap_push(NODE{ i_new - node->g,node->y - 1, node->cnt ,  node->g });
    }
}
int main(void)
{
    int i, j, u , d,i_new;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'C') {
                start_x = i; start_y = j;
            }
        }
    }
    for (j = 0; j < M; j++) {
        u = -1;
        d = -1;
        for (i = 0; i < N; i++) {
            if (arr[i][j] == '#' || arr[i][j] == 'D') u = i;
            up_arr[i][j] = u;
            if (arr[N - 1 - i][j] == '#' || arr[N - 1 - i][j] == 'D') d = N - 1 - i;
            down_arr[N - 1 - i][j] = d;
        }
    }
    heap_push(NODE{ start_x, start_y, 0 , 1});
    NODE node = heap_pop();
    i_new = down_arr[node.x][node.y];
    if(i_new >= 0 && arr[i_new][node.y] == 'D')  heap_push(NODE{ i_new, node.y, node.cnt, node.g });
    if(i_new >=0 && arr[i_new - node.g][node.y]!='#' && visit[i_new - node.g][node.y]==0) heap_push(NODE{ i_new - node.g, node.y, node.cnt, node.g });
 
    for (;;) {
        NODE node = heap_pop();
        if (node.cnt == -1) break;
        if (arr[node.x][node.y]=='D') { printf("%d", node.cnt); return 0; }
        check_node(&node);
    }
    printf("%d", -1);
    return 0;
}