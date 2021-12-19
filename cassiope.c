// Copyright 2021 - Red Hat, Inc
// SPDX-License-Identifier: GPL-2.0-or-later


#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file(char* pathname)
{
     char buffer[4096] = { 0 }; // 4k for most page sizes
     int buffer_size = sizeof(buffer)/sizeof(buffer[0]);
     printf("%s:\n", pathname);
     int fd = open(pathname, O_RDONLY);
     if (fd < 0)
     {
          perror("error");
          return;
     }
     ssize_t ret = 0;
     while ((ret = read(fd, buffer, buffer_size)) > 0)
     {
          fputs(buffer, stdout);
     }
     puts("");
     if (ret < 0)
     {
          perror("error");
     }

     close(fd);
}

int main(int argc, char** argv)
{
     print_file("/etc/os-release");
     print_file("/proc/version");
     print_file("/proc/cpuinfo");
     print_file("/proc/meminfo");
     print_file("/proc/mounts");
     print_file("/proc/filesystems");
     print_file("/proc/cgroups");
     print_file("/proc/self/cgroup");
     print_file("/sys/fs/cgroup");

     return 0;
}
