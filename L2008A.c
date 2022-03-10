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
    int input_val;

    stack_init();

    while (input_val != 999){
        fflush(stdin);
        scanf("%d", &input_val);
        if (input_val == 0){
            if (t == -1){
                printf("Error - Stack is empty\n");
            }
            else{
                pop();
            }
        }
        else if (input_val < 0){
            int top_val;
            top_val = top();
            if (t == -1){
                printf("Error - Stack is empty\n");
            }
            else{
            printf("%d\n", top_val);
            }
        }
        else{
            push(input_val);
        }
    }
}