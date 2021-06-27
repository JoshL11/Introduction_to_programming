#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
list<int> line;
queue<int> country[3];
list<int> vip;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n, id;

    //cin >> n;
    //cin >> s;
    while(cin >> s){
        
        if(s == "ENQUEUE"){
            cin >> id;
            
            if(id%5 == 0 || id == 0) {
                //cout <<"FUCK";
                vip.push_back(id);
            } 
            else {
                int num = id%3;
                country[num].push(id);
                if(find(line.begin(),line.end(),num)==line.end()) line.push_back(num);
            }
        }
        else if(s == "DEQUEUE" ){
            
            /*if(vip.empty() == 0 && line.empty() == 0){
                cout << vip.front()<< ' ';
                vip.pop_front();
                int num = line.front();
                cout << country[num].front() << "\n";
                country[num].pop();
                if(country[num].empty()) line.pop_front();
            
            }
            if(vip.empty() == 1 && line.empty() == 0){
                
                int num = line.front();
                cout << country[num].front() << "\n";
                country[num].pop();
                if(country[num].empty()) line.pop_front();
            
            }
            if(vip.empty() == 0 && line.empty() == 1){
                cout << vip.front()<< "\n";
                vip.pop_front();
            }
            if(vip.empty() == 1 && line.empty() == 1){

            }*/
            
            if(vip.size() != 0){
                if(line.size() != 0)
                    cout << vip.front()<< ' ';
                else cout << vip.front()<< '\n';
                vip.pop_front();
            
            }
            if(line.size() != 0){
                int num = line.front();
                cout << country[num].front() << "\n";
                country[num].pop();
                if(country[num].empty()) line.pop_front();
            }
            
            
        }
    }
    return 0;
}        
   