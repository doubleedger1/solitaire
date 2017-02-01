// Title: Assignment 3 - Simple Solitaire game.
// Author: Anonymous.
// Purpose: To play a game of simple solitaire.
// Date: 27/12/2015.

#include <iostream> // Used to include standard library.
#include <time.h> // Used to allow for random special peg.


using namespace std;



void updateBoard(bool solBoard[5][5], int &randPeg1, int &randPeg2)
{

	// This is the updateBoard sub program used to update the games board.
	// It will draw the board after the user has made a valid move to show
	// that the move they made was valid and that it's working as intended.
	// Most of this code is similar to the one in the main program as it has
	// the same purpose which is to draw the simple solitaire gaming board.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.    
	//
	// 2. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 3. randPeg2 - * IN * Randomly assigned a number for special peg.         


	for (int k = 0; k < 5; k++) // Inserts a new line for each row
	{
		for (int l = 0; l < 5; l++) // Draws all of the elements in each row
		{

			if (solBoard[k][l] == true) // Check if there is a space
			{
				cout << "[ ]";  // Indicates that this is a space
			}
			else if (k != randPeg1 || l != randPeg2)
			{
				cout << "[O]"; // Indicates a peg is on this space
			}
			else
			{
				cout << "[#]"; // Indicates a special peg is on this space.
			}
		}
		cout << "\n";
	}
} // updateBoard



void startNewGame(bool solBoard[5][5], bool &inGame, int &randPeg1
	, int &randPeg2)
{
	// This is the startNewGame sub program it is used to start 
	// a new game after the current one has finished if the user
	// specifies to do so.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. inGame - * IN * - Used to check whether or not the game is still 
	// playing the game after completing 1 run through of the game.
	//
	// 3. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 4. randPeg2 - * IN * Randomly assigned a number for special peg.

	char wishToPlayAgain = ' ';
	while (wishToPlayAgain != 'Y' && wishToPlayAgain != 'N')
	{
		cout << "To quit enter 'N' to play another game enter 'Y': \n";
		cin >> wishToPlayAgain;
	}

	if (wishToPlayAgain == 'Y')
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				solBoard[i][i] = false; // Set values in row 1-5 to be false.
				solBoard[i][j] = false; // Set values in columns 1-5 to be false.
			}
		}

		solBoard[2][2] = true; // Manually set the center piece to true for space.
		updateBoard(solBoard, randPeg1, randPeg2);

		cout << "==============================================================\n";
		cout << "Rules: \n";
		cout << "- The chosen peg has to jump over another peg in\n";
		cout << "- In order for the peg to jump over another must contain "
			<< "\na space behind the peg\n";
		cout << "- You can't select a peg out of the 1-5 boundary\n";
		cout << "- You can't jump to a space that is out of the 1-5 boundary\n";
		cout << "- There is a special peg in the game indicated by a '[#]'\n";
		cout << "- You can not jump over the special peg but you can jump with it.";
		cout << "\n Once you use the special peg 3 times it will be removed.\n";
		cout << "==============================================================\n";

		cout << "\nSimple Solitaire has created a board for you!\n";
		cout << "You can end the game by typing 0 in each peg selection stage.\n";

		cout << "A new game has been created for you!\n";
		cout << "You can end the game by typing 0 in each peg selection stage.\n";
		cout << "You can change the peg you selected by typing 'Q' at direction.\n";

	}
	else
	{
		cout << "Thank you for playing Simple Solitaire!\n";
		inGame = false;
	}
} // startNewGame



