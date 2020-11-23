//=================================================//
//                                                 //
//         LIBRERIA LETTURA INPUT                  //
//                                                 //
//=================================================//

//======================================================================================//
pthread_mutex_t   mux_dist = PTHREAD_MUTEX_INITIALIZER;

char s[10];

void *inputread_task(void *arg) {


    int end=0;
	int ti;
	char scan;
	ti = get_task_index(arg);

	while(!end){
    scan = get_scancode();

    switch (scan) {
        case KEY_Q:
            rectfill(screen,IDN , 500, WIDTH ,510, COL0);

            pthread_mutex_lock(&mux_q);
            q1 ++;
            Qflag = true;
            sprintf(s, "%5.2f\n", q1);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 500, COL7, TR);
            break;

        case KEY_W:
            rectfill(screen,IDN , 500, WIDTH ,510, COL0);

            pthread_mutex_lock(&mux_q);
            q1 --;
            Qflag = true;
            sprintf(s, "%5.2f\n", q1);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 500, COL7, TR);
            break;

        case KEY_A:
            rectfill(screen,IDN , 520, WIDTH ,530, COL0);

            pthread_mutex_lock(&mux_q);
            q2 ++;
            Qflag = true;
            sprintf(s, "%5.2f\n", q2);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 520, COL7, TR);
            break;

        case KEY_S:
            rectfill(screen,IDN , 520, WIDTH ,530, COL0);

            pthread_mutex_lock(&mux_q);
            q2 --;
            Qflag = true;
            sprintf(s, "%5.2f\n", q2);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 520, COL7, TR);
            break;

        case KEY_D:
            rectfill(screen,IDN , 540, WIDTH ,550, COL0);

            pthread_mutex_lock(&mux_q);
            q3 ++;
            Qflag = true;
            sprintf(s, "%5.2f\n", q3);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 540, COL7, TR);
            break;

        case KEY_F:
            rectfill(screen,IDN , 540, WIDTH ,550, COL0);

            pthread_mutex_lock(&mux_q);
            q3 --;
            Qflag = true;
            sprintf(s, "%5.2f\n", q3);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 540, COL7, TR);
            break;

        case KEY_E:
            rectfill(screen,IDN , 560, WIDTH ,570, COL0);

            pthread_mutex_lock(&mux_q);
            q4 --;
            Qflag = true;
            sprintf(s, "%5.2f\n", q4);
            pthread_mutex_unlock(&mux_q);

            textout_ex(screen, font, s, IDN, 560, COL7, TR);
            break;

        case KEY_R:
            rectfill(screen,IDN , 560, WIDTH ,570, COL0);

            pthread_mutex_lock(&mux_q);
            q4 ++;
            Qflag = true;
            sprintf(s, "%5.2f\n", q4);

            pthread_mutex_unlock(&mux_q);
            textout_ex(screen, font, s, IDN, 560, COL7, TR);
            break;

        case KEY_LEFT:
            rectfill(screen,IDN , 580, WIDTH ,590, COL0);

            pthread_mutex_lock(&mux_rot);
            rotz ++;
            camflag = true;
            sprintf(s, "%5.2f\n", rotz);
            pthread_mutex_unlock(&mux_rot);

            textout_ex(screen, font, s, IDN, 580, COL7, TR);
            break;

        case KEY_RIGHT:
            rectfill(screen,IDN , 580, WIDTH ,590, COL0);

            pthread_mutex_lock(&mux_rot);
            rotz --;
            camflag = true;
            sprintf(s, "%5.2f\n", rotz);
            pthread_mutex_unlock(&mux_rot);

            textout_ex(screen, font, s, IDN, 580, COL7, TR);
            break;

        case KEY_UP:
            rectfill(screen,IDN , 600, WIDTH ,610, COL0);

            pthread_mutex_lock(&mux_rot);
            rotx ++;
            camflag = true;
            sprintf(s, "%5.2f\n", rotx);
            pthread_mutex_unlock(&mux_rot);

            textout_ex(screen, font, s, IDN, 600, COL7, TR);
            break;

        case KEY_DOWN:
            rectfill(screen,IDN , 600, WIDTH ,610, COL0);

            pthread_mutex_lock(&mux_rot);
            rotx --;
            camflag = true;
            sprintf(s, "%5.2f\n", rotx);
            pthread_mutex_unlock(&mux_rot);

            textout_ex(screen, font, s, IDN, 600, COL7, TR);
            break;

        case KEY_M:
            rectfill(screen,IDN , 620, WIDTH ,630, COL0);

            if (dpov > DPOVMIN){
            pthread_mutex_lock(&mux_dist);
            dpov = dpov - 80;
            camflag = true ;
            sprintf(s, "%5.2f\n", dpov);
            pthread_mutex_unlock(&mux_dist);
            }

            textout_ex(screen, font, s, IDN, 620, COL7, TR);
            break;

        case KEY_N:
            rectfill(screen,IDN , 620, WIDTH ,630, COL0);

            if (dpov < DPOVMAX){
            pthread_mutex_lock(&mux_dist);
            dpov = dpov + 80;
            camflag = true;
            sprintf(s, "%5.2f\n", dpov);
            pthread_mutex_unlock(&mux_dist);
            }

            textout_ex(screen, font, s, IDN, 620, COL7, TR);
            break;

        default: break;

        }while(scan != KEY_ESC);

		if (deadline_miss(ti)){
            Dflag_i = true;
            Dmiss_i ++;
            }
        else{
            Dflag_i = false;
            }

        wait_for_period(ti);

    }
}
//======================================================================================//

