#include<iostream>
#include<stdio.h>

extern char Cell[3][3] ;

// functions definitions

void Update_TTT()
{

	printf(" %c  |  %c |  %c\n---|---|---\n", Cell[0][0], Cell[0][1], Cell[0][2]);
	printf(" %c  | %c  |  %c\n---|---|---\n", Cell[1][0], Cell[1][1], Cell[1][2]);
	printf(" %c  |  %c |  %c\n", Cell[2][0], Cell[2][1], Cell[2][2]);

}