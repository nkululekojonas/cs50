#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Check every candidate to see if they are chosen
    for (int i = 0; i < candidate_count; i++)
    {
        // If they are prefered
        if (strcmp(candidates[i], name) == 0)
        {
            // update the voters ranks with the candidate
            ranks[rank] = i;
            return true;
        }
    }
    // The name didn't match any of the candidates return false
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // For every rank
    for (int i = 0; i < candidate_count; i++)
    {
        // Get prefered canidate
        int x = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Get lower ranked preference
            int y = ranks[j];
            // Record preference
            preferences[x][y] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Start pair count
    pair_count = 0;

    // For every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Every other candidate
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Create a new pair
            pair current;
            if (preferences[i][j] > preferences[j][i])
            {
                current.winner = i;
                current.loser = j;
                pairs[pair_count] = current;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                current.winner = j;
                current.loser = i;
                pairs[pair_count] = current;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Iterate over the every pair
    for (int i = 0; i < pair_count; i++)
    {
        // Get the current pair
        pair current = pairs[i];

        // Get the strength of victory
        int margin =
            preferences[current.winner][current.loser] - preferences[current.loser][current.winner];

        // Compare against other pairs
        for (int j = i + 1; j < pair_count; j++)
        {
            pair next_pair = pairs[j];
            int next_margin = preferences[next_pair.winner][next_pair.loser] -
                              preferences[next_pair.loser][next_pair.winner];

            if (next_margin > margin)
            {
                pair temp = current;
                pairs[i] = next_pair;
                pairs[j] = temp;
                current = next_pair;
                margin = next_margin;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
bool creates_cycle(int winner, int loser)
{
    if (winner == loser)
        return true;

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (creates_cycle(winner, i))
                return true;
        }
    }

    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // For every pair
    for (int i = 0; i < pair_count; i++)
    {
        // Get the current pair
        pair current = pairs[i];
        if (!creates_cycle(current.winner, current.loser))
            locked[current.winner][current.loser] = true;
    }
    return;
}

void print_winner(void)
{
    // Iterate through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_winner = true;

        // Check if any candidate locks this candidate (i.e., checks for incoming edges)
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i]) // If any candidate locks i, it's not the winner
            {
                is_winner = false;
                break;
            }
        }

        // If no one locks candidate i, they are the winner
        if (is_winner)
        {
            printf("%s\n", candidates[i]);
            return; // Once we find the winner, we can stop
        }
    }
}