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

}


#endif //_VALIDATOR_H_