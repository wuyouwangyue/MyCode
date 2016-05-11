#include "Validator.h"

namespace UI
{

///校验姓名, 长度小于10位
bool ValidateName(const std::string& str, char ch)
{
	return str.length() < 10 && isalnum(ch);
}
///校验密码
bool ValidatePass(const std::string& str, char ch)
{
	return str.length() < 8 && !isspace(ch);
}
///校验身份证
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
///校验钱数，只能有两位小数，小数前面最多有8位，总长度不超过11位，包括小数点
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