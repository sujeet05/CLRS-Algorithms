#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
void printArray(vector<int> v)
{
	for(int i=0;i<v.size();++i)
			cout << v[i] << "..";
	cout << endl;
}
int merge(vector<int > v,int p,int q,int r)
{
	int n1= q-p+1;
	int n2 =r-q;
	vector<int> v1(n1+1);
	vector<int> v2(n2+1);
	int k =p;
	for(int i=0;i<v1.size();++i,++p)
			v1[i]=v[p];
	for(int j=0;j<v2.size();++j,++q)
			v2[j]=v[q+1];
	v1[n1]=99999;
	v2[n2] =99999;
	int i=0;
	int j=0;
	int count=0;
	for(int m=k;m<=r;++m)
	{
			if(v1[i] >=v2[j])
			{
				v[m]=v1[i];
				i++;
				count++;
			}
			else
			{
				v[m]=v2[j];
			    j++;
			}
	}
	return count;
}
int InversionCount(vector<int> v,int p,int r)
{
   int count =0;
   if(p < r)
   {
   		int q = floor((p+r)/2);
   		count = count+InversionCount(v,p,q);
		count = count+InversionCount(v,q+1,r);
		count = count+merge(v,p,q,r);
   }
   return count;
}
int main()
{
   //vector<int> v ={5,2,4,6,1,3};
   vector<int> v ={1,1,1,2,2};
   vector<int> v2 ={2,1,3,1,2};
   std::cout << InversionCount(v,0,4) << std::endl;
   std::cout << InversionCount(v2,0,4) << std::endl;
   return 0;
}
