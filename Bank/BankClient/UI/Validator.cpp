#include "Validator.h"

namespace UI
{

///У������, ����С��10λ
bool ValidateName(const std::string& str, char ch)
{
	return str.length() < 10 && isalnum(ch);
}
///У������
bool ValidatePass(const std::string& str, char ch)
{
	return str.length() < 8 && !isspace(ch);
}
///У�����֤
bool ValidateId(const std::string& str, char ch)
{
	if ( str.length() >= 18 )
		return false;
	if ( !isdigit(ch) && ch != 'x' && ch != 'X' )
		return false;
	if ( str.length() != 17 && ( ch=='x' || ch=='X' ) )
		return false;

	return true;
}

bool ValidateAccountId(const std::string& str, char ch)
{
	return str.length() < 6 && isdigit(ch);
}
///У��Ǯ����ֻ������λС����С��ǰ�������8λ���ܳ��Ȳ�����11λ������С����
bool ValidateMoney(const std::string& str, char ch)
{
	if ( str.length() >= 11 || ( !isdigit(ch) && ch != '.' ) )
		return false;

	bool findDot = false;
	size_t dotPos = std::string::npos;
	dotPos = str.find('.');

	if ( dotPos != std::string::npos )
		findDot = true;

	if ( findDot )
	{
		if ( ch == '.' )
			return false;
		if ( str.length()-1 >= dotPos+2 )
			return false;
	}
	else if ( ch !='.' && str.length() >= 8 )
		return false;

	return true;
}

}