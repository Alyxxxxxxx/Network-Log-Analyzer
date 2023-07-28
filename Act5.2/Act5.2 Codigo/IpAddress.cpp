#include "IpAddress.h"

ipAddress::ipAddress(){
    ipString = "0.0.0.0";
    ipIndex = 0;
    degreeIn = 0;
    degreeOut = 0;
    ipValue = 0;
    showAccessedIp = false;
}

ipAddress::ipAddress(std::string _ip, int idx){
    ipString = _ip;
    ipIndex = idx;
    degreeIn = 0;
    degreeOut = 0;
    showAccessedIp = false;

    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;

    while (posFound >= 0){
        posFound = ipString.find(".", posInit);
        splitted = ipString.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    try{
        int partA = std::stoi(results[0]);
        int partB = std::stoi(results[1]);
        int partC = std::stoi(results[2]);
        int partD = std::stoi(results[3]);
        
        ipValue = partA * (pow(256, 3)) + partB * (pow(256, 2)) + partC * (pow(256, 1)) + partD;
    }

    catch (const std::exception &e){
        std::cerr << "Error: " << "Direccion IP no valida." << std::endl;
    }

}

std::string ipAddress::getIp(){
    return ipString;
}

unsigned int ipAddress::getIpValue(){
    return ipValue;
}

int ipAddress::getIpIndex(){
    return ipIndex;
}

std::ostream &operator<<(std::ostream &os, const ipAddress &object){

    if (object.showAccessedIp == true){
        os << "IP: " << object.ipString;
    }

    else{
        os << "Direccion IP: " << object.ipString << "\t\t\t\t     |\n" << "Direcciones accesadas: " << object.degreeOut << "\t\t\t\t     |\n" << "Direcciones que intentaron acceder: " << object.degreeIn << "\t\t\t     |";
    }

    return os;
}

bool ipAddress::operator==(const ipAddress &other) const{
    return this->ipValue == other.ipValue;
}

bool ipAddress::operator!=(const ipAddress &other) const{
    return this->ipValue != other.ipValue;
}

bool ipAddress::operator>(const ipAddress &other) const{
    return this->ipValue > other.ipValue;
}

bool ipAddress::operator>=(const ipAddress &other) const{
    return this->ipValue >= other.ipValue;
}

bool ipAddress::operator<(const ipAddress &other) const{
    return this->ipValue < other.ipValue;
}

bool ipAddress::operator<=(const ipAddress &other) const{
    return this->ipValue <= other.ipValue;
}

void ipAddress::setDegreeIn(int g){
    degreeIn = g;
}

void ipAddress::addToDegreeIn(){
    degreeIn++;
}

int ipAddress::getDegreeIn(){
    return degreeIn;
}

void ipAddress::setDegreeOut(int g){
    degreeOut = g;
}

void ipAddress::addToDegreeOut(){
    degreeOut++;
}

int ipAddress::getDegreeOut(){
    return degreeOut;
}

std::string toString(){
    int value = 0;
    return std::to_string(value);
}