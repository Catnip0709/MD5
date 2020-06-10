#include "helpFunc.h"
#include "MD5.h"

// 打印help信息
void print_h(int argc,char *argv[]) {
    if (2 != argc) {
        cout << "参数错误" << endl;
    }
    cout << "usage：" << "\t" << "[-h] --help information " << endl
         << "\t" << "[-t] --test MD5 application" << endl
         << "\t" << "[-c] [file path of the file computed]" << endl
         << "\t" << "\t" <<"--compute MD5 of the given file" << endl
         << "\t" << "[-v] [file path of the file validated]" << endl
         << "\t" << "\t" <<"--validate the integrality of a given file by manual input MD5 value" << endl
         << "\t" << "[-f] [file path of the file validated] [file path of the .md5 file]" << endl
         << "\t" << "\t" <<"--validate the integrality of a given file by read MD5 value from .md5 file" << endl;
}

// 打印程序的测试信息
void print_t(int argc,char *argv[]) {
    if (2 != argc) {
        cout << "参数错误" << endl;
    }
    vector<string> str = {"", "a", "abc", "message digest", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", "12345678901234567890123456789012345678901234567890123456789012345678901234567890"};
    MD5 md5;
    for (int i = 0; i < str.size(); ++i) { 
        md5.Update(str[i]);
        cout << "MD5(\"" + str[i] + "\") = " << md5.Tostring() << endl;
    }
}

// 计算出的被测文件的MD5摘要并打印
void print_c(int argc,char *argv[]) {
    if (3 != argc) {
        cout << "参数错误" << endl;
    }
    string filePath = argv[2];
    ifstream fileStream(filePath);
    MD5 md5;
    md5.Update(fileStream);
    cout << "The MD5 value of file(\"" << filePath << "\") is " << md5.Tostring() << endl;
}

// 让用户输入被测文件的MD5摘要，然后重新计算被测文件的MD5摘要，将两个摘要逐位比较
void print_v(int argc,char *argv[]) {
    if (3 != argc) {
        cout << "参数错误" << endl;
    }
    string filePath = argv[2];
    cout << "Please input the MD5 value of file(\"" << filePath << "\")..." << endl;
    string inputMD5;
    cin >> inputMD5;
    cout << "The old MD5 value of file(\"" << filePath << "\") you have input is" << endl << inputMD5 << endl;
    ifstream fileStream(filePath);
    MD5 md5;
    md5.Update(fileStream);
    string genMD5 = md5.Tostring();
    cout << "The new MD5 value of file(\"" << filePath << "\") that has computed is" << endl << genMD5 << endl;
    if (!genMD5.compare(inputMD5)) {
        cout << "OK! The file is integrated" << endl;
    }
    else {
        cout << "Match Error! The file has been modified!" << endl;
    }
}

// 程序读取.md5摘要，重新计算被测文件的MD5，最后将两者逐位比较
void print_f(int argc, char *argv[]) {
    if (4 != argc) {
        cout << "参数错误" << endl;
    }
    string filePath = argv[2];
    string md5Path = argv[3];

    ifstream md5Stream(md5Path);
    string oldMD5Str((istreambuf_iterator<char>(md5Stream)), istreambuf_iterator<char>());
    cout << "The old MD5 value of file(\"" << filePath << "\") in " << md5Path << " is " << endl << oldMD5Str << endl;

    ifstream fileStream(filePath);
    MD5 md5;
    md5.Update(fileStream);
    string genMD5 = md5.Tostring();
    cout << "The new MD5 value of file(\"" << filePath << "\") that has computed is" << endl << genMD5 << endl;
    if (!genMD5.compare(oldMD5Str)) {
        cout << "OK! The file is integrated" << endl;
    }
    else {
        cout << "Match Error! The file has been modified!" << endl;
    }
}