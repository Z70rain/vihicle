#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "SmartCar.h"
#include "Student.h"

#ifdef _WIN32
#include <windows.h> // Windows headers
#include <filesystem>
#else
#include <dirent.h>  // Linux headers
#endif

std::string generateRandomLetters(int length) {
	// ������ĸ��
	const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// ���������ĸ��
	std::string random_letters;
	for (int i = 0; i < length; ++i) {
		int random_index = std::rand() % alphabet.length();
		random_letters += alphabet[random_index];
	}

	return random_letters;
}

Student* searchStuIfExist(Student students[], int n, std::string id)
{
	for (size_t i = 0; i < n; i++) {
		if (students[i].getStudentID() == id)
			return &students[i];
	}
	return nullptr;
}

// ����nλ�������
std::string generateRandomDigits(int n) {
	// ����������ִ�
	std::string random_digits;
	for (int i = 0; i < n; ++i) {
		int random_digit = std::rand() % 10;  // ����0��9֮����������
		random_digits += std::to_string(random_digit);
	}

	return random_digits;
}

void inputSmartCarInfo(SmartCar& car, std::string car_id) {
	// �������С����Ϣ���������̡�AGX�׼���˫Ŀ����ͷ�������״�����ǡ�Һ����ʾ�������ģ��
	car.setId(car_id);

	Chassis chassis;
	chassis.setId("dp" + generateRandomDigits(8) + generateRandomLetters(2));
	chassis.setModel("SCOUT MINI");
	chassis.setWheelbase("451.0");
	chassis.setTrack("490.0");
	chassis.setGroundClearance("115.0");
	chassis.setTurningRadius("0.0");
	chassis.setDriveType("��������");
	chassis.setMaxTravel("10.0");
	chassis.setTireModel("��·��");
	chassis.setTireSize("175.0");

	AGXKit agxKit;
	agxKit.setModel("AGX Xavier");
	agxKit.setAIPerformance("32.0");
	agxKit.setCudaCores("512");
	agxKit.setTensorCores("64");
	agxKit.setMemory("32.0");
	agxKit.setStorage("32.0");

	Camera camera;
	camera.setModel("RealSense D435i");
	camera.setCameraType("D430");
	camera.setResolution("1920x1080");
	camera.setFrameRate("30");
	camera.setFOV("87.58");
	camera.setDepthFrameRate("90");

	Lidar lidar;
	lidar.setModel("RS-Helios-16p");
	lidar.setChannels("16");
	lidar.setRange("100.0");
	lidar.setPowerConsumption("8.0");

	Gyroscope gyroscope;
	gyroscope.setModel("CH110");
	gyroscope.setManufacturer("NXP");

	Display display;
	display.setSize("11.6");
	display.setModel("super");

	Battery battery;
	battery.setParameters("24V/15Ah");
	battery.setExternalPower("24.0");
	battery.setChargingDuration("2.0");

	car.setChassis(chassis);
	car.setAGXKit(agxKit);
	car.setCamera(camera);
	car.setLidar(lidar);
	car.setGyroscope(gyroscope);
	car.setDisplay(display);
	car.setBattery(battery);
}


void inputStudentInfo(Student& student, std::string stuId, std::string name) {
	student.setStudentID(stuId);
	student.setName(name);
}

