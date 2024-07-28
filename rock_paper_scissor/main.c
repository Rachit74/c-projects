// basic CLI Bases Rock paper scissor game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int user_points = 0;
int computer_points=0;
int tie=0;

char *generateRandomRPS() { //function which will generate return random choice out of RPS on behalf of computer.

    char *rps[] = {"rock","paper","sissor"};
    int size = sizeof(rps)/sizeof(rps[0]);

    // generate a random index from rps (0 to n-1)
    int random_index = rand() % size;

    // assings the rps[random_index] to computer choice;
    char *computer_choice = rps[random_index];
    return computer_choice;
};

char userRPS() {
    char user_input;
    printf("Enter your Choice (R,P,S): ");
    scanf(" %c", &user_input);
    
    // Clear the input buffer
    while (getchar() != '\n');

    user_input = tolower(user_input);
    return user_input;

};

void logic(char u,char *c) {
    // main logic

    if (u == 'r' && c[0] == 'p')
    {
        computer_points +=1;
    } else if (u == 'r' && c[0] == 's')
    {
        user_points +=1;
    } else if (u == 's' && c[0] == 'r')
    {
        computer_points += 1;
    } else if (u == 's' && c[0] == 'p')
    {
        user_points +=1;
    } else if (u == 'p' && c[0] == 's') 
    {
        computer_points += 1;
    } else if (u == 'p' && c[0] == 'r')
    {
        user_points +=1;
    } else if (u == c[0])
    {
        tie +=1;
    }
    
    
};

int main() {
    // seed random generator with current time for diffrent generation each time the program runs
    srand(time(0));

    int i = 0;
    int rounds;
    printf("Enter Number of Rounds you would like to play: ");
    scanf("%d", &rounds);

    while (i<rounds) {
        i++;
        char *com = generateRandomRPS();
        char use = userRPS();
        logic(use,com);
        printf("----Current Score---- (Round %d)\nUser: %d\nComputer: %d\nTie: %d\n----------------\n",i,user_points,computer_points,tie);
    };

    if (user_points > computer_points) {
        printf("User Won \nFinal Score\nUser: %d\nComputer: %d\n",user_points,computer_points);
    }else if (user_points == computer_points)
    {
        printf("Match Tie \nFinal Score\nUser: %d\nComputer: %d\n",user_points,computer_points);
    }
     else {
        printf("User Lost \nFinal Score\nUser: %d\nComputer: %d\n",user_points,computer_points);
    };

    return 0;
};