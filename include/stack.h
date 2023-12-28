#ifndef STACK

#define STACK


#include<iostream>
#include<vector>
#include<string>


template <class T>
class Stack {
    T* data;
    int size_data;
    int top; // stack is empty -> top = -1
public:

    Stack(int s_d = 10) : size_data(s_d)
    {
        if (size_data <= 0)
            throw "Wrong size";
        data = new T[size_data];
        top = -1;
    }
    void push(const T& dat) {
        if (top + 1 == size_data) {
            T* buff = new T[size_data << 1];
            std::copy(data, data + size_data, buff);
            delete[] data;
            size_data <<= 1;
            data = buff;
        }
        data[++top] = dat;
    }

    void pop() {
        if (!isEmpty())
            top--;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else
            return false;
    }

    T Top() {
        if (isEmpty())
            throw "Error";

        return data[top];
    }

};
#endif