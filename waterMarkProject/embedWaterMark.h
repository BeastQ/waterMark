#pragma once
#include <vector>;
#include<opencv2/opencv.hpp>
#include "Uitls.h";
using namespace cv;
using namespace std;
/*
Ƕ��ˮӡ�������
*/
class embedWaterMark
{
public:
	//��ʼ��ˮӡ��Ϣ
	void initWaterMark(int bitdepth, int vlen, float p, int delta, int DPI, float MarginRatio);
	//Ƕ��ˮӡ�㷨
	void embedWaterMrak();
	//giQimHide_DCT_block_vertical_Glp������ʵ��,��������
	Mat giQimHide_DCT_block_vertical_Glp(Mat cfData, vector<int> ones,int delta,
		int vlen,double p,int block[2]);
private:
	//��Ҫ����һЩ��Ҫ������
	//ˮӡ����
	int wfLen = 64;
	int bitdepth;//8
	int vlen;//32
	float p;//2.0
	int delta;//70
	int DPI;//96
	float MarginRatio;//0.059
	int block[2] = {8,8};
	vector<int> ones,wfData;
	double MarginH;//ѡȡˮӡ�����ˮƽ����߾�
	double MarginV;//ѡȡˮӡ����Ĵ�ֱ����߾�
	double RowSt, RowEd, ColSt, ColEd;
	Mat cfData;
	Uitls uitls;
};


