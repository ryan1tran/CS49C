#include<stdio.h>
#include<ctype.h>
#include <math.h>

#define SIZE 50 // size of stack

int stack[SIZE]; // using int array to implement stack
int top = -1; // index for top of stack

// push int to top of stack
void push(int value)
{
    if (top != SIZE) // if stack isn't full
        stack[++top] = value; // increment and place value
    else
        puts("Error: stack is full."); // else print error message
}

// pop int from stop of stack
int pop()
{
    if (top != -1) // if stack isn't empty
        return stack[top--]; // decrement and return value
    else
        puts("Error: stack is empty."); // else print error message
}

// returns if stack is empty, which is when top = -1
int isEmpty()
{
    return top == -1;
}

// prints the stack from oldest to newest
void printStack()
{
    for (int i = 0; i <= top; i++) // iterates up to top and prints
        printf("%d ", stack[i]);
}

// calculates the result of two operands based on the operator
int calculate(int op1, int op2, char operator)
{
    // switch cases based on the operator
    switch (operator)
    {
        case '+':
            return op2 + op1;
        case '-':
            return op2 - op1;
        case '*':
            return op2 * op1;
        case '/':
            return op2 / op1;
        case '^':
            return pow(op2, op1);
        case '%':
            return op2 % op1;
    }
}

// evaluates the postfix expression
void evaluatePostfixExpression(void)
{
    char equation[SIZE]; // char array for postfix equation
    char* ch; // pointer to a char
    int A, B, result, value; // int variables for evaluating

    printf("Enter the expression: ");
    scanf("%[^\n]", equation); // scans in equation as a string, including spaces

    ch = equation; // assign pointer to char array of equation
    while (*ch != '\0') // while pointer does not point to end of equation string
    {
        // if the character is a digit
        if (isdigit(*ch))
        {
            value = *ch - 48; // subtract 48 to deal with ascii
            push(value); // and push the value into the stack
        }
        // if the character is a space, do nothing
        else if (isspace(*ch))
            ;
        // else the character is an operator
        else
        {
            // take the top two values in the stack
            A = pop();
            B = pop();

            // use calculate to get the result depending on the operator character
            result = calculate(A, B, *ch);

            push(result); // push the result to the stack
        }

        ch++; // increment to the next character in the equation
    }

    // print result of the postfix equation
    // very last element of the stack after the equation is evaluated is the solution
    printf("\nPostfix result of %s is %d\n", equation, pop());

    /*
        sample test cases
            Postfix Equation      Regular Equation          Solution
        -----------------------------------------------------------
        1.  3 4 +                 3 + 4                     7
        2.  5 7 -                 5 - 7                     -2
        3.  3 5 *                 3 * 5                     15
        4.  6 4 /                 6 / 4                     1
        5.  6 4 %                 6 % 4                     2
        6.  6 2 + 5 * 8 4 / -     ((6 + 2) * 5) - (8 / 4)   38
        7.  8 2 * 3 4 * +         (8 * 2) + (3 * 4)         28
        8.  8 5 / 6 4 % *         (8 / 5) * (6 % 4)         2
        9.  2 3 ^ 3 ^ 2 +         2 ^ 3 ^ 3 + 2             514
     */
}

void hw5p1(void)
{
    evaluatePostfixExpression();
}

int main(void)
{
    hw5p1();
    return 0;
}
