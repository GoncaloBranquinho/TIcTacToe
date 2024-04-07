#include <stdio.h>
#include <stdlib.h>
#define flushbuffer while(getchar() != '\n')

void draw(int x, int y, char arr1[x][y],char  arr2[x][y]) {
	printf("\nGame Matrix         Guide Matrix\n");
	for (int i = 0; i < 7; i++) {
	    for (int j = 0; j < 22; j++) {
		if (j == 11) {
	            printf("    |    ");
		    printf("%c", arr2[i][0]);
		}
		if (j > 11) {
		    printf("%c", arr2[i][j-11]);
		}
		if (j == 21) {
		    printf("\n");
		}
		if (j < 11) {
		    printf("%c", arr1[i][j]);
		}
	    }
	}
}

char winner(int x, int y, char table[x][y]) {
	if ( (table[1][1] == table[1][5] && table[1][1] == table[1][9]) || (table[1][1] == table[3][1] && table[1][1] == table[5][1]) || (table[1][1] == table[3][5] && table[1][1] == table[5][9]) ) {
	    return table[1][1];
	}
	else if ( (table[3][5] == table[1][5] && table[3][5] == table[5][5]) || (table[3][5] == table[3][1] && table[3][5] == table[3][9]) || (table[3][5] == table[1][9] && table[3][5] == table[5][1]) ) {
	    return table[3][5];
	}
	else if ( (table[5][9] == table[5][5] && table[5][9] == table[5][1]) || (table[5][9] == table[3][9] && table[5][9] == table[1][9]) ) {
	    return table[5][9];
	}
    return '\0';
}

int main() {



    char table[7][11] = {"   |   |   ",
              	         "   |   |   ",
		         "---|---|---",
		         "   |   |   ",
		         "---|---|---",
		         "   |   |   ",
		         "   |   |   "};

    char guide[7][11] = {"   |   |   ",
                         " 1 | 2 | 3 ",
                         "---|---|---",
                         " 4 | 5 | 6 ",
                         "---|---|---",
                         " 7 | 8 | 9 ",
                         "   |   |   "};

    int toDraw[9][2] = {{1,1},{1,5},{1,9},{3,1},{3,5},{3,9},{5,1},{5,5},{5,9}};
    int* placed = (int*)calloc(9, sizeof(int));
    int input, x, y, turn = 2;
    char keep;
    draw(7, 11, table, guide);
    while(1) {
	if (turn % 2 == 0) {
	    printf("Its X's turn.\nEnter a square: ");
	}
	else {
	    printf("Its O's turn.\nEnter a square: ");
	}
	invalid:
	input = getchar();
	flushbuffer;
	input -= 48;
	if (!placed[input-1] && input < 10 && input > 0) {
	    x = toDraw[input-1][0];
	    y = toDraw[input-1][1];
	    if (turn % 2 == 0) {
	        table[x][y] = 'X';
	    }
	    else {
                table[x][y] = 'O';
	    }
	    placed[input-1] = input;
	    turn++;
	    draw(7, 11, table, guide);
        }
	else {
	    printf("\nInvalid Square.\nTry again: ");
	    goto invalid;
	}
	keep = winner(7, 11, table);
	if (keep != '\0' && keep != ' ') {
	    printf("\nThe Winner is player %c, congratulations.\n", keep);
	    free(placed);
	    return 0;
	}
	if (turn - 2 == 9) {
	    printf("\nThe game ends in a draw.\n");
	    free(placed);
	    return 0;
	}
    }
    return 0;
}







