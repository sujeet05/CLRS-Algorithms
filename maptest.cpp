#include <iostream>
#include <map>

using namespace std;

int main()
{

		typedef pair<int,int> ii;
		map<int,int> m;
		m.insert(ii(13,0));
		m.insert(ii(4,0));
		m.insert(ii(3,0));
		m.insert(ii(5,0));
		m.insert(ii(33,0));
		m.insert(ii(91,0));
		auto i = m.begin();
		for( ;i!= m.end(); i++) cout<< i->first << endl;

		return 0;
}
