#include "Battery.h"
#include <iostream>

Battery::Battery() : m_parameters("24V/15Ah"), m_externalPower("24V"),
m_chargingDuration("2H") {}

void Battery::setParameters(const std::string& p) {
	m_parameters = p;
}

void Battery::setExternalPower(const std::string& ep) {
	m_externalPower = ep;
}

void Battery::setChargingDuration(const std::string& cd) {
	m_chargingDuration = cd;
}

void Battery::print() const {
	std::cout << "��ز���: " << m_parameters << std::endl;
	std::cout << "�ⲿ��Դ: " << m_externalPower << std::endl;
	std::cout << "���ʱ��: " << m_chargingDuration << std::endl;
}

void Battery::save(std::ofstream& outFile) const {
	outFile << "��ز���: " << m_parameters << std::endl;
	outFile << "�ⲿ��Դ: " << m_externalPower << std::endl;
	outFile << "���ʱ��: " << m_chargingDuration << std::endl;
}

std::string Battery::getParameters() const {
	return m_parameters;
}

std::string Battery::getExternalPower() const {
	return m_externalPower;
}

std::string Battery::getChargingDuration() const {
	return m_chargingDuration;
}
