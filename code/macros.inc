#declare Pi = 3.1415926535897932384626;
#declare O = <0,0,0>;
#declare SIZE_TABLEAU = 16.0;
#declare CENTER_TABLEAU = < SIZE_TABLEAU/2 ,SIZE_TABLEAU/2 ,-0.4>;

/**
* Devuelve la pieza correspondiente dependiendo la posicion
*/
#macro get_pice_by_pos(piece, pos, equipe)
	#switch(pos)
	#case (-1)
			#declare piece = pieces_list[0][equipe];
		#break

		#case (0)
		#case (7)
			#declare	piece = pieces_list[1][equipe];
		#break

		#case (1)
		#case (6)
			#declare	piece = pieces_list[2][equipe];
		#break

		#case (2)
		#case (5)
			#declare	piece = pieces_list[3][equipe];
		#break

		#case (3)
		 	#declare	piece = pieces_list[4][equipe];
		#break

		#case (4)
			#declare piece = pieces_list[5][equipe];
		#break
	#end
#end

/**
* Devuelve la posicion en el espacion dependiendo el indice del tablreo
* vect: indices del tablero
*/
#macro get_postion_by_indextab(pos, vect )
 #local posIni = <1,1,0> * SIZE_TABLEAU/ 16 ;
 #local paso = SIZE_TABLEAU /8 ;
 #declare pos = posIni +
                vect.x * paso * x +
                vect.y * paso * y +
                vect.z * z;
#end

/**
* coloca una pieza en el tablero
* vect: indices del tablero
* piece: pieza a colocar
*/
#macro place_piece_tableau(vect, piece)
    #local post = 0;
    get_postion_by_indextab(post, vect)
  	object{ piece translate post}
#end


//---------------------------- 1 -----------------------------------------------


/**
* positionner les pieces sur le tableau
* une liste de pièces ordonnée est nécessaire
*/
 #macro placement_pieces_tableau( pieces_list, positions  )
	#local pos0 = 0;
	#local pos1 = 0;
	#local piece0 = pieces_list[0][0];
	#local piece1 = pieces_list[0][1];
	#declare i = 0;
	#while (i < 16)

    #if(i <8)
        get_pice_by_pos(piece0, i, 0)
        get_pice_by_pos(piece1, i, 1)
    #else
      #local piece0 = pieces_list[0][0];
    	#local piece1 = pieces_list[0][1];
    #end

    place_piece_tableau( positions[i][0] , piece0 )
    place_piece_tableau( positions[i][1] , piece1 )

		#declare i = i+1;
	#end

#end

/**
* positionner les pieces sur la table
* positionement avant de ranger les pieces sur le tableau
* une liste de pièces ordonnée est nécessaire
*/
#macro placement_pieces_table( pieces_list )

  #local rayom1 = SIZE_TABLEAU * 0.82;
  #local rayom2 = SIZE_TABLEAU * 0.67;
  #local rayom = rayom1;
  #local pos_x = 0.0;
  #local pos_y = 0.0;
	#local piece = pieces_list[0][0];

  #local decalge = 0.04;
  #local angle_ini = Pi/3;

	#declare j = 0;
  #while (j < 2)

  	#declare i = 0;
  	#while (i < 16)

      #if (i < 8)
        #local rayom = rayom1;
        get_pice_by_pos(piece, i, j)
      #else
        #local rayom = rayom2;
        #local piece = pieces_list[0][j];
      #end

      #local argu = mod(i,8) * angle_ini/8 + max(4*j,1) * angle_ini + decalge;
      #local pos_x = rayom*cos(argu) + CENTER_TABLEAU.x;
      #local pos_y = rayom*sin(argu) + CENTER_TABLEAU.y;

      object{ piece translate <pos_x, pos_y, -.4>}

  		#declare i = i+1;
  	#end
    #declare j = j+1;
  #end

#end