void endGameScoring(bool solBoard[5][5], bool &inGame, int &highScore
	, int &randPeg1, int &randPeg2)
{

	// This is the endGameScoring sub program used to output a score at the end
	// of the game. This will be called whenever the use realises that there is
	// no valid moves left to take and is forced to type 0 into x and y integers.
	// This is the moveWest subprogram. It is used when the user
	// has selected a peg and has chosen to move in this direction.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. inGame - * IN * - Used to check whether or not the game is still 
	// playing the game after completing 1 run through of the game.
	// 
	// 3. highScore - * OUT * - Used to display the high score at the end of the
	// game currently being played and if a new high score is achieved.
	//
	// 4. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 5. randPeg2 - * IN * Randomly assigned a number for special peg.

	int scoreArray[9]; // Used to assign an endgame score depending on num pegs.

	int scorePoints = 90; // Assigned to each element of the scoreArray.

	// Assign the scores to each of the scoreArray elements.
	// We use this to assign to specific peg amounts later on.
	// There will need to be less than 9 pegs otherwise we manually
	// set the score to 0 to prevent breaking of the code later on.

	for (int i = 0; i < 9; i++)
	{
		scoreArray[i] = scorePoints;
		scorePoints = scorePoints - 10;
	}

	int pegCount = 0; // Stores the amount of pegs left on the board.

	int localScore = 0; // Stores the total amount of score accumulated.

	// For each column and row we check whether or not any of the elements
	// in the 2D array contain pegs, if they do add one to the total of pegs.
	// This is then used to calculate the total score afterwards to compare
	// With the highscore. If the score is higher that is the new high score.

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (solBoard[i][j] == false)
			{
				pegCount = pegCount + 1;
			}
		}
	}

	// Check if there are more than 8 pegs left on the board.
	// This is to ensure that there are no runtime errors.

	if (pegCount > 8)
	{
		cout << "You scored 0 points because there was more than 8 pegs!\n";
		cout << "Try to get less than that in order to achieve a high score!\n";
	}
	else
	{
		localScore = scoreArray[pegCount];
	}

	// Check if the last peg is in the center of the board for extra points.

	if (pegCount < 2 && solBoard[2][2] == false)
	{
		localScore = localScore + 20;
	}

	// Check if the score is higher than the previous high score.

	if (localScore > highScore)
	{
		cout << "Congratulations! You set a new high score!\n";
		cout << "The new high score is: " << localScore << "!\n";
	}
	startNewGame(solBoard, inGame, randPeg1, randPeg2);
}  // endGameScoring



void moveWest(bool solBoard[5][5], int &h, int &v, int &randPeg1,
	int &randPeg2, int &specialPegCount)
{
	// This is the moveWest subprogram. It is used when the user
	// has selected a peg and has chosen to move in this direction.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. h - * IN * - Contains a user input for the Y co-ordinate used 
	// as a short letter to signify that it's going horizontally.
	// 
	// 3. v - * IN * - Contains a user input for the X co-ordinate used
	// as a short letter to signify that it's going vertically.
	//
	// 4. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 5. randPeg2 - * IN * Randomly assigned a number for special peg.
	// 
	// 6. specialPegCount - * IN-OUT * Used to track number of times the
	// special peg on the board has been moved for removal after 3 times.

	if ((v - 2) > -1)
	{
		if (solBoard[h - 1][v - 2] == true)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is no peg to jump over in space: ";
			cout << "(" << h << ", " << v - 1 << ")\n";
		}
		else if (h - 1 == randPeg1 && v - 2 == randPeg2)
		{
			cout << "Invalid move attempted!\n";
			cout << "You can't jump over the special peg!\n";
		}
		else if (solBoard[h - 1][v - 3] == false)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is a peg in this space!\n";
		}
		else if (h - 1 == randPeg1 && v - 1 == randPeg2)
		{
			solBoard[h - 1][v - 3] = false;
			randPeg1 = h - 1;
			randPeg2 = v - 3;
			specialPegCount = specialPegCount + 1;
			cout << "Special peg moved: " << specialPegCount << " times.\n";
			solBoard[h - 1][v - 2] = true;
			solBoard[h - 1][v - 1] = true;
			if (specialPegCount == 3 && h > -1 && v > -1)
			{
				randPeg1 = -1;
				randPeg2 = -1;
				solBoard[h - 3][v - 3] = true;
				cout << "The special peg was removed as it was moved 3 times\n";
			}
		}
		else
		{
			solBoard[h - 1][v - 3] = false;
			solBoard[h - 1][v - 2] = true;
			solBoard[h - 1][v - 1] = true;
		}
	}
	else
	{
		cout << "Invalid move attempted!\n";
		cout << "You attempted to reach an out of bounds position: ";
		cout << "(" << h << ", " << v - 2 << ")\n";
	}
} // moveWest



