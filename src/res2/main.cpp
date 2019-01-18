#include <stdlib.h>
#include <time.h>

namespace {
    static inline double Random() {
        return 1.0 + (((double)rand() / ((double)RAND_MAX + 1.0)) * 1000.0);
    }
}

int main() {
#ifdef __linux__
    srand(time(nullptr));
#else
    sranddev();
#endif

    double a = Random();
    double b = Random();
    double c = Random();

    while (true) {
        const double a_ = Random();
        const double b_ = Random();
        const double c_ = Random();

        a *= a_;
        b += b_;
        c = (a / b) * c_;
    }

    return 0;
}
