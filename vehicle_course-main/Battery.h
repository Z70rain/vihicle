#pragma once
#include <string>
#include <fstream>

class Battery {
public:
	Battery();

	void setParameters(const std::string& p);
	void setExternalPower(const std::string& ep);
	void setChargingDuration(const std::string& cd);

	std::string getParameters() const; // ��ӻ�ȡ������getter
	std::string getExternalPower() const; // ��ӻ�ȡ�ⲿ��Դ��getter
	std::string getChargingDuration() const; // ��ӻ�ȡ���ʱ����getter

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_parameters;
	std::string m_externalPower;
	std::string m_chargingDuration;
};
