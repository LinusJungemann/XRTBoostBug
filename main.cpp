#include <boost/program_options.hpp>

// XRT
#include "xrt/xrt_device.h"
#include "xrt/xrt_kernel.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]){
    // Command Line Argument Parser
        po::options_description desc{"Options"};
        // clang-format off
        desc.add_options()("help,h", "Display help")("exec_mode,e", po::value<std::string>()->default_value("throughput"),
            R"(Please select functional verification ("execute") or throughput test ("throughput")")("configpath,c", po::value<std::string>(),
                "Required: Path to the config.json file emitted by the FINN compiler")(
                    "input,i", po::value<std::vector<std::string>>()->multitoken()->composing(), "Path to one or more input files (npy format). Only required if mode is set to \"file\"")(
                        "output,o", po::value<std::vector<std::string>>()->multitoken()->composing(), "Path to one or more output files (npy format). Only required if mode is set to \"file\"")(
                            "batchsize,b", po::value<int>()->default_value(1), "Number of samples for inference")("check", "Outputs the compile time configuration");
        // clang-format on
        po::variables_map varMap;
        po::store(po::parse_command_line(argc, argv, desc), varMap);

    std::cout << "Pre initialize Device" << std::endl;
    device = xrt::device(0);
    std::cout << "Post initialize Device" << std::endl;
}