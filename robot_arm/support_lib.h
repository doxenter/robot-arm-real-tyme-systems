
//=======================================================================================================//
//                                                                                                       //
//   LIBRERIA DI SUPPORTO : FUNZIONI DI BASE UTILI ALLO SVILUPPO DEL PROGRAMMA                           //
//                                                                                                       //
//=======================================================================================================//
#include <allegro.h>
#include <math.h>
#include "global_constants.h"
#include "global_variables.h"

pthread_mutex_t   mux_rot = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t   mux_gr1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t   mux_gr2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t   mux_Pr = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t   mux_q = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t   mux_dpov = PTHREAD_MUTEX_INITIALIZER;


char s1[10]; char s2[10]; char s3[10];
char s4[10]; char s5[10]; char s6[10];
char s7[10]; char s8[10]; char s9[10];
char s10[10]; char s11[10]; char s12[10];

//=======================================================================================================//
//drow gui and interfaces elements
void drow_GUI(){

    rectfill(screen, PG1, PG2 , COL7);                                      //drow left gui line
    rectfill(screen, PG3, PG4, COL7);                                       //drow upper gui line
    rectfill(screen, PG5, PG6, COL7);     //drow lower gui line

    textout_ex(screen, font,"JOINTS COMMANDS:", IDENT, 60, COL7, TR);

    textout_ex(screen, font,"press Q/W to rotate q1 joint", IDENT, 100, COL7, TR);
    textout_ex(screen, font,"press A/S to rotate q2 joint", IDENT, 120, COL7, TR);
    textout_ex(screen, font,"press D/F to rotate q3 joint", IDENT, 140, COL7, TR);
    textout_ex(screen, font,"press E/R to rotate q4 joint", IDENT, 160, COL7, TR);

    textout_ex(screen, font,"VISUAL COMMANDS:", IDENT,200, COL7, -1);
    textout_ex(screen, font,"press LEFT/RIGHT to rotate ", IDENT, 220, COL7, TR);
    textout_ex(screen, font,"press UP/DOWN to rotate ", IDENT, 240, COL7, TR);
    textout_ex(screen, font,"press N to increse distance", IDENT, 260, COL7, TR);
    textout_ex(screen, font,"press M to decrease distance", IDENT, 280, COL7, TR);

    textout_ex(screen, font,"POSITION OF POINT A,B,C:", IDENT, 320, COL7, TR);
    textout_ex(screen, font,"A(X,Y,Z)=", IDENT, 340, COL7, TR);
    textout_ex(screen, font,"B(X,Y,Z)=", IDENT, 360, COL7, TR);
    textout_ex(screen, font,"C(X,Y,Z)=", IDENT, 380, 3, TR);

    textout_ex(screen, font,"DMISS visual task:", IDENT, 420, COL7, TR);
    textout_ex(screen, font,"DMISS compute task:", IDENT, 440, COL7, TR);
    textout_ex(screen, font,"DMISS input task:", IDENT, 460, COL7, TR);

    textout_ex(screen, font,"q1 :", IDENT, 500, COL7, TR);
    textout_ex(screen, font,"q2 :", IDENT, 520, COL7, TR);
    textout_ex(screen, font,"q3 :", IDENT, 540, COL7, TR);
    textout_ex(screen, font,"q4 :", IDENT, 560, COL7, TR);
    textout_ex(screen, font,"cam X rotation :", IDENT, 580, COL7, TR);
    textout_ex(screen, font,"cam Z rotation :", IDENT, 600, COL7, TR);
    textout_ex(screen, font,"distance :", IDENT, 620, COL7, TR);



}

//=======================================================================================================//
//init functions of allegro, keyboard , welcome
void init() {

    allegro_init();
    install_keyboard();

    set_color_depth(C_DP);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, WIDTH, HEIGHT, COL0, COL0);     //initialize window
    clear_to_color(screen, COL0);                             // black background

    textout_ex(screen, font,"ROBOT DEMO", 500, 380, COL3, TR);
    sleep(TEMP);
    textout_ex(screen, font,"ROBOT DEMO", 500, 380, COL0, TR);

    drow_GUI();

    textout_ex(screen, font,"0", IDN, 500, COL7, TR);
    textout_ex(screen, font,"0", IDN, 520, COL7, TR);
    textout_ex(screen, font,"0", IDN, 540, COL7, TR);
    textout_ex(screen, font,"0", IDN, 560, COL7, TR);
    textout_ex(screen, font,"0", IDN, 580, COL7, TR);
    textout_ex(screen, font,"0", IDN, 600, COL7, TR);
    textout_ex(screen, font,"1000", IDN, 620, COL7, TR);

}

