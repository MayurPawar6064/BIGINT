#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 35
#define LIMIT_OF_BIGINT 1000000000
typedef long long int big_num;
struct BigInt
{
    big_num digit[MAX_SIZE];
};

struct BigInt intialize_to_zero(struct BigInt num)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        num.digit[i] = 0;
    }
    return num;
}

int digit_counter(big_num num)
{
    int counter = 0;
    while (num != 0)
    {
        counter++;
        num = num / 10;
    }
    return counter;
}

void print_big_number(struct BigInt num)
{
    int i = 0;

    while (i < MAX_SIZE && num.digit[i] == 0)
    {
        i++;
    }
    printf("%lld", num.digit[i]);
    i++;
    for (; i < MAX_SIZE; i++)
    {
        if (i != 0)
        {
            int count = digit_counter(num.digit[i]);
            for (int j = 0; j < 9 - count; j++)
            {
                printf("0");
            }
            printf("%lld", num.digit[i]);
        }
    }
    printf("\n\n");
}

struct BigInt subtraction_operation(struct BigInt n1, struct BigInt n2, struct BigInt ans)
{

    big_num borrow = 0;
    big_num difference = 0;
    for (int i = MAX_SIZE - 1; i >= 0; i--)
    {
        // if diff is negative then the borrow becomes 1 and it stores the 10's complement of modulus of num
        difference = n1.digit[i] - n2.digit[i] - borrow;

        if (difference >= 0)
        {
            borrow = 0;
        }
        else
        {
            difference = difference + LIMIT_OF_BIGINT;
            borrow = 1;
        }

        ans.digit[i] = difference;
    }

    return ans;
}

big_num Add_to_big_num(char n1[], int n)
{
    big_num ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * 10 + n1[i] - '0';
    }

    return ans;
}

void BigInt_converter(char *number, struct BigInt *result)
{
    int k = MAX_SIZE - 1;
    int i = strlen(number) - 1;
    // we should add string of charters to array of big_num from back
    int count = 0;
    while (i >= 0)
    {
        count++;
        if (count == 9)
        {
            result->digit[k] = Add_to_big_num(number + i, 9);
            count = 0;
            k--;
        }
        i--;
    }
    // If there are remaining digits after the loop, convert them
    if (count > 0)
    {
        result->digit[k] = Add_to_big_num(number, count);
    }
}

struct BigInt multiplication_operation(struct BigInt n1, struct BigInt n2, struct BigInt ans)
{
    // ans should be zero initially
    int error = 0;
    big_num carry = 0;
    big_num product = 0;
    for (int i = (MAX_SIZE - 1); i >= 0; i--)
    {
        for (int j = (MAX_SIZE - 1); j >= 0; j--)
        {
            // if index greater than 1024 bits then it will return error
            int index = i + j - (MAX_SIZE - 1);
            if (index < 0)
            {
                error = 1;
            }
            else
            {
                product = (n1.digit[j] * n2.digit[i]) % LIMIT_OF_BIGINT;
                ans.digit[index] = (ans.digit[index] + product) % LIMIT_OF_BIGINT;
                carry = (n1.digit[j] * n2.digit[i]) / LIMIT_OF_BIGINT;

                if (index != 0)
                {
                    ans.digit[index - 1] = ans.digit[index - 1] + carry;
                    carry = 0;
                }

                else
                {
                    if (carry != 0)
                    {
                        carry = 0;
                        error = 1;
                    }
                }
                
            }
        }
    }
    if (error == 1 && ans.digit[0] != 0)
    {
        printf("Limit is more than 1024 bits\n");
    }
    return ans;
}

struct BigInt addition_operation(struct BigInt n1, struct BigInt n2, struct BigInt ans)
{

    big_num carry = 0;
    big_num sum = 0;
    for (int i = MAX_SIZE - 1; i >= 0; i--)
    {
        sum = n1.digit[i] + n2.digit[i];
        ans.digit[i] = (sum + carry) % LIMIT_OF_BIGINT;
        carry = (carry + sum) / LIMIT_OF_BIGINT;
    }
    return ans;
}

void Swap_if_greater(char *number1, char *number2, int size)
{
    char temp[310];
    int num1, num2;
    num1 = number1[0] - '0';
    num2 = number2[0] - '0';

    if (strlen(number1) < strlen(number2))
    {
        strcpy(temp, number1);
        strcpy(number1, number2);
        strcpy(number2, temp);
    }
    else if (strlen(number1) == strlen(number2) && num1 < num2)
    {
        strcpy(temp, number1);
        strcpy(number1, number2);
        strcpy(number2, temp);
    }
}

int main()
{
    int option;
    struct BigInt n1, n2, ans;
    n1 = intialize_to_zero(n1);
    n2 = intialize_to_zero(n2);

    char number1[310];
    char number2[310];

    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error file not opened\n");
        return 1;
    }
    if (fscanf(file, "%s %s", number1, number2) == 2)
    {
        printf("numbers are read from file from the file.\n");
    }
    else
    {
        printf("numbers are not recorded \n");
        return 1;
    }
    Swap_if_greater(number1, number2, sizeof(number1) / sizeof(number1[0]));

    fclose(file);
    // sends address of first element of string
    BigInt_converter(number1, &n1);
    BigInt_converter(number2, &n2);
    printf("Number 1: ");
    print_big_number(n1);
    
    printf("Number 2: ");
    print_big_number(n2);

    do
    {
        printf("ENTER 1 FOR ADDITION\n");
        printf("ENTER 2 FOR MULTIPLICATION\n");
        printf("ENTER 3 FOR SUBSTRACTION\n");
        printf("ENTER 4 FOR EXIT\n");
        printf("    Enter the option:-");
        scanf("%d", &option);
        switch (option)
        {
        case 2:
            ans = intialize_to_zero(ans);
            ans = multiplication_operation(n1, n2, ans);
            printf("Multiplication:");
            print_big_number(ans);

            break;
        case 1:
            ans = intialize_to_zero(ans);
            ans = addition_operation(n1, n2, ans);
            printf("Addition:");
            print_big_number(ans);
            break;
        case 3:
            ans = intialize_to_zero(ans);
            ans = subtraction_operation(n1, n2, ans);
            printf("Substraction:");
            print_big_number(ans);

            break;
        case 4:
            printf("THE PROGRAM GOT EXITED\n");
            break;
        default:
            printf("ENTER VALID INPUT\n");
            break;
        }
    } while (option != 4);

    return 0;
}