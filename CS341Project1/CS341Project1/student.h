#pragma once
class student
{
public:
	string Name;
	int Midterm;
	int Final;

	student(string name, int midterm, int final) 
		: Name(name), Midterm(Midterm), Final(final) 
	{}
	~student();
};

