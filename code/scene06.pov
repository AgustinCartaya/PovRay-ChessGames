
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

//------------------------- CAMERA -----------------------------
camera{
	location PC_UP
	look_at PCK_UP
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

#declare positions = DEFAULT_POSITIONS;

#declare fou_b0_0 = DEFAULT_POSITIONS[2][1];
#declare fou_b0_1 =  fou_b0_0 + x*5 + y*5;
#declare fou_b0 = fou_b0_0 + (fou_b0_1 - fou_b0_0)*clock;

#declare positions[2][1] = fou_b0;



#declare pion_a7_0 = <7, 5, 0>;
#declare pion_a7_1 =  pion_a7_0 + x;

#if( fou_b0.x >=  pion_a7_0.x-.5)
	#declare t0 = (pion_a7_0.x- .5 - fou_b0_0.x) / (fou_b0_1.x - fou_b0_0.x);
	#declare t_pion_a7 = (clock- t0) / (1-t0);

	#declare pion_a7 = pion_a7_0 + (pion_a7_1 - pion_a7_0)*t_pion_a7;

#else
	#declare pion_a7 = pion_a7_0;
#end

//--posiciones antiguas
#declare positions[11][1] =  <3, 3, 0>;
#declare positions[15][0] = pion_a7;

placement_pieces_tableau( PIECES_LIST, positions )
