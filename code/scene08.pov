
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
	location PC_BACK
	look_at PCK_BACK
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

/* #declare cheval_a0 = cheval_a0_0; */
/* #declare cheval_a0_1 =  <7, 5, 0>; */
/* #declare cheval_a0 = cheval_a0_0 + (cheval_a0_1 - cheval_a0_0)*clock; */



//-------part 1 monter ------------------
#switch (clock)

	#range (0,1/4)
		#declare cheval_a0_0 = positions[1][0];
		#declare cheval_a0_1 = cheval_a0_0 + z*3;
		#declare cheval_a0 = cheval_a0_0 + (cheval_a0_1 - cheval_a0_0)*clock*4;
		#break

	//-------part 2 avancer ------------------
	#range (1/4, 1/2)
		#declare cheval_a0_0 = positions[1][0] + z*3;
		#declare cheval_a0_1 = cheval_a0_0 - y*2;
		#declare cheval_a0 = cheval_a0_0 + (cheval_a0_1 - cheval_a0_0)*(clock-1/4)*4;
		#break

	#range (1/2, 3/4)
		#declare cheval_a0_0 = positions[1][0] + z*3 -  y*2;
		#declare cheval_a0_1 = cheval_a0_0 +x;
		#declare cheval_a0 = cheval_a0_0 + (cheval_a0_1 - cheval_a0_0)*(clock-1/2)*4;
		#break

	#range (3/4,1)
		#declare cheval_a0_0 = positions[1][0] + z*3 -  y*2 + x;
		#declare cheval_a0_1 = cheval_a0_0 - z*3;
		#declare cheval_a0 = cheval_a0_0 + (cheval_a0_1 - cheval_a0_0)*(clock-3/4)*4;
		#break

#end


#declare positions[1][0]=cheval_a0;

//--posiciones antiguas
#declare positions[11][1] =  <3, 3, 0>;
#declare positions[15][0] =  <8, 5, -.4>;
#declare positions[2][1] =  <7, 5, 0>;

placement_pieces_tableau( PIECES_LIST, positions )
