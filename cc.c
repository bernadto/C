#include <cs50.h>
#include <stdio.h>
//Declare at first
void print_cc_brand(long ccn);
bool check_valid(long cc_number);
int find_length(long n);
bool checksum(long ccn);

//Main Program
int main(void)
{
    long cc_number;
    do
    {
        cc_number = get_long("Input Number: ");
    }
    while (cc_number < 0);

    if (check_valid(cc_number))
    {
        print_cc_brand(cc_number);
    }
    else
    {
        printf("INVALID\n");
    }
}
//check validity of credit card number
bool check_valid(long cc_number)
{
    int len = find_length(cc_number);
    return (len == 13 || len == 15 || len == 16) && checksum(cc_number);
}
//find length of credit card number
int find_length(long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}
//check validity for each number of cc
bool checksum(long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int mult = 2 * (ccn % 10);
            sum += mult / 10 + mult % 10;
        }
    }
    return (sum % 10) == 0;
}
//print brand of cc
void print_cc_brand(long ccn)
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }

    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
