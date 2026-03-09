#include <iostream>
#include <bitset>

int main(int argc, char* argv[]) {

    if(argc != 3){
        std::cout << "Error: Program requires two floating-point arguments." << std::endl;
        return 1;
    }

    float bound = std::stof(argv[1]);
    float inc = std::stof(argv[2]);

    unsigned int rawBound = *(unsigned int*)&bound;
    unsigned int rawInc = *(unsigned int*)&inc;

    std::bitset<32> boundBits(rawBound);
    std::bitset<32> incBits(rawInc);

    std::cout << boundBits << std::endl;
    std::cout << incBits << std::endl;

    int expBound = (rawBound >> 23) & 0xFF;
    int expInc = (rawInc >> 23) & 0xFF;

    int diff = expBound - expInc;

    if(diff > 23){

        std::cout << "Warning: Possible overflow!" << std::endl;
        std::cout << "Overflow threshold:" << std::endl;

        int thresholdExp = expInc + 23;
        unsigned int thresholdRaw = thresholdExp << 23;

        float threshold = *(float*)&thresholdRaw;

        std::bitset<32> thresholdBits(thresholdRaw);

        std::cout << threshold << std::endl;
        std::cout << thresholdBits << std::endl;

    } else {
        std::cout << "No overflow!" << std::endl;
    }

    return 0;
}