#include "helpFunc.h"

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))              //F函数
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))              //G函数
#define H(x, y, z) ((x) ^ (y) ^ (z))                         //H函数
#define I(x, y, z) ((y) ^ ((x) | (~z)))                      //I函数
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n)))) //32位数字x的循环左移n位操作

#define FF(a, b, c, d, x, s, ac) { (a) += F ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }
#define GG(a, b, c, d, x, s, ac) { (a) += G ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }
#define HH(a, b, c, d, x, s, ac) { (a) += H ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }
#define II(a, b, c, d, x, s, ac) { (a) += I ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }

#define T(i) 4294967296 * abs(sin(i))

/* 主要功能：
1、为任意长度的字符串生成 MD5 摘要
2、为任意大小的文件生成 MD5 摘要
3、利用 MD5 摘要验证文件的完整性
*/
class MD5 {
public:
    void Update(const string &str); // 对给定长度的字符串进行MD5运算
    void Update(ifstream &in); // 对文件中的内容进行MD5运算
    string Tostring(); // 将MD5摘要以字符串形式输出

private:
    void Reset(); // 重置初始变量
    void Update(vector<uint8_t> input); // 对给定长度的字节流进行MD5运算
    void Transform(const vector<uint8_t> block); // 对一个512比特的消息分组进行MD5运算
    vector<uint32_t> Decode(const vector<uint8_t>input); // 将64byte的数据块划分为16个32bit大小的子分组
    string from10To16(uint32_t decimal); //32位十进制转成16进制，用8个字母的string表示
    vector<uint8_t> fromInt64ToInt8Vec(uint64_t num); // 将1个64位int转成vector<uint8_t>

private:
    uint32_t state[4]; // 用于表示4个初始向量
};