//=======================================================================================================//
//delete old values of dmiss and print new values
void refresh_dmiss() {

        if (Dflag_v = 1){
            rectfill(screen,IDN,415,WIDTH,426,COL0);
            textout_ex(screen, font, s10, IDN, 420, COL0, TR);
            Dflag_v = 0;
            }

        if (Dflag_i = 1){
            rectfill(screen,IDN,455,WIDTH,466,COL0);
            Dflag_i = 0;
            }

        if (Dflag_c = 1){
            rectfill(screen,IDN,435,WIDTH,446,COL0);
            Dflag_c = 0;
            }

        sprintf(s10, "%i \n", Dmiss_v);
        textout_ex(screen, font, s10, IDN, 420, COL7, TR);
        sprintf(s11, "%i \n", Dmiss_c);
        textout_ex(screen, font, s11, IDN, 440, COL7, TR);
        sprintf(s12, "%i \n", Dmiss_i);
        textout_ex(screen, font, s12, IDN, 460, COL7, TR);


}

//=======================================================================================================//
//delete old values of joints positions and print new values
void refresh_points_value(){

        rectfill(screen, AL1, 340, AL1 + CANC, 355 ,COL0);
        sprintf(s1, "%3.1f\n", Xr2);
        textout_ex(screen, font, s1, AL1, 340, COL7, TR);

        rectfill(screen, AL2, 340, AL2 + CANC, 355, COL0);
        sprintf(s2, "%3.1f\n", Yr2);
        textout_ex(screen, font, s2, AL2, 340, COL7, TR);

        rectfill(screen, AL3, 340, AL3 + CANC, 355, COL0);
        sprintf(s3, "%3.1f\n", Zr2);
        textout_ex(screen, font, s3, AL3, 340, COL7, TR);

        rectfill(screen, AL1, 355, AL1 + CANC, 375, COL0);
        sprintf(s4, "%3.1f\n", Xr3);
        textout_ex(screen, font, s4, AL1, 360, COL7, TR);

        rectfill(screen, AL2, 355, AL2 + CANC, 375, COL0);
        sprintf(s5, "%3.1f\n", Yr3);
        textout_ex(screen, font, s5, AL2, 360, COL7, TR);

        rectfill(screen, AL3, 355, AL3 + CANC, 375, COL0);
        sprintf(s6, "%3.1f\n", Zr3);
        textout_ex(screen, font, s6, AL3, 360, COL7, TR);

        rectfill(screen,AL1, 375, AL1 + CANC, 400,COL0);
        sprintf(s7, "%3.1f\n", Xr4);
        textout_ex(screen, font, s7, AL1, 380, COL7, TR);

        rectfill(screen,AL2, 375, AL2 + CANC, 400,COL0);
        sprintf(s8, "%3.1f\n", Yr4);
        textout_ex(screen, font, s8, AL2, 380, COL7, TR);

        rectfill(screen,AL3, 375, AL3 + CANC, 400,COL0);
        sprintf(s9, "%3.1f\n", Zr4);
        textout_ex(screen, font, s9, AL3, 380, COL7, TR);


}
//=======================================================================================================//
//conversion in radiant
float radiant_conv(float q){
    float qr = q* (2*pi / 360);
    return(qr);
}
//=======================================================================================================//
//project 3d point in screen bidimensional space
float project_x(float dpov, float px, float py, float pz){

    float a = - ( py * dpov / (dpov - px) ) * SCALE + CENTERXM;

    return a ;
}

float project_y(float dpov, float px, float py, float pz){

    float b = - (pz * dpov / (dpov - px) ) * SCALE + CENTERYM;

    return b ;
}

