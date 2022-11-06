//
//  Github: ranystephan
//  my_stack.cpp
//  ranystephan.rcs04.asst2
//
//  Created by Rany STEPHAN
//

#include "my_stack.hpp"

#include <iostream>
#include <vector>

using namespace std;

#include "my_stack.hpp"

#include <iostream>
#include <vector>

using namespace std;

template <class T> class Stack ;

template <class T>
Stack <T> operator +(const Stack <T> &s1 , const Stack <T> &s2);

template <class T>
class Stack {
    friend Stack <T> operator +<>(const Stack <T> &s1 , const Stack <T> &s2);
    vector<T> items ;
    
public :
    /*
        requires: nothing
        effects: returns true if stack is empty, returns false otherwise
        testing strategy:
        1) passing a empty stack
        2) passing a non empty stack
        */
    bool empty () const { return items.empty() ;}
    /*
    requires: a constant refernce of any type
    effects: pushes the last item in the stack
    testing strategy:
    1) pushing a non empty stack
    2) pushing an empty stack
    3) pushing an integer
    4) pushing a char
    5) pushing a float
    6) pushing a double
    7) pushing a long
    */
    void push (const T &item) { items.push_back(item);}
    /*
    requires: nothing
    effects: returns the top element of the stack and removes
    testing strategy:
    1) calling on a non empty stack
    2) calling on an empty stack
    */
    T pop() {
        T last = items.back();
        items.pop_back();
        return last ;
    }
    /*
    requires: nothing
    effects: returns the top element of the stack
    testing strategy:
    1) calling on a non empty stack
    2) calling on an empty stack
    */
    T top() {
        return items.back();
    }
};

// Operator Overloading is added to this file
// The behavior should that when the + operator is used, for instance a + b, you get a new stack containing a's items followed by b's items
/*
requires: 2 stacks
effects: returns a new stack with the values of both previous
stacks
testing strategy:
1) calling on 1 empty stack
2) calling on 2 empty stacks
3) have one stack shorter than the other
4) have both stacks of equal size
5) concatinating sevral stacks
*/
template <class T>
Stack <T> operator +(const Stack <T> &s1 , const Stack <T> &s2)
{
    Stack <T> result = s1;
    for (unsigned i = 0; i < s1.items.size(); ++i) {
        result.items.push_back(s2.items[i]);
    }

    return result ;
}

int main() {
    Stack<int> a, b;
    a.push(0);
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a + b;
    // the contents of c should now be 0, 1, 2, 3, 4 (in that order)
    while (!c.empty()) {
        cout << c.top() << endl;
        c.pop();
    }

    Stack<char> d, e;
    //in this case, 'd' is still empty so it should print 1
    cout << d.empty() << " Empty func: 1 means yes, else no" << endl;
    
    d.push('a');
    d.push('b');
    d.push('c');
    d.push('d');
    e.push('e');
    e.push('f');
    e.push('g');
    e.push('h');
    Stack<char> f = d + e;
    while (!f.empty())
    {
        cout << f.top() << endl;
        f.pop();
    }
}

