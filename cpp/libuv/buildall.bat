
@set LIBUV=E:/Git/libuv

@rem gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 hello_uv.c -luv -lws2_32 -lpsapi -liphlpapi -o hello_uv
@rem gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 idle_basic.c -luv -lws2_32 -lpsapi -liphlpapi -o idle_basic
@rem gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 uvcat.c -luv -lws2_32 -lpsapi -liphlpapi -o uvcat
@rem gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 uvtee.c -luv -lws2_32 -lpsapi -liphlpapi -o uvtee
@rem gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 uvonchange.c -luv -lws2_32 -lpsapi -liphlpapi -o uvonchange
@rem gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 uvthread.c -luv -lws2_32 -lpsapi -liphlpapi -o uvthread
gcc -g -Wall -Wextra -Wno-unused-parameter -I%LIBUV%/include -L%LIBUV% -std=c99 uvlocks.c -luv -lws2_32 -lpsapi -liphlpapi -o uvlocks