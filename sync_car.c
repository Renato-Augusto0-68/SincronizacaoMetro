#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "sync_car.h"

void station_init(struct station *station){
    pthread_mutex_t *aux = &(station->mutex1);
    pthread_mutex_init(aux,NULL);

}

void station_load_car(struct station *station, int count){
}

void station_wait_for_car(struct station *station){
}

void station_on_board(struct station *station){
}
