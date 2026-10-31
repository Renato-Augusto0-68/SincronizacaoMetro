#ifndef SYNC_CAR_H
#define SYNC_CAR_H
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct station{
    pthread_mutex_t mutex1;
    pthread_cond_t car_here;
    pthread_cond_t all_seats;
    int on_board;
    int free_p;
    int passageers;
}station;

void station_init(struct station *station);

void station_load_car(struct station *station, int count);

void station_wait_for_car(struct station *station);

void station_on_board(struct station *station);

#endif