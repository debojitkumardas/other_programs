#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "queue_ds.h"
#include <pthread.h>

typedef struct ThreadPool ThreadPool;
typedef struct ThreadJob ThreadJob;

struct ThreadPool {
    int num_threads;
    int active;
    /** Queue */
    Node* work;
    pthread_t *pool;
    pthread_mutex_t lock;
    pthread_cond_t signal;
};

struct ThreadJob {
    void* (*job)(void* arg);
};

ThreadPool ThreadPoolConst(int num_threads);
ThreadJob ThreadJobConst(void* (*job)(void* arg), void* arg);

#endif // !THREADPOOL_H
