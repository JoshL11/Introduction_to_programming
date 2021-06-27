#include <iostream>
#include <map>
using namespace std;
int price[1000005];
int weight[1000005];
int recprice[1000005];
int recweight[1000005];
int main() {
    int n,q,flag = 0;
    cin >> n;
    int i=0;
    int y = n;
    while(y--) {
        cin >> weight[i] >> price[i];
        i++;
    }
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1 || type == 2) {
            int a,b;
            cin >> a >> b;
            if(type == 1) {
                weight[i] = a;
                price[i] = b;
                i++;
                n++;
            } else if(type == 2) {
                for(int i=0;i<n;i++) {
                    //cout << weight[i] << ' ' << price[i];
                    if(weight[i] == a && price[i] == b){
                        cout <<"OK\n";
                        flag =1;
                        break;
                        
                    } 
                }
                if(flag ==0)cout <<"No Item\n";
                flag = 0;
                
            }


        } else {
            int c,check = 0,min = 10e9,t;
            cin >> c;
            if(type == 3) {
                for(int i=0;i<n;i++) {
                    if(c >= weight[i]) {
                        recweight[i]++;
                        check++;
                    }
                }
                if(check == 1) {
                    for(int i=0;i<n;i++) if(c >= weight[i])cout << weight[i] << ' ' << price[i];
                } else {
                    for(int i=0;i<n;i++) if(c >= weight[i]) {
                        if(min < price[i]) {
                            min = price[i];
                            t = i;
                        }
                        cout << weight[t] << ' ' << price[t];
                    }
                }
            } else if(type == 4) {
                int u = 0;
                for(int i=0;i<n;i++) {
                    if(c >= price[i]) {
                        price[i]++;
                        u++;
                    }
                }
            }
        }
    }

}