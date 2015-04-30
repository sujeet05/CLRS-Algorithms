#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> v)
{
		for(std::vector<int>::iterator it =v.begin();it != v.end();++it)
		cout << *it << " ";
		cout << endl;
}
vector<int> sort(vector<int> v)
{

#if 0
	std::vector<int>::iterator it =v.begin();
	for(it =++it;it<v.end();++it)
	{
			int key =*it;
			std::vector<int>::iterator traversal= --it;
			for(;*traversal > key;--traversal)
					*(++traversal)= *traversal;
			*traversal = key;
	}
	cout << v.size();
#endif

	for(int j=1;j<v.size() ;j++)
    {   
        int key = v[j];
	    int k = j-1;
	    while(k>=0 && key < v[k])
	    {   
	        v[k+1] = v[k];
	         k--;
       }   

	    v[k+1] = key;
    }  
   return v;
}
void Merge(vector<int> v ,int p,int q,int r)
{
	vector<int> left;
	vector<int> right;
	left.assign(v.begin()+p,v.begin()+q+1);
	right.assign(v.begin()+q+1,v.begin()+r+1);
    std::cout << "Before running merge left .."<< endl;
	display(left);
    std::cout << "Before running merge right .."<< endl;
	display(right);
	vector<int> _lret=sort(left);
	left.assign(_lret.begin(),_lret.end());
	std::cout << "After sort left ..."<< endl;
	display(_lret);
	vector<int> _rret=sort(right);
	right.assign(_rret.begin(),_rret.end());
	std::cout << "After sort right ..."<< endl;
	display(_rret);
	std::vector<int>::iterator left_it =_lret.begin();
	std::vector<int>::iterator right_it =_rret.begin();
	int i =0;
	int j =0;
	for(int it =p;it < r;++it)
	{
           if(_lret[i]<=_rret[j])
		   {
				v[it] = _lret[i];
				i++;
		   }
		   else
		   {
				   v[it] = _rret[j];
				   cout << "xxx"<< _rret[j] << endl;
				   cout << "xxx"<< v[it] << endl;
				   j++;
		   }
	}
	display(v);
}
int main()
{
	vector<int> a {3,41,52,26,38,57,9,49};
	display(a);
	Merge(a,2,4,6);
	return 0;
}
