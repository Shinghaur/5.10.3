#include <iostream>

typedef long long int L;
using namespace std;

struct Node
{
    L data;
    Node *next;
    Node() {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

L func(L b, L p, L m) 
{
	long long x = 1, y = b;

	while (p > 0) 
    {
		cout << x << " " << y << " " << p << endl;
        if (p % 2 == 1)
			x = (x * y) % m;

		y = (y * y) % m;
		p = p / 2;
	}
	return x % m;
}


int main()
{
    long long b, p, m;
    Node *head = nullptr, *ptr;

	while (cin >> b >> p >> m && (b || p || m))
    {
        if (!head)
        {
            head = new Node(func(b, p, m));
            ptr = head;
        }
        
        else
        {
            ptr->next = new Node(func(b, p, m));
            ptr = ptr->next;
        }
    }

    ptr = head;

    while (ptr)
    {    
        cout << ptr->data << endl;
        ptr = ptr->next;
    }

    return 0;
}