#pragma once



/*
enum Keys
{
	KEY_RETURN = SDLK_RETURN,
	KEY_ESCAPE = SDLK_ESCAPE,
	KEY_BACKSPACE = SDLK_BACKSPACE,
	KEY_TAB = SDLK_TAB,
	KEY_SPACE = SDLK_SPACE,

	KEY_0 = SDLK_0,
	KEY_1 = SDLK_1,
	KEY_2 = SDLK_2,
	KEY_3 = SDLK_3,
	KEY_4 = SDLK_4,
	KEY_5 = SDLK_5,
	KEY_6 = SDLK_6,
	KEY_7 = SDLK_7,
	KEY_8 = SDLK_8,
	KEY_9 = SDLK_9,

	KEY_A = SDLK_a,
	KEY_B = SDLK_b,
	KEY_C = SDLK_c,
	KEY_D = SDLK_d,
	KEY_E = SDLK_e,
	KEY_F = SDLK_f,
	KEY_G = SDLK_g,
	KEY_H = SDLK_h,
	KEY_I = SDLK_i,
	KEY_J = SDLK_j,
	KEY_K = SDLK_k,
	KEY_L = SDLK_l,
	KEY_M = SDLK_m,
	KEY_N = SDLK_n,
	KEY_O = SDLK_o,
	KEY_P = SDLK_p,
	KEY_Q = SDLK_q,
	KEY_R = SDLK_r,
	KEY_S = SDLK_s,
	KEY_T = SDLK_t,
	KEY_U = SDLK_u,
	KEY_V = SDLK_v,
	KEY_W = SDLK_w,
	KEY_X = SDLK_x,
	KEY_Y = SDLK_y,
	KEY_Z = SDLK_z
};


struct KeysPressed {
	Keys key;
	bool pressed;
};


const int KEY_AMOUNT = 41;
KeysPressed keysPressed[KEY_AMOUNT] = {
	{ KEY_RETURN, false },
	{ KEY_ESCAPE, false },
	{ KEY_BACKSPACE, false },
	{ KEY_TAB, false },
	{ KEY_SPACE, false },

	{ KEY_0, false },
	{ KEY_1, false },
	{ KEY_2, false },
	{ KEY_3, false },
	{ KEY_4, false },
	{ KEY_5, false },
	{ KEY_6, false },
	{ KEY_7, false },
	{ KEY_8, false },
	{ KEY_9, false },

	{ KEY_A, false },
	{ KEY_B, false },
	{ KEY_C, false },
	{ KEY_D, false },
	{ KEY_E, false },
	{ KEY_F, false },
	{ KEY_G, false },
	{ KEY_H, false },
	{ KEY_I, false },
	{ KEY_J, false },
	{ KEY_K, false },
	{ KEY_L, false },
	{ KEY_M, false },
	{ KEY_N, false },
	{ KEY_O, false },
	{ KEY_P, false },
	{ KEY_Q, false },
	{ KEY_R, false },
	{ KEY_S, false },
	{ KEY_T, false },
	{ KEY_U, false },
	{ KEY_V, false },
	{ KEY_W, false },
	{ KEY_X, false },
	{ KEY_Y, false },
	{ KEY_Z, false }
};

void pressKey(int key);
void clearKeys();


*/

void readInput(void);