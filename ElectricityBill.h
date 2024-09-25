#pragma once
#include "iostream"
class ElectricityBill
{
private:
	int static const Months = 12;
	char* Address;
	int MonthlyExpand[Months];
	int RecordingYear;
	double MonthlyPayment[Months];
	double TotalPaymentAmount;
	float Rate;
	double AverageConsumption;
	std::string MonthName[12]{ "Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь" };
public:
	ElectricityBill();
	ElectricityBill(float rate, int year, const char* address, int* expands, int number_of_months);
	ElectricityBill(float rate);
	~ElectricityBill();

	enum class Info {
		Get_RecordingYear = 1,
		Get_TotalPaymentAmount,
		Get_Rate,
		Get_AverageConsumption
	};

	enum class Month {
		JANUARY ,
		FEBRUARY,
		MARCHT,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBRE
	};

	std::string GetMonthName(int index_of_month);
	double Selector(Info choice) const;
	void GetMonthlyInfo() const;
	void SetInfoForYear(const char* address, int year, int* expands);
	void ChangeMonthlyinfo(Month month, int expand);

};


