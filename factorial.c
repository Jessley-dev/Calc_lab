# include <stdio.h>  // Provides standard input/output functions

# include <stdlib.h> // Provides general utility functions like strtol(string to long)

# include <errno.h>  // Provides errno for identifying errors in different library funtions

# include <limits.h> //Provides limits of integer types in C like INT_MAX and INT_MIN

# include <string.h> // Provides string-handling functions like strchr(string character search)

# include <ctype.h> // Provides funtions for character checking like isspace(whitespace check)

// The factorial function is for calculating  and displaying the factorial of the entered number.
// Using void because the fuction displays the result rather than returning a value the the calling function.
void factorial(int num) {

    // Using long long int to store the result of the factorial calculation to handle larger values.
    // Initialized to 1 because the factorial of 0 is 1 in case it is entered 
    // and also to serve as the multiplicative identity for the factorial calculation. 
    long long int result = 1;
       
    // Starts at 1 and iterates up to the entered number, multiplying the result by each integer in the range.
    for(int i = 1; i <= num; i++) {
            result *= i;
    }
       
    // Displays the calculated factorial result to the user.
    printf("The factorial of %d is: %lld\n", num, result);

}

int main() {

    // Creates a character array to store the user input up to 499 characters
    char input[500];

    // Variable to store converted input as a long integer
    long num;   
    
    // This will be used to validate that the input was valid enough and stop the program from giving 
    // two contrasting ideas that do not compy with each other at the end of the validation process
    int validInput = 0;

    // Loop executes at least once to ensure the user is prompted for input 
    // and continues until a valid non-negative integer is entered.
    do { 
        
        printf("Enter a non-negative integer to find its factorial:\n");
        
        // Reads a line of text from the input
        // sizeof(input) tells fgets the size of array
        // stdin is the standard input
        //fgets returns NULL  if there is an error or long integer
         if (fgets(input, sizeof(input), stdin) == NULL) {
            
            printf("No more input available.\n");
           
            // return 1 is used to indicate that the program encountered an error 
            // and terminates the program in that case
            return 1;
        }

        // Search for the newline character in the input string, if not there then returns NULL
        // This means can mean the user entered the final line without pressing enter.
        if (strchr(input, '\n') == NULL) {

            // read one additional character to check whether more input remains on the same line
            int ch =getchar();

            // if there are still additional characters then, this if is executed the input buffer can't hold that much.
            if (ch != '\n' && ch != EOF) {
                
                printf("Input too long. Please enter a valid non-negative integer.\n");    
                
                // This is to consume all characters to clear the input buffer
                // to prevent the leftover characters from being mistakenly into the new input on the next iteration
                while((ch = getchar()) != '\n' && ch != EOF) {
                }
                
                // Skip the rest of the loop after these iterations and go back to the do-while loop
                continue;
            }
        }
        
        // Declaring a pointer for strtol() to indicate it where it stopped converting the input string
        char *endptr;

        // Resets errors this is to detect errors
        // This is also done in order not to confuse them with the previous ones
        errno = 0; 
        
        // This is to convert the string into a large integer.
        // num = assigning the num variable
        // strtol is used to convert
        // input this is the string to convert
        // &endptr this addresses the first character strtol() did not convert 
        // 10 this indicates it is done in base 10
        num = strtol(input, &endptr, 10);

        // this checks whether strtol encountered a range error
        // ERANGE means the converted value was too large
        // or too small to be represented by long
        // INT_MAX and INT_ MIN are representing the int limits
        // this if is executed when one of these conditions is true
        if (errno == ERANGE || num > INT_MAX || num < INT_MIN) {
            
            printf("The number is out of range. Please enter a valid non-negative integer.\n");
            
            continue;
        }

        // endptr == input means strtol() didn't convert any digits
        if (endptr == input ) {
            
            printf("Invalid input. Please enter a valid non-negative integer.\n");
            

            continue;
        }
        
        // this is to skip any whitespaces if detected after the number entered
        while(isspace((unsigned char)*endptr)) {
            endptr++;
        }
        
        // *endptr != '\0' means that there are other errors other than the white space characters
        if ( *endptr != '\0') {
            
            printf("Invalid input. Please enter a valid non-negative integer.\n");
            
            continue;
        }


        // This lets the user know that factorials greater than 20 cannot be represented
        // efficiently because the value is far too large than long long int
        if (num > 20) {
            
            printf("Unfortunately, the factorial of numbers greater than 20 cannot be calculated due to integer overflow. Please re-enter an integer that is less than or equal to 20.\n");
            
            continue;
        }

        // This lets the user know that negative factorials are undefined
        if(num < 0) {
            
            printf("The factorial is not defined for negative integers!\n"); 
            
            continue;
        }

        // If all the validation conditions are found false then we initiate 
        // the validInput to 1 for the while to keep changing
        validInput = 1;

      // Repeats this loop if this condition is true
      // when false it leaves the loop
    } while( validInput == 0);
    
    // Calls the factorial funtion but first
    // convert it into int because it is from 0 to anywhere below 20
    factorial((int)num);

    //This indicatest that there is successfull execution
    return 0;
}