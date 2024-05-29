#include "timer.h"

namespace utils
{
    timer::timer(uint32_t time) 
        : m_trigger_time(time),
            m_running(true)
    {
        m_start_time = millis();
    }

    bool timer::is_triggered() {
        if (!m_running) {
            return false;
        }
        if (millis() > m_start_time + m_trigger_time) {
            m_start_time = millis();
            return true;
        }
        return false;
    }

    void timer::start(uint32_t time) {
        if (time != 0) {
            m_trigger_time = time;
        }
        m_running = true;
        m_start_time = millis();
    }

    void timer::stop() {
        m_running = false;
    }
} // namespace utils
