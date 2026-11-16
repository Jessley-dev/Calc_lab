# include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;
    printf("Enter your calculation in this format (10 + 5):\n");
    scanf("%lf %c %lf", &num1, &operator, &num2);

    switch(operator){
        case '+':
        result = num1 + num2;
        break;

        case '-':
        result = num1 - num2;
        break;

        case '*':
        result = num1 * num2;
        break;

        case '/':
        if(num2 !=0){
            result = num1 / num2;
        }
        else{
            printf("Division by zero is undefined!\n");
        }

    }
    printf("The result of your operation is: %d", result);
return 0;
}
