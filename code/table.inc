#declare H_TABLE = 0.50; // height,
#declare W_TABLE  = 0.45; // width in x and z
#local R = 0.02; // thickness
//------------------------
#declare TABLE_01 =
union{
   // feet
   union{
    cylinder{<0,0,0>,<0,H_TABLE ,0>, R
             translate< W_TABLE /2-R,0,-W_TABLE /2+R>}
    cylinder{<0,0,0>,<0,H_TABLE ,0>, R
             translate< W_TABLE /2-R,0, W_TABLE /2-R>}
    cylinder{<0,0,0>,<0,H_TABLE ,0>, R
             translate<-W_TABLE /2+R,0, W_TABLE /2-R>}
    cylinder{<0,0,0>,<0,H_TABLE ,0>, R
             translate<-W_TABLE /2+R,0,-W_TABLE /2+R>}
   texture{ Chrome_Metal}
   }
  // seat
  box{ <-W_TABLE /2,-0.025,-W_TABLE /2>,<W_TABLE /2,0,W_TABLE /2>
       translate<0,H_TABLE ,0>
       /* texture{ NBglass } */
       /* texture {T_Silver_3E} */
       texture {T_Chrome_1A} //este es el que esta usando
       /* pigment{ color Black} */

      }

  /* pigment{ color rgb<0.75,0.5,0.3>*0.3} */
 rotate<90, 0 ,0>

}
