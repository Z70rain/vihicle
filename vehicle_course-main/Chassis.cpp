#include "Chassis.h"
#include "Lidar.h"
#include <iostream>
#include <fstream>

using namespace std;

Chassis::Chassis() {
	// Constructor implementation
}

void Chassis::setId(const std::string& i) {
	m_id = i;
}

void Chassis::setModel(const std::string& m) {
	m_model = m;
}

void Chassis::setWheelbase(const std::string& wb) {
	m_wheelbase = wb;
}

void Chassis::setTrack(const std::string& t) {
	m_track = t;
}

void Chassis::setGroundClearance(const std::string& gc) {
	m_groundClearance = gc;
}

void Chassis::setTurningRadius(const std::string& tr) {
	m_turningRadius = tr;
}

void Chassis::setDriveType(const std::string& dt) {
	m_driveType = dt;
}

void Chassis::setMaxTravel(const std::string& mt) {
	m_maxTravel = mt;
}

void Chassis::setTireModel(const std::string& m) {
	m_tires.setModel(m);
}

void Chassis::setTireSize(const std::string& s) {
	m_tires.setSize(s);
}

// Implement getters
std::string Chassis::getId() const {
	return m_id;
}

std::string Chassis::getModel() const {
	return m_model;
}

std::string Chassis::getWheelbase() const {
	return m_wheelbase;
}

std::string Chassis::getTrack() const {
	return m_track;
}

std::string Chassis::getGroundClearance() const {
	return m_groundClearance;
}

std::string Chassis::getTurningRadius() const {
	return m_turningRadius;
}

std::string Chassis::getDriveType() const {
	return m_driveType;
}

std::string Chassis::getMaxTravel() const {
	return m_maxTravel;
}

std::string Chassis::getTireModel() const {
	return m_tires.getModel();
}

std::string Chassis::getTireSize() const {
	return m_tires.getSize();
}

void Chassis::print() const {
	std::cout << "���̱��: " << m_id << std::endl;
	std::cout << "�����ͺ�: " << m_model << std::endl;
	std::cout << "���: " << m_wheelbase << std::endl;
	std::cout << "�־�: " << m_track << std::endl;
	std::cout << "��С��ؼ�϶: " << m_groundClearance << std::endl;
	std::cout << "��Сת��뾶: " << m_turningRadius << std::endl;
	std::cout << "������ʽ: " << m_driveType << std::endl;
	std::cout << "����г�: " << m_maxTravel << std::endl;
	std::cout << "��̥��Ϣ:" << std::endl;
	m_tires.print();
}

void Chassis::save(std::ofstream& outFile) const {
	outFile << "���̱��: " << m_id << std::endl;
	outFile << "�����ͺ�: " << m_model << std::endl;
	outFile << "���: " << m_wheelbase << std::endl;
	outFile << "�־�: " << m_track << std::endl;
	outFile << "��С��ؼ�϶: " << m_groundClearance << std::endl;
	outFile << "��Сת��뾶: " << m_turningRadius << std::endl;
	outFile << "������ʽ: " << m_driveType << std::endl;
	outFile << "����г�: " << m_maxTravel << std::endl;
	outFile << "��̥��Ϣ:" << std::endl;
	m_tires.save(outFile);
}

void Chassis::attachLidar(Lidar* l)
{
	m_lidar = l;
	m_lidar->subscribe(this);
}

void Chassis::onObstacleStatusChange(ObstacleStatus status)
{
	switch (status) {
	case OBSTACLE_FRONT:
		std::cout << getId() << ": �ϰ�����ǰ��������\n";
		break;
	case OBSTACLE_LEFT_FRONT:
		std::cout << getId() << ": �ϰ�������ǰ������ת\n";
		break;
	case OBSTACLE_RIGHT_FRONT:
		std::cout << getId() << ": �ϰ�������ǰ������ת\n";
		break;
	default:
		std::cout << getId() << ": û���ϰ������ǰ��\n";
		break;
	}
}
