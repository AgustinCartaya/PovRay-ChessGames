Pi = 3.1415926535897932384626;
clock = 1;
%clock = 0;

xp0 = 60;
xp1 = 30;
yp0 = 8;
yp1 = 8;

a  = sqrt(xp0 * xp0 + yp0 * yp0 );
b = (sqrt(xp1 * xp1 + yp1 * yp1 ) - a) / (2*Pi);

teta = 2*Pi * clock;
r = a + b*teta;

xp = r* cos(teta);
yp = r* sin(teta)+8;


zp0 = 25;
zp1 = 2;
zk0 = 7;
zk1 = 0;

zp = zp0 + (zp1-zp0)*clock;
zk = zk0 + (zk1-zk0)*clock;