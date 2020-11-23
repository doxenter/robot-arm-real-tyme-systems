//=================================================//
//                                                 //
//              LIBRERIA CALCOLI 3D                //
//                                                 //
//=================================================//


void *compute_task(void *arg) {		// schema di un task periodico

    int end=0;
    int ti;
	ti = get_task_index(arg);

	set_activation(ti);

	while(!end) {

        pthread_mutex_lock(&mux_q);
        Xr0 = ORIGINX;
        Yr0 = ORIGINY;
        Zr0 = ORIGINZ;
        pthread_mutex_unlock(&mux_q);

        pthread_mutex_lock(&mux_rot);
        Xr0v = cam_rotX(Xr0, Yr0, Zr0, rotx, rotz);
        Yr0v = cam_rotY(Xr0, Yr0, Zr0, rotx, rotz);
        Zr0v = cam_rotZ(Xr0, Yr0, Zr0, rotx, rotz);
        pthread_mutex_unlock(&mux_rot);

        pthread_mutex_lock(&mux_q);
        Xr1 = ORIGINX;
        Yr1 = ORIGINY;
        Zr1 = LZ01;
        pthread_mutex_unlock(&mux_q);

        pthread_mutex_lock(&mux_rot);
        Xr1v = cam_rotX(Xr1, Yr1, Zr1, rotx, rotz);
        Yr1v = cam_rotY(Xr1, Yr1, Zr1, rotx, rotz);
        Zr1v = cam_rotZ(Xr1, Yr1, Zr1, rotx, rotz);
        pthread_mutex_unlock(&mux_rot);

        pthread_mutex_lock(&mux_q);
        Xr2 = LX12 * cos(radiant_conv(q1)) * cos(radiant_conv(q2));
        Yr2 = LX12 * sin(radiant_conv(q1)) * cos(radiant_conv(q2));
        Zr2 = LZ01 - LX12 * sin(radiant_conv(q2));
        pthread_mutex_unlock(&mux_q);

        pthread_mutex_lock(&mux_rot);
        Xr2v = cam_rotX(Xr2, Yr2, Zr2, rotx, rotz);
        Yr2v = cam_rotY(Xr2, Yr2, Zr2, rotx, rotz);
        Zr2v = cam_rotZ(Xr2, Yr2, Zr2, rotx, rotz);
        pthread_mutex_unlock(&mux_rot);

        pthread_mutex_lock(&mux_q);
        Xr3 = (LX12 + LX23 * cos(radiant_conv(q3))) * cos(radiant_conv(q1)) * cos(radiant_conv(q2)) ;
        Yr3 = (LX12 ) * sin(radiant_conv(q1)) * cos(radiant_conv(q2)) + LX23 * sin(radiant_conv(q3));
        Zr3 = LZ01 - (LX12 + LX23) * sin(radiant_conv(q2)) ;
        pthread_mutex_unlock(&mux_q);

        pthread_mutex_lock(&mux_rot);
        Xr3v = cam_rotX(Xr3, Yr3, Zr3, rotx, rotz);
        Yr3v = cam_rotY(Xr3, Yr3, Zr3, rotx, rotz);
        Zr3v = cam_rotZ(Xr3, Yr3, Zr3, rotx, rotz);
        pthread_mutex_unlock(&mux_rot);

        pthread_mutex_lock(&mux_q);
        Xr4 = (LX12 + (LX23 + LX34 * cos(radiant_conv(q4))) * cos(radiant_conv(q3))) * cos(radiant_conv(q1)) * cos(radiant_conv(q2));
        Yr4 = (LX12 + (LX23 + LX34 * sin(radiant_conv(q4))) * sin(radiant_conv(q3))) * cos(radiant_conv(q1)) * cos(radiant_conv(q2));
        Zr4 = LZ01 - (LX12 + LX23 ) * sin(radiant_conv(q2)) + LX34 * sin(radiant_conv(q4)) ;
        pthread_mutex_unlock(&mux_q);

        pthread_mutex_lock(&mux_rot);
        Xr4v = cam_rotX(Xr4, Yr4, Zr4, rotx, rotz);
        Yr4v = cam_rotY(Xr4, Yr4, Zr4, rotx, rotz);
        Zr4v = cam_rotZ(Xr4, Yr4, Zr4, rotx, rotz);
        pthread_mutex_unlock(&mux_rot);

        pthread_mutex_lock(&mux_Pr);
        Pa0 = project_x(dpov, Xr0v, Yr0v, Zr0v) ;
        Pb0 = project_y(dpov, Xr0v, Yr0v, Zr0v) ;
        pthread_mutex_unlock(&mux_Pr);

        pthread_mutex_lock(&mux_Pr);
        Pa1 = project_x(dpov, Xr1v, Yr1v, Zr1v) ;
        Pb1 = project_y(dpov, Xr1v, Yr1v, Zr1v) ;
        pthread_mutex_unlock(&mux_Pr);

        pthread_mutex_lock(&mux_Pr);
        Pa2 = project_x(dpov, Xr2v, Yr2v, Zr2v) ;
        Pb2 = project_y(dpov, Xr2v, Yr2v, Zr2v) ;
        pthread_mutex_unlock(&mux_Pr);

        pthread_mutex_lock(&mux_Pr);
        Pa3 = project_x(dpov, Xr3v, Yr3v, Zr3v) ;
        Pb3 = project_y(dpov, Xr3v, Yr3v, Zr3v) ;
        pthread_mutex_unlock(&mux_Pr);

        pthread_mutex_lock(&mux_Pr);
        Pa4 = project_x(dpov, Xr4v, Yr4v, Zr4v) ;
        Pb4 = project_y(dpov, Xr4v, Yr4v, Zr4v) ;
        pthread_mutex_unlock(&mux_Pr);

        if (deadline_miss(ti)){
            Dflag_c = true;
            Dmiss_c ++;
            }
        else{
            Dflag_c = false;
            }

        wait_for_period(ti);

	}
}
//======================================================================================//
