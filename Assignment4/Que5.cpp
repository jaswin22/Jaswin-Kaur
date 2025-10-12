// 5) Write a program to implement a stack using (a) Two queues and (b) One Queue

#include <iostream>
using namespace std;

class Queue {
	int arr[1000];
	int frontIdx, rearIdx;
public:
	Queue() : frontIdx(0), rearIdx(0) {}
	void push(int x) 
    { 
        arr[rearIdx++] = x; 
    }
	void pop() 
    { 
        if (!empty()) 
                ++frontIdx; 
    }
	int front() 
    { 
        return arr[frontIdx]; 
    }
	int size() 
    { 
        return rearIdx - frontIdx; 
    }
	bool empty() 
    { 
        return size() == 0; 
    }
};

class StackTwoQueues 
{
	Queue q1, q2;
    public:
        void push(int x) 
        { 
            q1.push(x); 
        }
        void pop() 
        {
            if (q1.empty()) 
            {
                cout << "Stack is empty\n";
                return;
            }
            while (q1.size() > 1) 
            {
                q2.push(q1.front());
                q1.pop();
            }
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
            swap(q1, q2);
        }
        int top() 
        {
            if (q1.empty())
                return -1;
            while (q1.size() > 1) 
            {
                q2.push(q1.front());
                q1.pop();
            }
            int res = q1.front();
            q2.push(res);
            q1.pop();
            swap(q1, q2);
            return res;
        }
        bool empty() { return q1.empty(); }
};

class StackOneQueue
{
	Queue q;
    public:
        void push(int x) 
        {
            q.push(x);
            int sz = q.size();
            for (int i = 0; i < sz - 1; ++i) 
            {
                q.push(q.front());
                q.pop();
            }
        }
        void pop() 
        {
            if (q.empty()) 
            {
                cout << "Stack is empty\n";
                return;
            }
            cout << "Popped: " << q.front() << endl;
            q.pop();
        }
        int top() 
        {
            if (q.empty())
                return -1;
            else
                return q.front();
        }
        bool empty() { return q.empty(); }
};

int main() 
{
	cout << "Stack using Two Queues:\n";

	StackTwoQueues s2q;
	s2q.push(10);   s2q.push(20);   s2q.push(30);
	cout << "Top: " << s2q.top() << endl;
	s2q.pop();
	cout << "Top: " << s2q.top() << endl;
	s2q.pop();      s2q.pop();      s2q.pop();

	cout << "\nStack using One Queue:\n";
	StackOneQueue sq;
	sq.push(100);   sq.push(200);   sq.push(300);
	cout << "Top: " << sq.top() << endl;
	sq.pop();
	cout << "Top: " << sq.top() << endl;
	sq.pop();       sq.pop();   	sq.pop();
}