void moveEast(bool solBoard[5][5], int &h, int &v, int &randPeg1,
	int &randPeg2, int &specialPegCount)
{
	// This is the moveEast subprogram. It is used when the user
	// has selected a peg and has chosen to move in this direction.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. h - * IN * - Contains a user input for the Y co-ordinate used 
	// as a short letter to signify that it's going horizontally.
	// 
	// 3. v - * IN * - Contains a user input for the X co-ordinate used
	// as a short letter to signify that it's going vertically.
	//
	// 4. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 5. randPeg2 - * IN * Randomly assigned a number for special peg.
	// 
	// 6. specialPegCount - * IN-OUT * Used to track number of times the
	// special peg on the board has been moved for removal after 3 times.

	if (v + 2< 6)
	{
		if (solBoard[h - 1][v] == true)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is no peg to jump over in space: ";
			cout << "(" << h << ", " << v + 1 << ")\n";
		}
		else if (h - 1 == randPeg1 && v == randPeg2)
		{
			cout << "Invalid move attempted!\n";
			cout << "You can't jump over the special peg!\n";
		}
		else if (solBoard[h - 1][v + 1] == false)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is a peg in this space!\n";
		}
		else if (h - 1 == randPeg1 && v - 1 == randPeg2)
		{
			solBoard[h - 1][v + 1] = false;
			randPeg1 = h - 1;
			randPeg2 = v + 1;
			specialPegCount = specialPegCount + 1;
			cout << "Special peg moved: " << specialPegCount << " times.\n";
			solBoard[h - 1][v] = true;
			solBoard[h - 1][v - 1] = true;
			if (specialPegCount == 3 && h > -1 && v > -1)
			{
				randPeg1 = -1;
				randPeg2 = -1;
				solBoard[h - 1][v + 1] = true;
				cout << "The special peg was removed as it was moved 3 times\n";
			}
		}
		else
		{
			solBoard[h - 1][v + 1] = false;
			solBoard[h - 1][v] = true;
			solBoard[h - 1][v - 1] = true;
		}
	}
	else
	{
		cout << "Invalid move attempted!\n";
		cout << "You attempted to reach an out of bounds position: ";
		cout << "( " << h << ", " << v + 2 << ")\n";
	}
} // moveEast



void moveSouth(bool solBoard[5][5], int &h, int &v, int &randPeg1,
	int &randPeg2, int &specialPegCount)
{
	// This is the moveSouth subprogram. It is used when the user
	// has selected a peg and has chosen to move in this direction.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. h - * IN * - Contains a user input for the Y co-ordinate used 
	// as a short letter to signify that it's going horizontally.
	// 
	// 3. v - * IN * - Contains a user input for the X co-ordinate used
	// as a short letter to signify that it's going vertically.
	//
	// 4. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 5. randPeg2 - * IN * Randomly assigned a number for special peg.
	// 
	// 6. specialPegCount - * IN-OUT * Used to track number of times the
	// special peg on the board has been moved for removal after 3 times.

	if ((h + 2) < 6)
	{
		if (solBoard[h][v - 1] == true)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is no peg to jump over in space: ";
			cout << "(" << h + 1 << ", " << v << ")\n";
		}
		else if (h == randPeg1 && v - 1 == randPeg2)
		{
			cout << "Invalid move attempted!\n";
			cout << "You can't jump over the special peg!\n";
		}
		else if (solBoard[h + 1][v - 1] == false)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is a peg in this space!\n";
		}
		else if (h - 1 == randPeg1 && v - 1 == randPeg2)
		{
			solBoard[h + 1][v - 1] = false;
			randPeg1 = h + 1;
			randPeg2 = v - 1;
			specialPegCount = specialPegCount + 1;
			cout << "Special peg moved: " << specialPegCount << " times.\n";
			solBoard[h][v - 1] = true;
			solBoard[h - 1][v - 1] = true;
			if (specialPegCount == 3 && h > -1 && v > -1)
			{
				randPeg1 = -1;
				randPeg2 = -1;
				solBoard[h + 1][v - 1] = true;
				cout << "The special peg was removed as it was moved 3 times\n";
			}
		}
		else
		{
			solBoard[h + 1][v - 1] = false;
			solBoard[h][v - 1] = true;
			solBoard[h - 1][v - 1] = true;
		}
	}
	else
	{
		cout << "Invalid move attempted!\n";
		cout << "You attemped to reach an out of bounds position: ";
		cout << " (" << h + 2 << ", " << v << ")\n";
	}
} // moveSouth



