#include<iostream>
#include<list>

using namespace std;
struct element;
struct representative
{
	struct element* head;
	struct element* last;
};
struct element
{
		int data;
		struct element* next;
		struct representative *rep;
};
class set 
{
	private:
			struct element *m_element;
			struct representative *m_represent;
	public:
			set();
			void  makeset(struct element* data);
			struct representative*  Find(struct element* el);
			void join(struct element *e1,struct element *e2);
			static struct element* init(int data);
			 void printset();
};
set::set()
{
	m_represent = NULL;
	m_element = NULL;
}
struct element* set::init(int data)
{
	struct element *temp = new struct element;
	temp->data =data;
	temp->next = NULL;
	return temp;
}
void set::makeset(struct element* data)
{
	if(!m_represent)
	{
		m_represent = new struct representative;
		data->rep = m_represent;
		m_represent->head= data;
		m_represent->last = data;
	}
	else
	{
		data->rep = m_represent;
		m_represent->last->next= data;
		m_represent->last = data;
	}

}
void set:: printset()
{
		struct element* traversal= m_represent->head;
		while(traversal)
		{
			cout << traversal->data << "...";
			traversal= traversal->next;
		}
}
struct representative* set:: Find(struct element* el)
{
	return el->rep;
}
void set::join(struct element *e1,struct element *e2)
{
		if(Find(e1)==Find(e2) || Find(e1)==NULL || Find(e2)==NULL) return;
		struct element * traversal= Find(e2)->head;
		while(traversal->next)
		{
			traversal->rep=Find(e1);
			traversal= traversal->next;
		}
		Find(e1)->last->next = Find(e2)->head;
		Find(e1)->last= Find(e2)->last;
		

}
int main()
{
	set s1,s2;
	struct element* n1=set::init(1);
	struct element* n2=set::init(2);
	struct element* n3=set::init(3);
	struct element* n4=set::init(4);
	struct element* n5=set::init(5);
	struct element* n6=set::init(6);
	struct element* n7=set::init(7);
	s1.makeset(n1);
	s1.makeset(n2);
	s1.makeset(n3);
	s2.makeset(n4);
	s2.makeset(n5);
	s2.makeset(n6);
	s2.makeset(n7);
	s1.join(n3,n7);
	s1.printset();
	cout << endl;
	return 0;
}
