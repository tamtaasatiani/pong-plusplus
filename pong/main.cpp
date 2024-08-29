/*
		pong++
		Atari's 1972 Pong clone.

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Main Program --

		Main game loop.
*/






#include <string>
#include <time.h>

#include "engine.h"

#include "src/Paddle.h"
#include "src/Ball.h"
#include "src/constants.h"

// Font setup
TTF_Font* mediumFont = tahm.graphics->font->newFont("fonts/PublicPixel.ttf", 16);
TTF_Font* scoreFont = tahm.graphics->font->newFont("fonts/PublicPixel.ttf", 84);

// Create paddle and ball instances
Paddle player1(20, WINDOW_HEIGHT / 2 - 40, 20, 70);
Paddle player2(WINDOW_WIDTH - 40, WINDOW_HEIGHT / 2 + 40, 20, 70);
Ball ball(WINDOW_WIDTH / 2 - 5, WINDOW_HEIGHT / 2 - 5, 10, 10);


// Scores
int player1Score = 0;
int player2Score = 0;


// Score strings for printing to the screen
std::string player1ScoreText = "0";
std::string player2ScoreText = "0";


// Determines which player will serve first
int servingPlayer = 1;


// Determines the winner
int winningPlayer = 0;

// For printing the "win" message
std::string winningPlayerText = "0";


enum GameStates {
	START,
	SERVE,
	PLAY,
	WIN
};


// Simple State Machine
GameStates gameState;

// Sound struct to keep sounds neatly together
struct Sounds
{
	TahmSound * hit;
	TahmSound * score;
} sounds;


// Create the win text at the end
std::string generateWinText()
{
	std::string p1 = "PLAYER ";
	std::string p2 = winningPlayerText;
	std::string p3 = " WON";
	std::string full = p1 + p2 + p3;

	return full;
}


void start()
{
	// Random seed to get different outcomes for random generations
	srand(time(NULL));

	// Window setup
	tahm.window->create("Pong", WINDOW_WIDTH, WINDOW_HEIGHT);


	// Sound setup
	sounds.hit = tahm.audio->newSound("sounds/hit.wav");
	sounds.score = tahm.audio->newSound("sounds/score.wav");
	
}

void keypressed(Event event)
{
	if (gameState == START)
	{
		if (event.keyName == KEY_RETURN)
		{
			gameState = SERVE;
		}
	}
	else if (gameState == SERVE)
	{
		
		if (event.keyName == KEY_RETURN)
		{
			gameState = PLAY;
		}
	}
	else if (gameState == WIN)
	{

		// restart game
		if (event.keyName == KEY_RETURN)
		{
			gameState = START;


			player1Score = 0;
			player2Score = 0;

			player1ScoreText = "0";
			player2ScoreText = "0";

			winningPlayer = 0;
			winningPlayerText = "0";
		}

	}
}

void update()
{
	if (gameState == SERVE)
	{
		// Pick direction for the ball
		ball.dy = (rand() % -100 + 100) / 50.0f;

		if (servingPlayer == 1)
		{
			ball.dx = (rand() % 70 + 100) / 10.0f;
		}
		else
		{
			ball.dx = (- (rand() % 70, 100)) / 10.0f;
		}

	}
	else if (gameState == PLAY)
	{

		// ball collisions with the player

		if (ball.collides(player1))
		{

			ball.dx = -ball.dx * 1.03;
			ball.x = player1.x + ball.width + 1;

			if (ball.dy < 0)
			{
				ball.dy = (- rand() % 10 + 70) / 10.0f;
			}
			else
			{
				ball.dy = (rand() % 10 + 70) / 10.0f;
			}



			sounds.hit->play();
		}
		else if (ball.collides(player2))
		{

			ball.dx = -ball.dx * 1.03;
			ball.x = player2.x - ball.width;

			if (ball.dy < 0)
			{
				ball.dy = (- rand() % 10 + 70) / 10.0f;
			}
			else
			{
				ball.dy = (rand() % 10 + 70) / 10.0f;
			}


			sounds.hit->play();
		}


		// ball touches top/bottom

		if (ball.y <= 0)
		{

			ball.y = 0;
			ball.dy = -ball.dy;



			sounds.hit->play();
		}

		if (ball.y >= WINDOW_HEIGHT - ball.height)
		{

			ball.y = WINDOW_HEIGHT - ball.height;
			ball.dy = -ball.dy;


			sounds.hit->play();
		}

		// ball touches left/right, score a point

		if (ball.x < 0)
		{
			servingPlayer = 1;
			player2Score += 1;
			player2ScoreText = std::to_string(player2Score);

			if (player2Score == 10)
			{
				winningPlayer = 2;
				winningPlayerText = "2";
				gameState = WIN;
			}
			else
			{
				gameState = SERVE;
				ball.reset();
			}


			sounds.score->play();
		}
		else if (ball.x > WINDOW_WIDTH)
		{
			servingPlayer = 2;
			player1Score += 1;
			player1ScoreText = std::to_string(player1Score);

			if (player1Score == 10)
			{
				winningPlayer = 1;
				winningPlayerText = "1";
				gameState = WIN;
			}
			else
			{
				gameState = SERVE;
				ball.reset();
			}



			sounds.score->play();
		}

		ball.update();
	}




	// paddle movements

	
	if (tahm.input->keyPressed[KEYCODE_S])
	{
		player1.y = std::min(player1.y + PADDLE_SPEED, WINDOW_HEIGHT - player1.height);
	}
	else if (tahm.input->keyPressed[KEYCODE_W])
	{
		player1.y = std::max(player1.y - PADDLE_SPEED, 0);
	}

	if (tahm.input->keyPressed[KEYCODE_UP])
	{
		player2.y = std::max(player2.y - PADDLE_SPEED, 0);
	}
	else if (tahm.input->keyPressed[KEYCODE_DOWN])
	{
		player2.y = std::min(player2.y + PADDLE_SPEED, WINDOW_HEIGHT - player2.height);
	}
}


void draw()
{
	// fill background
	tahm.graphics->clear(20, 20, 25);


	// thin divider at the center
	tahm.graphics->setColor(255, 255, 255);
	tahm.graphics->draw->rect(WINDOW_WIDTH / 2 - 1, 0, 2, WINDOW_HEIGHT);


	// text rendering
	if (gameState == START)
	{
		tahm.graphics->printf("center", WINDOW_WIDTH, 0, 50, mediumFont, "WELCOME TO PONG++ CREATED BY TAMTA ASATIANI");
		tahm.graphics->printf("center", WINDOW_WIDTH, 0, 80, mediumFont, "PRESS ENTER TO START PLAYING!");
	}
	else if (gameState == SERVE)
	{
		tahm.graphics->printf("center", WINDOW_WIDTH, 0, 50, mediumFont, "PRESS ENTER TO SERVE");
	}
	else if (gameState == WIN)
	{
		tahm.graphics->printf("center", WINDOW_WIDTH, 0, 50, mediumFont, generateWinText().c_str());
		tahm.graphics->printf("center", WINDOW_WIDTH, 0, 80, mediumFont, "PRESS ENTER TO TRY AGAIN");
	}

	// score rendering

	tahm.graphics->printf("left", WINDOW_WIDTH, 500, WINDOW_HEIGHT / 3, scoreFont, player1ScoreText.c_str());
	tahm.graphics->printf("right", WINDOW_WIDTH, -500, WINDOW_HEIGHT / 3, scoreFont, player2ScoreText.c_str());



	player1.render();
	player2.render();
	ball.render();
}