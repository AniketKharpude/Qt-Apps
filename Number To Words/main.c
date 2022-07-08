#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
char *onetonineteen[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *twentytohundred[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};
void main()
{
    char ch;
    int number, tensplace, unitplace, i, hundredsplace, thousandsplace, lacsplace;
start:
    printf("Enter amount:");
    scanf("%d", &number);
    if (number > 99999 && number < 10000000)
    {
        lacsplace = number / 100000;
        if (lacsplace > 19 && lacsplace < 100)
        {
            printf("%s ", twentytohundred[lacsplace / 10]);
            unitplace = lacsplace % 10;
            printf("%s Lakh ", onetonineteen[unitplace]);
            number = number % 100000;
        }
        else
        {
            printf("%s Lakh ", onetonineteen[lacsplace]);
            number = number % 100000;
        }
        // printf("%s Lakh ", onetonineteen[lacsplace]);
        // number = number % 100000;
    }
    if (number > 999 && number < 100000)
    {
        thousandsplace = number / 1000;
        if (thousandsplace > 19 && thousandsplace < 100)
        {
            // thousandsplace = thousandsplace / 10;
            printf("%s ", twentytohundred[thousandsplace / 10]);
            unitplace = thousandsplace % 10;
            printf("%s Thousand ", onetonineteen[unitplace]);
            number = number % 1000;
        }
        else
        {
            printf("%s Thousand ", onetonineteen[thousandsplace]);
            number = number % 1000;
        }
    }

    if (number > 99 && number < 1000)
    {
        hundredsplace = number / 100;
        printf("%s Hundred ", onetonineteen[hundredsplace]);
        number = number % 100;
    }
    if (number > 19 && number < 100)
    {
        tensplace = number / 10;
        printf("%s ", twentytohundred[tensplace]);
        number = number % 10;
    }
    if (number <= 19 && number >= 0)
    {
        printf("%s Rupees Only /-\n", onetonineteen[number]);
    }
    printf("Enter 'Esc' To Exit OR Press Any Key To Continue[ ]\b\b");
    fgetc(stdin);
    scanf("%c", &ch);
    if (ch == 'E' || ch == 'e'|| ch==27)
    {
        exit;
    }
    else
        goto start;
}

