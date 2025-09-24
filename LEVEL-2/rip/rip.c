#include <unistd.h>
#include <stdio.h>

int calculate_length(char *string)
{
    int counter = 0;
    while (string[counter])
        counter++;
    return counter;
}

int check_validity(char *string)
{
    int balance = 0; 
    int index = 0;
    while (string[index])
    {
        if (string[index] == '(')
            balance++;
        else if (string[index] == ')')
        {
            balance--;
            if (balance < 0)
                return 0;
        }
        index++;
    }
    return (balance == 0);
}

void generate_combinations(char *text, int position, int excess_open, int excess_close)
{
    if (excess_open == 0 && excess_close == 0)
    {
        if (check_validity(text))
            puts(text);
        return;
    }

    int current = position;
    while (text[current])
    {
        if (text[current] == '(' && excess_open > 0)
        {
            text[current] = ' ';
            generate_combinations(text, current + 1, excess_open - 1, excess_close);
            text[current] = '(';
        } 
        else if (text[current] == ')' && excess_close > 0)
        {
            text[current] = ' ';
            generate_combinations(text, current + 1, excess_open, excess_close - 1);
            text[current] = ')';
        }
        current++;
    }
}

int main (int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    int length = calculate_length(argv[1]);
    int unmatched_open = 0, unmatched_close = 0;
    char buffer[length + 1];
    int idx = 0;
    while (idx < length)
    {
        buffer[idx] = argv[1][idx];
        idx++;
    }
    buffer[length] = '\0';

    idx = 0;
    while (idx < length)
    {
        if (buffer[idx] == '(')
            unmatched_open++;
        else if (buffer[idx] == ')')
        {
            if (unmatched_open > 0)
                unmatched_open--;
            else 
                unmatched_close++;
        }
        idx++;
    }
    generate_combinations(buffer, 0, unmatched_open, unmatched_close);
}
