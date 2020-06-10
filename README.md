# 基于 MD5 算法的文件完整性校验程序
## 程序功能
+ ./md5 -h  
查看帮助
+ ./md5 -t  
打印程序的测试信息
+ ./md5 -c nankai.txt  
计算出的被测文件的MD5摘要并打印
+ ./md5 -v nankai.txt  
验证文件完整性方法一：用户输入被测文件的MD5摘要，然后重新计算被测文件nankai.txt的MD5摘要，将两个摘要逐位比较
+ ./md5 -f nankai.txt nankai.md5  
验证文件完整性方法二：程序读取nankai.md5摘要，重新计算被测文件nankai.txt的MD5，最后将两者逐位比较