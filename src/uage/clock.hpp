#pragma once 

#include <chrono>
#include <cstdint>

namespace uage {

  struct Clock {

    using time_point = std::chrono::system_clock::time_point;
    using get_time   = std::chrono::high_resolution_clock;


    void new_frame() { frame_start_ = get_time::now(); }

    void update_frames() { ++frames_; }

    bool is_waiting();

    void print_status();

    uint32_t frames() const { return frames_; }
    uint32_t maxfps() const { return maxfps_; }

    private:

    uint32_t maxfps_{60};
    uint32_t nanosperframe_{1'000'000'000 / maxfps_};

    time_point start_{ get_time::now() };
    time_point frame_start_{};

    uint32_t frames_{0};
  };

}
