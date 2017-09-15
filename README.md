# xgboost_realtime_predict_test
xgboost在线预测

1、编译xgboost的源代码，可以得到一个.so文件
2、自己的程序include上面那个头文件， 编译时加 -lxgboost ，动态链接就可以了 

参考编译方法（替换你自己的xgboost编译目录）： g++ -std=c++11 -o predict predict.cpp -L. -lxgboost -I/data/code/yourname/xgboost/rabit/include  

测试案例：./predict 12345 2,0,0.0,0,0,0,1,0,0,0,0,0.0,0.0,0,25,1,0,0,0,0,2 xgboost.model2


