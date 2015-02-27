#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
struct Element {
	T data;
	Element *next;
};

template <typename T> 
class Stack {
	Element<T> *current = NULL;
public:
	void push(T new_data) {
		Element<T> *new_node = new Element<T>;
		new_node->data = new_data;
		new_node->next = current;
		current = new_node;
	}
	T top() {
		if (current == NULL)
			return (T)NULL;
		return current->data;
	}
	void pop() {
		if (current != NULL) {
			Element<T> *d = current;
			current = current->next;
			delete(d);
		}
	}
	int empty() {
		if (current == NULL) {
			return true;
		} else {
			return false;
		}
	}
	void print_stack() {
		Element<T> *runner = current;
		cout << "Stack : ";
		while (runner != NULL) {
			cout << runner->data << " ";
			runner = runner->next;
		}
		cout << endl;
	}
};

int main()
{
	Stack<int> S;
	cout << "Boş Stack" << endl;
	S.print_stack();
	
	cout << "Push(6)" << endl;
	S.push(6);
	S.print_stack();
	
	cout << "Push(5)" << endl;
	S.push(5);
	S.print_stack();
	
	cout << "Push(-2)" << endl;
	S.push(-2);
	S.print_stack();
	
	cout << "Top : " << S.top() << endl;
	S.print_stack();
	
	cout << "Top : " << S.top() << endl;
	S.print_stack();
	
	cout << "Pop" << endl;
	S.pop();
	S.print_stack();
	
	cout << "Push(8)" << endl;
	S.push(8);
	S.print_stack();

	cout << "Pop" << endl;
	S.pop();
	S.print_stack();
	
	return 0;
}
