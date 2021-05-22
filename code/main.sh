#!/bin/sh
#MY_MESSAGE=$(pwd)

#scene name
scene=$1

#resolution
# W=480
# H=270

W=1280
H=720

#animation
time=$2
FPS=12
frames=0
animation=""

#move
move=$3




if [ $# -gt 1 ] && [ $time -gt 0 ]
  then
    frames=$(($FPS*$time))
    animation="+KFI1 +KFF$frames"
fi
# echo "$scene, $time, frames: $frames"

$(povray +W$W +H$H $animation $scene.pov)

if [ $move -eq 1 ]
then
  if [ ! -d "$scene" ]
  then
     $(mkdir $scene)
  fi
  #mp4
  $(ffmpeg -framerate $FPS -s $W*$H -i $scene%2d.png $scene.mp4)

  #gif
  delaygif=$(( $time * 10 ))
  $(convert -loop 1 -delay $delaygif $scene*.png $scene.gif)

  $(mv ./$scene*.png ./$scene/ )
  $(mv ./$scene.mp4 ./$scene/ )
  $(mv ./$scene.gif ./$scene/ )
fi
