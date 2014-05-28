#include <stdio.h>
#include <uv.h>
#include <unistd.h>
#include <sys/time.h>

int32_t counter = 0;

void wait_for_a_while(uv_idle_t* handle) {
    counter++;

    if (counter >= 100)
        uv_idle_stop(handle);

    struct timeval tv;

    gettimeofday(&tv, NULL);
    printf("%ld, %ld: run idle: %d\n", tv.tv_sec, tv.tv_usec, counter);
    usleep(1000);
}

int main() {
    uv_idle_t idler;

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    printf("Idling...\n");
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    return 0;
}
