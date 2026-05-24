#include<stdio.h>

void display_board(char board[9]){

    int i, count = 0;

    for(i = 0; i < 9; i++){

        printf("%c\t", board[i]);

        count++;

        if(count % 3 == 0){
            printf("\n");
        }
    }
}

int check(int entries[9], int response, int size){

    int i, j;

    for(i = 0; i < size; i++){

        if(response == entries[i]){

            for(j = i; j < size - 1; j++){
                entries[j] = entries[j + 1];
            }

            return 1;
        }
    }

    return 0;
}

int win_condition(char board[9]) {

    int i;

    for(i = 0; i < 3; i++) {

        if(board[i] == 'X' &&
           board[i + 3] == 'X' &&
           board[i + 6] == 'X') {

            printf("\nPlayer 1 wins!\n");
            return 1;
        }

        else if(board[i] == 'O' &&
                board[i + 3] == 'O' &&
                board[i + 6] == 'O') {

            printf("\nPlayer 2 wins!\n");
            return 1;
        }
    }

    for(i = 0; i < 7; i += 3) {

        if(board[i] == 'X' &&
           board[i + 1] == 'X' &&
           board[i + 2] == 'X') {

            printf("\nPlayer 1 wins!\n");
            return 1;
        }

        else if(board[i] == 'O' &&
                board[i + 1] == 'O' &&
                board[i + 2] == 'O') {

            printf("\nPlayer 2 wins!\n");
            return 1;
        }
    }

    if(board[0] == 'X' &&
       board[4] == 'X' &&
       board[8] == 'X') {

        printf("\nPlayer 1 wins!\n");
        return 1;
    }

    else if(board[0] == 'O' &&
            board[4] == 'O' &&
            board[8] == 'O') {

        printf("\nPlayer 2 wins!\n");
        return 1;
    }

    if(board[2] == 'X' &&
       board[4] == 'X' &&
       board[6] == 'X') {

        printf("\nPlayer 1 wins!\n");
        return 1;
    }

    else if(board[2] == 'O' &&
            board[4] == 'O' &&
            board[6] == 'O') {

        printf("\nPlayer 2 wins!\n");
        return 1;
    }

    return 0;
}

void replace(char board[9], int res, int *count){

    if(*count % 2 == 0){
        board[res - 1] = 'O';
    }

    else{
        board[res - 1] = 'X';
    }
}

int main(){

    char board[9] = {'1','2','3','4','5','6','7','8','9'};

    int entries[9] = {1,2,3,4,5,6,7,8,9};

    int size = 9, i, count = 1, res;

    printf("The game starts with the first player X and second player gets O\n");
    printf("Alternatively enter the numbers on the board to place your mark on it\n");
    printf("Press Enter to continue...");
    getchar();

    for(i = 0; i < 9; i++){

        printf("\033[H\033[J");

        display_board(board);

        if(count % 2 == 0){
            printf("\nEnter the number on the board where you would like to put O: ");
        }

        else{
            printf("\nEnter the number on the board where you would like to put X: ");
        }

        scanf("%d", &res);

        while(!check(entries, res, size)){

            printf("\033[H\033[J");

            display_board(board);

            printf("\nThe box has already been filled up or is not present. Please try again\n");

            scanf("%d", &res);
        }

        size--;

        replace(board, res, &count);

        printf("\033[H\033[J");

        display_board(board);

        if(win_condition(board)){
            return 0;
        }

        count++;
    }

    printf("\nIt's a draw!\n");

    return 0;
}