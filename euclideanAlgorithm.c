# include <stdio.h>

void euclideanAlgorithm(int num1, int num2) {
    int rem;

    while(num2 != 0) {
        rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }
    printf("The GCD of the two numbers is: %d\n", num1);
}
int main() {
    int num1, num2;
    int validInput;
    
    do { printf("Enter two positive integers to find their GCD:\n");
        validInput = scanf("%d,%d",&num1, &num2);
        if (validInput == EOF) {
            printf("No more input available.\n");
            return 1;
        }
        if(validInput != 2) {
            printf("Invalid input format. Please enter in the format: number, number (!remember comma!)\n");
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF) {
            }
        }
        }while(validInput != 2 || num1 <= 0 || num2 <= 0 );

        euclideanAlgorithm(num1, num2); 
    return 0;
}