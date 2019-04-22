// エディタの設定が悪くてこれが必要
#undef _MSC_VER

#ifdef _MSC_VER
#include <Windows.h>
double get_ms() { return (double)GetTickCount64() / 1000; }
#else
#include <sys/time.h>
double get_ms() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec * 1000 + (double)t.tv_usec / 1000;
}
#endif

class Timer {
 private:
    double start_time;
    double elapsed;

#ifdef USE_RDTSC
    double getSec() { return get_absolute_sec(); }
#else
    double getSec() { return get_ms() / 1000; }
#endif

 public:
    Timer() {}

    void start() { start_time = getSec(); }
    double getElapsed() { return getSec() - start_time; }
};
