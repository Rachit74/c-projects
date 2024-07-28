#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

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
    scanf("%c", &user_input);

    user_input = tolower(user_input);
    return user_input;

};

const char *logic(char u,char *c) {
    int user_points=0;
    int computer_points=0;
    char *winner;

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
    };
    
    if (user_points > computer_points) {
        winner = "User";
        return winner;
    } else {
        winner = "Computer";
        return winner;
    };    
};

int main() {
    // seed random generator with current time for diffrent generation each time the program runs
    srand(time(0));

    char *com = generateRandomRPS();
    char use = userRPS();
    const char *win = logic(use,com);
    printf("%s",win);
    return 0;
};