//=======================================================================================================//
//go forward then press EXIT

 int exit_function(){
    srand(time(NULL));

    while (!key[KEY_ESC]);
    return 0;
}
//=======================================================================================================//
//read scancode by the keyboard
char get_scancode()
{
    if (keypressed())
    return readkey() >> 8;
    else return 0;
}



//=======================================================================================================//
// X_trasf; Y_trasf; Z_trasf : they handle rotation in 3d space
float cam_rotX(float x, float y, float z, float angle_theta , float angle_phi){
    float phi = radiant_conv(angle_phi);
    float theta = radiant_conv(angle_theta);
    float xr = x * cos(theta) * cos(phi) + y * sin(phi) * cos(theta) + z * sin(phi);
    return xr;
}

float cam_rotY(float x, float y, float z, float angle_theta , float angle_phi){
    float phi = radiant_conv(angle_phi) ;
    float theta = radiant_conv(angle_theta);
    float yr = - x * sin(theta) + y * cos(theta);
    return yr;
}


float cam_rotZ(float x, float y, float z, float angle_theta , float angle_phi){
    float phi = radiant_conv(angle_phi);
    float theta = radiant_conv(angle_theta);
    float zr = - x * sin(theta) * cos(phi) - y * sin(phi) * sin(theta) + z * cos(theta);
    return zr;
}

