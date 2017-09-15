# xgboost_realtime_predict_test
xgboost在线预测

1、编译xgboost的源代码，可以得到一个.so文件
2、自己的程序include上面那个头文件， 编译时加 -lxgboost ，动态链接就可以了 

参考： g++ -std=c++11 -o predictpredict.cpp -L. -lxgboost -I/data/code/kevinshuang/xgboost/rabit/include  


