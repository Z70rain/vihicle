#pragma once
#include <vector>
#include <string>
#include "SmartCar.h"
#include "Student.h"


// ��ָ��Ŀ¼�ж�ȡ����С����Ϣ�ļ�������ΪSmartCar���󣬴洢��һ��std::vector�в�����
std::vector<SmartCar> readSmartCarsFromDirectory(const std::string& directoryPath);

// �Ӹ����ļ�·���н�������С����Ϣ��������һ��SmartCar����
SmartCar parseSmartCarInfoFromFile(const std::string& filePath);

// �ֶ�����ѧ����Ϣ������ѧ��ID��������Ȼ����Ϣ���õ�Student������
void inputStudentInfo(Student& student, std::string stuId, std::string name);

// �ֶ���������С����Ϣ
void inputSmartCarInfo(SmartCar& car, std::string car_id);

// ����ָ�����ȵ���������ַ���
std::string generateRandomDigits(int n);

// ��ѧ������������ָ��ID��ѧ����������ָ���ѧ����ָ�롣���δ�ҵ����򷵻�nullptr
Student* searchStuIfExist(Student students[], int n, std::string id);

// ����ָ�����ȵ������ĸ�ַ���
std::string generateRandomLetters(int length);

// ���ն���ʾ����������С�������е���Ϣ
void showCarVecInfoInTermial(std::vector<SmartCar> cars);

// �ֶ���������С����Ϣ
void inputSmartCarInfoManually(SmartCar& car);

// �����������������
std::string generateRandomChineseName();

// ��ʾ�û��Ƿ�ִ���Զ����������磬���������Ϣ�����������û����뷵��true��false
bool isAutoOperation(const std::string& tip);

