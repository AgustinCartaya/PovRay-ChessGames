
#include "shapes.inc"
#include "colors.inc"
#include "textures.inc"
#include "woods.inc"
#include "glass.inc"
#include "metals.inc"
#include "functions.inc"
#include "skies.inc"

#include "pieces.inc"
#include "tableau.inc"
#include "table.inc"
#include "macros.inc"
#include "initialisation.inc"

/**
* Movimiento circular de la camara al rededor de la mesa se juego
*
*
*
**/
//----------------------- ANimation Camera -------------------------

//position initial camera et look at
#declare pc0 = PC_RIGHT_UP;
#declare pck0 = PCK_RIGHT_UP;

//position final camera et look at
#declare pc1 = PC_RIGHT_EXT;
#declare pck1 = PCK_RIGHT_EXT;


//mouvement spiral XY equations polaires
#declare a  = sqrt( pow(pc0.x,2) + pow(pc0.y,2) );
#declare b = (sqrt( pow(pc1.x,2) + pow(pc1.y,2)  ) - a) / (2*Pi);

#declare teta = 2*Pi * clock;
#declare r = a + b*teta;

//pisition camera et looak at lors de l'animation
#declare pc = <r* cos(teta),
							r* sin(teta)+8,
							pc0.z + (pc1.z-pc0.z)*clock > ;

#declare pck = < pck1.x,
								 pck1.y,
								 pck0.z + (pck1.z-pck0.z)*clock > ;


//------------------------- CAMERA -----------------------------
camera{
  //orthographic angle 100
	location pc
	look_at pck
  sky  <0,0,1> // position verticale de la camera
  right <-image_width/image_height,0,0> // repere direct
}

//------------------------sol ---------------------------------
 /* plane { z, -40 texture{PinkAlabaster}} */
plane { z, -40
	texture{
		pigment{ agate scale 2 rotate <0,0,0>
		         color_map{ [0.0 color rgb <1,1,1>]
		                    [0.5 color rgb <0,0,0>]
		                    [1.0 color rgb <1,1,1>]
		                  }// end of color_map
		        } //---- end of pigment ------
			 }
		 }



//------------------------ciel ---------------------------------
 /* sky_sphere {S_Cloud5 rotate <90,0.051, 1>} */
 /* sky_sphere {
	// pigment { color <0.1,0.1,0.1> }
	 pigment { gradient  z color_map { [0 rgb <.05, .05, .05>] [1 color rgb <0,0,0>] } }
	 scale 2 translate -1
 } */

 sky_sphere {
	 pigment {  crackle form <1.5,1.5,0>
		 color_map { [.4 rgb 10] [.5 rgb 0]  }  scale .002 }
	}


//------------------------- LIGHTS -----------------------------
/* light_source{  <100, 100, 100> White}
light_source{  <10, 10, 10>  White } */

light_source {
	< 8, -10, 80>
	color White
	spotlight
	radius 20
	falloff 60
	tightness 1
	point_at <8,20,0>
}



light_source {
	< 8, 26, 80>
	color White
	spotlight
	radius 20
	falloff 60
	tightness 1
	point_at <8,-2,0>
}

light_source {
	< 8, 8, 25>
	color White
	spotlight
	radius 20
	falloff 30
	tightness 1
	point_at <8,8,0>
}

//------------------------- objets -----------------------------
object { TABLE  }
object { TABLEAU  }
placement_pieces_table( PIECES_LIST )
