#include "io.h"
void *Calloc(size_t n,size_t size)
{
	void *ptr;
	if ( (ptr = calloc(n ,size)) == NULL)
		perror("calloc()");
		exit(1);
	return ptr;
}

void Close(int fd)
{
  if (close(fd) == -1)
    err_sys("close error");
}

void Dup2(int fd1, int fd2)
{
  if (dup2(fd1, fd2) == -1)
    err_sys("dup2 error");
}

int Fcntl(int fd, int cmd, void *arg)
{
  int n;

  if ( (n = fcntl(fd, cmd, arg)) == -1)
    err_sys("fcntl error");
  return(n);
}

void * Malloc(size_t size)
{
  void  *ptr;

  if ( (ptr = malloc(size)) == NULL)
    err_sys("malloc error");
  return(ptr);
}
void Fstat(int fd, struct stat *ptr)
{
  if (fstat(fd, ptr) == -1)
    err_sys("fstat error");
}

off_t Lseek(int fd, off_t offset, int whence)
{
  off_t pos;

  if ( (pos = lseek(fd, offset, whence)) == (off_t) -1)
    err_sys("lseek error");
  return(pos);
}

 void * Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
  void  *ptr;

  if ( (ptr = mmap(addr, len, prot, flags, fd, offset)) == MAP_FAILED)
    err_sys("mmap error");
  return(ptr);
}

void Munmap(void *addr, size_t len)
{
  if (munmap(addr, len) == -1)
    err_sys("munmap error");
}


int Open(const char *pathname, int oflag, ...)
{
  int   fd;
  va_list ap;
  mode_t  mode;

  if (oflag & O_CREAT) {
    va_start(ap, oflag);    /* init ap to final named argument */
    mode = va_arg(ap, mode_t);
    if ( (fd = open(pathname, oflag, mode)) == -1)
      err_sys("open error for %s", pathname);
    va_end(ap);
  } else {
    if ( (fd = open(pathname, oflag)) == -1)
      err_sys("open error for %s", pathname);
  }
  return(fd);
}

int Ioctl(int fd, int request, void *arg)
{
  int   n;

  if ( (n = ioctl(fd, request, arg)) == -1)
    err_sys("ioctl error");
  return(n);  /* streamio of I_LIST returns value */
}

int Getopt(int argc, char *const *argv, const char *str)
{
  int   opt;

  if ( ( opt = getopt(argc, argv, str)) == '?')
    exit(1);    /* getopt() has already written to stderr */
  return(opt);
}

key_t Ftok(const char *pathname, int id)
{
  key_t key;

  if ( (key = ftok(pathname, id)) == -1)
    err_sys("ftok error for pathname \"%s\" and id %d", pathname, id);
  return(key);
}
void Ftruncate(int fd, off_t length)
{
  if (ftruncate(fd, length) == -1)
    err_sys("ftruncate error");
}



long Sysconf(int name)
{
  long  val;

  errno = 0;    /* in case sysconf() does not change this */
  if ( (val = sysconf(name)) == -1) {
    if (errno != 0)
      err_sys("sysconf error");
    else
      err_sys("sysconf: %d not defined", name);
  }
  return(val);
}

