#include "Validator.h"

namespace UI
{

///校验姓名, 长度小于10位
bool ValidateName(const std::string& str, char ch)
{
	return str.length() < 17 && isalnum(ch);
}
///校验密码
bool ValidatePass(const std::string& str, char ch)
{
	return str.length() < 8 && !isspace(ch);
}

}