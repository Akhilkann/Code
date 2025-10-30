#ifndef LOGGINGSERVICE_HPP
#define LOGGINGSERVICE_HPP
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <string>
#include <unistd.h>
#include "LoggingLibrary.hpp"

#include <fcntl.h>
#include <sys/stat.h>

#include <sys/mman.h>
#include <semaphore.h>


#define SHM_NAME "/my_shm_struct"
#define SEM_EMPTY "/sem_empty_struct"
#define SEM_FULL "/sem_full_struct"

struct LogMessage {
    LogLevel level;
   char appTag[128];
   char message[128];
   char mode[128];
};
#endif //LOGGINGSERVICE_HPP