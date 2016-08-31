#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

string parseString() {
	string ret_value;
	char c;

	scanf("%c",&c);
	assert(c == '#');

	scanf("%c",&c);
	assert(c == '\t');

	while(1){
		scanf("%c",&c);

		if(c == '#') break;

		ret_value.push_back(c);
	}

	return ret_value;
}

int main(){
	while(1){
		int idx, paragraph, ansExist, bloomCategory, subsPosition;
		string questionStatement;

		scanf("%d\t",&idx);

		if(feof(stdin)) break;

		questionStatement = parseString();

		for(int i=0;i<questionStatement.length();i++){
			if(questionStatement[i] == '\n')
				questionStatement[i] = ' ';
		}

		scanf("%d %d %d %d",&paragraph, &ansExist, &bloomCategory, &subsPosition);

		printf("%s\n",questionStatement.c_str());
		printf("%d\n",subsPosition);
	}

	return 0;
}
