#include "shapes.inc"

// --------------------------- pie --------------------------------------------
#local pie =
	merge{

		lathe{ linear_spline 4,
				 < 0.00, -0.40>, < 0.70, -0.40>,< 0.70, -0.25>, < 0.30, 0.00>}

		difference{
			torus{ 0.5, 0.1	translate <0, -0.17, 0>	}
			box{	<-.6, -0.2, -.6>	<.6,-.4,.6>	}
		}

		difference{
			torus{	.4, 0.1 translate <0, -0.1, 0>	}
			box{	<-.5, -0.1, -.5>	<.5,-.3,.5>	}
		}
};

// --------------------------- base --------------------------------------------
	#declare base = object{
			lathe{    cubic_spline 7,
				< 0.40, 0.00>,< 0.40, 0.00>, < 0.25, 0.60>, < 0.30, 1.00>,< 0.30, 1.00>, < 0.00, 1.10>, < 0.00, 1.10> }
	};

// --------------------------- corps --------------------------------------------
	#local corps = 	merge{
			object{ pie }
		  object{ base }
			translate <0, -1.00, 0>
	};


//---------------------------- pion ---------------------------------------

	#local tete_pion =
	    union{
	        lathe{ bezier_spline 4,
							 < 0.50, 0.00>,   < 0.70, 0.30>, < 0.50, 0.30>,< 0.20, 0.10>}

					lathe{ bezier_spline  4,
							 < 0.20, 0.10>,< 0.05, 0.00>,  < 0.00, 0.10>,< 0.10, 0.20>  }

					lathe{ bezier_spline 4,
	             < 0.10, 0.20>,< 0.20, 0.30>,< 0.37, 0.33>, < 0.48, 0.52> }

					lathe{  bezier_spline  4,
	             < 0.48, 0.52>,< 0.65, 0.80>,< 0.54, 1.32>,< 0.00, 1.35>}

				 torus{	.3, 0.1 translate <0, 0.25, 0>	}

				 scale .75
				};

	#declare PION = merge{
		object{ corps }
		object{ tete_pion }
	  pigment{ color rgb<0,0,0>}
	 	rotate<90,0,0>
		translate <0,0,1.4>
		scale 0.65
	}

//---------------------------- fou ---------------------------------------


#declare tete_fou = union{

			lathe{ bezier_spline 4,
				 <1.0, 0.0>, <1.1, 0.4>, <0.10, 0.06>, <0.4, 1.6>
			}
			difference{
				torus{ .8, 0.2 translate <0, -0.1, 0>  }
				box{  <-10, -0.1, -10>  <10,-10,10>}
			}

	  difference{
	        blob  {
	            threshold 1.5
	            cylinder{<0,0,0>,<0,1.5,0>,1.5,1.8  }
	            sphere{  <0,3.2,0>,2.8,1.53}
	          }
	        box{
	          <-0.1,0,-5>
	          <0.1,5,5>
	          rotate<0, 0, -25>
	          translate<0.2,1.8,0>
	        }

	}
	scale .38
}

	#declare FOU = merge{
		object{ corps }
		object{ tete_fou }
	  pigment{ color rgb<0,0,0>}
		rotate<90,0,0>
		translate <0,0,1.35>
		scale .87
	}

	//------------------------------ tour ---------------------------------------------

	#local tete_tour = union {
	   intersection {
	      union {
	         plane { +x, -0.5 }
	         plane { -x, -0.5 }
	         plane { y, 9 }
	      }

	      union {
	         plane { +z, -0.5 }
	         plane { -z, -0.5 }
	         plane { y, 9 }
	      }

	      plane { y, 10 }
	      object { Cylinder_Y scale <2, 1, 2> }
	      object { Cylinder_Y scale <1.2, 1, 1.2> inverse }
	      plane { -y, -8 }

					scale 1.3
					translate <0,-5.6,0>
	   }



	   sphere { <0, 4, 0>, 1.1
	      scale <2.5, 0.5, 2.5>
	      translate 2.8*y
	   }
		 scale .15
		 	 translate <0,-0.70,0>
	}

	#declare TOUR = merge{
		object{ corps scale <1,1.25,1> }
		object{ tete_tour }
	  pigment{ color rgb<0,0,0>}
		rotate<90,0,0>
	 	translate <0,0,1.7>
	 	scale .95
	}

