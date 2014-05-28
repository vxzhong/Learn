
@set LIBUV=E:/Git/libuv

@rem gcc -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% hello_uv.c -luv -lws2_32 -lpsapi -liphlpapi -o hello_uv
@rem gcc -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% idle_basic.c -luv -lws2_32 -lpsapi -liphlpapi -o idle_basic
gcc -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% uvcat.c -luv -lws2_32 -lpsapi -liphlpapi -o uvcat