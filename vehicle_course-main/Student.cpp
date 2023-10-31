#include "Student.h"
#include <iostream>

Student::Student() : m_name(""), m_studentID(""){}

void Student::setName(const std::string& name) {
	m_name = name;
}

void Student::setStudentID(const std::string& studentID) {
	m_studentID = studentID;
}

void Student::print() const {
	std::cout << "ѧ������: " << m_name << std::endl;
	std::cout << "ѧ��: " << m_studentID << std::endl;
}

void Student::save(std::ofstream& outFile) const {
	outFile << "ѧ������: " << m_name << std::endl;
	outFile << "ѧ��: " << m_studentID << std::endl;
}

std::string Student::getName() const {
	return m_name;
}

std::string Student::getStudentID() const {
	return m_studentID;
}
