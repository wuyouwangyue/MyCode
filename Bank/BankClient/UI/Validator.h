#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <ctype.h>
#include <string>

///校验文件

namespace UI
{

///校验姓名
bool ValidateName(const std::string& str, char ch);
///校验密码
bool ValidatePass(const std::string& str, char ch);
///校验身份证
bool ValidateId(const std::string& str, char ch);
///校验登陆Id
bool ValidateAccountId(const std::string& str, char ch);
///校验钱数，只能有两位小数，小数前面最多有8位，总长度不超过11位，包括小数点
bool ValidateMoney(const std::string& str, char ch);
}


#endif //_VALIDATOR_H_