#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size ;
    int top;
    int * arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        return val;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    int n;
    printf("enter stack size\n");
    scanf("%d",&n);
    sp->size = n;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Pushed %d in the stack\n", push(sp, 1));
    printf("Pushed %d in the stack\n", push(sp, 23));
    printf("Pushed %d in the stack\n", push(sp, 99));
    printf("Pushed %d in the stack\n", push(sp, 75));

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    return 0;
}
