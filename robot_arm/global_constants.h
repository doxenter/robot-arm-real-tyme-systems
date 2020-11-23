//=====================================================//
// PROGRAM CONSTANTS				       //
//=====================================================//
//-----------------------------------------------------//
//bolean
#define true					1
#define false 					0
//-----------------------------------------------------//
//values
#define pi				        3.14159265
//-----------------------------------------------------//
//limits
#define DPOVMAX					4000
#define DPOVMIN					-4000						

//=====================================================//
// GRAPHICS CONSTANTS				       //
//=====================================================//
//-----------------------------------------------------//
//colours
#define TR 					-1
#define COL0					0
#define COLBG					7
#define COLGR					7
#define COL1					13
#define COL2					11
#define COL3					12
#define COL4					14
#define COL5					15
#define COLR					6
#define COL7					3
#define COL8					8
#define COLAX					2
//-----------------------------------------------------//
//interface parameters
#define IDENT					740
#define C_DP					8
#define WIDTH					1024
#define HEIGHT					768
#define TEMP 					3
#define MENUIDENT				785
#define INSCREENX				720
#define MENU0Y					0
#define CANC					50
#define CENTERX					300
#define CENTERZ					300
#define PDOWN					755
#define INSPACE					90
#define PG1					IDENT-5, 50
#define PG2					IDENT-7, 642
#define PG3					IDENT-5, 52
#define PG4					1022, 50
#define PG5					IDENT-7, 642
#define PG6					1022, 644
#define IDN					950
//-----------------------------------------------------//
//ambient parameters
#define CAMDIST					1000
#define CENTERXM				400
#define CENTERYM				400
#define AL1					IDENT + 85
#define AL2					IDENT + 150
#define AL3					IDENT + 215
#define SCALE				        0.5 
#define GRIDP3 					200, 0, 0
#define GRIDP4 					-200, 0, 0
#define GRPX0					200
#define GRPY0					200
#define GRPX1					-200
#define GRPY1					-200
#define GRSTEP					40
#define AXZH					400
#define AXL					300
#define OR					0
#define RADIUS					2
//=====================================================//
// ROBOT CONSTANTS				       //
//=====================================================//
//-----------------------------------------------------//
//position of the link in the begin configuration
//-----------------------------------------------------//
//origin
#define ORIGINX     				0
#define ORIGINY     				0
#define ORIGINZ     				0
//first link
#define LX01 					0.0
#define LY01 					0.0
#define LZ01 					250.0
//-------------------------------------------------------
//second link
#define LX12 					100.0
#define LY12 					0.0
#define LZ12 					0.0
//-------------------------------------------------------
//third link
#define LX23 					100.0
#define LY23 					0.0
#define LZ23 					0.0
//-------------------------------------------------------
//fourth link
#define LX34 					150.0
#define LY34 					0.0
#define LZ34 					0.0
//-------------------------------------------------------
//fourth link
#define LX45 					100.0
#define LY45 					0.0
#define LZ45 					0.0
//-------------------------------------------------------
//joints offsets
#define QOFF1 					0.0
#define QOFF2 					0.0
#define QOFF3 					0.0
#define QOFF4 					0.0

//=====================================================//
// TASK CONSTANTS				       //
//=====================================================//
//-------------------------------------------------------
//visual task constants
#define VPER                    60
#define VDREL                   30
#define VPRIO                   8
//-------------------------------------------------------
//computational task constants
#define CPER                    80
#define CDREL                   40
#define CPRIO                   4
//-------------------------------------------------------
//inputread task constants
#define IPER                    20
#define IDREL                   10
#define IPRIO                   2
//=====================================================//




