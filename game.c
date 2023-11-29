#include "game.h"

void handle_quit() {
	exit(0);
}

int handle_game(int **board, int y, int x, int h, int w)
{
	int n = 0;

	if (y > 0 && board[y-1][x]) 
		n++;
	if ((y+1) < h && board[y+1][x])
		n++;
	if (x > 0 && board[y][x-1])
		n++;
	if ((x+1) < w && board[y][x+1])
		n++;
	if (y>0 && x>0 && board[y-1][x-1])
		n++;
	if ((y+1)<h && (x+1)<w && board[y+1][x+1])
		n++;
	if ((y+1)<h && x >0 && board[y+1][x-1])
		n++;
	if ((x+1)<w && y >0 && board[y-1][x+1])
		n++;

	if (board[y][x])
	{
		if (n < 2 || n > 3)
			return (0);
		else
			return (1);
	}
	else if (n == 3)
	{
		return (1);
	}
	return (0);
}


int main(int argc, char **argv) {

	if (argc < 3)
	{
		printf("Please use it as follows: %s [height_of_board] [width_of_board]\n", argv[0]);
		exit(1);
	}

	int h = atoi(argv[1]);
	int w = atoi(argv[2]);

	int **board;
	int running = 1;

	board = malloc(sizeof(int *)*h);

	for (int i = 0; i < h; i++)
	{
		board[i] = malloc(sizeof(int)*w);
		for (int j = 0; j < w; j++)
		{
			int r = rand() % 100;
			if (r < 70)
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}

	while (running)
	{
		signal(SIGINT, handle_quit);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j])
				{
					putchar('O');
				}
				else
				{
					putchar(' ');
				}
				putchar(' ');
				board[i][j] = handle_game(board, i, j, h, w);
			}
			putchar('\n');
		}
		sleep(1);
		system("clear");
	}
}
