#pragma once
#include <string>
#include <fstream>

class AGXKit {
public:
	AGXKit();

	// ��ȡAGX�׼��ͺ�
	std::string getModel() const;

	// ��ȡAI����
	std::string getAIPerformance() const;

	// ��ȡCUDA������
	std::string getCudaCores() const;

	// ��ȡTensor CORE��
	std::string getTensorCores() const;

	// ��ȡ�Դ�
	std::string getMemory() const;

	// ��ȡ�洢
	std::string getStorage() const;

	void setModel(const std::string& m);
	void setAIPerformance(const std::string& a);
	void setCudaCores(const std::string& cc);
	void setTensorCores(const std::string& tc);
	void setMemory(const std::string& m);
	void setStorage(const std::string& s);

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_model;
	std::string m_aiPerformance;
	std::string m_cudaCores;
	std::string m_tensorCores;
	std::string m_memory;
	std::string m_storage;
};
