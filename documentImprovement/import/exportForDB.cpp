#include <cstdio>
#include <cassert>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

FILE *Sub = fopen("Sub-NL1.txt","r");
FILE *Parse = fopen("parse-NL1.txt","r");

map <int, double> timeMap;
char buffer[10000];

void loadSub() {
	while(1){
		int idx;
		double time;

		fscanf(Sub, "%d",&idx);

		if(feof(Sub)) break;

		int a, b, c, d, e, f, g, h;

		fscanf(Sub, "%d:%d:%d,%d --> %d:%d:%d,%d",&a, &b, &c, &d, &e, &f, &g, &h);
		fgets(buffer, 10000, Sub); // contents
		fgets(buffer, 10000, Sub); // blank line

		assert(a == 0);

		time = (b * 60) + c + (d * 0.001);

		timeMap[idx] = time;
	}
}

void loadParse() {
	int cnt = 0;

	while(1) {
		int idx;

		fgets(buffer, 10000, Parse);

		if(feof(Parse)) break;

		fscanf(Parse, "%d\n",&idx);

		if(idx != -1) {
			cnt++;

			printf("%lf\n%s", timeMap[idx], buffer);
		}
	}
}

int main(){

	loadSub();
	loadParse();

	return 0;
}
