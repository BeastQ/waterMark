#include "embedWaterMark.h";
#include <vector>;
#include<opencv2/opencv.hpp>;
#include<math.h>
#include"stdafx.h"
using namespace cv;
using namespace std;
void embedWaterMark::initWaterMark(int bitdepth1, int vlen1, float p1, 
	int delta1, int DPI1, float MarginRatio1) {
	bitdepth = bitdepth1;
	vlen = vlen1;
	p = p1;
	delta = delta1;
	DPI = DPI1;
	MarginRatio = MarginRatio1;
	//����һ������ˮӡ������
	vector<int> ones(wfLen,1);
	cfData = imread("ͼƬ·��");//��ȡͼ��

}
void embedWaterMark::embedWaterMrak() {
	/*
	* ��Ҫ��Ϊ����
	* 1.ѡȡǶ������
	* 2.��ƵǶ�봦��
	* 3.Ƕ�����giQimHide_DCT_block_vertical_Glp
	*/
	//ѡȡǶ������
	int m = cfData.cols;//��ȡͼ����������
	int n = cfData.rows;//����
	int t = cfData.depth;//���
	MarginH = floor(n * MarginRatio); //ƽ����߾�
	MarginV = floor(m * MarginRatio); //��ֱ����߾�
	RowSt = MarginH + 1;
	RowEd = n - MarginH;
	ColSt = MarginV + 1;
	ColEd = m - MarginV;
	Mat stg = cfData;
	for (int j = 1; j <= t;j++) {
		
	}
}
Mat embedWaterMark::giQimHide_DCT_block_vertical_Glp(Mat cfData, vector<int> ones,
	int delta,int vlen, double p, int block[2]) {
	//��ӦgiQimHide_DCT_block_vertical_Glp.m������
	Mat cfL = uitls.gauLowPass(cfData,3,0.5);//��Ƶ����
	//Mat* cflz = &cfL;
	Mat cfH = cfData - cfL;//��Ƶ����
	int si[2] = {cfL.rows,cfL.cols};//��ȡ����cfL������������
	int len = wfLen;
	int N1 = floor((floor(si[1] / block[1])*floor(si[0] / block[0])) / (2 * vlen));
	if (len<N1)
	{
		vector<int> zeros((len-N1),0);
		zeros.insert(zeros.begin(), ones.begin(), ones.end());
		wfData = zeros;
	}
	if (len>N1)
	{
		for (int i = N1; i <= len;i++) 
		{
			wfData.erase[i];
		}
	}
	int N = floor(si[0] / block[0]); //there are N blocks in each row
	int M = floor(si[1] / block[1]); // there are M block in each colomn
	if ((M % 2)==1) {
		M -= 1;
	}
	Mat v1 = Mat::zeros(M/2,N, CV_8UC1);
	Mat v2 = Mat::zeros(M / 2, N, CV_8UC1);
	Mat v = Mat::zeros(M , N, CV_8UC1);
	int oddCount = 0;
	int evenCount = 0;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			Mat srcV = uitls.getMatV(cfL, (i - 1)*block[0], i*block[0]-1,
				(j - 1)*block[1], j*block[1]-1);
			Mat V;
			cvDCT(&srcV,&V,CV_DXT_FORWARD);
			v.at<uchar>(i, j) = V.at<uchar>(2,1);
		}
		if ((i%2)==0)
		{
			evenCount = evenCount + 1;
			v2.row(evenCount - 1) = v.row(i);//?matlab�Ǵ�1��ʼ�ģ�c++�Ǵ�0��ʼ�ģ�����Ҫ��һ
			//v2(evenCount, :) = v(i, :);
		}
		if (true)
		{
			oddCount = oddCount + 1;
			v1.row(oddCount - 1) = v.row(i);//?matlab�Ǵ�1��ʼ�ģ�c++�Ǵ�0��ʼ�ģ�����Ҫ��һ
			//v1(oddCount,:)=v(i,:);
		}
	}
	v1 = uitls.Creshape(v1,vlen);
	v2 = uitls.Creshape(v2,vlen);
	Mat z1 = Mat::zeros(1, N1, CV_8UC1);
	Mat z = Mat::zeros(1, N1, CV_8UC1);
	for (int i = 1; i <= N1;i++) {
		Mat v1Col = uitls.getPowMat(v1,i,p);
		Mat v2Col = uitls.getPowMat(v2,i,p);
		double lx = uitls.getLxOrLy(v1Col,vlen,1/p);
		double ly = uitls.getLxOrLy(v2Col,vlen,1/p);
		if ((std::abs(lx)<=(1e-6))||(std::abs(ly)<=(1e-6)))
		{		
			
		}
		
	}
	return;

}