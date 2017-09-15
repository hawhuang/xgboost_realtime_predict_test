#include <stdlib.h>

#include<iostream>

#include<fstream> 

#include<string>

#include<vector>

#include <sstream>

#include"../xgboost/include/xgboost/c_api.h"

#include <stdio.h> 

#include <string.h>

using namespace std;



void split(string str, char ch, vector<string> &ivec)

{

	stringstream sin(str);

	string word;

      int i=0;

	while (std::getline(sin, word, ch))

	{

	//	cout<<i<<":"<<word<<endl;

		ivec.push_back(word );

	i++;

	}

}





int main(int argc, char *argv[])

{

	cout<<"begin"<<endl;	

	if(argc != 4)

	{ 

		cout<<"wrong input"<<endl;

		return 1; //参数不够

	}



	char *uin = argv[1];  //用户id

	//cout<<uin<<endl;

	char *char_character = argv[2];	   //用户特征序列，逗号隔开

	//cout<<char_character<<endl;

	const char *fname = argv[3];       //模型文件路径

	//cout<<fname<<endl;

	vector<string> ivec;

  	string test_data=char_character;



	//cout<<test_data<<endl;

  	split(test_data,',',ivec);    //解析用户特征，都逗号分隔，放入vector

	  int cols=ivec.size();



	  float uin_data[1][cols];             //放入二维矩阵

	  for ( int i = 0 ; i < ivec.size() ; ++i )

	  {

		  uin_data[0][i]=atof(ivec[i].c_str());

	  }



	  BoosterHandle h_booster;



	  const float *f;

	  bst_ulong out_len;

		DMatrixHandle h_test[1];

		int sample_rows=1;

	XGDMatrixCreateFromMat((float *) uin_data, sample_rows, cols, -1, &h_test[0]);

	  XGBoosterCreate(h_test,1,&h_booster);

	//      ret=XGBoosterLoadModelFromBuffer(h_booster,pbuf, iSize);

	int ret=XGBoosterLoadModel(h_booster,fname);  //加载模型

	cout << uin <<" ,load:"<<ret<<endl;	       

	  XGBoosterPredict(h_booster, h_test[0], 0,0,&out_len,&f);  //预测



	  for (unsigned int i=0;i<out_len;i++)

	  {

		  cout << uin << " ,prediction[" << i << "]=" << f[i] << endl;

	  }

	// free xgboost internal structures

	XGDMatrixFree(h_test[0]);

	XGBoosterFree(h_booster);



	cout<<"end"<<endl;



	return 0;

}
