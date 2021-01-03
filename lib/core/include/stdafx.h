#ifndef __INC_LIBTHECORE_STDAFX_H__
#define __INC_LIBTHECORE_STDAFX_H__

#ifndef __FreeBSD__
#define __USE_SELECT__
#ifdef __CYGWIN__
#define _POSIX_SOURCE 1
#endif
#endif

#include <stdio.h>
#include <string>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <dirent.h>

#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#include <sys/signal.h>
#include <sys/wait.h>

#include <pthread.h>
#include <semaphore.h>

#ifndef false
#define false	0
#define true	(!false)
#endif

#ifndef FALSE
#define FALSE	false
#define TRUE	(!FALSE)
#endif

#include "typedef.h"
#include "heart.h"
#include "fdwatch.h"
#include "socket.h"
#include "kstbl.h"
#include "hangul.h"
#include "buffer.h"
#include "signal.h"
#include "log.h"
#include "main.h"
#include "utils.h"
#include "crypt.h"
#include "memcpy.h"

#include <cstring>
#include <stdlib.h>

#endif // __INC_LIBTHECORE_STDAFX_H__
