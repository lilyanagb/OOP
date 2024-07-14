#pragma once

class Message
{
public:
	Message(const int data =0);

	int getData() const;

private:
	int data;
};