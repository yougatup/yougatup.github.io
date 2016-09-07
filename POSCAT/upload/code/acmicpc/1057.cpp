#include <iostream>

using namespace std;

int main()
{
	int n,kim,im;
	cin>>n>>kim>>im;
	kim--;
	im--;
	n=1;
	while(kim/2!=im/2)
	{
		n++;
		kim/=2;
		im/=2;
	}
	cout<<n<<endl;

	return 0;
}
