#include <iostream>
using namespace std;

//��������
template <class T>
struct Node
{
    T data;
    Node<T> *next;  
};

template <class T>
class LinkStack
{
public:
    LinkStack( );    
    ~LinkStack( );  
    void Push(T x);  
    T Pop( );    
    T GetTop( );   
    bool Empty( );  
private:
    Node<T> *top;   
};

//ʵ�ֲ���
template <class T>
LinkStack<T>::LinkStack( )
{
	top=NULL; 
}

template <class T>
LinkStack<T>::~LinkStack( )
{
	while (top)
	{
		Node<T> *p;
		p=top->next;
        delete top;
        top=p;
	}
}

template<class T> 
void LinkStack<T>::Push(T x)
{
    Node<T> *s;
	s=new Node<T>;    
    s->data = x;     //����һ��������Ϊx�Ľ��s
    s->next = top; 
	top=s;           //�����s����ջ��
}

template <class T> T LinkStack<T>::Pop( )
{   
    Node<T> *p;
	int x; 
    if (top==NULL) 
		return -1;
    x=top->data;   //�ݴ�ջ��Ԫ��
    p=top; 
	top=top->next; //��ջ�����ժ��
    delete p;
    return x;
}

template <class T> 
T LinkStack<T>::GetTop( )
{
    if (top!=NULL) 
		return top->data;
}

template <class T> bool LinkStack<T>::Empty( )
{
    if(top==NULL) 
		return 1;
	else 
		return 0;
}

int main()
{
	LinkStack<int> S1;
	int i;
	int data[3];
	cout<<"����3��������"<<endl;
	for(i=0;i<3;i++)
	{
		cin>>data[i];
		S1.Push(data[i]);
	}
	cout<<"Top:"<<S1.GetTop()<<endl;

	LinkStack<double> S2;
	double data2[3];
	cout<<"����3����������"<<endl;
	for(i=0;i<3;i++)
	{
		cin>>data2[i];
		S2.Push(data2[i]);
	}
	cout<<"Top:"<<S2.GetTop()<<endl;
	return 0;
}