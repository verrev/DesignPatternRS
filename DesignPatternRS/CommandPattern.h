#pragma once

#include <string>
#include <vector>
#include <iostream>

class Device
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
	virtual void volumeUp() = 0;
	virtual void volumeDown() = 0;
};

class Television : public Device
{
public:
	void on() { std::cout << "TV is on."; }
	void off() { std::cout << "TV is off."; }
	void volumeUp() { ++mVolume; std::cout << "Volume: " << mVolume; }
	void volumeDown() { --mVolume; std::cout << "Volume: " << mVolume; }
private:
	int mVolume;
};

class Radio : public Device
{
public:
	void on() { std::cout << "Radio is on."; }
	void off() { std::cout << "Radio is off."; }
	void volumeUp() { ++mVolume; std::cout << "Volume: " << mVolume; }
	void volumeDown() { --mVolume; std::cout << "Volume: " << mVolume; }
private:
	int mVolume;
};

class Command
{
public:
	virtual void execute() = 0;
protected:
	Device *mDevice;
};

class MasterOff : public Command
{
public:
	MasterOff(std::vector<Device*> devices) { mDevices = devices; }
	void execute() { for (auto d : mDevices) d->off(); }
private:
	std::vector<Device*> mDevices;
};

class TurnTVOn : public Command
{
public:
	TurnTVOn(Device *electronicDevice) { mDevice = electronicDevice; }
	void execute() { mDevice->on(); }
};

class TurnTVOff : public Command
{
public:
	TurnTVOff(Device *electronicDevice) { mDevice = electronicDevice; }
	void execute() { mDevice->off(); }
};

class IncreaseVolume : public Command
{
public:
	IncreaseVolume(Device *electronicDevice) { mDevice = electronicDevice; }
	void execute() { mDevice->volumeUp(); }
};

class DecreaseVolume : public Command
{
public:
	DecreaseVolume(Device *electronicDevice) { mDevice = electronicDevice; }
	void execute() { mDevice->volumeDown(); }
};

class DeviceButton
{
public:
	DeviceButton(Command *command) : mCommand(command) {}
	virtual void press() { mCommand->execute(); }
private:
	Command *mCommand;
};

class TVRemote : public DeviceButton
{
public:
	static Device *getDevice();
};

/*

Device *TVRemote::getDevice()
{
return new Television();
}

Device *television = new Television;

Command *onCommand = new TurnTVOn(television);
DeviceButton *onPressedButton = new DeviceButton(onCommand);
onPressedButton->press();
onPressedButton->press();
onPressedButton->press();

Command *offCommand = new TurnTVOff(television);
DeviceButton *offPressedButton = new DeviceButton(offCommand);
offPressedButton->press();

Device *radio = new Radio;

std::vector<Device*> devices;
devices.push_back(television);
devices.push_back(radio);

Command *masterOff = new MasterOff(devices);
DeviceButton *masterOffButton = new DeviceButton(masterOff);
masterOffButton->press();

delete masterOff;
delete masterOffButton;
delete onCommand;
delete onPressedButton;
delete television;
delete offCommand;
delete offPressedButton;
delete radio;
*/