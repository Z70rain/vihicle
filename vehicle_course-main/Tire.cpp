#include "Tire.h"
#include <iostream>
#include <fstream>

Tire::Tire() : m_model(""), m_size("") {}

void Tire::setModel(const std::string& m) {
	m_model = m;
}

void Tire::setSize(const std::string& s) {
	m_size = s;
}

void Tire::print() const {
	std::cout << "��̥�ͺ�: " << m_model << ", �ߴ�: " << m_size << std::endl;
}

void Tire::save(std::ofstream& outFile) const {
	outFile << "��̥�ͺ�: " << m_model << ", �ߴ�: " << m_size << std::endl;
}

std::string Tire::getModel() const { 
	return m_model;
}

std::string Tire::getSize() const { 
	return m_size;
}
