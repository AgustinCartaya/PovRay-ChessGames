#include "textures.inc"

//---------------------------- TABLEUX ---------------------------------------
#declare TABLEAU_01 =
union{
box {<-1.01,0.00,-1.01>,<1.01,0.049,1.01>
      texture{
        pigment{
          color rgb<0.75,0.5,0.30>*0.5}
             } // end of texture
    } // end of box ----------------------
box {<-1.00,0.00,-1.00>,<1.00,0.050,1.00>
      texture{
        pigment{ checker
                 color rgb<1,1,1>
                 color rgb<0,0,0>
               } // end pigment
               scale 0.25
             } // end of texture
	 }
	 rotate<90, 0 ,0>
};
//object{Chessboard rotate<90, 0 ,0> translate<7.9, 7.9,-.4>}
