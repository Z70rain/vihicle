#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "ObstacleStatus.h"

class Chassis;
class Lidar {
public:
	Lidar();

	void setModel(const std::string& m);
	void setChannels(const std::string& c);
	void setRange(const std::string& r);
	void setPowerConsumption(const std::string& pc);

	std::string getModel() const;
	std::string getChannels() const;
	std::string getRange() const;
	std::string getPowerConsumption() const;

	void print() const;
	void save(std::ofstream& outFile) const;


	// ע�ᶩ����
	void subscribe(class Chassis* chassis);
	// �����ϰ���״̬��֪ͨ������
	void updateObstacleStatus(ObstacleStatus status);
	// ֪ͨ���ж�����
	void notifySubscribers();
private:
	std::string m_model;
	std::string m_channels;
	std::string m_range;
	std::string m_powerConsumption;
	ObstacleStatus m_obstacleStatus;
	std::vector<class Chassis*> m_subscribers;
};
