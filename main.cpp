#include <boost/program_options.hpp>

// XRT
#include "xrt/xrt_device.h"
#include "xrt/xrt_kernel.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]){
    // Command Line Argument Parser
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Display help");
    po::variables_map varMap;
    po::store(po::parse_command_line(argc, argv, desc), varMap);

    std::cout << "Pre initialize Device" << std::endl;
    auto device = xrt::device(0);
    std::cout << "Post initialize Device" << std::endl;
}