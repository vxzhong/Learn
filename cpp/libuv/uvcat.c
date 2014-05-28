#include <uv.h>
#include <fcntl.h>
#include <stdio.h>

static uv_fs_t open_req;
static uv_fs_t read_req;
static uv_fs_t write_req;

char buf[1024];

void OnRead(uv_fs_t *req);

void OnWrite(uv_fs_t *req)
{
    uv_fs_req_cleanup(req);

    if (req->result < 0) {
        fprintf(stderr, "Failed to write file.\n");
    } else {
        uv_buf_t uvbuf = uv_buf_init(buf, sizeof(buf));

        uv_fs_read(uv_default_loop(), &read_req, open_req.result, &uvbuf, 1, -1, OnRead);
    }
}

void OnRead(uv_fs_t *req)
{
    uv_fs_req_cleanup(req);

    if (req->result < 0) {
        fprintf(stderr, "Failed to read file.\n");
    } else if (req->result == 0) {
        uv_fs_t close_req;
        uv_fs_close(uv_default_loop(), &close_req, open_req.result, NULL);
    } else {
        uv_buf_t uvbuf = uv_buf_init(buf, req->result);

        uv_fs_write(uv_default_loop(), &write_req, 1, &uvbuf, 1, -1, OnWrite);
    }
}

void OnOpen(uv_fs_t *req)
{
    fprintf(stdout, "open file id: %d.\n", req->result);
    if (req->result < 0) {
        fprintf(stderr, "Failed to open file: %s\n", req->path);
    } else {
        uv_buf_t uvbuf = uv_buf_init(buf, sizeof(buf));
        uv_fs_read(uv_default_loop(), &read_req, req->result, &uvbuf, 1, -1, OnRead);
    }

    uv_fs_req_cleanup(req);
}

int main(int argc, char *argv[])
{
    if (argc < 2) return 0;

    uv_fs_open(uv_default_loop(), &open_req, argv[1], O_RDONLY, 0, OnOpen);
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    return 0;
}
