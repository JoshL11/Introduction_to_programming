#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
string str;

int com[30];
void check();
vector<int> v;
void del() {

}
int main() {
     v.resize(30);
    int n,c=0;
    cin >> n;
    int flag = 0;
    map<string,vector<int>> s;
    while(n--) {
        
        //if(c==0){
            cin >> str;
            check();
            s.insert(pair<string,vector<int>>(str,v));
            //for(int i=0;i<10;i++)cout <<v[i];
        






/*
            cin >> str;
            check();
            //for(int i=0;i<10;i++)cout <<v[i];
            auto it = s.begin();
            for(it;it!=s.end();it++) {
                if(v == it->second) {
                    s.erase(it);
                    flag = 1;
                    if(s.size() == 0) {
                    c = 0;
                    break;
                    }
                }
            }
            if(flag == 0)s.insert(pair<string,vector<int>>(str,v));
            flag = 0;
        }
    }*/
        }
    //map<string,vector<int>> r;
    vector<int> r;
    string h;
    
    auto i = s.begin();
    auto j = i++;
    for(i;j!=s.end();i++) {
        for(j;j!=s.end();j++){
            if(i->second == j->second) {
                //s.erase(i);
                h = i->first;
                s.erase(j);
                auto iter = s.find(h);
                s.erase(iter);
            }
            
        }
        
    }
    
    
    auto it = s.begin();
    for(it;it!=s.end();it++) cout << it->first << endl;

}
void check() {
    int i=0;
    for(int i=0;i<30;i++)v[i] = 0;
    while(str[i] != '\0') {
        if(str[i] == 'a' || str[i] == 'A') i++,v[0]++;
        else if(str[i] == 'b' || str[i] == 'B') i++,v[1]++;
        else if(str[i] == 'c' || str[i] == 'C') i++,v[2]++;
        else if(str[i] == 'd' || str[i] == 'D') i++,v[3]++;
        else if(str[i] == 'e' || str[i] == 'E') i++,v[4]++;
        else if(str[i] == 'f' || str[i] == 'F') i++,v[5]++;
        else if(str[i] == 'g' || str[i] == 'G') i++,v[6]++;
        else if(str[i] == 'h' || str[i] == 'H') i++,v[7]++;
        else if(str[i] == 'i' || str[i] == 'I') i++,v[8]++;
        else if(str[i] == 'j' || str[i] == 'J') i++,v[9]++;
        else if(str[i] == 'k' || str[i] == 'K') i++,v[10]++;
        else if(str[i] == 'l' || str[i] == 'L') i++,v[11]++;
        else if(str[i] == 'm' || str[i] == 'M') i++,v[12]++;
        else if(str[i] == 'n' || str[i] == 'N') i++,v[13]++;
        else if(str[i] == 'o' || str[i] == 'O') i++,v[14]++;
        else if(str[i] == 'p' || str[i] == 'P') i++,v[15]++;
        else if(str[i] == 'q' || str[i] == 'Q') i++,v[16]++;
        else if(str[i] == 'r' || str[i] == 'R') i++,v[17]++;
        else if(str[i] == 's' || str[i] == 'S') i++,v[18]++;
        else if(str[i] == 't' || str[i] == 'T') i++,v[19]++;
        else if(str[i] == 'u' || str[i] == 'U') i++,v[20]++;
        else if(str[i] == 'v' || str[i] == 'V') i++,v[21]++;
        else if(str[i] == 'w' || str[i] == 'W') i++,v[22]++;
        else if(str[i] == 'x' || str[i] == 'X') i++,v[23]++;
        else if(str[i] == 'y' || str[i] == 'Y') i++,v[24]++;
        else if(str[i] == 'z' || str[i] == 'Z') i++,v[25]++;

    }
}

