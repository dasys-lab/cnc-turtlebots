#include <stdio.h>
#include <string>

int main(int argc, char **argv)
{
    std::string cmd = "flite -t ";
    std::string text = "\"hello World\"";

    std::system((cmd+text).c_str());
}
