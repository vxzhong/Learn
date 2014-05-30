#include <uv.h>
#include <stdio.h>
#include <unistd.h>

void hare(void *arg)
{
    int tracklen = *(int *)arg;

    while (tracklen--) {
        sleep(1);
        fprintf(stderr, "hare run in another step: %d.\n", tracklen);
    }

    fprintf(stderr, "hare run is finishing.\n");
}

void tortoise(void *arg)
{
    int tracklen = *(int *)arg;

    while (tracklen--) {
        sleep(3);
        fprintf(stderr, "tortoise run in another step: %d.\n", tracklen);
    }

    fprintf(stderr, "tortoise run is finishing.\n");
}

int main(int argc, char *argv[])
{
    int tracklen = 10;

    uv_thread_t id0;
    uv_thread_t id1;

    uv_thread_create(&id0, hare, &tracklen);
    uv_thread_create(&id0, tortoise, &tracklen);

    uv_thread_join(&id0);
    uv_thread_join(&id1);

    return 0;
}
