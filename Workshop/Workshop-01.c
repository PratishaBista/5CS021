//Q1
#include <stdio.h>

int main() {
    int sum = 0;
    int i = 0;
    for(i=1; i <=10; i++) {
        sum+=i;
    }
    printf("%d", sum);

    return 0;
}

//Q2 factorial of a number
#include <stdio.h>

int main() {
    int i, num;
    unsigned long long fact = 1;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    if (num < 0 ) {
        printf("Factorial of negative number doesn't exist.");
    }
    else {
        for (i = 1; i<= num; i++){
            fact=fact*i;
        }
        printf("Factorial of %d = %llu", num, fact);
    }


    return 0;
}

//Q3 
#include<stdio.h>
int main () {
    int n, pattern;
    printf("Enter the number: ");
    scanf("%d", &n);
    
    for(int i = 1; i <=n; i++) {
        pattern = (i * (i + 1)/2);
        printf("Triangular number of %d: %d\n", i, pattern);
    }
   
    return 0;
    
}
    
//Q4 
#include <stdio.h>

int main() {
    char ch; 
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z') { 
        ch = ch + 32; 
    }
    printf("Character in lowercase: %c", ch);

    return 0;
}


//Q5
#include <stdio.h>

int main() {
    char ch;
    printf("Enter characters (press Enter to stop): ");

    while (1) { 
        scanf("%c", &ch); 

        if (ch == 13) {
            break;
        }

        printf("Program terminated");
    }

    return 0;
}


//Q6 
#include <stdio.h>
int main (){
    int i, j;
    char ch;
   
    for (i = 1; i<=5; i++){
        ch = 'A' + (i-1);
        
        for (j = 1; j<=i ; j++){
            printf("%c", ch);
    }
    printf("\n");
    }
    
    return 0;
    
}