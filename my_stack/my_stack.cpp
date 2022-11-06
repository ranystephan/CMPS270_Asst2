//
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
    bool empty () const { return items.empty() ;}
    void push (const T &item) { items.push_back(item);}
    T pop() {
        T last = items.back();
        items.pop_back();
        return last ;
    }
    T top() {
        return items.back();
    }
};

    
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
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a + b;
    // the contents of c should now be 1, 2, 3, 4 (in that order)
    while (!c.empty()) {
        cout << c.top() << endl;
        c.pop();
    }

    return 0;

}

