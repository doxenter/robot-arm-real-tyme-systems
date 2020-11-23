
//=================================================//
//	ROBOT DEBO : GLOBL VARIABLES	           //
//=================================================//

//---------------------------------------------------
//joints angles
float q1; float q2; float q3; float q4;		   
//---------------------------------------------------
//aux variables  set #1
float X_rx; float X_ry; float X_rz;
float Y_rx; float Y_ry; float Y_rz;
float Z_rx; float Z_ry; float Z_rz;
//---------------------------------------------------
//aux variables  set #2
float Xr4; float Yr4; float Zr4;
float Xr3; float Yr3; float Zr3;
float Xr2; float Yr2; float Zr2;
float Xr1; float Yr1; float Zr1;
float Xr0; float Yr0; float Zr0;
//---------------------------------------------------
//joints positions 3D
float Xr4v; float Yr4v; float Zr4v;
float Xr3v; float Yr3v; float Zr3v;
float Xr2v; float Yr2v; float Zr2v;
float Xr1v; float Yr1v; float Zr1v;
float Xr0v; float Yr0v; float Zr0v;
//---------------------------------------------------
//cam parameters
float rotx; 
float rotz;
float dpov = CAMDIST;
//---------------------------------------------------
//joints positions 2D
float Pa0; float Pb0;
float Pa1; float Pb1;
float Pa2; float Pb2;
float Pa3; float Pb3;
float Pa4; float Pb4;
//---------------------------------------------------
//ambient variables 3D
float xgrid1 ; float ygrid1; float zgrid1;
float xgrid2 ; float ygrid2; float zgrid2;
//---------------------------------------------------
//ambient variables 2D
float Pa1_grid; float Pb1_grid;
float Pa2_grid; float Pb2_grid;
//---------------------------------------------------
//deadline miss variables
int Dmiss_v;
int Dmiss_i;
int Dmiss_c;
//---------------------------------------------------
//flag variables
_Bool Dflag_v;
_Bool Dflag_i;
_Bool Dflag_c;
_Bool camflag = true;
_Bool Qflag;
