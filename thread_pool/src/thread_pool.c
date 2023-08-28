#include "../hdr/thread_pool.h"
#include <pthread.h>
#include <stdlib.h>

void* ThreadJobFunc(void* arg) {
    //
}

ThreadPool ThreadPoolConst(int num_threads) {
    ThreadPool thread_pool;

    thread_pool.num_threads = num_threads;
    thread_pool.active = 1;
    thread_pool.pool = (pthread_t*)malloc(num_threads * sizeof(pthread_t));

    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&thread_pool.pool[i], NULL, ThreadJobFunc, NULL);
    }

    thread_pool.work = CreateNode(0);
    thread_pool.lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    thread_pool.signal = (pthread_cond_t)PTHREAD_COND_INITIALIZER;

    return thread_pool;
};
