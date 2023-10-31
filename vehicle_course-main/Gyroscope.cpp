#include "Gyroscope.h"
#include <iostream>

Gyroscope::Gyroscope() : m_model("CH110"), m_manufacturer("NXP") {}

void Gyroscope::setModel(const std::string& m) {
	m_model = m;
}

void Gyroscope::setManufacturer(const std::string& mf) {
	m_manufacturer = mf;
}

void Gyroscope::print() const {
	std::cout << "9���������ͺ�: " << m_model << std::endl;
	std::cout << "������: " << m_manufacturer << std::endl;
}

void Gyroscope::save(std::ofstream& outFile) const {
	outFile << "9���������ͺ�: " << m_model << std::endl;
	outFile << "������: " << m_manufacturer << std::endl;
}

std::string Gyroscope::getModel() const {
	return m_model;
}

std::string Gyroscope::getManufacturer() const {
	return m_manufacturer;
}
