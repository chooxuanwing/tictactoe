#include <iostream>
using namespace std;
char board[3][3];

char chkW();	// win function
char draw();	// draw check fnc

char draw()		// draw checker
{
	int empty=0;
	for (int i=0; i<3 ;i++)
		for(int j=0; j<3 ; j++)
		{
			if (board[i][j]!=' ')		//filled box counter
				empty = empty +1;
		}
			if (empty==9)
				return 'D';		// End game if no more empty spaces
			else
				return 'C';		// else continue
		
}

char chkW()		// winning check
{
	if (board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X' ||
		board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X' ||
		board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X' ||
		board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X' ||
		board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X' ||
		board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X' ||
		board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X' ||
		board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X' )
		return 'X';
	else if (board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O' ||
			 board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O' ||
			 board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O' ||
			 board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O' ||
			 board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O' ||
			 board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O' ||
			 board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O' ||
			 board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O' )
		return 'O';
	else
		return 'c';
		
}

int main()
{
	char p1='X', p2='O';
	int r,c, check, count=1;
//	char board[3][3];
	
	for (int i=0; i<3 ;i++)			// Reset board
		for(int j=0; j<3 ; j++)
			board[i][j]=' ';
	
	goto play1;
	
	play1:
	{
		for (int i=0; i<3; i++)			// Print board
		{
			cout << " -------------\n";
			for (int j=0; j<3; j++)
				cout << " | " << board [i][j];
			cout << " | \n";
		}
		cout << " -------------" <<endl;
		
		cout << "Player 1 (X)\n";			// Imputs player 1
		cout << "Row 1-3 : ";
		cin >> r;
		r=r-1;		// deduct 1
		cout << "Column 1-3: ";
		cin >> c;
		c=c-1;		// deduct 1
		goto next;
	
	}
	
	play2:
	{
		for (int i=0; i<3; i++)			// Print board
		{
			cout << " -------------\n";
			for (int j=0; j<3; j++)
				cout << " | " << board [i][j];
			cout << " | \n";
		}
		cout << " -------------" <<endl;
		
		cout << "Player 2 (O)\n";			// Imputs player 2
		cout << "Row 1-3: ";
		cin >> r;
		r=r-1;		// deduct 1 so in range
		cout << "Column 1-3: ";
		cin >> c;
		c=c-1;		// deduct 1 so in range for comp
		goto next;
	}
	
	next:
	{
		if (r<0 || r>2 || c<0 || c>2){				// check if numbers are in range
			cout << "\n******\nRow and/or columns must be between 1 and 3 inclusive\n******\n" << endl;
			if (count%2 != 0)
				goto play1;
			else if( count %2==0)
				goto play2;
		}
		else if(board[r][c] != ' '){			// Check if space is filled
			cout << "\n*** Choose another spot ***\n" << endl;
			if (count%2 != 0)
				goto play1;
			else if( count %2==0)
				goto play2;
		}
		
		else{						// turn taking system
			if (count%2 ==0)		// P1 turn
			{
				count=count+1;
				board[r][c]=p2;
				if (chkW()=='X'){				// check win p1
					for (int i=0; i<3; i++)			// Print winning board
					{
						cout << " -------------\n";
						for (int j=0; j<3; j++)
							cout << " | " << board [i][j];
						cout << " | \n";
					}
					cout << " -------------" <<endl;
					cout << "***** Player 1 Wins *****" <<endl;
					return 0;
					}
				else if (chkW()=='O'){		// check win p2
					for (int i=0; i<3; i++)			// Print winning board
					{
						cout << " -------------\n";
						for (int j=0; j<3; j++)
							cout << " | " << board [i][j];
						cout << " | \n";
					}
					cout << " -------------" <<endl;
					cout << "***** Player 2 Wins *****" << endl;
					return 0;
					}
				else if (chkW()=='c')		// no win continue with player 1
				{
					if (draw()=='D')
					{
						for (int i=0; i<3; i++)			// Print draw board
						{
							cout << " -------------\n";
							for (int j=0; j<3; j++)
								cout << " | " << board [i][j];
							cout << " | \n";
						}
						cout << " -------------" <<endl;
						cout << "***** Game is a Draw *****" << endl;
						return 0 ;
					}
					else
						goto play1;
				}
			}
			else if (count%2 !=0)				// P2's turn
			{
				count=count+1;
				board[r][c]=p1;
				if (chkW()=='X'){				// P1 wins
					for (int i=0; i<3; i++)			// Print winning board
					{
						cout << " -------------\n";
						for (int j=0; j<3; j++)
							cout << " | " << board [i][j];
						cout << " | \n";
					}
					cout << " -------------" <<endl;
					cout << "***** Player 1 Wins *****" <<endl;
					return 0;
					}
				else if (chkW()=='O'){				// P2 wins
					for (int i=0; i<3; i++)			// Print winning board
					{
						cout << " -------------\n";
						for (int j=0; j<3; j++)
							cout << " | " << board [i][j];
						cout << " | \n";
					}
					cout << " -------------" <<endl;
					cout << "***** Player 2 Wins *****" << endl;
					return 0;
					}
				else if (chkW()=='c')			// no win, contunue with P2
				{
					if (draw()=='D')
					{
						for (int i=0; i<3; i++)			// Print draw board
						{
							cout << " -------------\n";
							for (int j=0; j<3; j++)
								cout << " | " << board [i][j];
							cout << " | \n";
						}
						cout << " -------------" <<endl;
						cout << "***** Game is a Draw *****" << endl;
						return 0 ;
					}
					else
						goto play2;
				}
			}
		}
	}
}
	
	
	






