#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "sync_car.h"

void station_init(struct station *station){
    pthread_mutex_t *aux = &(station->mutex1);
    pthread_cond_t *aux2 = &(station->car_left);
    pthread_cond_t *aux3 = &(station->all_seats);
    pthread_mutex_init(aux,NULL);
    pthread_cond_init(aux2,NULL);
    pthread_cond_init(aux3,NULL);
    station->count=0;
}

void station_load_car(struct station *station, int count){
    pthread_mutex_t *aux = &station->mutex1;

    pthread_mutex_lock(aux);

    station->count=count;
    while(count==0 || station->count!=0 ){
        pthread_mutex_lock(aux)
    }

}

void station_wait_for_car(struct station *station){



}

void station_on_board(struct station *station){

}