//=======================================================================================================//
//clear the old bitmap pf robot,grid and axis, then refresh usin new values
void refresh_ambient(){

    BITMAP *buffer;
    buffer = create_bitmap(INSCREENX, HEIGHT);
    clear_to_color(buffer, COL0);

    int k;
    int i;

    pthread_mutex_lock(&mux_rot);
    for(i=-5; i<6; i++){

        xgrid1 = cam_rotX(GRPX0, i * GRSTEP, OR, rotx, rotz);
        ygrid1 = cam_rotY(GRPX0, i * GRSTEP, OR, rotx, rotz);
        zgrid1 = cam_rotZ(GRPX0, i * GRSTEP, OR, rotx, rotz);

        xgrid2 = cam_rotX(GRPX1, i * GRSTEP, OR, rotx, rotz);
        ygrid2 = cam_rotY(GRPX1, i * GRSTEP, OR, rotx, rotz);
        zgrid2 = cam_rotZ(GRPX1, i * GRSTEP, OR, rotx, rotz);

        Pa1_grid = project_x(dpov, xgrid1, ygrid1, zgrid1);
        Pb1_grid = project_y(dpov, xgrid1, ygrid1, zgrid1);

        Pa2_grid = project_x(dpov, xgrid2, ygrid2, zgrid2);
        Pb2_grid = project_y(dpov, xgrid2, ygrid2, zgrid2);


        line(buffer, Pa1_grid, Pb1_grid, Pa2_grid, Pb2_grid, COLGR);
        }
    pthread_mutex_unlock(&mux_rot);

    pthread_mutex_lock(&mux_rot);
    for(i=-5; i<6; i++){

        xgrid1 = cam_rotX(i * GRSTEP, GRPY0, OR, rotx, rotz);
        ygrid1 = cam_rotY(i * GRSTEP, GRPY0, OR, rotx, rotz);
        zgrid1 = cam_rotZ(i * GRSTEP, GRPY0, OR, rotx, rotz);

        xgrid2 = cam_rotX(i * GRSTEP, GRPY1, OR, rotx, rotz);
        ygrid2 = cam_rotY(i * GRSTEP, GRPY1, OR, rotx, rotz);
        zgrid2 = cam_rotZ(i * GRSTEP, GRPY1, OR, rotx, rotz);

        Pa1_grid = project_x(dpov, xgrid1, ygrid1, zgrid1);
        Pb1_grid = project_y(dpov, xgrid1, ygrid1, zgrid1);

        Pa2_grid = project_x(dpov, xgrid2, ygrid2, zgrid2);
        Pb2_grid = project_y(dpov, xgrid2, ygrid2, zgrid2);

        line(buffer, Pa1_grid, Pb1_grid, Pa2_grid, Pb2_grid, COLGR);

        }
    pthread_mutex_unlock(&mux_rot);

    pthread_mutex_lock(&mux_rot);
    xgrid1 = cam_rotX(GRPX1, GRPY0, OR, rotx, rotz);
    ygrid1 = cam_rotY(GRPX1, GRPY0, OR, rotx, rotz);
    zgrid1 = cam_rotZ(GRPX1, GRPY0, OR, rotx, rotz);

    xgrid2 = cam_rotX(GRPY1, GRPY0, AXZH, rotx, rotz);
    ygrid2 = cam_rotY(GRPY1, GRPY0, AXZH, rotx, rotz);
    zgrid2 = cam_rotZ(GRPY1, GRPY0, AXZH, rotx, rotz);

    Pa1_grid = project_x(dpov, xgrid1, ygrid1, zgrid1);
    Pb1_grid = project_y(dpov, xgrid1, ygrid1, zgrid1);

    Pa2_grid = project_x(dpov, xgrid2, ygrid2, zgrid2);
    Pb2_grid = project_y(dpov, xgrid2, ygrid2, zgrid2);

    line(buffer, Pa1_grid, Pb1_grid, Pa2_grid, Pb2_grid, COLAX);

    xgrid1 = cam_rotX(AXL, GRPY0, OR, rotx, rotz);
    ygrid1 = cam_rotY(AXL, GRPY0, OR, rotx, rotz);
    zgrid1 = cam_rotZ(AXL, GRPY0, OR, rotx, rotz);

    xgrid2 = cam_rotX(GRPX0, GRPY0, OR, rotx, rotz);
    ygrid2 = cam_rotY(GRPX0, GRPY0, OR, rotx, rotz);
    zgrid2 = cam_rotZ(GRPX0, GRPY0, OR, rotx, rotz);

    Pa1_grid = project_x(dpov, xgrid1, ygrid1, zgrid1);
    Pb1_grid = project_y(dpov, xgrid1, ygrid1, zgrid1);

    Pa2_grid = project_x(dpov, xgrid2, ygrid2, zgrid2);
    Pb2_grid = project_y(dpov, xgrid2, ygrid2, zgrid2);
    pthread_mutex_unlock(&mux_rot);


    line(buffer, Pa1_grid, Pb1_grid, Pa2_grid, Pb2_grid, COLAX);

    pthread_mutex_lock(&mux_rot);
    xgrid1 = cam_rotX(GRPX1, GRPY1, OR, rotx, rotz);
    ygrid1 = cam_rotY(GRPX1, GRPY1, OR, rotx, rotz);
    zgrid1 = cam_rotZ(GRPX1, GRPY1, OR, rotx, rotz);
    xgrid2 = cam_rotX(GRPX1, - AXL, OR, rotx, rotz);
    ygrid2 = cam_rotY(GRPX1, - AXL, OR, rotx, rotz);
    zgrid2 = cam_rotZ(GRPX1, - AXL, OR, rotx, rotz);

    Pa1_grid = project_x(dpov, xgrid1, ygrid1, zgrid1);
    Pb1_grid = project_y(dpov, xgrid1, ygrid1, zgrid1);

    Pa2_grid = project_x(dpov, xgrid2, ygrid2, zgrid2);
    Pb2_grid = project_y(dpov, xgrid2, ygrid2, zgrid2);
    pthread_mutex_unlock(&mux_rot);

    line(buffer, Pa1_grid, Pb1_grid, Pa2_grid, Pb2_grid, COLAX);

    pthread_mutex_lock(&mux_Pr);
    circlefill(buffer,Pa0,Pb0,RADIUS,COLR);
    circlefill(buffer,Pa1,Pb1,RADIUS,COLR);
    circlefill(buffer,Pa2,Pb2,RADIUS,COLR);
    circlefill(buffer,Pa3,Pb3,RADIUS,COLR);
    circlefill(buffer,Pa4,Pb4,RADIUS,COLR);

    line(buffer, Pa0, Pb0, Pa1, Pb1, COLR);
    line(buffer, Pa1, Pb1, Pa2, Pb2, COLR);
    line(buffer, Pa2, Pb2, Pa3, Pb3, COLR);
    line(buffer, Pa3, Pb3, Pa4, Pb4, COLR);
    pthread_mutex_unlock(&mux_Pr);

    blit(buffer, screen, OR, OR, OR, OR, buffer->w, buffer->h);

    destroy_bitmap(buffer);
}


