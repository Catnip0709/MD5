#include "MD5.h"

int main(int argc,char *argv[]) { //argc=外部命令参数的个数，argv[]存放各参
    unordered_map<string, void(*)(int, char*[])> mapOp = {{"-t", print_t}, 
                                                          {"-h", print_h}, 
                                                          {"-c", print_c}, 
                                                          {"-v", print_v},
                                                          {"-f", print_f}};
    if (argc < 2) {
        cout << "参数错误，argc = " << argc << endl;
        return -1;
    }
    string op = argv[1];
    if (mapOp.find(op) != mapOp.end()) {
        mapOp[op](argc, argv);
    }
    return 0;
}