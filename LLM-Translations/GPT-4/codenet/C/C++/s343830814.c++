#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string buf;
    int len;
    std::getline(std::cin, buf);
    len = buf.length();
    std::cout << buf[0] << len-2 << buf[len-1] << std::endl;
    return 0;
}
// 
