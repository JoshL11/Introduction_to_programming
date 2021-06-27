#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "11021.function.h"

void RleCodec::encode()
{
	std::string str;
	char al[30] = {'W','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int cnt = 1,flag = 0;
	char ch = code_str[0];
	int t = 0;;	
	int o=1;
	while(code_str[t]!='\0'){
		t++;
	}
	for(auto c : code_str){
		if(flag == 0)flag = 1;
		else if(c == ch){
			cnt++;
			o++;
			ch = c;
		} else if(c != ch &&o!=t-1){
			while(cnt>26){
				str.push_back('Q');
				str.push_back('Z');
				str.push_back(ch);
				cnt-=26;
			}
			o++;
			str.push_back('Q');
			str.push_back(al[cnt]);
			str.push_back(ch);
			ch = c;
			cnt = 1;
		} else if(c != ch &&o==t-1){
			while(cnt>26){
				str.push_back('Q');
				str.push_back('Z');
				str.push_back(ch);
				cnt-=26;
			}
			o++;
			str.push_back('Q');
			str.push_back(al[cnt]);
			str.push_back(ch);
			ch = c;
		}
	}
	while(cnt>26){
				str.push_back('Q');
				str.push_back('Z');
				str.push_back(ch);
				cnt-=26;
			}
			o++;
			str.push_back('Q');
			str.push_back(al[cnt]);
			str.push_back(ch);
	code_str = str;


	encoded = true;
}

void RleCodec::decode()
{
	std::stringstream os;
	std::string int_str;
	char q = 'A';
	char number = ' ';
	int cnt = 0;
	for (auto c : code_str) {
        if (q=='A') {
            q = c;
		}else if(number == ' '){
            number = c;
		}
        else {
            int_str.push_back(c);
			int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
					os << c;
			int_str.clear();
			number = ' ';
			q = 'A';
		}
	}

	code_str = os.str();
	encoded = false;
}
