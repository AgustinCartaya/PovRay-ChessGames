
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

//------------------------- CAMERA -----------------------------
camera{
  //orthographic angle 100
	location PC_UP
	look_at PCK_UP
  sky  <0,0,1> // position verticale de la camera
  right <-image_width/image_height,0,0> // repere direct
}

//------------------------sol ---------------------------------
 /* plane { z, -40 texture{PinkAlabaster}} */
/* plane { z, -40
	texture{
		pigment{ agate scale 2 rotate <0,0,0>
		         color_map{ [0.0 color rgb <1,1,1>]
		                    [0.5 color rgb <0,0,0>]
		                    [1.0 color rgb <1,1,1>]
		                  }// end of color_map
		        } //---- end of pigment ------
			 }
		 } */



//------------------------ciel ---------------------------------
 /* sky_sphere {S_Cloud5 rotate <90,0.051, 1>} */
 /* sky_sphere {
	// pigment { color <0.1,0.1,0.1> }
	 pigment { gradient  z color_map { [0 rgb <.05, .05, .05>] [1 color rgb <0,0,0>] } }
	 scale 2 translate -1
 } */

 sky_sphere {
	 pigment {  color White}
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
/* object { TABLE  } */
object { TABLEAU  }
placement_pieces_tableau( PIECES_LIST, DEFAULT_POSITIONS )


//------- montrer les pieces une a cote de l'autre ------------
// la camera PC_RIGHT est necessaire
/* #declare i =0;
#declare cumul = <20, 4, .5>;
#while (i < 6)

	object{
		PIECES_LIST[i][ mod(i,2)]
		translate cumul
	}
	#declare  cumul = cumul + 1.6*y;
	#declare i =i+1;
#end */