void moveNorth(bool solBoard[5][5], int &h, int &v, int &randPeg1,
	int &randPeg2, int &specialPegCount)
{
	// This is the moveNorth subprogram. It is used when the user
	// has selected a peg and has chosen to move in this direction.
	//
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. h - * IN * - Contains a user input for the Y co-ordinate used 
	// as a short letter to signify that it's going horizontally.
	// 
	// 3. v - * IN * - Contains a user input for the X co-ordinate used
	// as a short letter to signify that it's going vertically.
	//
	// 4. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 5. randPeg2 - * IN * Randomly assigned a number for special peg.
	// 
	// 6. specialPegCount - * IN-OUT * Used to track number of times the
	// special peg on the board has been moved for removal after 3 times.

	if ((h - 3) > -1) // Checking if direction is out of range
	{
		if (solBoard[h - 2][v - 1] == true) // Check if there is no peg there
		{
			cout << "Invalid move attempted!\n";
			cout << "There is no peg to jump over in space: ";
			cout << "(" << h - 1 << ", " << v << ")\n";
		}
		else if (h - 2 == randPeg1 && v - 1 == randPeg2)
		{
			cout << "Invalid move attempted!\n";
			cout << "You can't jump over the special peg!\n";
		}
		else if (solBoard[h - 3][v - 1] == false) // Check if there is peg in space
		{
			cout << "Invalid move attempted!\n";
			cout << "There is a peg in this space!\n";
		}
		else if (h - 1 == randPeg1 && v - 1 == randPeg2)
		{
			solBoard[h - 3][v - 1] = false;
			randPeg1 = h - 3;
			randPeg2 = v - 1;
			specialPegCount = specialPegCount + 1;
			cout << "Special peg moved: " << specialPegCount << " times.\n";
			solBoard[h - 2][v - 1] = true;
			solBoard[h - 1][v - 1] = true;
			if (specialPegCount == 3 && h > -1 && v > -1)
			{
				randPeg1 = -1;
				randPeg2 = -1;
				solBoard[h - 3][v - 1] = true;
				cout << "The special peg was removed as it was moved 3 times\n";
			}
		}
		else
		{
			solBoard[h - 3][v - 1] = false; // Landing position of the peg since jump
			solBoard[h - 2][v - 1] = true; // The peg to remove as it was jumped over
			solBoard[h - 1][v - 1] = true; // The old peg space to replace since jump
		}
	}
	else
	{
		cout << "Invalid move attempted!\n";
		cout << "You attemped to reach an out of bounds position: ";
		cout << " (" << h - 1 << ", " << v << ")\n";
	}
} // moveNorth



