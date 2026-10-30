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
    station->free=0;
}

void station_load_car(struct station *station, int count){
    pthread_mutex_t *aux = &station->mutex1;

    pthread_mutex_lock(aux);

    station->count=count;
    station->free=count;
    
    pthread_cond_broadcast(&station->car_left);
    
    while(station->free>0 || station->count>0 ){
        pthread_cond_wait(&station->car_left,aux);
    }

    station->free=0;
    pthread_mutex_unlock(aux);
    return;
}

void station_wait_for_car(struct station *station){
    pthread_mutex_t *aux = &station->mutex1;
    pthread_mutex_lock(aux);

    while(station->count==0){
        pthread_cond_wait(&station->all_seats,aux);
    }



    pthread_mutex_unlock(aux);
    return;
}

void station_on_board(struct station *station){
    pthread_mutex_t *aux = &station->mutex1;
    
    if(station->count==0)
        pthread_cond_wait(&station->car_left,aux);
    pthread_cond_signal(&station->all_seats);
    return;
}
