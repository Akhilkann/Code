cmake_minimum_required(VERSION 3.10)
project(logging_framework)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
)
set(COMMON
    src/LogConfig.cpp
    src/LoggingLibrary.cpp
    src/LogLevel.cpp
    src/RemoteLoggingNetwork.cpp
)
set(SERVICES
    src/LoggingService.cpp    
)
set(SHM 
    
)


# Add executable
add_executable(logging_framework ${SOURCES} ${COMMON})
add_executable(client_framework ${SERVICES} ${COMMON})
#add_executable(shm_framework ${SHM} ${COMMON})

# Link yaml-cpp library
find_package(yaml-cpp REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(logging_framework yaml-cpp Threads::Threads)
target_link_libraries(client_framework yaml-cpp Threads::Threads)
#target_link_libraries(shm_framework Threads::Threads)
