#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output)
    try : _api(input, output) {}
        catch (std::exception const &ex) {
            throw CommunicationError("Error: " + std::string(ex.what()));
        }

CommunicationDevice::~CommunicationDevice()
{
}

void    CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    } catch (std::exception const &ex) {
        throw CommunicationError("LogicError: " + std::string(ex.what()));
    } catch (std::logic_error const &ex) {
        throw CommunicationError("LogicError: " + std::string(ex.what()));
    } catch (std::runtime_error const &ex) {
        throw CommunicationError("LogicError: " + std::string(ex.what()));
    }
}

void    CommunicationDevice::send(std::string const &user, std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch(std::exception const &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void    CommunicationDevice::receive(std::string const &user, std::string &message) const
{
    if (user.length() == 0)
        throw CommunicationError("Error: userName should be at least 1 char.");
    try {
        _api.receiveMessage(user, message);
    } catch(std::exception const &ex) {
        std::cerr << ex.what() << std::endl;
        std::cerr << "INVALID MESSAGE";
    }
}
