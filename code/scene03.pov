
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
* Posicionamiento de piezas en la mesa de juego
**/

//position initial camera et look at
#declare pc0 = PC_RIGHT_EXT;
#declare pck0 = PCK_RIGHT_EXT;

//position final camera et look at
#declare pc1 = <15, -3, 8>;
#declare pck1 = <8, 8, 1>;

//position median camera et look at
#declare pc2 = PC_UP;
#declare pck2 = PCK_UP;

#declare pc = x;
#declare pck = x;

bezier2(pc, clock, pc0, pc1, pc2 )
bezier2(pck, clock, pck0, pck1, pck2 )


//------------------------- CAMERA -----------------------------
camera{
	location pc
	look_at pck
  sky  <0,0,1> // position verticale de la camera
  right <-image_width/image_height,0,0> // repere direct
}

//------------------------sol ---------------------------------
plane { z, -40
	texture{
		pigment{ agate scale 2 rotate <0,0,0>
		         color_map{ [0.0 color rgb <1,1,1>]
		                    [0.5 color rgb <0,0,0>]
		                    [1.0 color rgb <1,1,1>]
		                  }
		        }
						/* pigment{ rgb<0.1,0.1,0.1>} */
			 }
		 }

//------------------------ciel ---------------------------------
 sky_sphere {
	 pigment {  crackle form <1.5,1.5,0>
		 color_map { [.4 rgb 10] [.5 rgb 0]  }  scale .002 }
	}


//------------------------- LIGHTS -----------------------------
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
placement_pieces_tableau( PIECES_LIST, DEFAULT_POSITIONS )
