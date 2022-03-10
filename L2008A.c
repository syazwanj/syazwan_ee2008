#include <stdio.h>

int t = -1;
int data[] = {};

void stack_init(void){
    t = -1;
}

int empty(void){
    if (t == -1) return 1;
    return 0;
}

void push(int val){
    t++;
    data[t] = val;
}

void pop(void){
    t--;
}

int top(void){
    return data[t];
}

int main(){
    if (empty() == 1){
        printf("Empty");
    }
    
    return 0;
}