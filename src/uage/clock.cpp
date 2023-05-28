#include "clock.hpp"

namespace uage {

  bool Clock::is_waiting() {
    return ((get_time::now() - frame_start_).count() < nanosperframe_ );
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void Clock::print_status() {
    auto end = get_time::now();

    auto ellapsed      = (end - start_).count(); //nanoseconds 
    auto ellapsed_secs = double(ellapsed) / 1'000'000'000.0;

    printf("seconds: %f\n", ellapsed_secs);
    printf("frames : %u\n", frames_);
    printf("FPS    : %f\n", double(frames_) / ellapsed_secs);
  }

}


