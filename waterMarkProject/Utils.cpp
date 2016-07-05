#include "Uitls.h"
#include<opencv2/opencv.hpp>;
#include<math.h>
#include"stdafx.h"

using namespace std;
using namespace cv;
void Uitls::attack() {
	//��ѡ������������������������������صĲ���
}
	
void Uitls::calcPBC() {
	//�����������ʣ���Ҫ�������ϵ������Ҫ������ֵ����ȣ���ѡ��
}

Mat Uitls::gauLowPass(Mat cfData,int n,double sigma) {
	//��Σ�ͼ�����ݣ���Σ����ڴ�С����׼�����ֵ���˲����ͼ��
	Mat glData;
	GaussianBlur(cfData,glData,cv::Size(n,n),sigma);
	return glData;	
}
Mat Uitls::getMatV(Mat cfL, int r1, int r2, int c1, int c2) {
	Mat R = cfL.rowRange(r1,r2).clone();
	Mat C = R.colRange(c1,c2).clone();
	return C;
}
Mat Uitls::Creshape(Mat v,int rows) {
	v = v.t();
	v = v.reshape(0,rows);
	return v;
}
Mat Uitls::getPowMat(Mat c,int i,int p) {
	Mat v1SrcC = c.col(i).clone;
	Mat v1DstC;
	cv::pow(v1SrcC,p,v1DstC);
	return v1DstC;
}
double Uitls::getLxOrLy(Mat cc,int vlen,double p1) {
	double sum = 0;
	for (int i = 0; i < cc.rows;i++) {
		 sum = sum + cc.at<uchar>(i,0);
	}
	double sum1 = std::abs(sum);
	double sum2 = sum1 / vlen;
	return std::pow(sum2,p1);
}
//������˹��������ͨ��Box-Muller�任���Բ���Gaussian����
double generateGaussianNoise() {
	static bool hasSpare = false;
	static double rand1, rand2;
	if (hasSpare)
	{
		hasSpare = false;
		return sqrt(rand1) * sin(rand2);
	}
	hasSpare = true;
	rand1 = rand() / ((double)RAND_MAX);
	if (rand1 < 1e-100) 
		rand1 = 1e-100;
	rand1 = -2 * log(rand1);
	rand2 = (rand() / ((double)RAND_MAX)) * TWO_PI;
	return sqrt(rand1) * cos(rand2);
}
//���Ӹ�˹����
Mat Uitls::cAwgn(Mat v,int i,double db) {
	Mat vv = getPowMat(v,i,2);
	double Ssum = 0;//�����ź�����
	double Nsum = 0;//��������
	for (int j = 0; j < vv.rows;j++) {
		Ssum = Ssum + vv.at<uchar>(j, 0);
	}
	if (Ssum==Nsum*(std::pow(10,i))) {
		//Mat v_noise = ;
	}
	return;
}
void Uitls::getBer() {
}
void Uitls::getCorr() {
}
void Uitls::getPsnr() {
}
void Uitls::RGB2GRAY() {
}