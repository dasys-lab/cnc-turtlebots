#include <stdio.h>
#include <string>

std::string cmd = "flite -t ";

int talk(std::string text)
{
    std::system((cmd+text).c_str());
}



int main(int argc, char **argv)
{
    std::string text = "\"hello World\"";

    talk(text);
}

