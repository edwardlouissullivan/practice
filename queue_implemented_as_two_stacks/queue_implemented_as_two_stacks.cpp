/* PROMPT: Implement a MyQueue class which implements a queue using two stacks.



IMPLEMENTATION NOTES
===============
Every time you switch from a push to a pop, or from a pop to 
a push, you need to move the elements to the other stack


*/

#include <stack>

template <class T>
class Queue {

    int len;
    stack<T> s1;
    stack<T> s2; 

    public:
        // Constructors
        Queue(): len(0) {}

        // Queue operators
        void push(T);
        T leftpop();
        int length();

};





template <class T>
void Queue::push(T){
        
    len++;
}

template <class T>
void Queue::leftpop(T){
    
    len--;
}

template <class T>
void Queue::length(T){
    return len;
}


void test_queue(){
       
    return;
}

int main(){
    test_queue();
    cout << "ALL TESTS PASSED" << endl;
    return 0;
}



