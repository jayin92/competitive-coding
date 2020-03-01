#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 1003;
const int INF = 475634765;

int rudu[MAX_N];
int dp[MAX_N];
int pre_max[MAX_N];
bool visit[MAX_N];
bool in_que[MAX_N];
vector<int> chudu[MAX_N];
queue<int> que;

void bfs(int root) {
    int ret=-1;
    visit[root]=true;
    que.push(root);
    while (!que.empty()) {
        int tmp=que.front();
        que.pop();
        dp[tmp]+=pre_max[tmp];
        in_que[tmp]=false;
        visit[tmp]=true;
        int len=chudu[tmp].size();
        for (int x=0;len>x;x++) {
            int y=chudu[tmp][x];
            pre_max[y]=max(pre_max[y],dp[tmp]);
            rudu[y]--;
            if (rudu[y]==0) {
                if (in_que[y]==false) {
                    que.push(y);
                    in_que[y]=true;
                }
            }
        }
    }
}

int main () {
    int T;
    scanf("%d",&T);
    while (T--) {
        memset(rudu,0,sizeof(rudu));//入度 
        memset(dp,0,sizeof(dp));    //cost
        memset(pre_max,0,sizeof(pre_max));
        int n;
        scanf("%d",&n);
        for (int x=1;n>=x;x++) {
            scanf("%d",&dp[x]);
            chudu[x].clear();
            visit[x]=false;
            int i;
            scanf("%d",&i);
            for (int y=0;i>y;y++) {
                int k;
                scanf("%d",&k);
                rudu[k]++;
                chudu[x].push_back(k);
            }
        }
        int ans=-INF;
        for (int i=1;n>=i;i++) {
            if (visit[i]==false && rudu[i]==0) bfs(i);
        }
        for (int i=1;n>=i;i++) {
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
}
