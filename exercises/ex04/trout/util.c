#include "trout.h"

void err_doit (int errnoflag, int level, char *fmt, va_list ap)
{
  int errno_save, n;
  char buf[MAXLINE];

  errno_save = errno;             /* value caller might want printed */
  vsnprintf (buf, sizeof(buf), fmt, ap);
  n = strlen (buf);
  if (errnoflag)
    snprintf (buf+n, sizeof(buf) - n, ": %s", strerror(errno_save));
  strcat (buf, "\n");

  fflush (stdout);
  fputs (buf, stderr);
  fflush (stderr);
}

void err_sys (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  err_doit (1, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(1);
}

void err_quit (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  err_doit (0, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(1);
}


Sigfunc *signal(int signo, Sigfunc *func)
{
  struct sigaction act, oact;

  act.sa_handler = func;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  if (signo == SIGALRM) {
    act.sa_flags |= SA_INTERRUPT;     /* SunOS 4.x (and Linux, apparently) */
  }
  if (sigaction(signo, &act, &oact) < 0)
    return(SIG_ERR);
  return(oact.sa_handler);
}

Sigfunc *Signal(int signo, Sigfunc *func)	/* for our signal() function */
{
  Sigfunc *sigfunc;

  if ( (sigfunc = signal(signo, func)) == SIG_ERR)
    err_sys("signal error");
  return(sigfunc);
}

void *Malloc(size_t size)
{
  void	*ptr;

  if ( (ptr = malloc(size)) == NULL)
    err_sys("malloc error");
  return(ptr);
}

void *Calloc(size_t n, size_t size)
{
  void	*ptr;

  if ( (ptr = calloc(n, size)) == NULL)
    err_sys("calloc error");
  return(ptr);
}

void Gettimeofday(struct timeval *tv, void *foo)
{
  if (gettimeofday(tv, foo) == -1)
    err_sys("gettimeofday error");
  return;
}

void Pipe(int *fds)
{
  if (pipe(fds) < 0)
    err_sys("pipe error");
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
  if (bind(fd, sa, salen) < 0)
    err_sys("bind error");
}

void Setsockopt(int fd, int level, int optname, const void *optval,
		socklen_t optlen)
{
  if (setsockopt(fd, level, optname, optval, optlen) < 0)
    err_sys("setsockopt error");
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
  ssize_t n;

  if ( (n = read(fd, ptr, nbytes)) == -1)
    err_sys("read error");
  return(n);
}

void Write(int fd, void *ptr, size_t nbytes)
{
  if (write(fd, ptr, nbytes) != nbytes)
    err_sys("write error");
}

ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr)
{
  ssize_t n;

  n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr);
  if (n < 0)
    err_sys("recvfrom error");
  return(n);
}
