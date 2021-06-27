// model solution by Yazmau
#include<stdio.h>
/*#define MAXN 100005
#define MAXS 1000005
int arr[MAXN], coef[MAXN];
char s[MAXS];
int pos = 0;
int p,q,n;
int getNumber() {
    int ret = 0;
    while('0' <= s[pos] && s[pos] <= '9')   ret = ret * 10 + s[pos++] - '0';
    return ret;
}
int build( int nowCoef) {
    int ret;
    if(s[pos] != 'f') {
        int idx = getNumber();
        coef[idx] = ((long long)coef[idx] + nowCoef) % q;
        ret = ((long long)nowCoef * arr[idx]) % q;
    }
    else {
        pos += 2;
        int lVal = build( ((long long)nowCoef * p) % q);
        pos++;
        int rVal = build( nowCoef);
        pos++;
        ret = ((long long)lVal + rVal) % q;
    }
    return ret;
}
int main() {
    scanf("%d %d", &p, &q);
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &arr[i]);
    scanf("%s", s);
    int ans = build(1), m;
    scanf("%d", &m);
    while(m--) {
        int d,v;
        scanf("%d %d", &d, &v);
        ans = ((ans + (long long)coef[d] * (-arr[d] + v)) % q + q) % q;
        printf("%d\n", ans);
        arr[d] = v;
    }
    return 0;
}
*/


#define MAXN 100005
#define MAXS 1000005
char s[MAXS];
int arr[MAXN],coef[MAXN];
int pos;
int n,p,q;
int getnumber(){
    int ret = 0;
    while(s[pos] >= '0' && s[pos] <= '9')ret = ret*10+s[pos++]-'0';
    return ret;
}
int solve(int nowCoef){
    int ret;
    if(s[pos] != 'f') {
        int idx = getnumber();
        coef[idx] = ((long long)coef[idx] + nowCoef) % q;
        ret = ((long long)nowCoef * arr[idx]) % q;
    }
    else {
        pos += 2;
        int lVal = solve( ((long long)nowCoef * p) % q);
        pos++;
        int rVal = solve( nowCoef);
        pos++;
        ret = ((long long)lVal + rVal) % q;
    }
    return ret;
    
}

int main(void){
    scanf("%d %d %d",&p,&q,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%s",s);
    int ans = solve(1);
    int t;
    scanf("%d",&t);
    while(t--){
        int d,v;
        scanf("%d %d",&d,&v);
        ans = ((ans +(long long)coef[d] * (-arr[d] + v))%q+q)%q;
        printf("%d\n",ans);
        arr[d] = v;
    }
}












