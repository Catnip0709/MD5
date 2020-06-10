#include "MD5.h"

// 将64byte（64*8 bit）的数据块划分为16个32bit大小的子分组，input.size()=64
vector<uint32_t> MD5::Decode(const vector<uint8_t>input) {
    // input的4个8bit数字合并成一个output的32bit数字，但是要反过来，ABCD->DCBA
    vector<uint32_t> output;
    for (int i = 0; i < input.size() / 4; ++i) {
        uint32_t temp = 0;
        for (int j = 3; j >= 0; --j) {
            temp += input[i * 4 + j];
            if (j != 0) {
                temp = temp << 8;
            }
        }
        output.push_back(temp);
    }
    return output;
}

// decimal是32位十进制的表示，转成16进制，用8个字母的string表示
string MD5::from10To16(uint32_t decimal) {
    string hex;
    uint32_t help = 4026531840;
    unordered_map<int, string> map10To16 = { {0, "0"},  {1, "1"},  {2, "2"},  {3, "3"},
                                             {4, "4"},  {5, "5"},  {6, "6"},  {7, "7"},
                                             {8, "8"},  {9, "9"},  {10, "a"}, {11, "b"},
                                             {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"} };
    for (int i = 0; i < 8; ++i) {
        int tempResult = (decimal & help) >> 28;
        hex += map10To16[tempResult];
        decimal = decimal << 4;
    }
    return hex;
}

// 将1个64位int转成vector<uint8_t>
vector<uint8_t> MD5::fromInt64ToInt8Vec(uint64_t num) {
    vector<uint8_t> result(8);
    uint8_t help = 255;
    for (int i = 0; i < 8; ++i) {
        result[i] = num & help;
        num = num >> 8;
    }
    return result;
}