void inputSmartCarInfoManually(SmartCar& car) {

	// ��������С�����
	std::cout << "����������С�����: ";
	std::string carID;
	std::cin >> carID;
	car.setId(carID);

	// ���������Ϣ
	Chassis chassis;
	std::cout << "��������̱��: ";
	std::string chassisNumber;
	std::cin >> chassisNumber;
	chassis.setId(chassisNumber);

	std::cout << "����������ͺ�: ";
	std::string chassisModel;
	std::cin >> chassisModel;
	chassis.setModel(chassisModel);

	std::cout << "������������ (mm): ";
	std::string wheelbase;
	std::cin >> wheelbase;
	chassis.setWheelbase(wheelbase);

	std::cout << "����������־� (mm): ";
	std::string track;
	std::cin >> track;
	chassis.setTrack(track);

	std::cout << "��������С��ؼ�϶ (mm): ";
	std::string groundClearance;
	std::cin >> groundClearance;
	chassis.setGroundClearance(groundClearance);

	std::cout << "��������Сת��뾶 (m): ";
	std::string turningRadius;
	std::cin >> turningRadius;
	chassis.setTurningRadius(turningRadius);

	std::cout << "������������ʽ: ";
	std::string driveType;
	std::cin >> driveType;
	chassis.setDriveType(driveType);

	std::cout << "����������г� (KM): ";
	std::string maxTravel;
	std::cin >> maxTravel;
	chassis.setMaxTravel(maxTravel);

	// ������̥��Ϣ
	std::cout << "��������̥�ͺ�: ";
	std::string tireModel;
	std::cin >> tireModel;
	chassis.setTireModel(tireModel);

	std::cout << "��������̥�ߴ� (mm): ";
	std::string tireSize;
	std::cin >> tireSize;
	chassis.setTireSize(tireSize);

	// ����AGX�׼���Ϣ
	AGXKit agxKit;
	std::cout << "������AGX�׼��ͺ�: ";
	std::string agxKitModel;
	std::cin >> agxKitModel;
	agxKit.setModel(agxKitModel);

	std::cout << "������AI���� (TOPS): ";
	std::string aiPerformance;
	std::cin >> aiPerformance;
	agxKit.setAIPerformance(aiPerformance);

	std::cout << "������CUDA������: ";
	std::string cudaCores;
	std::cin >> cudaCores;
	agxKit.setCudaCores(cudaCores);

	std::cout << "������Tensor CORE��: ";
	std::string tensorCores;
	std::cin >> tensorCores;
	agxKit.setTensorCores(tensorCores);

	std::cout << "�������Դ� (G): ";
	std::string memory;
	std::cin >> memory;
	agxKit.setMemory(memory);

	std::cout << "������洢 (G): ";
	std::string storage;
	std::cin >> storage;
	agxKit.setStorage(storage);

	// ���������Ϣ
	Camera camera;
	std::cout << "����������ͺ�: ";
	std::string cameraModel;
	std::cin >> cameraModel;
	camera.setModel(cameraModel);

	std::cout << "�������������: ";
	std::string cameraType;
	std::cin >> cameraType;
	camera.setCameraType(cameraType);

	std::cout << "����������ֱ���: ";
	std::string resolution;
	std::cin >> resolution;
	camera.setResolution(resolution);

	std::cout << "���������֡��: ";
	std::string frameRate;
	std::cin >> frameRate;
	camera.setFrameRate(frameRate);

	std::cout << "������FOV: ";
	std::string fov;
	std::cin >> fov;
	camera.setFOV(fov);

	std::cout << "���������֡��: ";
	std::string depthFrameRate;
	std::cin >> depthFrameRate;
	camera.setDepthFrameRate(depthFrameRate);

	// ���뼤���״���Ϣ
	Lidar lidar;
	std::cout << "�����뼤���״��ͺ�: ";
	std::string lidarModel;
	std::cin >> lidarModel;
	lidar.setModel(lidarModel);

	std::cout << "�����뼤���״�ͨ����: ";
	std::string channels;
	std::cin >> channels;
	lidar.setChannels(channels);

	std::cout << "�����뼤���״���Է�Χ (m): ";
	std::string testRange;
	std::cin >> testRange;
	lidar.setRange(testRange);

	std::cout << "�����뼤���״﹦�� (W): ";
	std::string powerConsumption;
	std::cin >> powerConsumption;
	lidar.setPowerConsumption(powerConsumption);

	// ������������Ϣ
	Gyroscope gyroscope;
	std::cout << "�������������ͺ�: ";
	std::string gyroscopeModel;
	std::cin >> gyroscopeModel;
	gyroscope.setModel(gyroscopeModel);

	std::cout << "������������������: ";
	std::string gyroscopeManufacturer;
	std::cin >> gyroscopeManufacturer;
	gyroscope.setManufacturer(gyroscopeManufacturer);

	// ����Һ����ʾ����Ϣ
	Display display;
	std::cout << "������Һ����ʾ���ߴ� (Ӣ��): ";
	std::string displaySize;
	std::cin >> displaySize;
	display.setSize(displaySize);

	std::cout << "������Һ����ʾ���ͺ�: ";
	std::string displayModel;
	std::cin >> displayModel;
	display.setModel(displayModel);

	// ������ģ����Ϣ
	Battery battery;
	std::cout << "�������ز���: ";
	std::string batteryParameters;
	std::cin >> batteryParameters;
	battery.setParameters(batteryParameters);

	std::cout << "�������ⲿ��Դ��ѹ (V): ";
	std::string externalPower;
	std::cin >> externalPower;
	battery.setExternalPower(externalPower);

	std::cout << "��������ʱ�� (H): ";
	std::string chargingDuration;
	std::cin >> chargingDuration;
	battery.setChargingDuration(chargingDuration);

	// ����ѧ����Ϣ
	Student studentInfo;
	std::cout << "������ѧ������: ";
	std::string studentName;
	std::cin >> studentName;
	studentInfo.setName(studentName);

	std::cout << "������ѧ��ѧ��: ";
	std::string studentID;
	std::cin >> studentID;
	studentInfo.setStudentID(studentID);

	// �������������Ϣ���õ�����С������
	car.setChassis(chassis);
	car.setAGXKit(agxKit);
	car.setCamera(camera);
	car.setLidar(lidar);
	car.setGyroscope(gyroscope);
	car.setDisplay(display);
	car.setBattery(battery);
	car.setStudentInfo(studentInfo);
}


