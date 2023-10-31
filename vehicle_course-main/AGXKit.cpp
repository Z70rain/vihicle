#include "AGXKit.h"
#include <iostream>

AGXKit::AGXKit() : m_model("AGX Xavier"), m_aiPerformance("32 TOPS"), m_cudaCores("512"),
m_tensorCores("64"), m_memory("32G"), m_storage("32G") {}

void AGXKit::setModel(const std::string& m) {
	m_model = m;
}

void AGXKit::setAIPerformance(const std::string& a) {
	m_aiPerformance = a;
}

void AGXKit::setCudaCores(const std::string& cc) {
	m_cudaCores = cc;
}

void AGXKit::setTensorCores(const std::string& tc) {
	m_tensorCores = tc;
}

void AGXKit::setMemory(const std::string& m) {
	m_memory = m;
}

void AGXKit::setStorage(const std::string& s) {
	m_storage = s;
}

void AGXKit::print() const {
	std::cout << "AGX�׼��ͺ�: " << m_model << std::endl;
	std::cout << "AI����: " << m_aiPerformance << std::endl;
	std::cout << "CUDA������: " << m_cudaCores << std::endl;
	std::cout << "Tensor CORE��: " << m_tensorCores << std::endl;
	std::cout << "�Դ�: " << m_memory << std::endl;
	std::cout << "�洢: " << m_storage << std::endl;
}

void AGXKit::save(std::ofstream& outFile) const {
	outFile << "AGX�׼��ͺ�: " << m_model << std::endl;
	outFile << "AI����: " << m_aiPerformance << std::endl;
	outFile << "CUDA������: " << m_cudaCores << std::endl;
	outFile << "Tensor CORE��: " << m_tensorCores << std::endl;
	outFile << "�Դ�: " << m_memory << std::endl;
	outFile << "�洢: " << m_storage << std::endl;
}

// ��ȡAGX�׼��ͺ�
std::string AGXKit::getModel() const {
	return m_model;
}

// ��ȡAI����
std::string AGXKit::getAIPerformance() const {
	return m_aiPerformance;
}

// ��ȡCUDA������
std::string AGXKit::getCudaCores() const {
	return m_cudaCores;
}

// ��ȡTensor CORE��
std::string AGXKit::getTensorCores() const {
	return m_tensorCores;
}

// ��ȡ�Դ�
std::string AGXKit::getMemory() const {
	return m_memory;
}

// ��ȡ�洢
std::string AGXKit::getStorage() const {
	return m_storage;
}
