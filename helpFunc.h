#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <streambuf>

using namespace std;

void print_h(int argc, char *argv[]); // 打印help信息
void print_t(int argc, char *argv[]); // 打印程序的测试信息
void print_c(int argc, char *argv[]); // 计算出的被测文件的MD5摘要并打印出来
void print_v(int argc, char *argv[]); // 让用户输入被测文件MD5，然后重新计算被测文件的MD5，将两个摘要逐位比较
void print_f(int argc, char *argv[]); // 程序读取.md5摘要，重新计算被测文件的MD5，最后将两者逐位比较