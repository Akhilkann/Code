#include<iostream>
#include "LoggingLibrary.hpp"

int main()
{
    
    ErrorLog(LogLevel::CRT, "speedo", "lookup table not correct\n");
    ErrorLog(LogLevel::CRT, "das", "lane keep warning cannot be triggered\n");
    ErrorLog(LogLevel::CRT, "warning", "warning text cannot be parsed\n");
    ErrorLog(LogLevel::CRT, "diag", "engine malfunction error cannot be erased\n");

    ErrorLog(LogLevel::ERR, "chime", "cannot play chime 101\n");
    ErrorLog(LogLevel::ERR, "acc", "Adaptive Cruise control config not enabled\n");
    ErrorLog(LogLevel::ERR, "hilldescent", "feature not working\n");

    ErrorLog(LogLevel::WRN, "pers", "file cannot be opened\n");
    ErrorLog(LogLevel::WRN, "perimeteralarm", "sensors not live\n");
    ErrorLog(LogLevel::WRN, "revmatch", "speed data from speedo not received yet\n");

    ErrorLog(LogLevel::INF, "telltale", "freq of blinking not correct\n");
    ErrorLog(LogLevel::INF, "neutraltow", "tow function cannot be enabled\n");
    
    ErrorLog(LogLevel::DBG, "infotainment", "radio metadata no found\n");
    ErrorLog(LogLevel::DBG, "acc", "lane keep assist not functional\n");

    ErrorLog(LogLevel::TRC, "trackapps", "Acceleration timer did not start\n");
    ErrorLog(LogLevel::TRC, "autostopstart", "hardware switch malfunction\n");

    //ErrorLog(LogLevel::CRT, "shared memory", "shared memory testing\n");

    return 0;
}