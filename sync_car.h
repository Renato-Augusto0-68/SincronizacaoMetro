#ifndef SYNC_CAR_H
#define SYNC_CAR_H
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct station{
    int count;
}station;

void station_init();

void station_load_car(struct station *station, int count);

void station_wait_for_car(struct station *station);

void station_on_board(struct station *station);

#endif