

#ifndef TYPEDEF_H
#include "typedef.h"
#endif
#ifndef CHARACTER_H
#include "character.xbm"
#endif

void drawChar(unsigned long x_origin_coordinate, unsigned long y_origin_coordinate, sRGB ** data, char character)
{

	//	Decoding xbm
	//	Coded like this:
	/*
	   8px
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000 15 px
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000
	   00000000

	   0 = no pixel
	   1 = pixel
	   */

	//Defining a little test variable
	char table[CHAR_HEIGHT];

	//Decode provided character
	switch (character)
	{

	case 'A':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = A_bits[y];
		}
		break;

	case 'B':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = B_bits[y];
		}
		break;

	case 'C':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = C_bits[y];
		}
		break;

	case 'D':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = D_bits[y];
		}
		break;

	case 'E':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = E_bits[y];
		}
		break;

	case 'F':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = F_bits[y];
		}
		break;

	case 'G':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = G_bits[y];
		}
		break;

	case 'H':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = H_bits[y];
		}
		break;

	case 'I':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = I_bits[y];
		}
		break;

	case 'J':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = J_bits[y];
		}
		break;

	case 'K':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = K_bits[y];
		}
		break;

	case 'L':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = L_bits[y];
		}
		break;

	case 'M':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = M_bits[y];
		}
		break;

	case 'N':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = N_bits[y];
		}
		break;

	case 'O':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = O_bits[y];
		}
		break;

	case 'P':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = P_bits[y];
		}
		break;

	case 'Q':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = Q_bits[y];
		}
		break;

	case 'R':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = R_bits[y];
		}
		break;

	case 'S':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = S_bits[y];
		}
		break;

	case 'T':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = T_bits[y];
		}
		break;

	case 'U':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = U_bits[y];
		}
		break;

	case 'V':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = V_bits[y];
		}
		break;

	case 'W':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = W_bits[y];
		}
		break;

	case 'X':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = X_bits[y];
		}
		break;

	case 'Y':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = Y_bits[y];
		}
		break;

	case 'Z':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = Z_bits[y];
		}
		break;

	case 'a':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = a_bits[y];
		}
		break;

	case 'b':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = b_bits[y];
		}
		break;

	case 'c':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = c_bits[y];
		}
		break;

	case 'd':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = d_bits[y];
		}
		break;

	case 'e':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = e_bits[y];
		}
		break;

	case 'f':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = f_bits[y];
		}
		break;

	case 'g':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = g_bits[y];
		}
		break;

	case 'h':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = h_bits[y];
		}
		break;

	case 'i':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = i_bits[y];
		}
		break;

	case 'j':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = j_bits[y];
		}
		break;

	case 'k':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = k_bits[y];
		}
		break;

	case 'l':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = l_bits[y];
		}
		break;

	case 'm':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = m_bits[y];
		}
		break;

	case 'n':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = n_bits[y];
		}
		break;

	case 'o':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = o_bits[y];
		}
		break;

	case 'p':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = p_bits[y];
		}
		break;

	case 'q':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = q_bits[y];
		}
		break;

	case 'r':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = r_bits[y];
		}
		break;

	case 's':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = s_bits[y];
		}
		break;

	case 't':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = t_bits[y];
		}
		break;

	case 'u':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = u_bits[y];
		}
		break;

	case 'v':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = v_bits[y];
		}
		break;

	case 'w':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = w_bits[y];
		}
		break;

	case 'x':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = x_bits[y];
		}
		break;

	case 'y':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = y_bits[y];
		}
		break;

	case 'z':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = z_bits[y];
		}
		break;

	case '0':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = zero_bits[y];
		}
		break;

	case '1':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = un_bits[y];
		}
		break;

	case '2':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = deux_bits[y];
		}
		break;

	case '3':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = trois_bits[y];
		}
		break;

	case '4':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = quatre_bits[y];
		}
		break;

	case '5':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = cinq_bits[y];
		}
		break;

	case '6':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = six_bits[y];
		}
		break;

	case '7':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = sept_bits[y];
		}
		break;

	case '8':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = huit_bits[y];
		}
		break;

	case '9':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = neuf_bits[y];
		}
		break;

		//	HandMade Character
	case ' ':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = 0x00;
		}
		break;

	case '.':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = POINT_bits[y];
		}
		break;

	case '-':
		for (int y = 0; y < CHAR_HEIGHT; y++)
		{
			table[y] = MINUS_bits[y];
		}
		break;

		//	If unrecognized character, then write a square
	default:
		for (int i = 0; i < CHAR_HEIGHT; i++)
		{
			table[i] = 0xFF;
		}
		break;
	};

	//	Write Character
	for (unsigned char y = 0; y < CHAR_HEIGHT; y++)
	{
		char line = table[y];
		for (unsigned char x = 0; x < CHAR_WIDTH; x++)
		{
			if ((line & 0x00000001) == 0x00000001)
			{
				data[y_origin_coordinate + y][x_origin_coordinate + x] = _BLACK;
			}
			line = line >> 1;
		}
	}
}