void checkValidMove(bool solBoard[5][5], int &h, int &v, char &pegDirection,
	bool &inGame, int &highScore, int &randPeg1, int &randPeg2,
	int &specialPegCount)
{

	// This is the checkValidMove sub program used to check moves against rules.
	//  
	// Parameters:
	// 1. solBoard - * OUT * - Holds all the values of the board; used in
	// drawing the board and modifying values when moves are made.             
	//
	// 2. h - * IN * - Contains a user input for the Y co-ordinate used 
	// as a short letter to signify that it's going horizontally.
	// 
	// 3. v - * IN * - Contains a user input for the X co-ordinate used
	// as a short letter to signify that it's going vertically.
	// 
	// 4. pegDirection - * IN * - Contains a user input for the direction 
	// of the peg.
	//
	// 5. inGame - * IN * - Contains a value that changes depending on whether
	// the user decides to play another game or not.
	//
	// 6. highScore - * OUT * - Contains the high score of the current run 
	// of the simple solitaire program. 
	//
	// 7. randPeg1 - * IN * Randomly assigned a number for special peg.
	//
	// 8. randPeg2 - * IN * Randomly assigned a number for special peg.
	// 
	// 9. specialPegCount - * IN-OUT * Used to track number of times the
	// special peg on the board has been moved for removal after 3 times.

	// We have to make sure that the values are subtracted by one to actually 
	// work with the array checking since the user inputs between 1 and 5.
	// This is because arrays when initialised start at 0 rather than 1 so
	// when a user inputs 5 and we didn't do this the program would crash.
	// We don't need to check between 1-5 as this is done when the user inputs.

	// First we check if the peg that was selected is actually a peg not a space.

	if (h != 0 || v != 0)
	{
		h = 6 - h;
		if (solBoard[h - 1][v - 1] == true)
		{
			cout << "Invalid move attempted!\n";
			cout << "There is no peg on space (" << h << ", " << v << ")\n";
		}
		else
		{
			if (pegDirection == 'N')
			{
				moveNorth(solBoard, h, v, randPeg1, randPeg2, specialPegCount);
				// Direction is north handled in moveNorth
			}

			if (pegDirection == 'E')
			{
				moveEast(solBoard, h, v, randPeg1, randPeg2, specialPegCount);
				// Direction is east handled in moveEast
			}

			if (pegDirection == 'S')
			{
				moveSouth(solBoard, h, v, randPeg1, randPeg2, specialPegCount);
				// Direction is south handled in moveSouth
			}

			if (pegDirection == 'W')
			{
				moveWest(solBoard, h, v, randPeg1, randPeg2, specialPegCount);
				// Direction is west handled in moveWest
			}
		}
		updateBoard(solBoard, randPeg1, randPeg2); // Update the board after every move made
	}
	else
	{
		cout << "You have chosen to end your current game.\n";
		endGameScoring(solBoard, inGame, highScore, randPeg1, randPeg2); // Scoring
	}

	h = -1; // Set these to out of range so that the loop doesn't break

	v = -1; // Set these to out of range so that the loop doesn't break

	pegDirection = ' '; // Set this to empty so that the loop doesn't break

} // checkValidMove