SmartCar parseSmartCarInfoFromFile(const std::string& filePath) {
	SmartCar car;

	std::ifstream file(filePath);
	Chassis chassis;
	AGXKit agxKit;
	Camera camera;
	Lidar lidar;
	Gyroscope gyroscope;
	Display display;
	Battery battery;
	Student studentInfo;

	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string key, value;
			std::getline(iss, key, ':');
			std::getline(iss, value);

			if (key == "����С�����")
				car.setId(value);
			else if (key == "���̱��")
				chassis.setId(value);
			else if (key == "�����ͺ�")
				chassis.setModel(value);
			else if (key == "���")
				chassis.setWheelbase(value);
			else if (key == "�־�")
				chassis.setTrack(value);
			else if (key == "��С��ؼ�϶")
				chassis.setGroundClearance(value);
			else if (key == "��Сת��뾶")
				chassis.setTurningRadius(value);
			else if (key == "������ʽ")
				chassis.setDriveType(value);
			else if (key == "����г�")
				chassis.setMaxTravel(value);
			else if (key == "��̥��Ϣ") {
				std::getline(iss, key, ':');
				std::getline(iss, value);
				if (key == "��̥�ͺ�") {
					chassis.setTireModel(value);
				}
				else if (key == "�ߴ�") {
					chassis.setTireSize(value);
				}
			}
			else if (key == "AGX�׼��ͺ�")
				agxKit.setModel(value);
			else if (key == "AI����")
				agxKit.setAIPerformance(value);
			else if (key == "CUDA������")
				agxKit.setCudaCores(value);
			else if (key == "Tensor CORE��")
				agxKit.setTensorCores(value);
			else if (key == "�Դ�")
				agxKit.setMemory(value);
			else if (key == "�洢")
				agxKit.setStorage(value);
			else if (key == "˫Ŀ����ͷ�ͺ�")
				camera.setModel(value);
			else if (key == "����ͷ����")
				camera.setCameraType(value);
			else if (key == "RGB֡�ֱ���")
				camera.setResolution(value);
			else if (key == "RGB֡��")
				camera.setFrameRate(value);
			else if (key == "FOV")
				camera.setFOV(value);
			else if (key == "���֡��")
				camera.setDepthFrameRate(value);
			else if (key == "���߼����״��ͺ�")
				lidar.setModel(value);
			else if (key == "ͨ����")
				lidar.setChannels(value);
			else if (key == "���Է�Χ")
				lidar.setRange(value);
			else if (key == "����")
				lidar.setPowerConsumption(value);
			else if (key == "9���������ͺ�")
				gyroscope.setModel(value);
			else if (key == "������")
				gyroscope.setManufacturer(value);
			else if (key == "Һ����ʾ���ߴ�")
				display.setSize(value);
			else if (key == "Һ����ʾ���ͺ�")
				display.setModel(value);
			else if (key == "��ز���")
				battery.setParameters(value);
			else if (key == "�ⲿ��Դ")
				battery.setExternalPower(value);
			else if (key == "���ʱ��")
				battery.setChargingDuration(value);
			else if (key == "ѧ������")
				studentInfo.setName(value);
			else if (key == "ѧ��")
				studentInfo.setStudentID(value);
		}
		car.setChassis(chassis);
		car.setAGXKit(agxKit);
		car.setCamera(camera);
		car.setDisplay(display);
		car.setGyroscope(gyroscope);
		car.setLidar(lidar);
		car.setStudentInfo(studentInfo);
		car.setBattery(battery);
		file.close();
		std::cout << "������С����Ϣ" << car.getId() << std::endl;
	}

	return car;
}

