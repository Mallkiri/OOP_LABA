#include "ElectricityBill.h"

ElectricityBill::ElectricityBill() 
{
	Rate = 1;
	RecordingYear = 0;
	AverageConsumption = 0;
	TotalPaymentAmount = 0;
	Address = new char[50];
	memset(MonthlyExpand, 0, Months);
	memset(MonthlyPayment, 0, Months);
}

ElectricityBill::ElectricityBill(float rate, int year, const char* address, int* expands, int number_of_months) 
{
	if (address == nullptr) 
	{
		throw std::invalid_argument("������� ������ ������");
	}
	if (rate <= 0)
	{
		throw std::invalid_argument("����� �� ����� ���� ������ ���� ����� ����");
	}
	switch (address[0])
	{
	case '\0':
		throw std::invalid_argument("������ �� ����� ���� ������");
		break;
	case ' ':
		throw std::invalid_argument("������ �� ����� ���������� � �������");
		break;
	default:
		break;
	}
	for (int i = 0; i < number_of_months; i++)
	{
		if (expands[i] < 0) {
			throw std::invalid_argument("������� �� ������������� �� ����� ���� ��������������");
		}
	};
	this->Rate = rate;
	RecordingYear = year;
	TotalPaymentAmount = 0;
	Address = new char[strlen(address) + 1];
	strcpy_s(Address, strlen(address) + 1, address);
	memset(MonthlyExpand, 0, Months);
	memset(MonthlyPayment, 0, Months);

	for (int i = 0; i < number_of_months; i++)
	{
		MonthlyExpand[i] = expands[i];
		MonthlyPayment[i] = MonthlyExpand[i] * Rate;
		TotalPaymentAmount += MonthlyPayment[i];
	};
	AverageConsumption = TotalPaymentAmount / Months;
}

ElectricityBill::ElectricityBill(float rate) 
{
	if (rate <= 0) {
		throw std::invalid_argument("����� �� ����� ���� ������ ���� ����� ����");
	}
	this->Rate = rate;
	RecordingYear = 0;
	Address = new char[50];
	memset(MonthlyExpand, 0, Months);
	memset(MonthlyPayment, 0, Months);
	TotalPaymentAmount = 0;
	AverageConsumption = TotalPaymentAmount / Months;
}

std::string ElectricityBill::GetMonthName(int index_of_month)
{
	return MonthName[index_of_month];
}



double ElectricityBill::Selector(Info choice) const 
{
	switch (choice)
	{
	case Info::Get_RecordingYear:
		return RecordingYear;
	case Info::Get_TotalPaymentAmount:
		return TotalPaymentAmount;
	case Info::Get_Rate:
		return Rate;
	case Info::Get_AverageConsumption:
		return AverageConsumption;
	default:
		break;
	}
}

void ElectricityBill::GetMonthlyInfo() const
{
	std::cout << "������� �� ������������� �� �������:\t�������� �����:" << std::endl;
	for (int i = 0; i < Months; i++) 
	{
		std::cout << MonthName[i] << ": " << MonthlyExpand[i] << '\t' << MonthlyPayment[i] << std::endl;
	}
	std::cout << "�����: " << Rate << std::endl;
	std::cout << "������� ����� �������: " << TotalPaymentAmount << std::endl;
	std::cout << "������� ����������� ������������� � �����: " << AverageConsumption << std::endl;
	std::cout << "������: " << Address << std::endl;
}

void ElectricityBill::SetInfoForYear(const char* address, int year, int* expands) 
{
	if (address == nullptr) 
	{
		throw std::invalid_argument("������ ������ ��������� �� ������");
	}
	switch (address[0])
	{
	case '\0':
		throw std::invalid_argument("������ �� ����� ���� ������");
		break;
	case ' ':
		throw std::invalid_argument("������ �� ����� ���������� � �������");
		break;
	default:
		break;
	}

	if (year < 1998 || year > 2100) 
	{
		throw std::invalid_argument("��� ������� �� ������ ���� ������ 1998 ���� � ����� 2100");
	}
	for (int i = 0; i < Months; i++)
	{
		if (expands[i] < 0) {
			throw std::invalid_argument("������� �� ����� ���� ������ 0");
		}
	}
	for (int i = 0; i < Months; i++)
	{
		if (expands[i] < 0) 
		{
			throw std::invalid_argument("������� �� ����� ���� ������ 0");
		}
		MonthlyExpand[i] = expands[i];
		MonthlyPayment[i] = MonthlyExpand[i] * Rate;
		TotalPaymentAmount += MonthlyPayment[i];
	}
	AverageConsumption = TotalPaymentAmount / 12;
}

void ElectricityBill::ChangeMonthlyinfo(Month month, int expand) 
{
	if (expand < 0) {
		throw std::invalid_argument("������� �� ����� ���� ������ 0");
	}
	MonthlyExpand[(int)month] = expand;
	TotalPaymentAmount -= MonthlyPayment[(int)month];
	MonthlyPayment[(int)month] = MonthlyExpand[(int)month] * Rate;
	TotalPaymentAmount += MonthlyPayment[(int)month];
	AverageConsumption = TotalPaymentAmount / 12;

}

ElectricityBill::~ElectricityBill() 
{
	delete[] Address;
}
