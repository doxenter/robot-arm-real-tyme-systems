//=================================================//
//      ROBOT_DEMO REAL TIME APPLICATION           //
//   simulation of a robot arm in 3d space         //
//                                                 //
//=================================================//
//=================================================//
//standard lib inclusion
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//custom lib inclusion
#include "support_lib.h"
#include "ptask.h"
#include "visual_task.h"
#include "compute_task.h"
#include "inputread_task.h"

//constant header inclusion
#include "global_constants.h"

int end = 0;

//======================================================================================//
int main() {

    char scan;

    init();

    do {
        scan = get_scancode();

        task_create(inputread_task, 1, IPER ,IDREL ,IPRIO);
        task_create(visual_task, 2, VPER ,VDREL ,VPRIO);
        task_create(compute_task , 3, CPER , CDREL, CPRIO);

        } while(scan != KEY_ESC);

    allegro_exit();
    return 0;

    }

//======================================================================================//
















