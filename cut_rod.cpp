#include<iostream>

using namespace std;

void cutrod1(int x, int p[], int l)
{
   if(x==0) {
		   for(int i=l-1;i>0;--i) cout<<p[i]<< " ";
		   cout<<endl;
   }
   for(int i=1;i<=x;++i)
	{
		p[l] = x;
		cutrod1(x-i,p,l+1);
	}
}
void cutrod(int x)
{
	if(x==0)
	{
		cout << endl;
		return ;
	}
	for(int i=1;i<=x;++i)
	{
		cout << x-i;
	   	cutrod(x-i);
		cutrod(x-i+1);
	}
}
void cutrod1(int x){
		int p[100];
		cutrod1(x,p,1);
}
int main()
{
	cutrod(4);
	return 0;
}
