#include <uv.h>
#include <stdio.h>
#include <assert.h>

void OnChange(uv_fs_event_t *handle, const char *filename, int events, int status) {
    fprintf(stderr, "Change detected in %s: ", handle->path);
    if (events == UV_RENAME)
        fprintf(stderr, "renamed");
    if (events == UV_CHANGE)
        fprintf(stderr, "changed");

    fprintf(stderr, " %s\n", filename ? filename : "");
    //system(command);
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
        return 1;
    }

    //const char *command = argv[1];

    for (int i = 1; i < argc; ++i) {
        fprintf(stderr, "Adding watch on %s\n", argv[i]);

        uv_fs_event_t *fs_event = (uv_fs_event_t*)malloc(sizeof(uv_fs_event_t));
        int r = uv_fs_event_init(uv_default_loop(), fs_event);
        assert(r == 0);
        r = uv_fs_event_start(fs_event, OnChange, argv[i], 0);
        assert(r == 0);
    }

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    return 0;
}
