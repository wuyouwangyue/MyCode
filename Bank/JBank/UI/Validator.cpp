#include "Validator.h"

namespace UI
{

///У������, ����С��10λ
bool ValidateName(const std::string& str, char ch)
{
	return str.length() < 17 && isalnum(ch);
}
///У������
bool ValidatePass(const std::string& str, char ch)
{
	return str.length() < 8 && !isspace(ch);
}

}