/**
* posiciona las piesas en cualquier lugar del espacio
* una tabla con las piezas y otra con las psiciones son necesarias
*
*/
#macro placement_pieces_ext( pieces_list, positions  )
 #local pos0 = 0;
 #local pos1 = 0;
 #local piece0 = pieces_list[0][0];
 #local piece1 = pieces_list[0][1];
 #declare i = 0;
 #while (i < 16)

   #if(i <8)
       get_pice_by_pos(piece0, i, 0)
       get_pice_by_pos(piece1, i, 1)
   #else
     #local piece0 = pieces_list[0][0];
     #local piece1 = pieces_list[0][1];
   #end

   object{ piece0 translate positions[i][0] }
   object{ piece1 translate positions[i][1] }

   #declare i = i+1;
 #end

#end



/**
* calcula las posiciones de todas las piezas del tablero
*
*/
#macro calc_positions_tableau( pos, pos_tab  )
 #declare pos = array[16][2]

 #declare i = 0;
 #while (i < 16)

    /* #local temp_pos_tab = pos_tab[i][0]; */
    #local temp_pos = 0;
    get_postion_by_indextab(temp_pos, pos_tab[i][0])
    #declare pos[i][0] = temp_pos;

    /* #local temp_pos_tab = pos_tab[i][1]; */
    #local temp_pos = 0;
    get_postion_by_indextab(temp_pos, pos_tab[i][1])
    #declare pos[i][1] = temp_pos;

   #declare i = i+1;
 #end

#end




/**
* devuelve una lista con las pociciones circulares de las piezas en la mesa
* es parecido a placement_table la diferencia es que las piezas no son mostradas
*/

#macro calc_positions_table( positions )

  #declare list = array[16][2];
  #local rayom1 = SIZE_TABLEAU * 0.82;
  #local rayom2 = SIZE_TABLEAU * 0.67;
  #local rayom = rayom1;
  #local pos_x = 0.0;
  #local pos_y = 0.0;

  #local decalge = 0.04;
  #local angle_ini = Pi/3;


  	#local i = 0;
  	#while (i < 16)

      #if (i < 8)
        #local rayom = rayom1;
      #else
        #local rayom = rayom2;
      #end

      #local argu = 2 * angle_ini - decalge - mod(i,8) * angle_ini/8 ;
      #local pos_x = rayom*cos(argu) + CENTER_TABLEAU.x;
      #local pos_y = rayom*sin(argu) + CENTER_TABLEAU.y;

      #declare positions[i][0] = <pos_x, pos_y, -.4>;


      #local argu = mod(i,8) * angle_ini/8 + 4*angle_ini + decalge;
      #local pos_x = rayom*cos(argu) + CENTER_TABLEAU.x;
      #local pos_y = rayom*sin(argu) + CENTER_TABLEAU.y;

      #declare positions[i][1] = <pos_x, pos_y, -.4>;

  		#local i = i+1;
  	#end


#end



#macro calc_median_positions(medians, posI, posF, h)
  #declare medians = array[16][2];

   #local i = 0;
   #while (i < 16)
    #declare medians[i][0] = (posF[i][0] + posI[i][0]) /2
                              * <1,1,0> + z*(posI[i][0] + posF[i][0])*h;

    #declare medians[i][1] = (posI[i][1] + posF[i][1]) /2
                              * <1,1,0> + z*(posI[i][1] + posF[i][1])*h;

    #local i = i+1;
   #end


#end


//---------------------------- pour le sacene02  ---------------------------------------------

#macro calc_bezier_position(positions, t0, P0, P1, P2)

   #local i = 0;
   #while (i < 16)

     #local temp_pos = 0;
     bezier2(temp_pos, t0, P0[i][0], P1[i][0], P2[i][0], )
     #declare positions[i][0] =temp_pos;


     #local temp_pos = 0;
     bezier2(temp_pos, t0, P0[i][1], P1[i][1], P2[i][1], )
     #declare positions[i][1] =temp_pos;

    #local i = i+1;
   #end
 #end

//---------------------------- fin pour le scene02 ---------------------------------------------


//
/**
* renvoi dans res la valeur du ponit calcule a partir
* d'une courve de bezier de deuxieme degree avec les ponts
* de controle P0, P1, P2
*/
#macro bezier2(res,  t0, p0, p1, p2)
  #declare res = pow((1-t0),2)*p0 + 2*(1-t0)*t0*p1 +  pow(t0,2)*p2;
#end
