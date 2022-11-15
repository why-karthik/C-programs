#include <stdio.h>
#include<string.h>

int read_line(char str[]);

int main()
{

    char number[1000];

    int even_sum = 0, odd_sum = 0, total;
    int ch, i = 0;
    printf("Enter the value of X:");

    while ((ch = getchar()) != '\n'){
        if(ch == ' '){
            continue;
        }
        number[i++] = ch;
        if(i%2 == 0){
            even_sum = even_sum + (ch-'0');
        }
        else{
            odd_sum = odd_sum + (ch-'0');
        }
    }

    total = even_sum - odd_sum;

    if (total % 11 == 0)
    {
        printf("%s is a multiple of 11\n", number);
        return 0;
    }
    printf("%s is not a multiple of 11\n", number);
    return 0;
}
