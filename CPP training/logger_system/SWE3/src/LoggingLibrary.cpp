#include "LoggingLibrary.hpp"
#include "RemoteLoggingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>

#include<sys/ipc.h>
#include<sys/shm.h>
#include <sys/stat.h>
#include<string.h>

LoggingLibrary::LoggingLibrary(const LogConfig &config)  {
    this->config = config;
}

void LoggingLibrary::Log_write(LogLevel level, const std::string &appTag, const std::string &message)
{
    std::string formatted = formatMessage(level, appTag, message);
    if (level >= config.consoleLevel)
    {
        writeToConsole(formatted);
    }
    if (level >= config.fileLevel)
    {
        writeToFile(formatted);
    }
    if (level >= config.networkLevel)
    {

        RemoteLoggingNetwork remoteLogger(config);

        remoteLogger.writeToNetwork(formatted);
    }
}

void LoggingLibrary::writeToConsole(const std::string& formatted) {
    std::cout << formatted << std::endl;
}

void LoggingLibrary::writeToFile(const std::string& formatted) {
    static int maximum = config.fileSize;
    try{
        // std::cout<<"max = "<<maximum<<std::endl;
        if(maximum>0)
        {
            maximum--;
            std::ofstream file(config.filePath, std::ios::app);
            if (!file.is_open()) {
            throw std::runtime_error("Failed to open log file: /logs" + config.filePath);
            }
            file << formatted << std::endl;
            file.close();
            // std::cout<<"append "<<std::endl;
        }
        else
        {
            std::ofstream file(config.filePath);
            if (!file.is_open()) {
            throw std::runtime_error("Failed to open log file: /logs" + config.filePath);
            }
            maximum = config.fileSize -1;
            file << formatted << std::endl;
            file.close();
            // std::cout<<"open "<<std::endl;
        } 
    }catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    }  
}

std::string LoggingLibrary::formatMessage(LogLevel level, const std::string& appTag, const std::string& message) {
    std::ostringstream oss;
    oss << "[" << __DATE__ << " GMT " << __TIME__ << "] " << appTag << ": " << logLevelToString(level) << " : " << message;
    return oss.str();
}

void LoggingLibrary::writeToSharedMemory(LogLevel severity, std::string applicationName, std::string A_message, std::string A_mode)
{
    //PIPE NOT working
    // const char *fifo_path = "/tmp/myfifo";
    // mkfifo(fifo_path, 0666); // Create the FIFO

    // int fd = open(fifo_path, O_WRONLY);
    // struct shmseg pipeline;
    
    // pipeline.Severity = severity;
    // memcpy(pipeline.AppName, applicationName.c_str(), applicationName.size());
    // memcpy(pipeline.Message, A_message.c_str(), A_message.size());
    // memcpy(pipeline.mode, A_mode.c_str(), A_mode.size());

    // write(fd, (void*) &pipeline, sizeof(pipeline));
    // memset((void*)&pipeline,0, sizeof(pipeline));
    // sleep(1);
    // close(fd);

    //SHARED MEMORY & SEMAPHORE

    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(shmseg));
    shmseg* shm_ptr = (shmseg*) mmap(0, sizeof(shmseg), PROT_WRITE, MAP_SHARED, shm_fd, 0);
    std::cout<<"entered shared mem"<<std::endl;
    sem_t* sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1);
    sem_t* sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);

    memset((void*)shm_ptr, 0, sizeof(shmseg));
        std::cout<<"entered shared mem2"<<std::endl;

            sem_wait(sem_empty);
            std::cout<<"copied severity"<<std::endl;
            shm_ptr->Severity = severity;
            std::cout<<"copied app"<<std::endl;
            
            strncpy(shm_ptr->AppName, applicationName.c_str(), sizeof(shm_ptr->AppName) - 1);
            shm_ptr->AppName[sizeof(shm_ptr->AppName) - 1] = '\0';


            std::cout<<"copied message"<<std::endl;
            strncpy(shm_ptr->Message, A_message.c_str(), sizeof(shm_ptr->Message) - 1);
            shm_ptr->Message[sizeof(shm_ptr->Message) - 1] = '\0';

            strncpy(shm_ptr->mode, A_mode.c_str(), sizeof(shm_ptr->mode) - 1);
            shm_ptr->mode[sizeof(shm_ptr->mode) - 1] = '\0';

            sem_post(sem_full);
            std::cout<<"waiting for receiver to read"<<std::endl;
        sleep(1);

    munmap(shm_ptr, sizeof(shmseg));
    close(shm_fd);
    sem_close(sem_empty);
    sem_close(sem_full);

}

void ErrorLog(LogLevel level, const std::string& appTag, const std::string& message)
{
    LogConfig config = LogConfig::loadFromFile("../config/logger_config.yaml");
    LoggingLibrary logger(config);
    // std::cout<<"mode = "<<config.mode<<std::endl;
    if(config.mode == "standalone")
    {
        logger.Log_write(level, appTag, message);
    }
    else
    {
        logger.writeToSharedMemory(level, appTag, message, config.mode);
    }

}