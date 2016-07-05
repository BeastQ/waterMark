#pragma once
#include<string>;
#include<opencv2/opencv.hpp>;
using namespace cv;
using namespace std;
/*
�㷨��ط���������
*/
class WaterMarkUtils
{
public:
	//���·�����ʵ��,�������ͺͲ�������
	//void initDIR(string *dirs);	//��ʼ��Ŀ¼����ʵ�֣���Ӧprepare.m									
	void addBorder();//��Σ�ͼ�����ݣ���Σ��߿��ȣ�����ֵ���ӱ߿���ͼ��						 
	void genData();
	//getDiag
	void getDiag();
	//igetDiag
	void igetDiag();
	//zigzagOrder
	void zigzagOrder();
	void izigzagOrder();
	//minEucDistance
	void minEucDistance();
	//quantificate
	void quantificate();
	void getWaterMarkRect(Mat img);
private:
	//����һЩ��Ҫ������
	string INPUT_DIR = ".\\Input\\";
	string OUTPUT_DIR = ".\\Output\\";
	string COVER_CMYK_DIR = INPUT_DIR + "orgImage\\CMYK\\";
	string COVER_RGB_DIR = INPUT_DIR + "orgImage\\RGB\\";
	string WATERMARK_DIR = INPUT_DIR + "Watermark\\";
	string LOG_DIR = OUTPUT_DIR + "Log\\";
	string STEGO_CMYK_DIR = OUTPUT_DIR + "Glp\\CMYK\\";
	string STEGO_RGB_DIR = OUTPUT_DIR + "Glp\\RGB\\";
	string dirs[8] = {INPUT_DIR,OUTPUT_DIR,COVER_CMYK_DIR,COVER_RGB_DIR,
		WATERMARK_DIR,LOG_DIR,STEGO_CMYK_DIR,STEGO_RGB_DIR};

};