void main()
{

	// The code chunk just below is an initialisation of the board itself 
	// First we shall set up the default board by setting all elements to false
	// Of course we do this to all of the positions apart from position 3,3
	// We set the position in the array drawing the board 3,3 to true so that 
	// the center of the board contains a space rather than a peg.
	// Setting position 3,3 in the array drawing the board true indicates a space
	// Any position in solBoard array that is false indicates there is no space
	// We should also remember that all arrays in C++ start from 0 so the true
	// position will be solBoard 2, 2 not 3, 3 as arrays start from 0 not 1.
	// Later on when the checks for validation of moves is being used we will 
	// -1 off of each input in the local checks so that we receive no run time
	// errors from the program as we'd be attempting to access a part of the 
	// array that does not exist resulting in a potential crash of the program.

	srand(time(NULL)); // Used to generate a new seed for random selection.

	bool solBoard[5][5]; // This the board used to contain the pegs

	int specialPegCount = 0; // This keeps track of how many moves the special
	// peg has made since its initialisation.

	int randPeg1 = rand() % 5; // Selects a number at random between 1 and 5.

	int randPeg2 = rand() % 5; // Selects a number at random between 1 and 5.

	// Just to make sure it doesn't set the space to a special peg.
	// Otherwise it will break the game since there are no pegs to jump over.
	while (randPeg2 == 2)
	{
		randPeg2 = rand() % 5;
	}

	bool inGame = true; // This is used to check if a game is being played

	int highScore = 0; // This is used to store the high score every game

	int h = -1; // This is used as input by the user to select a row

	int v = -1; // This is used as input by the user to select a column

	char pegDirection = ' '; // This is used as input by the user to jump NSEW

	// This loop sets all of the values to false to set the initilised elements.
	// This is only used once to initialise the board for a new game.
	// There is a separate subprogram used to update the board after a move.

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			solBoard[i][i] = false; // Set values in row 1-5 to be false.
			solBoard[i][j] = false; // Set values in columns 1-5 to be false.
		}
	}

	solBoard[2][2] = true; // Manually set the center piece to true for space.

	// This loop draws out the whole simple solitaire board for a visual of
	// the game. It sets spaces to [ ] and pegs to [O] to indicate what is 
	// going on in the game. This will only be used to initialise the board.
	// We use a loop within a loop to draw the horizontal and vertical board.
	// Note that I don't check in the first loop for empty spaces on the board.
	// This is because this is the initial drawing and will obviously contain
	// a peg already on the positions of the rows as only the center is empty.
	// The updateBoard subprogram will re-draw the board with updated spaces
	// after the user has made a move that does not conflict with validation.

	for (int k = 0; k < 5; k++) // Inserts a new line for each row
	{
		for (int l = 0; l < 5; l++) // Draws all of the elements in each row
		{

			if (solBoard[k][l] == true) // Check if there is a space
			{
				cout << "[ ]";  // Indicates that this is a space
			}
			else if (k != randPeg1 || l != randPeg2)
			{
				cout << "[O]"; // Indicates a peg is on this space
			}
			else
			{
				cout << "[#]"; // Indicates a special peg is on this space.
			}
		}
		cout << "\n";
	}

	cout << "\n";

	cout << "==============================================================\n";
	cout << "Rules: \n";
	cout << "- The chosen peg has to jump over another peg in\n";
	cout << "- In order for the peg to jump over another must contain "
		<< "\na space behind the peg\n";
	cout << "- You can't select a peg out of the 1-5 boundary\n";
	cout << "- You can't jump to a space that is out of the 1-5 boundary\n";
	cout << "- There is a special peg in the game indicated by a '[#]'\n";
	cout << "- You can not jump over the special peg but you can jump with it.";
	cout << "\n Once you use the special peg 3 times it will be removed.\n";
	cout << "==============================================================\n";

	cout << "\nSimple Solitaire has created a board for you!\n";
	cout << "You can end the game by typing 0 in each peg selection stage.\n";
	cout << "You can change the peg you selected by typing 'Q' at direction.\n";

	while (inGame == true)
	{

		while (v < 0 || v > 5)
		{
			cout << "Please choose a column for 1-5 peg selection: \n";
			cin >> v;
		}

		while (h < 0 || h > 5)
		{
			cout << "Please choose a row 1-5 for peg selection: \n";
			cin >> h;
		}

		while (pegDirection != 'N' && pegDirection != 'S' && pegDirection != 'E'
			&& pegDirection != 'W' && pegDirection != 'Q')
		{
			if (v == 0 && h == 0)
			{
				pegDirection = 'N';
			}
			else
			{
				cout << "Please choose a direction for the peg: \n";
				cout << "Directions: North (N), South (S), East (E) or West (W) \n";
				cin >> pegDirection;
			}
		}

		if (pegDirection == 'Q')
		{
			h = -1;
			v = -1;
			pegDirection = ' ';
		}
		else
		{
			checkValidMove(solBoard, h, v, pegDirection, inGame, highScore,
				randPeg1, randPeg2, specialPegCount);
		}
	}
} // main