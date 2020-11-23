//----------------------------------------

//	LIBRERIA PER TASK PERIODICHE

//----------------------------------------



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

//#include "ptask.h"

/*

struct timespec {	// struttura per il tempo definita da <math.h>, qui riportata per migliore comprensione del codice



	time_t	tv_sec;	//time_t di solito e' un intero a 32 bit,	tv = time variable

	long	tv_nsec;

};



struct sched_param {	// priorita' di un thread (va specificata attraverso una struttura) definita da <sched.h> e <pthread.h>



	int sched_priority;

};

*/



/*

void *task(void *arg) {		// schema di un task periodico



	//local state variables



	int ti;



	ti = get_task_index(arg);

	set_activation(ti);



	while(1) {



		//task body



		if (deadline_miss(ti))

			;	//FAI QUALCOSA

		wait_for_period(ti);

	}

}

*/

#ifndef PTASK
#define PTASK



#define NT 100



pthread_t		tid[NT];



struct task_par {	// parametri real-time

			// questa struttura va inizializzata prima di chiamare pthread_create() e va passata come argomento del thread

	int argument;		// argomento del task (codice identificativo)

	long wcet;		// (us)

	int period;		// (ms)

	int deadline;		// relativa (ms)

	int priority;		// in [0,99]

	int dmiss;		// numero di deadline miss

	struct timespec at;	// prossimo activation time

	struct timespec dl;	// deadline assoluta

};



struct task_par		tp[NT];



void time_copy(struct timespec *td, struct timespec ts) {	// copia la variabile temporale source ts in una variabile temporale 									// destination puntata da td

	td->tv_sec = ts.tv_sec;

	td->tv_nsec = ts.tv_nsec;

}



void time_add_ms(struct timespec *t, int ms) {	// la variabile temporale a cui aggiungo ms e' puntata da t



	t->tv_sec += ms/1000;

	t->tv_nsec += (ms%1000)*1000000;//1 milione di nsec = 1 ms



	if (t->tv_nsec > 1000000000) {//1 miliardo di nsec = 1 sec



		t->tv_nsec -= 1000000000;//1 miliardo

		t->tv_sec += 1;

	}

}



int time_cmp(struct timespec t1, struct timespec t2) {	// ritorna 0 se le due variabili temporali sono uguali, 1 se la prima

							// e' maggiore, -1 se la seconda e' maggiore

	if (t1.tv_sec > t2.tv_sec) return 1;

	if (t1.tv_sec < t2.tv_sec) return -1;

	if (t1.tv_nsec > t2.tv_nsec) return 1;

	if (t1.tv_nsec < t2.tv_nsec) return -1;

	return 0;

}



void set_activation(int id) {	// legge il tempo corrente e computa il prossimo activation time e la deadline assoluta del task id

				// NOTA: il timer non e' settato su interrupt

	struct timespec now;



	clock_gettime(CLOCK_MONOTONIC, &now);	// copia in now il valore del clock specificato da CLOCK_MONOTONIC



	time_copy(&(tp[id].at), now);

	time_copy(&(tp[id].dl), now);

	time_add_ms(&(tp[id].at), tp[id].period);

	time_add_ms(&(tp[id].dl), tp[id].deadline);

}



int get_task_index(void* arg) {		// NOTA: siccome l'argomento di un thread e' passato come un puntatore a void, tale puntatore deve

					// prima essere convertito in un puntatore a task_par

	struct task_par *t_p;		//??????????????????????????????????????????????????????????????????????????????????????????????????



	t_p = (struct task_par *)arg;

	return t_p->argument;

}



int deadline_miss(int id) {		// se il thread e' ancora in esecuzione quando ri-attivato, incrementa il valore di

					// dmiss e ritorna 1, altrimenti ritorna 0

	struct timespec now;



	clock_gettime(CLOCK_MONOTONIC, &now);



	if ( time_cmp(now, tp[id].dl) > 0 ) {	// se now e' maggiore del tempo di deadiline della task id



		tp[id].dmiss++;

		return 1;			// c'e' stato un deadline miss

	}

	return 0;				// non c'e' stato un deadline miss

}



void show_dmiss(int id) {



	printf("deadline miss della task %d: %d \n", id, tp[id].dmiss);

}



void wait_for_period(int id) {	// sospende la chiamata al thread fino alla prossima attivazione e, quando svegliato,

				// aggiorna l'activation time e la deadline

	clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &(tp[id].at), NULL);	// sospende l'esecuzione del thread chiamato fino a che

										// CLOCK_MONOTONIC non raggiunge il tempo specificato da &t.

										// TIMER_ABSTIME significa che t e' interpretato come assoluto

	time_add_ms(&(tp[id].at), tp[id].period);

	time_add_ms(&(tp[id].dl), tp[id].period);

}



int task_create( void* (*task)(void *), int id, int period, int drel, int prio ) {

		// puntatore a una funzione che ha come argomento un puntatore a void, e il tutto restituisce un puntatore a void

	pthread_attr_t	myattr;

	struct	sched_param mypar;	// sched_param contiene solo sched_priority

	int tret;



	tp[id].argument = id;

	tp[id].period = period;

	tp[id].deadline = drel;

	tp[id].priority = prio;

	tp[id].dmiss = 0;



	pthread_attr_init(&myattr);

	/*

	pthread_attr_setinheritsched(&myattr, PTHREAD_EXPLICIT_SCHED);

	pthread_attr_setschedpolicy(&myattr, SCHED_RR);

	*/

	mypar.sched_priority = tp[id].priority;

	pthread_attr_setschedparam(&myattr, &mypar);



	tret = pthread_create( &tid[id], &myattr, task, (void*)(&tp[id]) );



	return tret;

}



void wait_for_task_end(int id) {



	pthread_join(tid[id], NULL);

}

#endif
