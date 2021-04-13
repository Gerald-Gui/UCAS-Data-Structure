#include <iostream>
#include <cstdio>
using namespace std;

struct Point{
    int x;
    int y;
};

struct ListNode{
    Point pt;
    ListNode * nxt;
    ListNode(){
        pt.x = pt.y = 0;
        nxt = nullptr;
    }
    ListNode(Point p): pt(p){
        nxt = nullptr;
    }
    ListNode(Point p, ListNode * ptr): pt(p), nxt(ptr){}
};

struct LinkQueue{
    ListNode * front;
    ListNode * rear;
    LinkQueue(){
        front = rear = new ListNode;
        front->nxt = front;
    }
    void EnQueue(Point pt){
        ListNode * p = new ListNode(pt, rear->nxt);
        rear->nxt = p;
        rear = p;
    }
    Point DeQueue(){
        Point tmp = front->nxt->pt;
        front = front->nxt;
        delete rear->nxt;
        rear->nxt = front;
        return tmp;
    }
    bool IsEmpty(){
        return front == rear;
    }
};

const int dirx[] = {-1, 1, 0, 0};
const int diry[] = {0, 0, -1, 1};
const int color = 2;

inline bool InGraph(int x, int y, int m, int n){
    return x >= 0 && x < m && y >= 0 && y < n;
}

int main(){
    int m, n;
    int xs, ys, dir;

    cin >> m >> n >> xs >> ys >> dir;
    int arr[m][n];

    int c;
    while((c = getchar()) != '\n')
        ;
    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> arr[i][j];

    LinkQueue Q;
    c = arr[xs][ys];
    Q.EnQueue({xs, ys});
    while(!Q.IsEmpty()){
        Point tmp = Q.DeQueue();
        for(int k = 0; k < 4; k++){
            int curdir = (k + dir) % 4;
            if(InGraph(tmp.x + dirx[curdir], tmp.y + diry[curdir], m, n))
                if(arr[tmp.x + dirx[curdir]][tmp.y + diry[curdir]] == c){
                    arr[tmp.x + dirx[curdir]][tmp.y + diry[curdir]] = color;
                    Q.EnQueue({tmp.x + dirx[curdir], tmp.y + diry[curdir]});
                }
        }
    }

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(j == n - 1)
                printf("%d\n", arr[i][j]);
            else
                printf("%d", arr[i][j]);

    return 0;
}