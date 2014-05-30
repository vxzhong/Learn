#include <uv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>


void buf_alloc(uv_handle_t* handle, size_t size, uv_buf_t* buf)
{
    buf->base = malloc(size);
    buf->len = size;
}

void buf_free(const uv_buf_t* buf)
{
    free(buf->base);
}

uv_pipe_t stdin_pipe;
uv_pipe_t stdout_pipe;
uv_pipe_t file_pipe;


typedef struct write_req_s {
    uv_write_t      req;
    uv_buf_t        *bufs;
    unsigned int    nbufs;
} write_req_t;


void FreeWriteReq(write_req_t *req)
{
    for (unsigned int i = 0; i < req->nbufs; i++) {
        free(req->bufs->base);
    }

    free(req->bufs);

    free(req);
}

void OnWriteStdout(uv_write_t* req, int status)
{
    (void)status;
    FreeWriteReq((write_req_t*) req);
}

void OnWriteFile(uv_write_t* req, int status)
{
    (void)status;
    FreeWriteReq((write_req_t*) req);
}

int write_data(uv_stream_t* handle, const uv_buf_t bufs[], unsigned int nbufs, uv_write_cb cb)
{
    write_req_t *req = malloc(sizeof(write_req_t));

    req->bufs = malloc(sizeof(uv_buf_t) * nbufs);
    req->nbufs = nbufs;
    for (unsigned int i = 0; i < nbufs; i++) {
        req->bufs[i] = uv_buf_init(malloc(bufs[i].len), bufs[i].len);
        memcpy(req->bufs[i].base, bufs[i].base, bufs[i].len);
    }

    return uv_write((uv_write_t *)req, handle, req->bufs, req->nbufs, cb);
}

void OnRead(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf)
{
    printf("nread=%d.\n", nread);
    if (nread == UV_EOF) {
        uv_close((uv_handle_t *) &stdin_pipe, NULL);
        uv_close((uv_handle_t *) &stdout_pipe, NULL);
        uv_close((uv_handle_t *) &file_pipe, NULL);
    } else {
        write_data((uv_stream_t *) &stdout_pipe, buf, 1, OnWriteStdout);
        write_data((uv_stream_t *) &stdout_pipe, buf, 1, OnWriteFile);
    }

    if (buf->base) {
        buf_free(buf);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int r = uv_pipe_init(uv_default_loop(), &stdin_pipe, 0);
    assert(r==0);
    uv_pipe_open(&stdin_pipe, 0);

    uv_pipe_init(uv_default_loop(), &stdout_pipe, 0);
    uv_pipe_open(&stdin_pipe, 1);

  printf("%d\n", uv_guess_handle(0));

    uv_fs_t file_req;
    int fd = uv_fs_open(uv_default_loop(), &file_req, argv[1], O_WRONLY | O_CREAT, 0644, NULL);

    uv_pipe_init(uv_default_loop(), &file_pipe, 0);
    uv_pipe_open(&file_pipe, fd);

    printf("hhhhhhhhhh\n");
    uv_read_start((uv_stream_t*) &stdin_pipe, buf_alloc, OnRead);

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    return 0;
}
