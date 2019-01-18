#include <http/server/server.hpp>
#include <http/handler/handler.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

static std::vector<std::ofstream> Files;
static size_t LogIndex = 0;

namespace {
    class THandler : public NAC::NHTTPHandler::THandler {
        void Handle(
            const std::shared_ptr<const NAC::NHTTP::TRequest> request,
            const std::vector<std::string>& args
        ) override {
            Files.at(LogIndex) << request->FirstLine() << std::endl;

            request->Send200();
        }
    };
}

int main() {
#ifdef __linux__
    srand(time(nullptr));
#else
    sranddev();
#endif

    THandler handler;
    NAC::NHTTPServer::TServer::TArgs args;

    args.BindIP4 = "0.0.0.0";
    args.BindPort6 = args.BindPort4 = 39754;
    args.ThreadCount = 1;

    static const std::string logRoot("/var/sgol/");
    static const std::string logSuffix(".log");

    for (size_t i = 0; i < 10; ++i) {
        Files.emplace_back(std::ofstream(logRoot + std::to_string(i) + logSuffix, std::ios::trunc));

        if (!Files.at(i)) {
            abort();
        }
    }

    LogIndex = (size_t)(((double)rand() / ((double)RAND_MAX + 1.0)) * Files.size());

    NAC::NHTTPServer::TServer(args, handler).Run();

    return 0;
}
