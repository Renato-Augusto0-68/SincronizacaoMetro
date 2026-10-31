#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include "sync_car.h"

void station_init(struct station *station){
    pthread_mutex_t *aux = &(station->mutex1);
    pthread_cond_t *aux2 = &(station->car_here); // car[0]
    pthread_cond_t *aux3 = &(station->all_seats); //car[1]
    pthread_mutex_init(aux,NULL);
    pthread_cond_init(aux2,NULL);
    pthread_cond_init(aux3,NULL);
    station->free_p=0;
    station->passageers=0;
    station->on_board=0;
}

void station_load_car(struct station *station, int count){
    pthread_mutex_t *aux = &station->mutex1;

    pthread_mutex_lock(aux);

    if(count<0){
        station->free_p=0;
        pthread_mutex_unlock(aux);
        return;
    }
    station->free_p=count;
    station->on_board=0;

    /*if(station->passageers>0 && station->free_p>0){
        pthread_cond_broadcast(&station->car_here);
    
        while((station->free_p>0 && station->passageers>0) || station->on_board>0){
            pthread_cond_wait(&station->all_seats,aux);
        }
    }*/
    while(station->free_p>0 && station->passageers>0){
        pthread_cond_broadcast(&station->car_here);
        pthread_cond_wait(&station->all_seats,aux);
    }
    station->free_p=0;
    pthread_mutex_unlock(aux);
    return;

}

void station_wait_for_car(struct station *station){
    pthread_mutex_t *aux = &station->mutex1;
    pthread_mutex_lock(aux);

    station->passageers++;

    while(station->free_p==0){
        pthread_cond_wait(&station->car_here,aux);
    }
    station->free_p--;
    station->passageers--;
    station->on_board++;
    pthread_mutex_unlock(aux);
    return;
    
}

void station_on_board(struct station *station){
    pthread_mutex_t *aux = &station->mutex1;
    pthread_mutex_lock(aux);
    station->on_board--;
    if (station->on_board<0){
        pthread_mutex_unlock(aux);
        return;
    }

    if(station->on_board==0 && (station->free_p==0|| station->passageers==0))
        pthread_cond_signal(&station->all_seats);
    
    pthread_mutex_unlock(aux);
}
