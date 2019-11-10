int main()
{
    float value, operand;
    char operater;

    printf("Enter an expression: ");
    scanf("%f", &value);

    while ((operater = getchar()) != '\n') {
        if (operater == ' ')
            continue;
        scanf("%f", &operand);
        switch (operater) {
        case '+':
            value += operand;
            break;
        case '-':
            value -= operand;
            break;
        case '*':
            value *= operand;
            break;
        case '/':
            value /= operand;
            break;
        }
    }
    printf("Value of expression: %g\n", value);
    return 0;
}