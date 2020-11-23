//=================================================//
//                                                 //
//      TASK GRAFICO : GETISCE L'OUTPUT VISIVO     //
//                     DEL ROBOT                   //
//=================================================//

//======================================================================================//
pthread_mutex_t   mux_cam = PTHREAD_MUTEX_INITIALIZER;

void *visual_task(void *arg) {

    int end=0;

	int ti;

	ti = get_task_index(arg);

	set_activation(ti);

	while(!end) {

        float Dflag = Dflag_c + Dflag_i + Dflag_v;

        if (Dflag = true){
            refresh_dmiss();
            Dflag_c = false;
            Dflag_i = false;
            Dflag_v = false;
        }

        if (camflag != false || Qflag != false){
            refresh_ambient();
            pthread_mutex_lock(&mux_cam);
            camflag = false;
            pthread_mutex_unlock(&mux_cam);
            }
        else{
            camflag = false;
            }

        if ( Qflag = true){
            refresh_points_value();
            Qflag = false;
        }



		if (deadline_miss(ti)){
            Dflag_v = true;
            Dmiss_v ++;
            }
        else{
            Dflag_v = false;
            }

		wait_for_period(ti);

    }


}


