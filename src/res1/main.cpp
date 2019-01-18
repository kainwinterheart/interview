#include <fstream>
#include <string.h>

static const size_t dataLen(1024 * 1024);

int main() {
    char data[dataLen];
    memset(data, 0, dataLen);

    while (true) {
        std::ofstream fh("/opt/res1", std::ios::trunc);

        for (size_t i = 0; i < 100; ++i) {
            fh.write(data, dataLen);
        }

        fh.close();
    }

    return 0;
}
