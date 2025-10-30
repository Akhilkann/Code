
#include "LoggingService.hpp"


  int main() 
  {

    // const char *fifo_path = "/tmp/myfifo";
    // mkfifo(fifo_path, 0666); // Create the FIFO if not already created

    // int fd = open(fifo_path, O_RDONLY);
    // struct LogMessage LogMsg;
    // // while(1)
    // // {
    // for(int i =0; i<20; i++){
    //   read(fd, (void*)&LogMsg, sizeof(LogMsg));
    //   std::cout<<" " <<LogMsg.appTag<<" "<<LogMsg.message<<std::endl;
    //    memset((void*)&LogMsg,0, sizeof(LogMsg));
    // }
    // // }
    
    // close(fd);


    int shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    LogMessage* shm_ptr = (LogMessage*) mmap(0, sizeof(LogMessage), PROT_READ, MAP_SHARED, shm_fd, 0);

    sem_t* sem_empty = sem_open(SEM_EMPTY, 0);
    sem_t* sem_full = sem_open(SEM_FULL, 0);

    while(1)
    {
      if(sem_trywait(sem_full) == 0)
      {
        sem_trywait(sem_full);
        LogConfig config = LogConfig::loadFromFile("../config/logger_config.yaml");
        LoggingLibrary logger_from_service(config);
        //std::cout<<"waiting for sender to send"<<std::endl;
        //ErrorLog(shm_ptr->level, shm_ptr->appTag, shm_ptr->message);
        //std::cout<<" "<<shm_ptr->appTag<<" "<<shm_ptr->message<<std::endl;
        logger_from_service.Log_write(shm_ptr->level,shm_ptr->appTag,shm_ptr->message);
        sem_post(sem_empty);
        //std::cout<<"read complete"<<std::endl;
      }
      sleep(1);
    }

    munmap(shm_ptr, sizeof(LogMessage));
    close(shm_fd);
    sem_close(sem_empty);
    sem_close(sem_full);

    // Cleanup
    shm_unlink(SHM_NAME);
    sem_unlink(SEM_EMPTY);
    sem_unlink(SEM_FULL);

    return 0;
}
