#include<iostream>
using namespace std;
template<typename Data> class stack
{
private:
	Data v[10001] = {0};
	int __size = 0;
public:
	stack() {}
	stack(Data v[])
	{
		__size = sizeof(v);
		for (int i = 0; i < sizeof(v); i++)
			this->v[i] = v[i];
	}
	bool empty()
	{
		return __size == 0;
	}
	int size()
	{
		return __size;
	}
	Data top()
	{
		return v[__size];
	}
	void push(Data el)
	{
		__size++;
		v[__size] = el;
	}
	void pop()
	{
		__size--;
		v[__size] = -1;
	}
	void swap(stack<Data>& x)
	{
		stack<Data> r;
		r = x;
		x = v;
		v = r;
		int __size2;
		__size2 = x.__size;
		x.__size = __size;
		__size = __size2;
	}
	stack operator[](int index)
	{
		if (index > __size)
		{
			cout << "index out of bounds";
			exit(0);
		}
		return v[index];
	}
	stack operator=(stack<Data>& obj)
	{
		stack<Data> st(obj);
		return st;
	}
	/*bool operator==(stack<Data>& obj)
	{
		if (size() != obj.size())
			return 0;
		for (int i = 0; i < size(); i++)
			if (v[i] != obj.v[i])
				return 0;
		return 1;
	}*/
	friend ostream& operator<<(ostream& os, stack& obj)
	{
		for (int i = 0; i < obj.size(); i++)
			os << obj.v[i] << " ";
		return os;
	}
};
int main()
{
	int v[] = { 1, 2 };
	int v1[] = { 1, 2 };
	stack<int> st(v), st1(v1);
	int r = st[100];
}
