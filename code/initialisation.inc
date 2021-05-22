
#include "textures.inc"

#include "pieces.inc"
#include "tableau.inc"
#include "table.inc"

//------------------- preation des pieces 2 equipes --------------------------------------
#declare PION_A = object{ PION	texture {T_Chrome_2A} }
#declare PION_B = object{ PION	texture {T_Brass_3A} }

#declare TOUR_A =  object{ TOUR texture {T_Chrome_2A} }
#declare TOUR_B =  object{ TOUR texture {T_Brass_3A} }

#declare CAVALIER_A =  object{ CAVALIER texture {T_Chrome_2A} }
#declare CAVALIER_B =  object{ CAVALIER rotate<0,0,180>   texture {T_Brass_3A} }

#declare FOU_A =  object{ FOU texture {T_Chrome_2A} }
#declare FOU_B =  object{ FOU texture {T_Brass_3A} }

#declare DAME_A =  object{ DAME texture {T_Chrome_2A} }
#declare DAME_B =  object{ DAME texture {T_Brass_3A} }

#declare ROI_A =  object{ ROI texture {T_Chrome_2A} }
#declare ROI_B =  object{ ROI texture {T_Brass_3A} }


//-------- Array qui contiendra tous les pieces des deux equipes -----
#declare PIECES_LIST = array[6][2]{ {PION_A, PION_B},
 																		{TOUR_A, TOUR_B},
																		{CAVALIER_A, CAVALIER_B},
																		{FOU_A, FOU_B},
																		{DAME_A, DAME_B},
																		{ROI_A, ROI_B }
																	};

#declare TABLEAU = object {
	TABLEAU_01
	scale SIZE_TABLEAU/2
	translate CENTER_TABLEAU
}

#declare TABLE = object {
	TABLE_01
	scale 80
	/* texture{ Cork} */
  /* texture{ NBglass} */
	translate<W_TABLE*18, W_TABLE*18, -H_TABLE*81>
}


//------------------------ POSITION PAR DAUT DES PIECES  ---------------------------
#declare DEFAULT_POSITIONS = array[16][2]{
	{<0,7,0>, <0,0,0>}, //Tour_a0,     Tour_b0
	{<1,7,0>, <1,0,0>}, //cavalier_a0,   cavalier_b0
	{<2,7,0>, <2,0,0>}, //fou_a0,      fou_b0
	{<3,7,0>, <3,0,0>}, //dame_a,      dame_b
	{<4,7,0>, <4,0,0>}, //roi_a,       roi_b
	{<5,7,0>, <5,0,0>}, //fou_a1,      fou_b1
	{<6,7,0>, <6,0,0>}, //cavalier_a1,   cavalier_b1
	{<7,7,0>, <7,0,0>}, //Tour_a1,     Tour_b1

	{<0,6,0>, <0,1,0>}, //pion_a0,     pion_b0
	{<2,6,0>, <2,1,0>}, //pion_a1,     pion_b1
	{<1,6,0>, <1,1,0>}, //pion_a2,     pion_b2
	{<3,6,0>, <3,1,0>}, //pion_a3,     pion_b3
	{<4,6,0>, <4,1,0>}, //pion_a4,     pion_b4
	{<5,6,0>, <5,1,0>}, //pion_a5,     pion_b5
	{<6,6,0>, <6,1,0>}, //pion_a6,     pion_b6
	{<7,6,0>, <7,1,0>}  //pion_a7,     pion_b7

};


//------------ POSITIONS CAMERA ET LOOK AT -----------------------------------

//vue de dessus étendue de l'échiquier
#declare PC_UP_EXT = <8,8,32>;
#declare PCK_UP_EXT = <8,8,0>;

//vue de dessus de l'échiquier
#declare PC_UP = <8,8,19>;
#declare PCK_UP = <8,8,0>;

//vue en haut à droite de l'échiquier
#declare PC_RIGHT_UP = <60,8,25>;
#declare PCK_RIGHT_UP = <8,8,7>;

//vue étendue à droite de l'échiquier
#declare PC_RIGHT_EXT = <29,8,2>;
#declare PCK_RIGHT_EXT = <8,8,2>;

//vue à droite de l'échiquier
#declare PC_RIGHT = <26,8,2>;
#declare PCK_RIGHT = <8,8,1>;

//vue en haut à droite de l'échiquier
#declare PC_BACK = <8,25,6>;
#declare PCK_BACK = <8,8,0>;

//vue en haut à droite de l'échiquier
#declare PC_BACK2 = <8,-8,6>;
#declare PCK_BACK2 = <8,8,0>;
