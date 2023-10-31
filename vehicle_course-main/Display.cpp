#include "Display.h"
#include <iostream>

Display::Display() : m_size("11.6"), m_model("super") {}

void Display::setSize(const std::string& s) {
	m_size = s;
}

void Display::setModel(const std::string& m) {
	m_model = m;
}

void Display::print() const {
	std::cout << "Һ����ʾ���ߴ�: " << m_size << "Ӣ��" << std::endl;
	std::cout << "Һ����ʾ���ͺ�: " << m_model << std::endl;
}

void Display::save(std::ofstream& outFile) const {
	outFile << "Һ����ʾ���ߴ�: " << m_size << "Ӣ��" << std::endl;
	outFile << "Һ����ʾ���ͺ�: " << m_model << std::endl;
}

std::string Display::getSize() const {
	return m_size;
}

std::string Display::getModel() const {
	return m_model;
}