//---------------------------- dame Et Roi ---------------------------------------

#local dameEtRoi = union {
sphere { <0, 10.5, 0>, 1.5 }

intersection {
	 union {
			sphere { <1.75, 12, 0>, 0.9  rotate 150*y }
			sphere { <1.75, 12, 0>, 0.9  rotate 120*y }
			sphere { <1.75, 12, 0>, 0.9  rotate 90*y }
			sphere { <1.75, 12, 0>, 0.9  rotate 60*y }
			sphere { <1.75, 12, 0>, 0.9  rotate 30*y }
			sphere { <1.75, 12, 0>, 0.9  }
			sphere { <1.75, 12, 0>, 0.9  rotate -30*y }
			sphere { <1.75, 12, 0>, 0.9  rotate -60*y }
			sphere { <1.75, 12, 0>, 0.9  rotate -90*y }
			sphere { <1.75, 12, 0>, 0.9  rotate -120*y }
			sphere { <1.75, 12, 0>, 0.9  rotate -150*y }
			sphere { <1.75, 12, 0>, 0.9  rotate  180*y }
			inverse
	 }

	 plane { y, 11.5 }

	 object { QCone_Y
			scale <1, 3, 1>
			translate 5*y
	 }

	 	plane { -y, -8 }
	}

	sphere { <0, 0, 0>, 1
		 scale <1.8, 0.4, 1.8>
		 translate 8*y
	}

};
//------------------- dame -----------------------------------------------------

#local tete_dame = union {
	sphere { <0, 12.3, 0>, 0.4 }
	object { dameEtRoi }
	scale .2
	translate <0,-1.6,0>
}

#declare DAME = merge{
	object{ corps scale <1,1.2,1> }
	object{ tete_dame }
  pigment{ color rgb<0,0,0>}
	rotate<90,0,0>
 	translate <0,0,1.64>

}

//------------------- roi -----------------------------------------------------

#local tet_roi= union {
   intersection {
      union {
         intersection {
            plane { y, 13 }
            plane { -y, -12.5 }
         }

         intersection {
            plane { +x, 0.25 }
            plane { -x, 0.25 }
         }
      }

      plane { +z,  0.25 }
      plane { -z,  0.25 }
      plane { +x,  0.75 }
      plane { -x,  0.75 }
      plane { +y,  13.5  }
      plane { -y,  -11.5  }
   }

   object { dameEtRoi }
	 scale .2
	 translate <0,-1.6,0>
}

#declare ROI = merge{
	object{ corps scale <1,1.25,1> }
	object{ tet_roi }
  pigment{ color rgb<0,0,0>}
	rotate<90,0,0>
 	translate <0,0,1.7>
}

//----------------------------- cavalier -------------------------------------------
#local tete_cavalier = union {
   intersection {
      object { Cylinder_Z
         scale <17.875, 17.875, 1>
         translate <-18.625, 7, 0>
         inverse
      }

      object { Cylinder_Z
         scale <17.875, 17.875, 1>
         translate <18.625, 7, 0>
         inverse
      }

      object { Cylinder_X
         scale <1, 5.1, 5.1>
         translate <0, 11.2, -5>
         inverse
      }

      union {
         plane { y, 0
            rotate 30*x
            translate 9.15*y
         }
         plane { z, 0
            rotate -20*x
            translate 10*y
         }
      }

      union {
         plane { -y, 0
            rotate 30*x
            translate 7.15*y
         }
         plane { y, 0
            rotate 60*x
            translate 7.3*y
         }
      }

      union {
         plane { y, 0  rotate -45*y   }
         plane { y, 0  rotate 45*z }
         translate 9*y
      }

      object { Cylinder_Y scale <2, 1, 2> }
      sphere { <0, 7, 0>, 4 }
   }

   sphere { <0, 0, 0>, 1
      scale <2.5, 0.5, 2.5>
      translate <0, 2.8, 0>
   			}
 	scale .23
	 translate <0,-0.70,0>
}

#declare CAVALIER = merge{
	object{ pie }
	object{ tete_cavalier }
  pigment{ color rgb<0,0,0>}
	rotate<90,0,0>
 	translate <0,0,0.4>
}
