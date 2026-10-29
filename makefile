sync_car: sync_car.c sync_car.h
	gcc -pthread sync_car-runner.c -o sync_car sync_car.c

run: sync_car
	./sync_car

clean:
	rm -f sync_car *.o

.PHONY: run clean