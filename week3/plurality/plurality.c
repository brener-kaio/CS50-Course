#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    candidate_count = argc - 1;

    for (int j = 1; j < candidate_count; j++)
    {
        candidates[j].name = argv[j];
    }

    int voters = get_int("Number of voters: ");
    string votes[voters];

    for (int i = 0; i < voters; i++)
    {
        votes[i] = get_string("Vote: ");
        while (vote(votes[i]) != false)
        {
            printf("Invalid vote. \n");
            votes[i] = get_string("Vote: ");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maxvotes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}