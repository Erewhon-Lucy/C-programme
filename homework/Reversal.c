#include <stdio.h>
#include <stdlib.h>

#define N 50

int read_message(char a[], int n);
void print_message(char a[], int n);
void print_message_reverse(char a[], int n);

int main()
{
    char message[N];

    int message_length = read_message(message, N);
    print_message(message, message_length);
    print_message_reverse(message, message_length);

    return 0;
}

int read_message(char a[], int n)
{
    char ch;
    int i;
    printf("Enter a message: ");
    for (i = 0; (ch = getchar()) != EOF && ch != '\n'; i++)
        a[i] = ch;

    return i;

}

void print_message(char a[], int n)
{
    char *p;

    for (p = a; p < a + n; p++)
        printf("%c", *p);
    printf("\n");
}

void print_message_reverse(char a[], int n)
{
    int i;
    printf("Reveral is: ");
    for (i = n - 1; i >= 0; i--)
        printf("%c", a[i]);
    printf("\n");
}
