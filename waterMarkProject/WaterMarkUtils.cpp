#include "WaterMarkUtils.h"
#include"stdafx.h"
void WaterMarkUtils::addBorder() {
	//��Σ�ͼ�����ݣ���Σ��߿��ȣ�����ֵ���ӱ߿���ͼ��
}


void WaterMarkUtils::genData() {
}

void WaterMarkUtils::getDiag() {
}

void WaterMarkUtils::igetDiag() {
}

/*void WaterMarkUtils::initDIR(string *dirs) {
	for (int i = 1; i <= 8;i++) {
		if () {
		}
	}
}*/

void WaterMarkUtils::izigzagOrder() {
}

void WaterMarkUtils::minEucDistance() {
}

double WaterMarkUtils::quantificate(double z,int d,int delta) {
	double dither = d*delta / 2;
	double z1 = delta * round((z + dither) / delta) - dither;
	return z1;
}

void WaterMarkUtils::zigzagOrder() {
}