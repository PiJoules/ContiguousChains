#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chilies(int w, int h, char done[h][w], int stack[w*h], int tail){
	int x = stack[tail]%w;
	int y = (stack[tail]-x)/w % h;
	return done[y][x];
}

int checkers(int w, int h, char board[h][w], int stack[w*h], int tail, int done[h][w]){
	int x = stack[tail]%w;
	int y = (stack[tail]-x)/w % h;
	if (x <= 0 ){
		if (y <= 0){
			if (board[y+1][x] == 'x' )
				return 3;
			else if (board[y][x+1] == 'x')
				return 2;
		}
		else if (y >= h-1){
			if (board[y-1][x] == 'x')
				return 1;
			else if (board[y][x+1] == 'x')
				return 2;
		}
		else {
			if (board[y+1][x] == 'x')
				return 3;
			else if (board[y-1][x] == 'x')
				return 1;
			else if (board[y][x+1] == 'x')
				return 2;
		}
	}
	else if (x >= w-1){
		if (y <= 0){
			if (board[y+1][x] == 'x')
				return 3;
			else if (board[y][x-1] == 'x')
				return 4;
		}
		else if (y >= h-1){
			if (board[y-1][x] == 'x')
				return 1;
			else if (board[y][x-1] == 'x')
				return 4;
		}
		else {
			if (board[y+1][x] == 'x')
				return 3;
			else if (board[y-1][x] == 'x')
				return 1;
			else if (board[y][x-1] == 'x')
				return 4;
		}
	}
	if (y <= 0){
		if (board[y+1][x] == 'x')
			return 3;
		else if (board[y][x-1] == 'x')
			return 4;
		else if (board[y][x+1] == 'x')
			return 2;
	}
	else if (y >= h-1){
		if (board[y][x-1] == 'x')
			return 4;
		else if (board[y-1][x] == 'x')
			return 1;
		else if (board[y][x+1] == 'x')
			return 2;
	}

	if (board[y][x-1] == 'x')
		return 4;
	else if (board[y-1][x] == 'x')
		return 1;
	else if (board[y][x+1] == 'x')
		return 2;
	else if (board[y+1][x] == 'x')
		return 3;

	return 0;
}


int main(){
	/* Read from stdin */
	int h,w;
	scanf("%d %d\n", &h, &w);
	char board[h][w+1]; // +1 for null terminator

	/* Get the board */
	int bufferSize = 256;
	char buffer[bufferSize];
	int i;
	for (i = 0; i < h; i++){
		fgets(buffer, bufferSize, stdin);
		strncpy(board[i], buffer, sizeof(char)*w); // Copy part of the buffer onto the board
		board[i][w] = '\0';
	}

	/* Perform breadth first search, keeping track of visited squares along the way. */
	int tail = 0;
	int stack[h*w];

	int done[h][w];
	int j;
	for (i = 0; i < h; i++){
		for (j = 0; j < w; j++){
			done[i][j] = 1;
			stack[tail] = i*j;
			tail++;
			int dir = checkers(w, h, board, stack, tail);
			while (tail){
				if (!dir){
					tail--;
					continue;
				}
				switch (dir){
					case 1:
						if (!chilies(w, h, done, stack, tail)){

						}
				}
			}
		}
	}

	for (i = 0; i < h; i++){
		printf("%s\n", board[i]);
	}

	return 0;
}