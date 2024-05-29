#ifndef IOT_SENSOREN_UTILS_TIMER_H
#define IOT_SENSOREN_UTILS_TIMER_H

#include <Arduino.h>

namespace utils
{
    class timer
    {

    public:
        /**
         * @brief Construct a new timer object
         * 
         * @param time 
         */
        timer(uint32_t time);
        /**
         * @brief Destroy the timer object
         * 
         */
        ~timer()=default;
    public:
        /**
         * @brief check if timer has been triggered
         * 
         * @return true 
         * @return false 
         */
        bool is_triggered();
        /**
         * @brief start the timer
         * 
         * @param time if 0, does not change the trigger time, else sets it to time
         */
        void start(uint32_t time = 0);
        /**
         * @brief stop the timer
         * 
         */
        void stop();
    private:
        uint32_t m_start_time;
        bool m_running;
        uint32_t m_trigger_time;
    };
    
} // namespace utils


#endif // IOT_SENSOREN_UTILS_TIMER_H