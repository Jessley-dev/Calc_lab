# include <stdio.h>
#include <math.h>

void basicOperations(double num1, char operator, double num2) {
    double result;
    int valid = 1;
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
        case 'x':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Division by zero is undefined!\n");
                valid = 0;
            }
            break;
        case '%':
            if(num2 != 0) {
                result =fmod(num1,num2);
               
            } else {
                printf("Modulus by zero is undefined!\n");
                valid = 0;
            }
            break;
        case '^':
            result = pow(num1, num2);
            break;
        default:
            printf("Invalid operator!\n");
            valid = 0;
    }
    if(valid == 1) {
        printf("The result of your calculation is %.2lf\n", result);
    }
}
int main() {
    double num1, num2;
    char operator;
    int validInput;
    printf("Welcome to the calculator!\n");
    printf("You can only perform basic operations which are the following: +, -, *, /, %, ^\n");
   do { printf("Enter your calculation:\n");
        validInput = scanf("%lf %c %lf", &num1, &operator, &num2);
        if (validInput == EOF) {
            printf("No more input available.\n");
            return 1;
        }
        if(validInput != 3) {
            printf("Invalid input format. Please enter in the format: number, operator, number\n");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF) {
            }
        }
        }while(validInput != 3);

    basicOperations(num1, operator, num2);
    printf("Thank you for using the calculator!\n");

return 0;
}