std::vector<SmartCar> readSmartCarsFromDirectory(const std::string& directoryPath) {
	std::vector<SmartCar> cars;

#ifdef _WIN32
	for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
		if (entry.is_regular_file()) {
			std::string filePath = entry.path().string();
			SmartCar car = parseSmartCarInfoFromFile(filePath);
			cars.push_back(car);
		}
	}
#else
	DIR* dir = opendir(directoryPath.c_str());
	if (dir != nullptr) {
		struct dirent* entry;
		while ((entry = readdir(dir))) {
			if (entry->d_type == DT_REG) {
				std::string filePath = directoryPath + "/" + entry->d_name;
				SmartCar car = parseSmartCarInfoFromFile(filePath);
				cars.push_back(car);
			}
		}
		closedir(dir);
	}
#endif

	return cars;
}

void showCarVecInfoInTermial(std::vector<SmartCar> cars)
{
	std::cout << "----------��ʾ����С����Ϣ----------" << std::endl;
	char choice;
	int current_car = 0;
	do {
		cars[current_car].print();
		std::cout << "����n����ʾ��һ����������p����ʾ��һ����������q����ʾ�˳� :";
		std::cin >> choice;

		if (choice == 'n' && current_car < cars.size() - 1) {
			current_car++;
		}
		else if (choice == 'p' && current_car > 0) {
			current_car--;
		}

	} while (choice != 'q');
}

// ���������������
std::string generateRandomChineseName() {
	// �����б�
	std::vector<std::string> first_names = {
		"��", "Ǯ", "��", "��", "��", "��", "֣", "��", "��", "��",
		"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"��", "��", "ʩ", "��", "��", "��", "��", "��", "��", "κ"
	};

	// �����б�
	std::vector<std::string> last_names = {
		"ΰ", "��", "��", "��", "ǿ", "��", "��", "��", "��", "��",
		"÷", "��", "��", "��", "��", "��", "ϼ", "ƽ", "��", "��"
	};

	// ���ѡ�����Ϻ�����
	std::string first_name = first_names[rand() % first_names.size()];
	std::string last_name = last_names[rand() % last_names.size()];

	// �������ɵ���������
	return first_name + last_name;
}

bool isAutoOperation(const std::string &tip)
{
	// �Ƿ��Զ���������С����Ϣ
	std::string strFlag;
	std::cout << tip;
	std::cin >> strFlag;
	if (strFlag == "y" || strFlag == "Y") {
		return true;
	}
	return false;
}