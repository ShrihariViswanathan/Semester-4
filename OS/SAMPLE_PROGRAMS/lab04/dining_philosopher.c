#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick up chopsticks
        if (id == NUM_PHILOSOPHERS - 1) {
            // The last philosopher picks up right then left to avoid deadlock
            pthread_mutex_lock(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
            pthread_mutex_lock(&chopsticks[id]);
        } else {
            pthread_mutex_lock(&chopsticks[id]);
            pthread_mutex_lock(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
        }

        printf("Philosopher %d is eating!\n", id);
        sleep(1);

        // Put down chopsticks
        pthread_mutex_unlock(&chopsticks[id]);
        pthread_mutex_unlock(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);

        printf("Philosopher %d finished eating and resumed thinking.\n", id);
    }
}

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
        ids[i] = i;
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
