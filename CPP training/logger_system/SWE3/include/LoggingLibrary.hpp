#ifndef LOGGINGLIBRARY_HPP
#define LOGGINGLIBRARY_HPP
#include <string>
#include "LogLevel.hpp"
#include "LogConfig.hpp"

#include <sys/mman.h>
#include <semaphore.h>

#include <fcntl.h>
#include<unistd.h>

#define SHM_NAME "/my_shm_struct"
#define SEM_EMPTY "/sem_empty_struct"
#define SEM_FULL "/sem_full_struct"

#define SHM_KEY 0x1234
struct shmseg {
   LogLevel Severity;
   char AppName[128];
   char Message[128];
   char mode[128];
};

void ErrorLog(LogLevel level, const std::string& appTag, const std::string& message);

class LoggingLibrary {
public:
    LoggingLibrary(const LogConfig& config);
    void Log_write(LogLevel level, const std::string& appTag, const std::string& message);
    void writeToSharedMemory(LogLevel severity, std::string applicationName, std::string message, std::string mode);
private:
    LogConfig config;
    void writeToConsole(const std::string &formatted);
    void writeToFile(const std::string &formatted);
    std::string formatMessage(LogLevel level, const std::string &appTag, const std::string &message);
};

#endif // LOGGINGLIBRARY_HPP