/*#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
list<int> line;
queue<int> country[3];

int main()
{
    string s;
    int n, id;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s == "ENQUEUE"){
            cin >> id;
            int num = id%3;
            country[num].push(id);
            if(find(line.begin(),line.end(),num)==line.end()) line.push_back(num);
        }
        else if(s == "DEQUEUE" ){
            int num = line.front();
            cout << country[num].front() << endl;
            country[num].pop();
            if(country[num].empty()) line.pop_front();
        }
    }
    return 0;
}        */
   
/*
#include <iostream>
#include <queue>
#include <list>
#include <string>

using namespace std;

list<queue<int>> L;

void ENQUEUE(int id)
{
    auto it=L.begin();
    for (; it!=L.end(); ++it) {
        if(((*it).front())%3==id%3) break;
    }
    if(it!=L.end()) (*it).push(id);
    else
    {
        queue<int> tmp_q;
        tmp_q.push(id);
        L.push_back(tmp_q);
    }
}

void DEQUEUE()
{
    auto it=L.begin();

    int id=(*it).front();
    (*it).pop();
    cout << id <<endl;

    if(!(*it).size()) L.pop_front();
}

int main()
{
    string s;
    int id;

    int n_cmd;
    cin >> n_cmd;

    for(int i=0;i<n_cmd;++i)
    {
        cin >> s;
        if (s=="ENQUEUE") {
            cin >> id;
            ENQUEUE(id);
        } else if (s=="DEQUEUE") {
            DEQUEUE();
        } else {
        }
    }
}
*/


/*#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, n;
    bool police = false;
    string cmd;
    queue<int> country[3];
    deque<int> line;
    while(cin >> cmd){
        if(cmd == "ENQUEUE"){
            cin >> a;
            n = a % 3;
            if(police){
                if(!country[n].empty()) country[n].push(-1);
                country[n].push(a);
                line.push_back(n);
                continue;
            }
            country[n].push(a);
            if(find(line.begin(),line.end(),n) == line.end()) line.push_back(n);
        }
        else if (cmd == "DEQUEUE"){
            if(!line.empty()){
                n = line.front();
                cout << country[n].front() << "\n";
                country[n].pop();
                if(country[n].empty()) line.pop_front();
                else if(country[n].front() == -1){
                    line.pop_front();
                    country[n].pop();
                }
            }
        }
        else if(cmd == "POLICEWATCHING"){
            police = true;
        }
        else if(cmd == "DONUTSTIME"){
            police = false;
        }
    }
}*/



#include <iostream>
#include <vector>
using namespace std;
int main() {
    string str;
    vector<int> v;
    v.resize(30);
    cin >> str;
    int i=0;
    while(str[i] != '\0') {
        if(str[i] == 'a' || str[i] == 'A') {
            i++;
            v[0]++;
        }
        i++;
    }
    for(int i=0;i<5;i++)cout <<v[i];
    cout << v[0];
}