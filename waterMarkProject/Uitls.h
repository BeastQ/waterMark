#pragma once
#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <iostream> 
using namespace cv;
/*
ͨ�÷����������
*/
class Uitls
{
public:
	//attackʵ�֣��������ͺͲ�������
	void attack();//��ѡ������������������������������صĲ���
				  //calcPBCʵ�֣��������ͺͲ�������
	void calcPBC();//�����ʣ���Ҫ�������ϵ������Ҫ������ֵ����ȣ���ѡ��	
				   //gauLowPassʵ�֣��������ͺͲ�������
	Mat gauLowPass(Mat cfData,int n,double sigma); //��Σ�ͼ�����ݣ���Σ����ڴ�С����׼�����ֵ���˲����ͼ��
					   //getBer
	void getBer();
	//getCorr
	void getCorr();
	//getPsnr
	void getPsnr();
	//RGB2GRAY
	void RGB2GRAY();
	Mat getMatV(Mat cfL,int r1,int r2,int c1,int c2);
	Mat Creshape(Mat v,int rows);
	Mat getPowMat(Mat v,int i,int p);
	Mat getPowMat(Mat v,int p);
	double getLxOrLy(Mat cc,int vlen,double p1);
	//������˹����
	double generateGaussianNoise(double Dx);
	//�����˹������
	Mat cAwgn(Mat v, int i, double db);
private:
	//����һЩ�������
};